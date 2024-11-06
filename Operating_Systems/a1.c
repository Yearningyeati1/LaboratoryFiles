#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
    FILE *rd;
    char buff[100];
    rd = popen("./input","r");
    while (fgets(buff, sizeof(buff), rd) != NULL) {
        printf("%s", buff);
    }
    pclose(rd);
}