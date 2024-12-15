#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("day3 <file>\n");
    return 1;
  }

  // open file
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    printf("Failed to open file\n");
    return 1;
  }
  
  char line[1024], pattern[] = "mul(";
  int patternSize = sizeof(pattern);
  long long int p1 = 0;
  while(fgets(line, sizeof(line), fp)) {
    char *ptr = line; 
    while(ptr = strstr(ptr, pattern)) {
      int op1, op2;
      char closing;
      if(sscanf(ptr, "mul(%d,%d%c", &op1, &op2, &closing) == 3 && closing == ')') {
        p1 += op1 * op2;
        printf("mul(%d,%d)\n", op1, op2);
      }
      ptr += patternSize;
    }
  }
  printf("%lld\n", p1);
}
