#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char inp[1024] = {0};
  unsigned count = 0;
  unsigned i = 0;
  int res;
  while((res = scanf("%c", &inp[i])) == 1)
  {
     count += inp[i];
     i++; 
  }
  
  #if 0
  for(int i = 0; i < 1024; i++)
  {
    if(inp[i] == '\0')break;
    printf("%d ", inp[i]);
  }
  #endif

  printf("%d", count+10);
}
