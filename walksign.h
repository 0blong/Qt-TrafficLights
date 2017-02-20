#ifndef WALKSIGN_H
#define WALKSIGN_H

#include <QObject>
#include <QTimer>

class WalkSign : public QObject
{
    Q_OBJECT
    Q_PROPERTY(EWalk walkState READ getWalkState WRITE setWalkState NOTIFY walkStateChanged)

public:
    explicit WalkSign(QObject *parent = 0);

    enum EWalk {
        WALK,
        FLASHON,
        FLASHOFF,
        DONTWALK
    };
    Q_ENUMS(EWalk)

    EWalk getWalkState() const { return m_walk_state; }
    void setWalkState(EWalk newWalkState);

    void startWalking();
    void stopWalking();
    void flashOn();
    void flashOff();
    QString getWalkStateString();

signals:
    walkStateChanged();

private:
    EWalk m_walk_state;


    explicit WalkSign(const WalkSign& rhs) = delete;
    WalkSign& operator= (const WalkSign& rhs) = delete;
};

#endif // WALKSIGN_H
