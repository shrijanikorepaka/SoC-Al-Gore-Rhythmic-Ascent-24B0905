#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;
int n, m;
char labyrinth[MAXN][MAXN];
bool visited[MAXN][MAXN];
pair<int,int> parent[MAXN][MAXN]; // store previous cell coordinates
char moveDir[MAXN][MAXN];         // store direction used to reach cell

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    pair<int,int> start, end;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> labyrinth[i][j];
            if (labyrinth[i][j] == 'A') start = {i, j};
            if (labyrinth[i][j] == 'B') end = {i, j};
        }
    }

    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    bool found = false;

    while (!q.empty() && !found) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == end.first && y == end.second) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (!visited[nx][ny] && labyrinth[nx][ny] != '#') {
                    visited[nx][ny] = true;
                    parent[nx][ny] = {x, y};
                    moveDir[nx][ny] = dir[i];
                    q.push({nx, ny});
                }
            }
        }
    }

    if (!found) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    // Reconstruct path
    string path;
    pair<int,int> cur = end;
    while (cur != start) {
        path += moveDir[cur.first][cur.second];
        cur = parent[cur.first][cur.second];
    }

    reverse(path.begin(), path.end());
    cout << (int)path.size() << "\n";
    cout << path << "\n";

    return 0;
}
