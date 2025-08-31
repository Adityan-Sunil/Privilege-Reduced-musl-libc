 #include <sys/stat.h>
 #include <fcntl.h>
 #include "syscall.h"

int mknod(const char *path, mode_t mode, dev_t dev)
{
	return syscall(SYS_mknodat, AT_FDCWD, path, mode, dev);
}
