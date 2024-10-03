#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


int* prod(int* a, int* b, int m){
  int* c = calloc(4, sizeof(int));
  c[0] = (a[0] * b[0] + a[1] * b[2]) % m;
  c[1] = (a[0] * b[1] + a[1] * b[3]) % m;
  c[2] = (a[2] * b[0] + a[3] * b[2]) % m;
  c[3] = (a[2] * b[1] + a[3] * b[3]) % m;
  return c;
}

int* pow_(int* a, int p, int m){
  if(p == 0){
    int *ax = calloc(4, sizeof(int));
    ax[0] = 1;
    ax[1] = 0;
    ax[2] = 0;
    ax[3] = 1;
    return ax;
  }
  if(p % 2 == 0){
    p = p / 2;
    int *a2 = pow_(a, p, m); 
    return (prod(a2, a2, m));
  }
  if(p % 2 != 0){
    p = p - 1;
    int* a1 = pow_(a, p, m);
    return (prod(a, a1, m));
  }
  return 0;
}

int main() {
  int res, p;
  int m;
  int ma[4] = {0};
  int mb[4] = {0};
  int mc[4] = {0};
  
  for(int i = 0; i < 4; ++i){
    res = scanf("%d", &ma[i]);
    if(res != 1){
      printf("%s", "Wrong input!");
      abort();
    }
  }
  res = scanf("%d%d", &p, &m);
  if(res != 2){
    printf("%s", "Wrong input!");
    abort(); 
  }
  int *po;
  int* pc = pow_(ma, p ,m);
  po = pc;
  for(int i = 0; i < 4; ++i)
    printf("%d ", pc[i]);
  free(po);
}
