#include <iostream>
using namespace std;

int main() {
    int n, D;
    cout << "Enter number of tasks: ";
    cin >> n;
    
    int task[n];
    cout << "Enter work for each task: ";
    for (int i = 0; i < n; i++) {
        cin >> task[i];
    }
    
    cout << "Enter maximum days (D): ";
    cin >> D;
    
    // Find maximum task
    int max_task = 0;
    for (int i = 0; i < n; i++) {
        if (task[i] > max_task) {
            max_task = task[i];
        }
    }
    
    // Binary search for minimum work per day
    int left = 1, right = max_task;
    int answer = max_task;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        int days_needed = 0;
        
        // Calculate total days needed for current mid value
        for (int i = 0; i < n; i++) {
            days_needed += (task[i] + mid - 1) / mid;
            if (days_needed > D)
                break;
        }
        
        if (days_needed <= D) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    cout << "Minimum work per day: " << answer << endl;
    
    return 0;
}
