#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t ret = fork();
    if(ret < 0)
    {
        return -1;
    }
    else if(ret == 0)
    {
        //child
        printf("child %d, father %d\n", getpid(), getppid());
        while(1)
        {
            sleep(1);
        
        }
    }
    else
    {
        printf("father %d, %d\n", getpid(), getppid());
        while(1)
        {
            sleep(1);
        }
    }
    return 0;
}