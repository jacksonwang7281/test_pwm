#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>


void pwm_plus_duty(int* fd,int* pwm_duty)
{

    write(*fd, pwm_duty, sizeof(u_int32_t));   
    *pwm_duty+=10;
      

}