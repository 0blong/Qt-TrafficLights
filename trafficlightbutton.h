#ifndef TRAFFICLIGHTBUTTON_H
#define TRAFFICLIGHTBUTTON_H

#include <QObject>
#include <QTimer>

class TrafficLightButton : public QObject
{
    Q_OBJECT
    Q_PROPERTY(EButton buttonState READ getButtonState WRITE setButtonState NOTIFY buttonStateChanged)

public:
    explicit TrafficLightButton(QObject *parent = 0);

    enum EButton {
        PUSH,
        WAIT,
        CROSS,
        OFF
    };
    Q_ENUMS(EButton)

    EButton getButtonState() const { return m_button_state; }
    void setButtonState(EButton newButtonState);

    void push();
    void wait();
    void cross();
    void off();

    QString getButtonStateString();

signals:
    buttonStateChanged();

private:
    EButton m_button_state;


    explicit TrafficLightButton(const TrafficLightButton& rhs) = delete;
    TrafficLightButton& operator= (const TrafficLightButton& rhs) = delete;
};

#endif // TRAFFICLIGHTBUTTON_H
