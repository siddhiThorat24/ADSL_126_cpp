#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int low = 0;
    int high = n * 5;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int temp = mid;
        int count = 0;
        while (temp > 0) {
            temp = temp / 5;
            count += temp;
        }
        if (count == n) {
            ans = mid;
            high = mid - 1;
        } else if (count < n) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (ans == -1) {
        cout << "No number found";
    } else {
        cout << ans;
    }
    return 0;
}
