#include <stdio.h>

int power(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int isPrime(int n, int k) {
    if (n <= 1 || n == 4) return 0;
    if (n <= 3) return 1;

    while (k > 0) {
        int a = 2 + rand() % (n - 4);
        if (power(a, n - 1, n) != 1) {
            return 0;
        }
        k--;
    }
    return 1;
}

int main() {
    int n, k = 5;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (isPrime(n, k)) {
        printf("%d is probably prime.\n", n);
    } else {
        printf("%d is not prime.\n", n);
    }

    return 0;
}

