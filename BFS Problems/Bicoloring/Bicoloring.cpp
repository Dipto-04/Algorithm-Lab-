#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool checkBipartite(int n, const vector<vector<int>>& g) {
    vector<int> col(n, -1);
    queue<int> q;
    q.push(0);
    col[0] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int x : g[u]) {
            if (col[x] == -1) {
                col[x] = 1 - col[u];
                q.push(x);
            } else if (col[x] == col[u]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, e;
    while (cin >> n && n != 0) {
        cin >> e;

        vector<vector<int>> g(n);
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        if (checkBipartite(n, g))
            cout << "BICOLORABLE." << endl;
        else
            cout << "NOT BICOLORABLE." << endl;
    }

    return 0;
}
