#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

unsigned clear_bit(unsigned n, unsigned pos){
  return n & ~(1 << pos); 
}

unsigned set_bit(unsigned n, unsigned pos){
  return (n | (1 << pos));
}

unsigned check_bit(unsigned n, unsigned pos){
  unsigned r = n & (1 << pos);
  if(r)return 1;
  return 0;
}

int* toggle_arr(unsigned* a, unsigned pos){
  unsigned x = pos / 8;
  unsigned pp = pos % 8;
  if(check_bit(a[x], pp)){
    a[x] = clear_bit(a[x], pp);
  }else{
    a[x] = set_bit(a[x], pp); 
  }
    return a;
}

int main(){
  int x, n, s;
  int res = scanf("%d", &s);
  if(res != 1){
    printf("%s", "Wrong input");
    abort();
  }
  unsigned *arr = calloc(s, sizeof(unsigned));
    for(int i = 0; i < s; ++i){
        res = scanf("%d", &arr[i]);
        if(res != 1){
            printf("%s", "Wrong input\n");
            abort();
        }        
    }
    res = scanf("%d", &n);
    if(res != 1)
        abort();
  
  arr = toggle_arr(arr, n); 
  for(int i = 0; i < s; ++i)
    printf("%d ", arr[i]);
  free(arr);
  
}
