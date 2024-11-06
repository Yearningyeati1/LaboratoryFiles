#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(){
    int res;
    char buffer[50];
//first file
    res=mkfifo("fifo1",0777);
    if(res==0) printf("named pipe created successfully!\n");
int a=fork();
int b=fork();
//opening
if(a>0 && b>0){
    int n,fd;
    fd=open("fifo1",O_RDONLY|O_NONBLOCK);
    while(1){
    n=read(fd,buffer,50);
    if(n) printf("%s",buffer);
    }

}

else if(a==0 && b>0){
    int n,fd;
    fd=open("fifo1",O_WRONLY);
    n=write(fd,"FIRST\n",6);
   
    }
else if(a>0 && b==0){
    int n,fd;
    fd=open("fifo1",O_WRONLY);
    n=write(fd,"SECOND\n",7);
  
    }
else if(a==0 && b==0){
    int n,fd;
    fd=open("fifo1",O_WRONLY);
    n=write(fd,"THIRD\n",8);    
    }


    return 0;
}
