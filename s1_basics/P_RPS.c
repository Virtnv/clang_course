#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int pow_(int a, int p, int m){
  if(p == 0)return 1;
  if(p % 2 == 0){
    p = p / 2;
    return (pow_(a, p, m) % m) * (pow_(a, p, m) % m);
  }
  if(p % 2 != 0){
    p = p - 1;
    return (a % m) * (pow_(a, p, m) % m);
  }
  return 0;
}

int spow(int a, int p, int m){
  int p1;
  if(p == 1)return a;
  if(p >= 2)
    p1 = p - 2;
  int b = a;
  int n = 1000000;
  while(p1){
    b = pow_(a, b, n);
    p1--;
  }
  return (pow_(a, b, m)) % m;
}

int main(){
  int res;
  int a, b, n;
  res = scanf("%u%u%u", &a, &b, &n);
  if(res != 3){
    printf("%s", "Wrong input!");
    abort();
  }
  printf("%d", (spow(a, b, n) % n));
}


