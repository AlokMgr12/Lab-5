#include <stdio.h>

int nextCombination(int comb[], int n, int r) {
    int i = r - 1;

    while (i >= 0 && comb[i] == n - r + i + 1) {
        i--;
    }

    if (i < 0) {
        return 0;
    }

    comb[i]++;

    for (int j = i + 1; j < r; j++) {
        comb[j] = comb[j - 1] + 1;
    }

    return 1;
}

int main() {
    int n = 5, r = 3;
    int comb[] = {1, 2, 3};

    do {
        printf("Combination: ");
        for (int i = 0; i < r; i++) {
            printf("%d ", comb[i]);
        }
        printf("\n");
    } while (nextCombination(comb, n, r));

    return 0;
}

