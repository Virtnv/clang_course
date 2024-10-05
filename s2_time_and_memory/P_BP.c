#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

unsigned check_bit(unsigned n, unsigned pos){
  unsigned r = n & (1 << pos);
  if(r)return 1;
  return 0;
}

int find_bits(int n, int* msb, int* lsb){
  if(n == 0)return 1;
  int s = sizeof(int) * 8 - 1;
  
  while(s >= 0){
    int v = check_bit(n, s);
    if(v && *msb == -1){
      *msb = s;
      *lsb = s;
    }
    else if(v && (*msb != -1))
      *lsb = s;
    s--;
  }
  return 0;
}

int main(){
  int n;
  int ms = -1, ls = -1;
  int res = scanf("%d", &n);
  if(res != 1){
    printf("%s", "Wrong input");
    abort();
  }
  if(find_bits(n, &ms, &ls)){
    printf("%s", "NO");
    return 0;
  }
  printf("%d %d",ms, ls);
  return 0;
}
