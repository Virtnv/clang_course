#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned search(const int* parr, unsigned len, int elem){
  unsigned i;
  for(i = 0; i < len; ++i){
    if(parr[i] == elem)
      return i;
  }
  return len;
}

void swap_(int* a, int* b){
  int t = *a;
  *a = *b;
  *b = t;
}

int main() {
  int res, n, last, i;
  int *parr;

  res = scanf("%d", &n);
  assert(res == 1);
  assert(n > 0);

  parr = calloc(n, sizeof(int));

  for (i = 0; i < n; ++i) {
    res = scanf("%d", parr + i);
    assert(res == 1);
  }

  res = scanf("%d", &last);
  assert(res == 1);
  assert(last < n);
  int fl = 0;
  int s = 0;
  while(1){
    int el = parr[last-1];
    s = last + search(&parr[last], n, (el + fl));
    //printf("%d %d", parr[last - 1] + fl);
    if((s - last) != n){
      swap_(&parr[s], &parr[last]);
      break; 
    }  
    fl++;
  }
  #if 1
  for (i = 0; i < n; ++i)
    printf("%d ", parr[i]);
  free(parr);
  #endif
}
