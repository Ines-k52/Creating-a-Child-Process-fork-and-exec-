#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        execl("./get_ancestors", "get_ancestors", NULL);
        perror("execl failed");
        exit(1);
    } else {
        int status;
    wait(&status);
    printf("Parent and child finished\n");
    }

    return 0;
}
