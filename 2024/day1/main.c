#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b) {
      return (*(int*)a - *(int*)b);
}

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

  for(int i = 0; fscanf(fp, "%d %d", &leftList[i], &rightList[i]) == 2; i++);
  fclose(fp);
  
  qsort(leftList, fpSize, sizeof(int), compare);
  qsort(rightList, fpSize, sizeof(int), compare);
  
  int result = 0;
  for(int i = 0; i < fpSize; i++) {
    result += abs(leftList[i] - rightList[i]);
  }
  
  printf("Result: %d\n", result);

  free(leftList);
  free(rightList);
  return 0;
}
