#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include "syscall.h"

int fchmod(int fd, mode_t mode)
{
	if (__syscall(SYS_fcntl, fd, F_GETFD) < 0)
	  return __syscall_ret(-EBADF);
	char buf[15+3*sizeof(int)];
	__procfdname(buf, fd);
	return syscall(SYS_fchmodat2, AT_FDCWD, buf, mode, 0);
}
