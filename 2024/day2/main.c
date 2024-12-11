#include <stdio.h>

int isSafe(int *report, int maxLvl) {
  int isSafe = 1;
  for (int i = 0; i < maxLvl - 1; i++) {
    int diff = report[i + 1] - report[i];
    isSafe = (report[0] < report[1]) 
              ? diff >= 1 && diff <= 3
              : diff <= -1 && diff >= -3;
    if(!isSafe) break;
  }
  return isSafe;
}

int isSafeDampened(int *report, int maxLvl) {
  if(isSafe(report, maxLvl)) return 1;

  for(int i = 0; i < maxLvl; i++) {
    int temp[maxLvl - 1], k = 0;
    for(int j = 0; j < maxLvl; j++) {
      if(j != i) temp[k++] = report[j];
    }
    if(isSafe(temp, maxLvl - 1)) return 1;
  }
  return 0;
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
  
  char buffer[25];
  int p1 = 0, p2 = 0;
  while(fgets(buffer, sizeof(buffer), fp)) {
    int report[8], maxLvl = 0;
    char *ptr = buffer;
    while(sscanf(ptr, "%d", &report[maxLvl]) == 1) {
      maxLvl++;
      while(*ptr && *ptr != ' ') ptr++;
      while(*ptr == ' ') ptr++;
    }
    p1 += isSafe(report, maxLvl);
    p2 += isSafeDampened(report, maxLvl);
  }
  printf("Part 1 = %d\n", p1);
  printf("Part 2 = %d\n", p2);
  fclose(fp);
  return 0;
}
