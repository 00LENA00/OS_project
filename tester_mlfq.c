
#include "types.h"
#include "user.h"


int number_of_processes = 5;
int a=0;
int b=1;
int c;
int main(int argc, char *argv[])
{

    int j;
    for (j = 0; j < number_of_processes; j++) {
        int pid = fork();
        if (pid < 0) {
            printf(1, "Fork failed\n");
            continue;
        }
        if (pid == 0) {
            volatile int i;
            for (volatile int k = 0; k < number_of_processes; k++) {
                if (k <= j) {
                    sleep(120); //io time
                } else {
                    for (i = 0; i < 100000000; i++) {
                        ; //cpu time
                     
                    }
                    getps();
                }
            }
            
            printf(1, "Process: PID %d :%d Finished\n", getpid(), j);
            //yield();
            getps();

  exit();
}
    }
    for (j = 0; j < number_of_processes; j++) {
        wait();
    }
    getps();
    exit();
}
