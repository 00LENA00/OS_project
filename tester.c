
#include "types.h"
#include "user.h"

int set_priority(int pid, int priority);
int number_of_processes = 10;

int main(int argc, char *argv[])
{
  int j;
  for (j = 0; j < number_of_processes; j++)
  {
    int pid = fork();
    if (pid < 0)
    {
      printf(1, "Fork failed\n");
      continue;
    }
    if (pid == 0)
    {
      volatile int i;
      for (volatile int k = 0; k < number_of_processes; k++)
      {
        if (k <= j)
        { 
          sleep(200); //io time
        }
        else
        {
          for (i = 0; i < 100000000; i++)
          {
            ; //cpu time
          }
        }
      }
      printf(1, "Process: PID %d :%d Finished\n", getpid(),j);
      exit();
    }
    
  }
  for (j = 0; j < number_of_processes+5; j++)
  {
    wait();
  }
  exit();
}