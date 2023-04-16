#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int count_possible_orders(int n, vector<int> left, vector<int> right) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (left[i-1] == 1 && right[i-1] == n) {
            count += (n-2)!;
        } else if (left[i-1] == n && right[i-1] == 1) {
            count += (n-2)!;
        } else if (left[i-1] == 1 || right[i-1] == n) {
            count += (n-3)!;
        } else {
            count += (n-4)! * (n-2);
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        vector<int> left(n), right(n);
        for (int j = 0; j < n; j++) {
            cin >> left[j];
        }
        for (int j = 0; j < n; j++) {
            cin >> right[j];
        }
        cout << "# " << i << " " << count_possible_orders(n, left, right) << endl;
    }
    return 0;
}