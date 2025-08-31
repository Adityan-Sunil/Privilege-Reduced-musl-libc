#include <unistd.h>
#include "syscall.h"
#include <fcntl.h>

int execve(const char *path, char *const argv[], char *const envp[])
{
	/* do we need to use environ if envp is null? */
	return syscall(SYS_execveat, AT_FDCWD, path, argv, envp, 0);
}
