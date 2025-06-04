#include <stdio.h>

void coinChangeGreedy(int coins[], int n, int amount) {
    // Sort coins in descending order (simple selection sort for clarity)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (coins[i] < coins[j]) {
                int temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    int count = 0;

    printf("Coins used: ");
    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
            printf("%d ", coins[i]);
        }
    }

    if (amount == 0) {
        printf("\nTotal coins used: %d\n", count);
    } else {
        printf("\nCannot make exact change. Output: -1\n");
    }
}

int main() {
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 93;

    coinChangeGreedy(coins, n, amount);

    return 0;
}
