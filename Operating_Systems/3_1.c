#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
int p1,p2;
printf("I am the first process: %d\n",p1=getpid());
pid_t p=fork();

if(p<0){
perror("Failed");
exit(1);
}

if(p==0){
    
    if(getppid()==p1){
    printf("\nMy process ID is: %d\n",p2=getpid());
    printf("My parent process ID is: %d\n",p1);
    }
    p=fork();
    
    if(p<0){
        perror("Failed");
        exit(1);
}

    if(p==0){
                if(getppid()==p2){
		printf("\nMy process ID is: %d\n",getpid());
                printf("My parent process ID is: %d\n",p2);
    
           }}
}


return 0;
}
