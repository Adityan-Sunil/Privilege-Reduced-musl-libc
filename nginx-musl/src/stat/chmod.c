#include <sys/stat.h>
#include <fcntl.h>
#include "syscall.h"

int chmod(const char *path, mode_t mode)
{
	return syscall(SYS_fchmodat2, AT_FDCWD, path, mode, 0);
}
