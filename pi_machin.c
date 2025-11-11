/*
Machin:
π = 16 arctan(1/5​)− 4arctan(1/239​)
*/
// gcc -o pi_machin pi_machin.c
#include <stdio.h>
#include <math.h>

long double arctan_series(long double x, long double eps) {
    long double term = x;        // término n=0
    long double x2 = x * x;
    long double sum = term;
    unsigned long n = 1;

    while (fabsl(term) > eps) {
        term *= -x2;                        // x^(2n+1) progresivo con signo alternante
        long double denom = 2.0L * n + 1.0L;
        long double to_add = term / denom;
        sum += to_add;
        ++n;
        // seguridad por si no converge (n muy grande)
        if (n > 10000000) break;
    }
    return sum;
}

int main(void){
    // Queremos 10 decimales; elegimos eps menor (ej: 1e-13)
    long double eps = 1e-13L;

    long double a = arctan_series(1.0L/5.0L, eps);
    long double b = arctan_series(1.0L/239.0L, eps);

    long double pi = 16.0L * a - 4.0L * b;

    // Imprimimos 12 decimales (10 correctos garantizados por eps)
    printf("PI aproximado (Machin): %.12Lf\n", pi);

    return 0;

}