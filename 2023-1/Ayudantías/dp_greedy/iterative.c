#include <stdio.h>
#include <stdlib.h>
#define N 50

u_int64_t iterative_fib(u_int64_t n){
    u_int64_t fib[n+1];
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i <= n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

int main(){

    u_int64_t fib_for_N = iterative_fib(N);
    printf("fib(%d) = %llu\n", N, fib_for_N);

    return 0;
}