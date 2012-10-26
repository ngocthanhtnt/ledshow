#include "mmtimer.h"
#include <MMSystem.h>
#include <mainwindow.h>
#ifdef __MINGW32__ //w32api bug
#define TIME_KILL_SYNCHRONOUS 0x0100
#endif

/*
timeSetEvent 和 timeKillEvent 可直接查阅 MSDN
另外，MinGW的win32api包，对TIME_KILL_SYNCHRONOUS没有定义，代码中做了一点修正
请确保正确链接所需要的库

LIBS += -lwinmm注意：MSDN 对timeSetEvent的介绍中这么说的(对此不做评论)

Note  This function is obsolete. New applications should use CreateTimerQueueTimer to create a timer-queue timer
*/

void WINAPI CALLBACK mmtimer_proc(uint timerId, uint, DWORD_PTR user, DWORD_PTR, DWORD_PTR)
{
    MMTimer *t = reinterpret_cast<MMTimer*>(user);
    emit t->timeout();

    //w->previewProc();
}

MMTimer::MMTimer(int interval, QObject *parent) :
    QObject(parent),m_interval(interval),m_id(0)
{

}

MMTimer::~MMTimer()
{
    stop();
}

void MMTimer::start()
{
    m_id = timeSetEvent(m_interval, 1, mmtimer_proc, (DWORD_PTR)this,
                 TIME_CALLBACK_FUNCTION | TIME_PERIODIC | TIME_KILL_SYNCHRONOUS);

}

void MMTimer::stop()
{
    if (m_id){
        timeKillEvent(m_id);
        m_id = 0;
    }
}
