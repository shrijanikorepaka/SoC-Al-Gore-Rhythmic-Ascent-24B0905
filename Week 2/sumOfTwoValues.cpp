#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    int* arr = new int[n];
    map<long long, int> seen; // value -> index

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; ++i) {
        long long complement = x - arr[i];
        if (seen.count(complement)) {
            cout << seen[complement] + 1 << " " << i + 1 << endl;
            delete[] arr;
            return 0;
        }
        seen[arr[i]] = i;
    }

    cout << "IMPOSSIBLE" << endl;
    delete[] arr;
    return 0;
}
