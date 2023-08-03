#include <stdio.h>
#include <stdlib.h>
#define N 100

u_int64_t dinamic_fib(u_int64_t* fib_table, u_int64_t n){
    if(fib_table[n] != 0){
        return fib_table[n];
    }
    fib_table[n] = dinamic_fib(fib_table, n-1) + dinamic_fib(fib_table, n-2);
    return fib_table[n];
}

int main(){
    u_int64_t* dinamic_fib_table = (u_int64_t*) malloc(sizeof(u_int64_t) * (N+1));
    dinamic_fib_table[0] = 1;
    dinamic_fib_table[1] = 1;

    u_int64_t fib_for_N = dinamic_fib(dinamic_fib_table, N);



    printf("fib(%d) = %llu\n", N, fib_for_N);

    return 0;
}