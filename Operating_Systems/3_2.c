#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
#include <sys/types.h>


int main(void) {
    int a=fork();
    int b=fork();
    int c=fork();
    
    if (a > 0 && b > 0 && c>0) { //1
		wait(NULL);
		wait(NULL);
		wait(NULL);
        printf("parent\n"); 
        printf("%d %d %d\n", a,b,c); 
        printf(" my id is %d \n", getpid()); 
    } 
    else if (a == 0 && b== 0 && c > 0) 
    { //2
        printf("First child\n"); 
        printf("%d %d %d\n", a, b, c); 
        printf("my id is %d  \n", getpid()); 
    } 
    else if (a == 0 && b> 0 && c == 0) 
    { //3
        printf("Second child\n"); 
        printf("%d %d %d\n", a, b, c); 
        printf("my id is %d  \n", getpid()); 
    } 
    else if (a > 0 && b== 0 && c == 0) 
    { //4
        printf("Third child\n"); 
        printf("%d %d %d\n", a, b, c); 
        printf("my id is %d  \n", getpid()); 
    } 
    else if (a > 0 && b== 0 && c > 0) 
    { //5
        printf("Fourth child\n"); 
        printf("%d %d %d\n", a, b, c); 
        printf("my id is %d  \n", getpid()); 
    } 
    else if (a > 0 && b> 0 && c == 0) 
    { //6
        printf("Fifth child\n"); 
        printf("%d %d %d\n", a, b, c); 
        printf("my id is %d  \n", getpid()); 
    } 
    else if (a > 0 && b== 0 && c > 0) 
    { //7
        printf("Sixth child\n"); 
        printf("%d %d %d\n", a, b, c); 
        printf("my id is %d  \n", getpid()); 
    }
    else  {//8 
        printf("Seventh child\n"); 
        printf("%d %d %d\n", a, b, c); 
        printf(" my id is %d \n", getpid()); 
    } 
    return 0; 
}


