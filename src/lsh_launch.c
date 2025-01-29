#include"../headers/lsh_launch.h"

int lsh_launch(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if(pid == 0) {
        // child process
        if(execvp(args[0], args) == -1) {
            perror("lsh");
        }
        exit(EXIT_FAILURE);
    } else if(pid < 0 ) {
        // Error forking
        perror("lsh");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}


/** some theory
    so fork will return 
    1. 0 to the child process
    2. pid of child process to the parent process

    Now, fork creates a duplicate of the process we need to distinguish 
    for which process we need to do what, here we'll identify if the process if 
    child and parent by pid

    if pid == 0 -> child
    if pid > 0 -> 0 parent

    if child -> execute the command
    if parent -> wait for the child to finish

    for exec command -> read exec documentation and it's variants
    for waitpid -> read its documentation

 */