#include <iostream>
using namespace std;

int countZeroes(int arr[], int left, int right) {
    if (left > right) return 0;

    if (left == right) {
        if (arr[left] == 0)
            return 1;
        else
            return 0;
    }

    int mid = (left + right) / 2;

    int leftCount = countZeroes(arr, left, mid);
    int rightCount = countZeroes(arr, mid + 1, right);

    return leftCount + rightCount;
}

int main() {
    int n;
    cin >> n;
    int arr[1000];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << countZeroes(arr, 0, n - 1) << endl;
    return 0;
}
