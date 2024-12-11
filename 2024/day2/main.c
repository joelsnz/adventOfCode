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
  
  char buffer[25];
  int result = 0;
  while(fgets(buffer, sizeof(buffer), fp)) {
    int report[8], maxLvl = 0;
    char *ptr = buffer;
    while(sscanf(ptr, "%d", &report[maxLvl]) == 1) {
      maxLvl++;
      while(*ptr && *ptr != ' ') ptr++;
      while(*ptr == ' ') ptr++;
    }
    int ascendent = (report[0] < report[1]);
    int isSafe = 1;
    for (int i = 0; i < maxLvl - 1; i++) {
      int diff = report[i + 1] - report[i];
      if(ascendent) {
        isSafe = diff >= 1 && diff <= 3;
      } else {
        isSafe = diff <= -1 && diff >= -3;
      }
        
      if(!isSafe) break;
    }
    result += isSafe;
  }
  printf("result = %d\n", result);
  fclose(fp);
  return 0;
}
