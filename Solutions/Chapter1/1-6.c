#include <stdio.h>

int main(void)
{
  printf("Press ENTER\n");
  printf("getchar() != EOF evaluates to %d\n", getchar() != EOF);
  return 0;
}
