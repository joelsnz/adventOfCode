#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("day1 <file>\n");
    return 1;
  }
  
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Error al abrir el archivo\n");
    return 1;
  }

  fseek(fp, 0, SEEK_END);
  int fpSize = ftell(fp);
  rewind(fp);

  int *leftList = malloc(fpSize * sizeof(int));
  int *rightList = malloc(fpSize * sizeof(int));

  int i = 0;
  while(fscanf(fp, "%d %d", &leftList[i], &rightList[i]) == 2) {
    printf("%d - %d\n", leftList[i], rightList[i]);
    i++;
  }

  free(leftList);
  free(rightList);
  fclose(fp);
  return 0;
}
