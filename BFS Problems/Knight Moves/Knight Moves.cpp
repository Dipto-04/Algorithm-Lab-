#include <bits/stdc++.h>
using namespace std;

int dr[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dc[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int knight_bfs(int sr, int sc, int tr, int tc) {
    const int N = 8;
    int dist[N][N];
    int vis[N][N];
    queue<pair<int,int>> q;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dist[i][j] = INT_MAX, vis[i][j] = 0;

    dist[sr][sc] = 0;
    vis[sr][sc] = 1;
    q.push({sr, sc});

    while (!q.empty()) {
        auto cur = q.front(); 
        q.pop();

        int r = cur.first, c = cur.second;
        if (r == tr && c == tc) return dist[r][c];

        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < N && nc >= 0 && nc < N && !vis[nr][nc]) {
                vis[nr][nc] = 1;
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    return (sr == tr && sc == tc) ? 0 : -1;
}

int main() {
    string a, b;
    while (cin >> a >> b) {
        int sr = a[1] - '1';
        int sc = a[0] - 'a';
        int tr = b[1] - '1';
        int tc = b[0] - 'a';

        int ans = knight_bfs(sr, sc, tr, tc);

        cout << "To get from " << a << " to " << b 
             << " takes " << ans << " knight moves." << endl;
    }
}
