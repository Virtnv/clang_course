#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct sieve_t {
    int n;
    char *s;
};

int sieve_bound(int num)
{
    double dnum, dres;
    if (num <= 20)
        return 100;
    dnum = num;
    dres = dnum * (log(dnum) + log(log(dnum)));
    return (int) round(dres);
}

void fill_sieve(struct sieve_t *s){
  //if prime - 0, else - 1
  for(int i = 2; i * i <= s->n; ++i){
    if(s->s[i] != 1)
      for(int j = i*i; j <= s->n; j = j + i){
        s->s[j] = 1;
      }
  }
};

int is_prime(struct sieve_t *s, int n){
  return s->s[n];
}

int find_n(int x){
  int ds = 1, i = 0;
  while(ds < x){
    ds = ds * 10;
    i++;
  }
  return i;
}

int pow_10(int n){
  int r = 1;
  if(!n)return r;
  while(n){
    r = r * 10;
    n--;
  }
  return r;
}

int check_cc(struct sieve_t* s, int x){
  int n = find_n(x);
  if((pow_10(n) - x) == 1)
    return is_prime(s, x);
  int r = n;
  int idx = n;
  //printf("\n%d %d\n", r, x);
  while(idx){
    int rst = x % (pow_10(n - 1));
    int mst = x / (pow_10(n - 1));
    if(!mst)return r;
    //printf("\n%d %d %d\n", (rst * 10 + mst), rst, mst);
    if(rst){
      x = rst * 10 + mst;
      if(is_prime(s, x) == 0)r--;
      //printf("\n%d", x); 
    }
    idx--;
  }
  //printf("\n%d %d\n", r, x);
  return r;
}

int finally(struct sieve_t* s, int n){
  int i = 0;
  int dp = 0, dn = 0;
  for(i = 0; i < 1000000; i++)
    if(check_cc(s, n + i) == 0){
      //printf("\n%d\n", i + n);
      dp = n + i;
      break;
    }
  
  for(i = 0; i < 1000000; i++)
    if(check_cc(s, n - i) == 0){
      //printf("\n%d\n", i + n);
      dn = n - i;
      break;
    }
  //printf("\n%d %d\n", dp, dn);
  if((dp-n) >= (n - dn))return dn;
  if(dp == 0 && dn != 0) return dn;
  return dp;
}

int main()
{
    int n;
    int res;
    struct sieve_t *s;

    res = scanf("%d", &n);
    assert(res == 1);
    
    s = (struct sieve_t *) malloc(sizeof(struct sieve_t));
    s->n = sieve_bound(n + 100);
    s->s = (char *) calloc(s->n, sizeof(char));

    fill_sieve(s);
    printf("%d\n", finally(s, n));

    free(s->s);
    free(s);
}

#line 10000


