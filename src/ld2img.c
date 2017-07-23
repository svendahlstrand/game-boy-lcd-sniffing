#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <file> ...", argv[0]);
    exit(0);
  }

  FILE* data = fopen(argv[1], "r");

  if (!data) {
    perror("File opening failed");
    return EXIT_FAILURE;
  }

  int c;
  int p = 'A';
  int pixels = 0;

  puts("P2");
  puts("160 144");
  puts("3");

  while ((c = fgetc(data)) != EOF) {
    if (p == '\'' && c >= '0' && c <= '3'){
      pixels++;

      switch (c) {
        case '0':
          c = '3';
          break;
        case '1':
          c = '2';
          break;
        case '2':
          c = '1';
          break;
        case '3':
          c = '0';
          break;
      }

      putchar(c);

      if (pixels % 160 == 0) {
        putchar('\n');
      }
      else {
        putchar(' ');
      }
    }

    p = c;

  }

  fclose(data);

  return 0;
}
