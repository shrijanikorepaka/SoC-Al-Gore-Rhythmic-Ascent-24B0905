#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> numbers[i];
    }
    long long total_sum = (long long)n * (n + 1) / 2;
    long long current_sum = 0;
    for (int num : numbers) {
        current_sum += num;
    }
    cout << total_sum - current_sum << endl;
    return 0;
}