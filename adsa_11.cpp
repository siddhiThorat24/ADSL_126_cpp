/*Implement program to find all distinct subsets of a given set using Bit
Masking Approach. Statement: - Given an array of integers arr[], The
task is to find all its subsets. The subset cannot contain duplicate
elements, so any repeated subset should be considered only once in
the output.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> result;
vector<int> current;

void backtrack(vector<int>& arr, int start) {
    // Add current subset to result
    result.push_back(current);

    for (int i = start; i < arr.size(); i++) {

        // Skip duplicates (same number at same level)
        if (i > start && arr[i] == arr[i - 1])
            continue;

        current.push_back(arr[i]);         // include element
        backtrack(arr, i + 1);             // move to next
        current.pop_back();                // backtrack
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());  // sort for duplicate handling

    backtrack(arr, 0);

    // Print all distinct subsets
    for (auto &subset : result) {
        cout << "{ ";
        for (int x : subset)
            cout << x << " ";
        cout << "}" << endl;
    }

    return 0;
}
