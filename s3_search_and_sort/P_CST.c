#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max_el(const int* parr, int n){
  int max = parr[0];
  if(n == 1)return max;
  for(const int* pi = &parr[1]; pi != &parr[n]; pi++)
    if(max < *pi)max = *pi;
  return max;
}

void bucket_sort(int* parr, int n, int* buckets){
  for(int* pi = &parr[0]; pi != &parr[n]; pi++)
    buckets[*pi] += 1;
}

int main() {
  int res, n, i;
  int *parr;

  res = scanf("%d", &n);
  assert(res == 1);
  assert(n > 0);

  parr = calloc(n, sizeof(int));

  for (i = 0; i < n; ++i) {
    res = scanf("%d", parr + i);
    assert(res == 1);
  }
  int bs = max_el(parr, n);
  
  int* buckets = calloc(bs+1, sizeof(int));
  bucket_sort(parr, n, buckets);
  n = bs + 1; 
  parr = buckets;
  for (i = 0; i < n; ++i)
    printf("%d ", parr[i]);
  free(parr);
}
