#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(){
    int res;
    char buffer[50];
//first file
    res=mkfifo("fifo1",0777);
    if(res==0) printf("named pipe created successfully!\n");
//second
    res=mkfifo("fifo2",0777);
    if(res==0) printf("named pipe created successfully!\n");
//opening
    int n,fd,fd2;
    fd=open("fifo1",O_WRONLY);
    fd2=open("fifo2",O_RDONLY);  
    while(1){
    fgets(buffer, 50, stdin);
    n=write(fd,buffer,strlen(buffer));
    //
    n=read(fd2,buffer,50);
    if(n) printf("%s",buffer);
    
    }
    return 0;
}
