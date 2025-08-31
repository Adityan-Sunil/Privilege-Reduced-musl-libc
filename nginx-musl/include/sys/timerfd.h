#ifndef _SYS_TIMERFD_H
#define _SYS_TIMERFD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>
#include <fcntl.h>

#define TFD_NONBLOCK O_NONBLOCK
#define TFD_CLOEXEC O_CLOEXEC

#define TFD_TIMER_ABSTIME 1
#define TFD_TIMER_CANCEL_ON_SET (1 << 1)

struct itimerspec;

#if _REDIR_TIME64
__REDIR(timerfd_settime, __timerfd_settime64);
__REDIR(timerfd_gettime, __timerfd_gettime64);
#endif

#ifdef __cplusplus
}
#endif

#endif
