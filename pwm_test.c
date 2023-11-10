#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>


#define DEVFILE "/dev/char-pwm-0"

extern void pwm_plus_duty(int* fd,int* pwm_duty);
extern void pwm_minus_duty(int* fd,int* pwm_duty);

//add a message to remote 1  
//add a message to remote 2 
//add a message to remote 3 in github
//add a message to remote 3 in local
//add a message to remote 4 in github
//add a message to remote 4 in local
//add a message to remote 5 in github
//add a message to remote 5 in local
//add a message to remote 6 in github
//add a message to remote 6 in local
//add a message to remote 7 in github


int main(int argc, char *argv[])
{
    int fd;
    int pwm_duty = 1000;

     
   

    fd = open(DEVFILE, O_RDWR);
    if (fd == -1) {
        perror("open");       
    }   
   
    while(1)   
    {
        while(pwm_duty <= 10000)
        {
            pwm_plus_duty(&fd,&pwm_duty);  
            //write(fd, &pwm_duty, sizeof(u_int32_t));   
            //pwm_duty+=10;               
            printf("pwm duty plus set to = 0x%x\n", pwm_duty); 
        }         

        while(pwm_duty >= 0)
        {
            pwm_minus_duty(&fd,&pwm_duty); 
            //write(fd, &pwm_duty, sizeof(u_int32_t));   
            //pwm_duty-=10;
            printf("pwm duty minus set to = 0x%x\n", pwm_duty);  
        }  

    }  

    
    
   if (close(fd) != 0) {
        perror("close");
    }



}
