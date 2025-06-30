#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    int total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
        total_sum += coins[i];
    }

    vector<bool> possible(total_sum + 1, false);
    possible[0] = true;

    for (int coin : coins) {
        // Iterate backwards to avoid reusing the same coin
        for (int s = total_sum; s >= 0; --s) {
            if (possible[s] && s + coin <= total_sum) {
                possible[s + coin] = true;
            }
        }
    }

    vector<int> sums;
    for (int s = 1; s <= total_sum; ++s) {
        if (possible[s]) {
            sums.push_back(s);
        }
    }

    cout << sums.size() << "\n";
    for (int s : sums) {
        cout << s << " ";
    }
    cout << "\n";
    return 0;
}
