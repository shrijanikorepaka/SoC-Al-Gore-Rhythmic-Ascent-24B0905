#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> songs(n);
    for (int i = 0; i < n; ++i) {
        cin >> songs[i];
    }

    unordered_map<int, int> lastSeen;
    int maxLength = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        int currentSong = songs[right];
        if (lastSeen.find(currentSong) != lastSeen.end() && lastSeen[currentSong] >= left) {
            left = lastSeen[currentSong] + 1;
        }
        lastSeen[currentSong] = right;
        maxLength = max(maxLength, right - left + 1);
    }

    cout << maxLength << endl;
    return 0;
}
