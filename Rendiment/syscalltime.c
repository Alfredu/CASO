#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/wait.h>



#define ITERATIONS 100000

int main() {
    int res;
    struct timeval timeOld;
    time_t now;
    struct timeval timeNew;
    char tmbuf[64];


    int i=0;
    gettimeofday(&timeOld,0);
    while(i<ITERATIONS) {
        // sbrk(0x7FFFFFFFFFFFFFFF);
        int pid = fork();
        if(pid==0) exit(0);
        else waitpid(pid, 0, 0);
        i++;
    }
    gettimeofday(&timeNew,0);

    float timeSpent = ((timeNew.tv_sec * 1000000) + timeNew.tv_usec) - ((timeOld.tv_sec * 1000000) + timeOld.tv_usec);
    printf("Total time: %f microseconds\n", timeSpent);
    timeSpent = timeSpent/(float)ITERATIONS;
    printf("Time for each iteration: %f microseconds\n", timeSpent);

    return 0;
}