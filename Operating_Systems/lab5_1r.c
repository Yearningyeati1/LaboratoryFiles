
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
//second
    res=mkfifo("fifo2",0777);
    if(res==0) printf("named pipe created successfully!\n");
//open
    int n,fd,fd2;
    fd=open("fifo1",O_RDONLY);
    fd2=open("fifo2",O_WRONLY);
    while(1){
    n=read(fd,buffer,50);
    if(n) printf("%s",buffer);
    if(strcmp(buffer,"exit")==0)break;
    
//
    fgets(buffer, 50, stdin);
    n=write(fd2,buffer,strlen(buffer));
    return 0;
}
}
