#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define N_CHILDREN 4
#define SIZE (1 << 16)

int
main(int argc, char *argv[])
{
    int pids[N_CHILDREN];
    int f = forkn(N_CHILDREN, pids);

    if (f == -1) {
        printf("Couldn't create child processes\nExiting...\n");
        exit(-1, 0);
    }
    int sum = 0;
    if (f == 0) {
        int n;
        int statuses[N_CHILDREN];
        waitall(&n, statuses);
        for (int i = 0; i < N_CHILDREN; i++) {
            sum += statuses[i];
        }
        
        printf("Parent sum: %d\n", sum);
        exit(0, 0);
    }
    else {
        for (int i = 0; i < SIZE / N_CHILDREN; i++) {
            int index = (f-1) * (SIZE / N_CHILDREN) + i;
            if (index > SIZE)
                printf("Invalid!!");
            else
                sum += index;
        }
        printf("Child %d sum: %d\n", f, sum);
        exit(sum, 0);
    }
    return 0;
}