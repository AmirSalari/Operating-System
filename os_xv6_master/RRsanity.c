#include "user.h"
#define CHILD_NUMBER 10
#define N  1000

void
printing(int number)
{
    int i;
    for (i = 0; i < N; ++i) {
        printf(1, "Child %d prints for the %d time.\n", number, i);
    }

}

void
RRsanity(void)
{

    int wTime[CHILD_NUMBER];
    int rTime[CHILD_NUMBER];
    int pid[CHILD_NUMBER];

    int i;
    for (i = 0; i < CHILD_NUMBER; i++) {
        pid[i] = fork();
        if(pid[i] == 0){
            printing(i);
            exit();
        }
    }

    int j;
    for (j = 0; j < CHILD_NUMBER; ++j) {
        wait2(&wTime[j], &rTime[j]);
    }

    int k;
    for (k = 0; k < CHILD_NUMBER; ++k) {
        printf(1, "Wtime of %d child is %d\n", k, wTime[k]);
        printf(1, "Rtime of %d child is %d\n", k, rTime[k]);
        printf(1, "turn around time of %d child is %d\n", k, (wTime[k] + rTime[k]));
    }

}
int
main(void)
{
    RRsanity();
    exit();
}
