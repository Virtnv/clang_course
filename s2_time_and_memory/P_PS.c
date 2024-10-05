#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//memory limit exceeded

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
  #if 0
  printf("\n");
  for(int i = 0; i < s->n; ++i)
    printf("%d ", s->s[i]);
  printf("\n");      
  #endif
};

int nth_prime(struct sieve_t *s, int N){
  assert(N < s->n);
  int cn = 0, i = 2;
  while(cn < N){
    if(s->s[i] == 0)cn++;
    i++;
  }
  return i-1;
};

int main()
{
    int n, outp;
    int res;
    struct sieve_t *s;

    res = scanf("%d", &n);
    assert(res == 1);
    s = (struct sieve_t *) malloc(sizeof(struct sieve_t));
    s->n = sieve_bound(n);
    s->s = (char *) calloc(s->n, sizeof(char));

    fill_sieve(s);
    outp = nth_prime(s, n);
    printf("%d\n", outp);

    free(s->s);
    free(s);
}

#line 10000

