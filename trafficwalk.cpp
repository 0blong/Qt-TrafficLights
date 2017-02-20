#include "trafficwalk.h"

#include <QTimerEvent>

#include "outputmessage.h"

//constructor
TrafficWalk::TrafficWalk(WalkSign * ws, TrafficLightButton * tlb, QObject *parent) :
    QObject(parent),
    walk_sign(ws),
    traffic_light_button(tlb),
    m_light_state(TWLight::GO),
    m_flash_state(TWFlash::FLASHON),
    m_flashes_done(0)
{
    flash_timer.setInterval(m_flash_cycle);
    stop_preamble_timer.setInterval(m_stop_preamble);

    walk_sign->stopWalking();
    traffic_light_button->push();

    setLightState(m_light_state);

    timer.setInterval(m_go);
    timer.start();
    connect(&timer, SIGNAL(timeout()), this, SLOT(setNextLightState()));
    connect(&flash_timer, SIGNAL(timeout()), this, SLOT(setNextFlashState()));
    connect(&stop_preamble_timer, SIGNAL(timeout()), this, SLOT(setStopState()));
}

//incoming message from button
void TrafficWalk::doLightStateChange()
{
    if(m_light_state == TWLight::GO) {
        setNextLightState();
    }
}

void TrafficWalk::setNextLightState()
{
    if(m_light_state == TWLight::FLASH) {//        OutputMessage::outputMessage("TRAFFICWALK - GO");
        setLightState(TWLight::GO);
        traffic_light_button->push();
        timer.setInterval(m_go);
    }
    else if(m_light_state == TWLight::GO) {//        OutputMessage::outputMessage("TRAFFICWALK - SLOW");
        setLightState(TWLight::SLOW);
        traffic_light_button->wait();
        timer.setInterval(m_slow);
    }
    else if (m_light_state == TWLight::SLOW) {//        OutputMessage::outputMessage("TRAFFICWALK - STOP");
        setLightState(TWLight::STOP);        
        timer.setInterval(m_stop);
        stop_preamble_timer.start();
    }
    else if (m_light_state == TWLight::STOP) {//        OutputMessage::outputMessage("TRAFFICWALK - FLASH");
        setLightState(TWLight::FLASH);
        timer.setInterval(m_flash);
        setNextFlashState();
        flash_timer.start();
    }
}

void TrafficWalk::setLightState(TWLight value)
{
    m_light_state = value;
    emit lightStateChanged();
}

void TrafficWalk::setStopState() {
    stop_preamble_timer.stop();
    walk_sign->startWalking();
    traffic_light_button->cross();
}

void TrafficWalk::setNextFlashState()
{
    if(m_flashes_done < m_flashes_to_do) {
        traffic_light_button->wait();
        m_flashes_done++;
        if(m_flash_state == TWFlash::FLASHOFF) {
            setFlashState(TWFlash::FLASHON);
            walk_sign->flashOn();
        }
        else {
            setFlashState(TWFlash::FLASHOFF);
            walk_sign->flashOff();
        }
    }
    else {
        m_flashes_done = 0;
        walk_sign->stopWalking();
        flash_timer.stop();
    }
}

void TrafficWalk::setFlashState(TWFlash value)
{
    m_flash_state = value;
    emit flashStateChanged();
}
