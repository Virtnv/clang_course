#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

unsigned long long fibnums[2024] = {0};

unsigned long long fib(unsigned n, unsigned m){
    unsigned long long first = 0, second = 1;
    if(n == 0)return 0ull;
    if(n == 1)return 1ull;
    if(fibnums[n] == 0){
        for(int i = 2; i <= n; ++i){
            fibnums[i] = (first + second) % m;
            
            first = second;
            second = fibnums[i];
           
        }        
    }   
    return fibnums[n]; 
}

int main(){
    unsigned res;
    unsigned n, m;
    res = scanf("%u%u", &n, &m);
    printf("%llu", fib(n, m));
}
