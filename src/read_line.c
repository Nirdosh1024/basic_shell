#include"../headers/read_line.h"

#define LSH_READ_LINE_BUFSIZE 1024

char *lsh_read_line(void) {
  int buf_size = LSH_READ_LINE_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * buf_size);
  int c;

  if(!buffer) {
    fprintf(stderr, "lsh allocation error\n");
    exit(EXIT_FAILURE);
  }

  while (1) {
    // Read a character
    c = getchar();

    if(c == EOF || c == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;

    if(position >= buf_size) {
      buf_size += LSH_READ_LINE_BUFSIZE;
      buffer = realloc(buffer, buf_size);
      if(!buffer) {
        fprintf(stderr, "lsh allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}
