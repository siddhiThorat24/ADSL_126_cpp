/*Implement Check if it is possible to transform one string to another.
Statement: - Given two strings s1 and s2 (all letters in uppercase).
Check if it is possible to convert s1 to s2 by performing following
operations. 1. Make some lowercase letters upper. 2. Delete all the
lowercase letters*/

#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    // DP table
    bool dp[n + 1][m + 1];

    // Initialize
    dp[0][0] = true;

    // s1 non-empty, s2 empty -> valid only if all lowercase (can delete)
    for (int i = 1; i <= n; i++)
        dp[i][0] = dp[i - 1][0] && islower(s1[i - 1]);

    // If s1 is empty but s2 is not → impossible
    for (int j = 1; j <= m; j++)
        dp[0][j] = false;

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            char c1 = s1[i - 1];
            char c2 = s2[j - 1];

            // Case 1: s1[i-1] is uppercase
            if (isupper(c1)) {
                dp[i][j] = (c1 == c2) && dp[i - 1][j - 1];
            }
            else { 
                // lowercase: two choices
                // delete OR capitalize
                dp[i][j] = dp[i - 1][j]; // delete

                if (toupper(c1) == c2) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - 1]; // use after capitalize
                }
            }
        }
    }

    if (dp[n][m])
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
