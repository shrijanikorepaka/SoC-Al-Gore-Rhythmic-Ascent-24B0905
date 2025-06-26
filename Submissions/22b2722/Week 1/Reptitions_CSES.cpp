#include <bits/stdc++.h>
using namespace std;

int solve(string S)
{
    int ans = 1, count = 1;
    for (int i = 1; i < S.length(); i++) {
        if (S[i] == S[i - 1])
            count += 1;
        else
            count = 1;
        ans = max(ans, count);
    }
    return ans;
}

int main()
{
    string S;

    cout << solve(S) << endl;
    return 0;
}