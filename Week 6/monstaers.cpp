#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 1e9;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const char dir[4] = {'D', 'U', 'R', 'L'};

int n, m;
vector<string> grid;
vector<vector<int>> monster_time, player_time;
vector<vector<pair<int, int>>> parent;

bool is_boundary(int x, int y) {
    return x == 0 || x == n - 1 || y == 0 || y == m - 1;
}

bool inside(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    monster_time.assign(n, vector<int>(m, INF));
    player_time.assign(n, vector<int>(m, INF));
    parent.assign(n, vector<pair<int, int>>(m, make_pair(-1, -1)));

    queue<pair<int, int>> monster_queue;
    queue<pair<int, int>> player_queue;
    pair<int, int> start;

    // Input and initialization
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'M') {
                monster_queue.push(make_pair(i, j));
                monster_time[i][j] = 0;
            }
            if (grid[i][j] == 'A') {
                start = make_pair(i, j);
                player_queue.push(start);
                player_time[i][j] = 0;
            }
        }
    }

    // BFS for monsters
    while (!monster_queue.empty()) {
        int x = monster_queue.front().first;
        int y = monster_queue.front().second;
        monster_queue.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (inside(nx, ny) && grid[nx][ny] != '#' && monster_time[nx][ny] == INF) {
                monster_time[nx][ny] = monster_time[x][y] + 1;
                monster_queue.push(make_pair(nx, ny));
            }
        }
    }

    // BFS for player
    while (!player_queue.empty()) {
        int x = player_queue.front().first;
        int y = player_queue.front().second;
        player_queue.pop();

        if (is_boundary(x, y)) {
            // Reconstruct the path
            string path = "";
            int cx = x;
            int cy = y;
            while (make_pair(cx, cy) != start) {
                int px = parent[cx][cy].first;
                int py = parent[cx][cy].second;
                for (int d = 0; d < 4; ++d) {
                    if (px + dx[d] == cx && py + dy[d] == cy) {
                        path.push_back(dir[d]);
                        break;
                    }
                }
                cx = px;
                cy = py;
            }
            reverse(path.begin(), path.end());
            cout << "YES" << endl;
            cout << path.length() << endl;
            cout << path << endl;
            return 0;
        }

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (inside(nx, ny) && grid[nx][ny] != '#' && player_time[nx][ny] == INF) {
                if (player_time[x][y] + 1 < monster_time[nx][ny]) {
                    player_time[nx][ny] = player_time[x][y] + 1;
                    parent[nx][ny] = make_pair(x, y);
                    player_queue.push(make_pair(nx, ny));
                }
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}
