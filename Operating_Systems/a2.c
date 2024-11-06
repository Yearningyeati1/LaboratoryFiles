#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#define BUFFER_SIZE 1024

void parent_process(int write_fd, int read_fd);
void child_process(int write_fd, int read_fd);

int main() {
    int pipe1[2]; 
    int pipe2[2]; 

    if (pipe(pipe1) == -1) {
        perror("pipe1");
        exit(EXIT_FAILURE);
    }
    if (pipe(pipe2) == -1) {
        perror("pipe2");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { 
        close(pipe1[1]); 
        close(pipe2[0]);
        child_process(pipe2[1], pipe1[0]);
        close(pipe1[0]); 
        close(pipe2[1]); 
    } else { 
        close(pipe1[0]); 
        close(pipe2[1]); 
        parent_process(pipe1[1], pipe2[0]);
        close(pipe1[1]); 
        close(pipe2[0]); 
        wait(NULL); 
    }

    return 0;
}

void parent_process(int write_fd, int read_fd) {
    char buffer[BUFFER_SIZE];
    while (1) {
        printf("Parent: ");
        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }
        buffer[strcspn(buffer, "\n")] = '\0'; 

        write(write_fd, buffer, strlen(buffer) + 1); 

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        ssize_t bytesRead = read(read_fd, buffer, BUFFER_SIZE);
        if (bytesRead <= 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        buffer[bytesRead] = '\0'; 
        printf("Child Sent: %s\n", buffer);

        if (strcmp(buffer, "exit") == 0) {
            break;
        }
    }
}

void child_process(int write_fd, int read_fd) {
    char buffer[BUFFER_SIZE];
    while (1) {
        ssize_t bytesRead = read(read_fd, buffer, BUFFER_SIZE);
        if (bytesRead <= 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        buffer[bytesRead] = '\0'; 
        printf("Parent Sent: %s\n", buffer);

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        printf("Child: ");
        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }
        buffer[strcspn(buffer, "\n")] = '\0';
        write(write_fd, buffer, strlen(buffer) + 1);
        if (strcmp(buffer, "exit") == 0) {
            break;
        }
    }
}