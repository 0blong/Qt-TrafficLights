#ifndef TRAFFICWALK_H
#define TRAFFICWALK_H

#include <QTimer>
#include <QObject>

#include "trafficlightbutton.h"
#include "walksign.h"

class TrafficWalk : public QObject
{
    Q_OBJECT
    Q_PROPERTY(TWLight lightState READ getLightState WRITE setLightState NOTIFY lightStateChanged)
    Q_PROPERTY(TWFlash flashState READ getFlashState WRITE setFlashState NOTIFY flashStateChanged)

public:
    explicit TrafficWalk(WalkSign * ws, TrafficLightButton * tlb, QObject *parent = 0);

    enum TWLight {
        STOP,
        FLASH,
        GO,
        SLOW
    };
    Q_ENUMS(TWLight)

    enum TWFlash {
        FLASHON,
        FLASHOFF
    };
    Q_ENUMS(TWFlash)

    TWLight getLightState() const { return m_light_state; }
    TWFlash getFlashState() const { return m_flash_state; }

    Q_INVOKABLE void doLightStateChange();

signals:
    lightStateChanged();
    flashStateChanged();

private slots:
    void setNextLightState();
    void setNextFlashState();
    void setStopState();

private:
    QTimer timer;
    QTimer flash_timer;
    QTimer stop_preamble_timer;

    TWLight m_light_state;
    TWFlash m_flash_state;

    WalkSign * walk_sign;
    TrafficLightButton * traffic_light_button;

    //timer durations for each light status
    const int m_go = 15000;
    const int m_slow = 4000;
    const int m_stop = 7000;
    const int m_stop_preamble = 750;
    const int m_flash = 5000;
    const int m_flash_cycle = 250;
    const int m_flashes_to_do = 13;
    int m_flashes_done = 0;

    void setLightState(TWLight value);
    void setFlashState(TWFlash value);

    explicit TrafficWalk(const TrafficWalk& rhs) = delete;
    TrafficWalk& operator= (const TrafficWalk& rhs) = delete;
};

#endif // TRAFFICWALK_H
