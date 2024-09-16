#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int iabs(int x) { return (x < 0) ? -x : x; }

int eu_mod(int x, int y) {
  int r = x % y;
  if (r < 0) r += iabs(y);
  return r;
}
unsigned long long gcd(unsigned long long x, 
                       unsigned long long y) {
  unsigned long long q = 1;
  while(q){
    q = eu_mod(x, y);
    if(q == 0)return y;
    x = y;
    y = q;
  }
  return y;
}

int main() {
  unsigned long long x = 0, y = 0, g;
  int res;

  res = scanf("%llu %llu", &x, &y);
  assert(res == 2);
  g = gcd(x, y);
  printf("%llu\n", g);
  return 0;
}
