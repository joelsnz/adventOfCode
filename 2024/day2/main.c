#include <stdio.h>

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("day1 <file>\n");
    return 1;
  }

  // open file
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Error al abrir el archivo\n");
    return 1;
  }
  
  char buffer[24];
  while(fgets(buffer, sizeof(buffer), fp)) {
    int num;
    char *ptr = buffer;
    while(sscanf(ptr, "%d", &num) == 1) {
      printf("%d ", num);
      while(*ptr != '\0' && *ptr != ' ') ptr++;
      while(*ptr == ' ') ptr++;
    }
    printf("\n");
  }

  fclose(fp);
  return 0;
}
