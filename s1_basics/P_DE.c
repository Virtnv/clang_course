#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int abs(int n){
  if(n < 0)return n *= (-1);
  return n;
}

int gcd2(int a, int b, int* s, int* t){
  assert(b != 0);
  assert(a != 0 && b != 0);
  int q = 0, ao = a, bo = b;
  int rn = 1;
  int s0 = 1, s1 = 0, sn = 1;
  int t0 = 0, t1 = 1, tn = 1;
  int tmp;
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
  *s = s0;
  *t = t0;
  if(tmp < 0 && (ao < 0 || bo < 0)){
    tmp *= -1; *s *= -1; *t *= -1;
  }
  return tmp;
}

int gcd(int a, int b, int *x, int *y){
  if(a==0){
    *x = 0, *y = 1;
    return b;
  }
  int x1, y1;
  int d = gcd(b%a, a, &x1, &y1);
  *x = y1 - (b / a) * (x1);
  *y = x1;
  return d;
}
 
int any_sol(int a, int b, int c, int *x0, int *y0, int *g){
  *g = gcd2(abs(a), abs(b), x0, y0);
  if(c % *g != 0)
    return 1;
  *x0 *= c / *g;
  *y0 *= c / *g;
#if 1
  if(a < 0) *x0 *= -1;
  if(b < 0) *y0 *= -1;
#endif 
  return 0;

}

int read_input(int *pa, int* pb, int* pc){
  int res;
  res = scanf("%d%d%d", pa, pb, pc);
  if(res != 3){  
    printf("%s", "Wrong input!\n");
    abort();
  }
#if 0
  if(((*pa + *pb + *pc) % 2) != 0)
    return 1;
#endif
  return 0;
}
 
int main(){
  int a, b, c, g;
  int x, y;
  if(read_input(&a, &b, &c)){
    printf("%s", "NONE");
    return 0;
  }
  if(any_sol(a, b, c, &x, &y, &g) != 0){
    printf("%s", "NONE");
    return 0;
  };
  printf("%d %d", x, y);

}
                  
