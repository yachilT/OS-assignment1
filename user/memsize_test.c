#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"


int
main(int argc, char **argv) 
{
    printf("# Bytes of memory: %d\n", memsize());

    void* new_mem = malloc(20000);
    printf("# Bytes of memory after malloc: %d\n", memsize());

    free(new_mem);
    printf("# Bytes of memory after freeing: %d\n", memsize());
    return 0;
}