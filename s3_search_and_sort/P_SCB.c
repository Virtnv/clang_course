#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*cmp_t)(void const *key, void const *elt);
void *cbsearch(void const *key, void const *base, int num, int size, cmp_t cmp);

struct triple {
  int x, y, z;
};

int tcmp(void const *key, void const *elt) {
  struct triple const *lhs = (struct triple const *)key;
  struct triple const *rhs = (struct triple const *)elt;
  return (lhs->y - rhs->y);
}

void *cbsearch(void const *key, void const *base, int num, int size, cmp_t cmp)
{
  if(size != sizeof(struct triple)){
    printf("%s", "Wrong size!");
    abort();
  }
  const struct triple* k = key;
  const struct triple* b = base;
  const struct triple* l = &b[0];
  const struct triple* r = &b[num-1];
  while(l <= r)
  {
    struct triple* m = l + (r - l) / 2;
    int re = cmp(k, m);
    if(re == 0)return m;
    if(re < 0)r = m - 1;
    if(re > 0)l = m + 1;
  } 
  //printf("%d %d %d\n", l->x, r->x, re);
  return 0;
}

int main() {
  int i, res, n, last;
  struct triple found = {-1, -1, -1};
  struct triple *parr, *answ;

  res = scanf("%d", &n);
  assert(res == 1);
  assert(n > 2);

  parr = (struct triple *)calloc(n / 3, sizeof(struct triple));

  for (i = 0; i < n / 3; ++i) {
    res = scanf("%d %d %d", &parr[i].x, &parr[i].y, &parr[i].z);
    assert(res == 3);
    if ((i == n / 7) && ((i % 10) != 0))
      found = parr[i];
  }

  answ = (struct triple *)cbsearch(&found, parr, n / 3, sizeof(found), &tcmp);

  if (!answ || (answ == (struct triple *)(parr + n / 3))) {
    printf("0\n");
    return 0;
  }

  printf("%d %d %d\n", answ->x, answ->y, answ->z);

  free(parr);
  return 0;
}

