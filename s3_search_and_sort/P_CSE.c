#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct triple {
  int x, y, z;
};

int tcmp(void const *key, void const *elt) {
  struct triple const *lhs = (struct triple const *)key;
  struct triple const *rhs = (struct triple const *)elt;
  if (lhs->x == rhs->x && lhs->y == rhs->y)
    return (lhs->z < rhs->z);
  if (lhs->x == rhs->x)
    return (lhs->y < rhs->y);
  return (lhs->x < rhs->x);
}

void swap_(void* a, void* b, int eltsize){
  if(eltsize != sizeof(struct triple)){
    printf("%s", "Unknown element size");
    abort();
  }
  #if 0
  struct triple* ta = a;
  struct triple* tb = b;
  struct triple tmp;
  tmp.x = ta->x;
  tmp.y = ta->y;
  tmp.z = ta->z;
  ta->x = tb->x;
  ta->y = tb->y;
  ta->z = tb->z;
  tb->x = tmp.x;
  tb->y = tmp.y;
  tb->z = tmp.z;
  #endif
  #if 1
  struct triple t;
  struct triple* pt = &t;
  struct triple* pa =(struct triple*)a;
  struct triple* pb =(struct triple*)b;
  memcpy(pt, pa, sizeof(struct triple));
  memcpy(pa, pb, sizeof(struct triple));
  memcpy(pb, pt, sizeof(struct triple));
  #endif
}

typedef int (*cmp_t)(const void *lhs, const void *rhs);

int selstep(void *parr, int eltsize, int n, int last, cmp_t cmp){
  struct triple* idx;
  struct triple m;
  struct triple* min = &((struct triple*)parr)[last];
  #if 1
  for(idx = &((struct triple*)parr)[last];
      idx != &((struct triple*)parr)[n]; idx++)
  {
    //printf("\n%d %d %d", idx->x, idx->y, idx->z);
    int r = cmp(min, idx);
    if(!r)
    {
      min = idx;
      //memcpy(min, idx, sizeof(struct triple));
    }
  }
  #endif
  swap_((void*)min, &((struct triple*)parr)[last], sizeof(struct triple));
  #if 0
  int i;
  parr = min;
  for (i = 0; i < n / 3; ++i)
    printf("%d %d %d\n", ((struct triple*)parr)[i].x, 
                         ((struct triple*)parr)[i].y,
                         ((struct triple*)parr)[i].z);
 
  #endif
  return 0;
}

int main() {
  int i, res, n, last;
  struct triple *parr;

  res = scanf("%d", &n);
  assert(res == 1);
  assert(n > 2);

  parr = (struct triple *)calloc(n / 3, sizeof(struct triple));

  for (i = 0; i < n / 3; ++i) {
    res = scanf("%d %d %d", &parr[i].x, &parr[i].y, &parr[i].z);
    assert(res == 3);
  }

  res = scanf("%d", &last);
  assert(res == 1);
  assert(last < n);

  selstep(parr, sizeof(struct triple), n / 3, last / 3, &tcmp);
#if 1
  for (i = 0; i < n / 3; ++i)
    printf("%d %d %d\n", parr[i].x, parr[i].y, parr[i].z);
#endif
  free(parr);
  return 0;
}

