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
    
    int i = 2;
    int c = 0;
    while(i <= n){
      if(is_prime(s, i) == 0)c++;
      i++;
    }
    printf("%d\n", c); 

    free(s->s);
    free(s);
}

#line 10000


