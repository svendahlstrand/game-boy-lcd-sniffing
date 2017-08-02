#include <stdlib.h>
#include <stdio.h>

const char *get_in_file(int argc, char const *argv[]);
const char *get_out_file(int argc, char const *argv[]);

int main(int argc, char const *argv[]) {
  const char* in_file = get_in_file(argc, argv);
  const char* out_file = get_out_file(argc, argv);

  FILE* data = fopen(in_file, "r");
  FILE* image = out_file ? fopen(out_file, "w+") : stdout;

  if (!data) {
    perror("File opening failed");
    return EXIT_FAILURE;
  }

  int c;
  int p = 'A';
  int pixels = 0;

  fputs("P5\n", image);
  fputs("160 144\n", image);
  fputs("255\n", image);

  while ((c = fgetc(data)) != EOF) {
    if (p == '\'' && c >= '0' && c <= '3'){
      pixels++;

      c -= '0';
      c = c ^ 3;

      fputc(c * 85, image);
    }

    p = c;
  }

  fclose(data);

  return EXIT_SUCCESS;
}

const char *get_in_file(int argc, char const *argv[]) {
  switch (argc) {
    case 4:
      return argv[3];
      break;
    case 2:
      return argv[1];
      break;
    default:
      printf("USAGE: %s [-o <file>] <file>\n\n", argv[0]);
      printf("OPTIONS:\n");
      printf("  -o <file>\tWrite to <file> instead of stdout.");
      exit(EXIT_SUCCESS);
  }
}

const char *get_out_file(int argc, char const *argv[]) {
  switch (argc) {
    case 4:
      return argv[2];
      break;
    default:
      return NULL;
  }
}
