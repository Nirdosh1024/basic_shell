#include"../headers/inbuilt.h"

/*
 Function declarations for builtin shell commands
*/
int lsh_cd(char **arg);
int lsh_help(char **arg);
int lsh_exit(char **arg);

/*
list of builtin commands, followed by their corresponding functions
 */
char *builtin_str[] = {
    "cd",
    "help",
    "exit"
};

/** Array of function pointers to built-in shell commands.
 Each function takes a char** (array of strings) as an argument and returns an int.
 This allows dynamic invocation of commands by indexing the array.
*/
int (*builtin_func[]) (char **) = {
    &lsh_cd,
    &lsh_help,
    &lsh_exit
};

int lsh_num_builtins() {
    return sizeof(builtin_str) / sizeof (char *);
}

/*
Builtin function implementations.
*/
int lsh_cd(char **args) {
    printf("%s", args[1]);
    if(args[1] == NULL) {
        fprintf(stderr, "lsh: expected argument \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("lsh");
        }
    }
    return 1;
}

int lsh_help(char **args) {
    int i;
    printf("Nirdosh Chauhan's LSH\n");
    printf("Type program names and arguments, and hit enter.\n");
    printf("The following are built in: \n");

    for(i = 0; i < lsh_num_builtins(); i++) {
        printf(" %s\n", builtin_str[i]);
    }

    printf("Use the man command for information on other programs.\n");
    return 1;
}

int lsh_exit(char **args) {
    return 0;
}

int lsh_execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    // An empty command was entered.
    // args might just contain NULL, if the user entered an empty string, or just whitespace. 
    // So, we need to check for that case at the beginning.
    return 1;
  }

  for (i = 0; i < lsh_num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  return lsh_launch(args);
}
