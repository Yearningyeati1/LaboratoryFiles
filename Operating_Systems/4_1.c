#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main()
{
	FILE *rd;
	char buffer[50];
	rd=popen("./input","r"); //pipe opened in reading mode
	int i=fread(buffer, 1, 40, rd); //will read only 50 characters
	buffer[i]='\n';
	write(1,buffer,i+1);
	pclose(rd);
}
