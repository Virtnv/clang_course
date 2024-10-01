#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


int is_prime(const int a){
    if(a < 2)return 0;
    assert(a > 0);
    for(int j = 2; j * j <= a; ++j)
      if(a % j == 0)return 0;
    return 1;
}

int n_prime(const int n){
  int idx = 2;
  int count = 0;
  while(n != count){
    
    if(is_prime(idx))count++;
    idx++;
  }
  return idx - 1;
}

int main(){
  int n, res;
  res = scanf("%d", &n);
  if(res != 1){
    printf("%s", "Wrong input");
    abort();
  }
  printf("%d", n_prime(n));
}
