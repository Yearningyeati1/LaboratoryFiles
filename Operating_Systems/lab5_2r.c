
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(){
    int res;
    char buffer[50];
//first
    res=mkfifo("fifo1",0777);
    if(res==0) printf("named pipe created successfully!\n");
//open
    int n,fd;
    fd=open("fifo1",O_RDONLY);
    while(1){
    n=read(fd,buffer,50);
    if(n) printf("%s",buffer);
    }
return 0;
}
