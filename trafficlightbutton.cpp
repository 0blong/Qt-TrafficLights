#include "trafficlightbutton.h"

TrafficLightButton::TrafficLightButton(QObject *parent) :
    QObject(parent),
    m_button_state(EButton::PUSH)
{
    setButtonState(m_button_state);
}

QString TrafficLightButton::getButtonStateString()
{
    return  (m_button_state == EButton::PUSH ? "PUSH" :
            (m_button_state == EButton::WAIT ? "WAIT" : "CROSS"));
}

void TrafficLightButton::setButtonState(EButton value)
{
    m_button_state = value;
    emit buttonStateChanged();
}

//incoming messages from traffic light
void TrafficLightButton::wait()
{
    setButtonState(EButton::WAIT);
}

void TrafficLightButton::cross()
{
    setButtonState(EButton::CROSS);
}

void TrafficLightButton::push()
{
    setButtonState(EButton::PUSH);
}

void TrafficLightButton::off()
{
    setButtonState(EButton::OFF);
}
