#include <stdio.h>
#include <fcntl.h>
#include "syscall.h"

int rename(const char *old, const char *new)
{
	return syscall(SYS_renameat2, AT_FDCWD, old, AT_FDCWD, new, 0);
}
