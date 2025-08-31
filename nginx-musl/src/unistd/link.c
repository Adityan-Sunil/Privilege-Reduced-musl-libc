#include <unistd.h>
#include <fcntl.h>
#include "syscall.h"

int link(const char *existing, const char *new)
{
	return syscall(SYS_linkat, AT_FDCWD, existing, AT_FDCWD, new, 0);
}
