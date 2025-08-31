#include <unistd.h>
#include <fcntl.h>
#include "syscall.h"

 int access(const char *filename, int amode)
 {
 	return syscall(SYS_faccessat2, AT_FDCWD, filename, amode, 0);
 }
