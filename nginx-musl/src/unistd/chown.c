#include <unistd.h>
#include <fcntl.h>
#include "syscall.h"

int chown(const char *path, uid_t uid, gid_t gid)
{
	return syscall(SYS_fchownat, AT_FDCWD, path, uid, gid, 0);
}
