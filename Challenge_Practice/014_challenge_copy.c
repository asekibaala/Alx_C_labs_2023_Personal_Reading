#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
    char *input;
    while(1) {
        printf("myshel> ");
        fflush(stdout);

        input = (char *)getline(NULL, 0, stdin);
        if (input == NULL) {
            break;
        }
        pid_t child_pid = fork();
        if (child_pid == 0) {
            char *const argv[] = {input, NULL};
            execve(input, argv, NULL);
            perror("execve");
            exit(1);
        }
        int status;
        wait(&status);
    }
    return 0;
}