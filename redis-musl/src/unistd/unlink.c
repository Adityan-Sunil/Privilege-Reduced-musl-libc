#include <unistd.h>
#include <fcntl.h>
#include "syscall.h"

int unlink(const char *path)
{
	return syscall(SYS_unlinkat, AT_FDCWD, path, 0);
}
