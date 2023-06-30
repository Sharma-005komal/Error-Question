bool path(vector<vector<int>>& mat, queue<pair<int, int>> q, int m, int n)
    {
        vector<vector<int>> vis(m+1, vector<int>(n+1, 0));
        int del_row[] = {-1, 0, +1, 0};
        int del_col[] = {0, +1, 0, -1};
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            /**if(mat[row][col] == 0 && row == m && col == n)
            {
                return true;
            }**/
            for(int i=0; i<4; i++)
            {
                int n_row = row + del_row[i];
                int n_col = col + del_col[i];
                if(mat[n_row][n_col] == 0 && n_row == m && n_col == n)
                {
                    return true;
                }
                else if(n_row > 1 && n_col > 1 && n_row < m && n_col < n
                && mat[n_row][n_col] != 1 && !vis[n_row][n_col])
                {
                    vis[n_row][n_col] = 1;
                    q.push({n_row, n_col});
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int ans = 0;
        vector<vector<int>> mat(row+1, vector<int>(col+1, 0));
        for(int i=1; i<=cells.size(); i++)
        {
            int nr = cells[i][1];
            int nc = cells[i][2];
            mat[nr][nc] = 1;
            queue<pair<int, int>> q;
            for(int j=1; j<=col; j++)
            {
                if(mat[1][j] == 0)
                {
                    q.push({1, j});
                }
            }
            if(path(mat, q, row, col))
            {
                ans = max(ans, i);
            }
        }
        return ans;
    }
};
