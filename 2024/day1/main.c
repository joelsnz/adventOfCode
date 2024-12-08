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

  // open file
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Error al abrir el archivo\n");
    return 1;
  }

  // get number of lines
  fseek(fp, 0, SEEK_END);
  int fpSize = ftell(fp);
  rewind(fp);

  // arrays for left and right lists
  int *leftList = malloc(fpSize * sizeof(int));
  int *rightList = malloc(fpSize * sizeof(int));

  // fill arrays
  for(int i = 0; fscanf(fp, "%d %d", &leftList[i], &rightList[i]) == 2; i++);
  fclose(fp);
  
  qsort(leftList, fpSize, sizeof(int), compare);
  qsort(rightList, fpSize, sizeof(int), compare);
  
  int p1 = 0, p2 = 0, similarity;
  for(int i = 0; i < fpSize; i++) {
    p1 += abs(leftList[i] - rightList[i]);
    similarity = 0;
    for(int j = 0; j < fpSize; j++)
      similarity += leftList[i] == rightList[j];
    p2 += leftList[i] * similarity;
  }
  
  printf("Part 1: %d\n", p1);
  printf("Part 2: %d\n", p2);

  free(leftList);
  free(rightList);
  return 0;
}
