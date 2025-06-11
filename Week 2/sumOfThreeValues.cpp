#include <iostream>
#include <algorithm>
using namespace std;

struct Element {
    int value;
    int index;
};

int main() {
    int n;
    long long x;
    cin >> n >> x;

    Element* arr = new Element[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].value;
        arr[i].index = i + 1;  // 1-based index
    }

    // Sort by value
    sort(arr, arr + n, [](Element a, Element b) {
        return a.value < b.value;
    });

    // Try each element as the first of the triplet
    for (int i = 0; i < n; ++i) {
        long long target = x - arr[i].value;
        int left = i + 1;
        int right = n - 1;

        // Two-pointer search
        while (left < right) {
            long long sum = arr[left].value + arr[right].value;
            if (sum == target) {
                cout << arr[i].index << " " << arr[left].index << " " << arr[right].index << endl;
                delete[] arr;
                return 0;
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    delete[] arr;
    return 0;
}
