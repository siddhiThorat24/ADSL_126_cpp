/*Implement Subset Sum Problem. Statement:-Given a set of non-
negative integers and a value sum, the task is to check if there is a
subset of the given set whose sum is equal to the given sum.*/

#include <iostream>
using namespace std;

int main() {
    int n, sum;
    cin >> n;

    // Invalid input
    if (n <= 0) {
        cout << "No";
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> sum;

    // Invalid sum
    if (sum < 0) {
        cout << "No";
        return 0;
    }

    bool dp[n + 1][sum + 1];

    // Initialize DP table
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;  // sum 0 always possible

    for (int j = 1; j <= sum; j++)
        dp[0][j] = false; // no elements → cannot make positive sum

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    // Final answer
    if (dp[n][sum])
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
