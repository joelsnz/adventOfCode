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
  
  char line[4096], pattern[] = "mul(";
  char do_[] = "do()", dont[] = "don't()";
  int p1 = 0, p2 = 0, enable = 1;
  while(fgets(line, sizeof(line), fp)) {
    char *ptr = line; 
    
    while(*ptr) {
      if(strncmp(ptr, do_, strlen(do_)) == 0) {
        enable = 1;
        ptr += strlen(do_);
        continue;
      }
      if(strncmp(ptr, dont, strlen(dont)) == 0) {
        enable = 0;
        ptr += strlen(dont);
        continue;
      }
      if(enable && strncmp(ptr, pattern, strlen(pattern)) == 0) {
        int op1, op2;
        char closing;
        if(sscanf(ptr, "mul(%d,%d%c", &op1, &op2, &closing) == 3 && closing == ')') {
          p1 += op1 * op2;
          p2 += op1 * op2 * enable;
        }
        ptr += strlen(pattern);
        continue;
      }
      ptr++;
    }
  }
  printf("%d\n", p1);
  printf("%d\n", p2);
  
  return 0;
}
