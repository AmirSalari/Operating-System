#include "user.h"
#define N  50

void
printing()
{
    int i;
    for (i = 0; i < N; ++i) {
        printf(1, "process %d is printing for the %d time.\n", getpid(), i);
    }

}

void
Gsanity(void)
{

    int pid;


    printf(1, "parent pid is %d", getpid());
    sleep(10);
    pid = fork();
    if(pid == 0){
        printing();
        exit();
    }


    printing();

}
int
main(void)
{
    Gsanity();
    exit();
}
