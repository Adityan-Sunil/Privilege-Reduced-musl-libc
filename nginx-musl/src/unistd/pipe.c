 #include <unistd.h>
 #include "syscall.h"

 int pipe(int fd[2])
 {
 	return syscall(SYS_pipe2, fd, 0);
 }
