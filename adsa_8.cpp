/*Implement Coin Change problem. Statement: - Given an integer array
of coins [ ] of size N representing different types of currency and an
integer sum, The task is to find the number of ways to make sum by
using different combinations from coins[].*/

#include <iostream>
using namespace std;

int main() {
    int N, sum;
    cin >> N;

    // Invalid case: number of coins must be positive
    if (N <= 0) {
        cout << 0;
        return 0;
    }

    int coins[N];
    for (int i = 0; i < N; i++)
        cin >> coins[i];

    cin >> sum;

    // Invalid sum
    if (sum < 0) {
        cout << 0;
        return 0;
    }

    long long dp[sum + 1] = {0};
    dp[0] = 1;  // one way to make 0

    for (int i = 0; i < N; i++) {

        // If coin value is invalid (<= 0), ignore it
        if (coins[i] <= 0) continue;

        for (int j = coins[i]; j <= sum; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << dp[sum];
    return 0;
}
