/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
    vector<int> dr = {0, -1, 0, 1};
    vector<int> dc = {-1, 0, 1, 0};
    int n;
    int m;
    vector<vector<char>> Board;
    vector<vector<bool>> Vis;
    string Word;

    bool dfs(int r, int c, int pr, int pc, int idx){
        if(idx == Word.size() - 1)return true;
        Vis[r][c] = 1;
        bool ret = false;
        for(int i=0; i<4; i++){
            int nr = r + dr[i], nc = c +dc[i];
            if(
               min(nr, nc) >= 0 && nr < n && nc < m && 
               Vis[nr][nc] == 0 && 
               Board[nr][nc] == Word[idx + 1]
            ){
                ret |= dfs(nr, nc, r, c, idx + 1);
            }
        }
        Vis[r][c] = 0;
        return ret;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        Board = board;
        Word = word;
        Vis = vector<vector<bool>>(n, vector<bool>(m));

        bool found = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    found |= dfs(i, j, -1, -1, 0);
                }
            }
        }
        return found;
    }
};
// @lc code=end

