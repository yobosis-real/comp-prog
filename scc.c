#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int n, int amount) {
    int dp[amount + 1];

    // Initialize all dp values as INT_MAX
    for (int i = 0; i <= amount; i++)
        dp[i] = INT_MAX;

    dp[0] = 0; // Base case: 0 coins to make amount 0

    // Compute minimum coins for all amounts from 1 to amount
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                int sub_res = dp[i - coins[j]];
                if (sub_res != INT_MAX && sub_res + 1 < dp[i])
                    dp[i] = sub_res + 1;
            }
        }
    }

    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
}

int main() {
    int coins[] = {1, 2, 5};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 11;

    int result = minCoins(coins, n, amount);

    if (result != -1)
        printf("Minimum coins required: %d\n", result);
    else
        printf("It's not possible to make the amount with given coins.\n");

    return 0;
}