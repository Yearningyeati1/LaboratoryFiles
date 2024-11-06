
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

void pnum(){
for(int i=1;i<10;i++){
printf("P1::%d\n",i);
sleep(1);
}
exit(1);
}

void palpha(){
char a='A';
for(int i=0;i<26;i++){
printf("P2::%c\n",a++);
sleep(1);
}
exit(1);
}

int main(){

pid_t pid1,pid2;

pid1=fork();
if(pid1==0){
palpha();}

pid2=fork();
if(pid2==0){
pnum();}


waitpid(pid1,0,0);
waitpid(pid2,0,0);



return 0;
}

