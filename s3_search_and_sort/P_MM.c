#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

void mm(int* arr, int l){
  if(l == 0){
    printf("0 0");
    return;
  }
  if(l == 1){
    printf("%d", arr[0]);
    return;
  }
  int min = arr[0], max = arr[0];
  for(int i = 1; i < l; ++i){
    if(arr[i] < min)min = arr[i];
    if(arr[i] > max)max = arr[i];   
  }
  printf("%d %d", min, max);
            
}

int main(){
  int n, res;
  res = scanf("%d", &n);
  if(res != 1){
    printf("%s", "Wrong input");
    abort();
  }
  int* arr = calloc(n, sizeof(int));
  for(int i = 0; i < n; ++i){
    res = scanf("%d", &arr[i]);
    if(res != 1)abort();
  }
  mm(arr, n);
}
