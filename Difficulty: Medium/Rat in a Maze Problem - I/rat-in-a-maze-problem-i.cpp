class Solution {
public:
    void solve(int x, int y, vector<vector<int>> &m, int n,
               vector<vector<int>> &vis, string path, vector<string> &ans) {
        // If destination is reached
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        // Down
        if (x + 1 < n && !vis[x + 1][y] && m[x + 1][y] == 1) {
            vis[x][y] = 1;
            solve(x + 1, y, m, n, vis, path + 'D', ans);
            vis[x][y] = 0;
        }

        // Left
        if (y - 1 >= 0 && !vis[x][y - 1] && m[x][y - 1] == 1) {
            vis[x][y] = 1;
            solve(x, y - 1, m, n, vis, path + 'L', ans);
            vis[x][y] = 0;
        }

        // Right
        if (y + 1 < n && !vis[x][y + 1] && m[x][y + 1] == 1) {
            vis[x][y] = 1;
            solve(x, y + 1, m, n, vis, path + 'R', ans);
            vis[x][y] = 0;
        }

        // Up
        if (x - 1 >= 0 && !vis[x - 1][y] && m[x - 1][y] == 1) {
            vis[x][y] = 1;
            solve(x - 1, y, m, n, vis, path + 'U', ans);
            vis[x][y] = 0;
        }
    }

    vector<string> ratInMaze(vector<vector<int>> &m) {
        int n = m.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        if (m[0][0] == 0) return ans; // No path if start is blocked

        solve(0, 0, m, n, vis, "", ans);
        return ans;
    }
};