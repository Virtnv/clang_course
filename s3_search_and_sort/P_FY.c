#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int myrand() {
  static unsigned long int seed = 1;
  seed = seed * 1103515245 + 12345;
  return (unsigned int)(seed / 65536) % 32768;
}

void swap_(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void ins_sort(int* arr, unsigned n){
   if(n == 0){
    printf("0");
    return;
   }
   if(n == 1){
    printf("%d", arr[0]);
    return;
   }
   for(int* i = &arr[n - 1]; i != &arr[0]; i--){
      swap_(&arr[(myrand() % (i - arr + 1))], i);
   }
   for(int* i = &arr[0]; i != &arr[n]; i++)
      printf("%d ", *i);
}

int main(){
    int res;
    unsigned n;
    res = scanf("%u", &n);
    if(res != 1)abort();
    int* arr = calloc(n, sizeof(int));
    for(int i = 0; i < n; ++i){
        res = scanf("%d", &arr[i]);
        if(res != 1)abort();
    }
    ins_sort(arr, n);
    free(arr);   
}
