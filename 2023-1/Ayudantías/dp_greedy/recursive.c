#include <stdio.h>
#include <stdlib.h>
#define N 50

u_int64_t fib(u_int64_t n){
    if(n == 0 || n == 1){
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

int main(){

    u_int64_t fib_for_N = fib(N);
    printf("fib(%d) = %llu\n", N, fib_for_N);

    return 0;
}