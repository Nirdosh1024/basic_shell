LSH
===

LSH is a simple implementation of a shell in C, I have been following this awesome [tutorial](https://brennan.io/2015/01/16/write-a-shell-in-c/) by Stephen Brennen in order to learn the basics of system programming.


Headers Used
   1. #include<sys/wait.h>
    // waitpid() and associated macros
   2. #include<unistd.h>
    // chdir(), fork(), exec(), pid_t
   3. #include<stdlib.h>
    // malloc(), realloc(), free(), exit(), execvp(), EXIT_FAILURE, EXIT_SUCCESS
   4. #include<stdio.h>
    // printf(), fprintf(), stderr, getchar(), perror()
   5. #include<string.h>
    // strcmp, strtok

It demonstrates the basics of how a shell works.
That is: read, parse, fork, exec, and wait.  Since its purpose is demonstration
(not feature completeness or even fitness for casual use), it has many
limitations, including:

* Commands must be on a single line.
* Arguments must be separated by whitespace.
* No quoting arguments or escaping whitespace.
* No piping or redirection.
* Only builtins are: `cd`, `help`, `exit`.

Running
-------

Use `gcc -o lsh src/main.c` to compile, and then `./lsh` to run.