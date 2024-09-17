#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int iabs(int x){return (x < 0) ? -x : x;}

int eu_mod(int x, int y){
  int r = x % y;
  if(r < 0)r += iabs(y);
  return r;
}

int gcd(long long a,long long b, long long* s, long long* t){
  assert(b != 0);
  assert(a != 0 && b != 0);
#if 0
  long long k = 1;
  if(a < 0 && b < 0){
    k = -1;
  }
#endif
  long long q = 0, ao = a, bo = b;
  long long rn = 1;
  long long s0 = 1, s1 = 0, sn = 1;
  long long t0 = 0, t1 = 1, tn = 1;
  long long tmp;
  while(b){
    q = a / b;
    rn = a - (q * b);
    sn = s0 - (q * s1);
    tn = t0 - (q * t1);
    s0 = s1; s1 = sn;
    t0 = t1; t1 = tn;
    a = b;
    tmp = b;
    b = rn;
  }
#if 0
  while(1){
    if(tmp == s0 * ao + t0 * bo)
      break;
  tmp *= -1; s0 *= -1; t0 *= -1;
  }
#endif
  *s = s0;
  *t = t0;
  if(tmp < 0 && (ao < 0 || bo < 0)){
    tmp *= -1; *s *= -1; *t *= -1;
  }
  return tmp;
}

int main(){
  long long a, b, s, t;
  int res;
  res = scanf("%lld%lld", &a, &b);
  if(res != 2){
    printf("Wrong input!");
    abort();
  }
  res = gcd(a, b, &s, &t);
  printf("%lld %lld %d", s, t, res);
}
