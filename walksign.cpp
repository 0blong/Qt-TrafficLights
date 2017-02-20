#include "walksign.h"
#include "outputmessage.h"

WalkSign::WalkSign(QObject *parent) :
    QObject(parent),
    m_walk_state(EWalk::DONTWALK)
{
    setWalkState(m_walk_state);
}

QString WalkSign::getWalkStateString()
{
    return  (m_walk_state == EWalk::DONTWALK ? "DONTWALK" :
            (m_walk_state == EWalk::WALK ? "WALK" :
            (m_walk_state == EWalk::FLASHON ? "FLASHON" : "FLASHOFF")));
}

void WalkSign::setWalkState(EWalk value)
{
    m_walk_state = value;
    emit walkStateChanged();
}

//incoming messages from traffic light
void WalkSign::startWalking()
{
    setWalkState(EWalk::WALK);
}

void WalkSign::stopWalking()
{
    setWalkState(EWalk::DONTWALK);
}

void WalkSign::flashOn()
{
    setWalkState(EWalk::FLASHON);
}

void WalkSign::flashOff()
{
    setWalkState(EWalk::FLASHOFF);
}
