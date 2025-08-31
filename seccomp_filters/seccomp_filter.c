#include <seccomp.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define REDIS_CMD "/usr/local/redis-new/bin/redis-server"
#define NGINX_CMD "/usr/local/nginx-new/sbin/nginx"

int main(int argc, char *argv[])
{
    scmp_filter_ctx ctx = seccomp_init(SCMP_ACT_KILL); // default rule to stop all system calls by default
    seccomp_arch_add(ctx, SCMP_ARCH_X86);              // apply rules on _86 arch system calls
    if (strcmp(argv[1], "redis") == 0)
    { // load the rules based on the application being executed
#include "redis_filter.inc"
    }
    else
    {
#include "nginx_filter.inc"
    }
  //  seccomp_export_bpf(ctx, 1); // print human readable format of the rules
//    seccomp_export_pfc(ctx, 2);
    seccomp_load(ctx);          // load the ruleset
    if (strcmp(argv[1], "redis") == 0)
    { // invoke the application
        execl(REDIS_CMD, 0);
    }
    else
    {
        execl(NGINX_CMD, 0);
    }
    seccomp_release(ctx);
    return 0;
}
