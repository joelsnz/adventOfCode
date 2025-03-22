#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("day3 <file>\n");
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Failed to open file\n");
    return 1;
  }
  
  char line[4096], find[] = "mul(";
  char doFind[] = "do()", dontFind[] = "don't()";
  int p1 = 0, p2 = 0, enable = 1;
  while(fgets(line, sizeof(line), fp)) {
    char *mulp = line;
  }
  printf("%d\n", p1);
  printf("%d\n", p2);
  
  return 0;
}
