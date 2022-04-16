#include <bits/stdc++.h>
using namespace std;


vector<string> Convert_Text_To_Vector(string& text, string space_delimiter) {
    text += space_delimiter;
    vector<string> words{};
    size_t pos = 0;
    while ((pos = text.find(space_delimiter)) != string::npos) {
        words.push_back(text.substr(0, pos));
        text.erase(0, pos + space_delimiter.length());
    }
    return words;
}


const int N = 4;                            // boarder of the Matrix
int dr[] = { -1, -1, -1, 0, 1, 1,1, 0 };    // Move Instruction throught Grid
int dc[] = { -1, 0, 1, 1,1, 0, -1, -1 };
int vis[N][N];                              // cannot use the same location twice    
vector<string> Matrix;

// don't go out
bool Is_Out_Matrix(int r, int c) {
    return r < N&& c < N&&
        r >= 0 && c >= 0 &&
        !vis[r][c];
}

// Graph Algorithm FloodFill
bool DFS_Floodfill_Find_Word(int r, int c, int idx, string& word) {
    vis[r][c] = 1;
    if (idx + 1 == word.size())return true;
    int ret = false;
    for (int i = 0; i < 8; i++)
    {
        int nr = r + dr[i], nc = c + dc[i];
        if (Is_Out_Matrix(nr, nc) && Matrix[nr][nc] == word[idx + 1])
            ret |= DFS_Floodfill_Find_Word(nr, nc, idx + 1, word);
    }
    return ret;
}

string MatrixChallenge(string arr[], int arrLength) {
    Matrix = Convert_Text_To_Vector(arr[0], " ");
    vector<string> search = Convert_Text_To_Vector(arr[1], ",");

    vector<int> Positions;  // Indx of the word that the algorithm can't find
    for (int ii = 0;ii < (int)search.size(); ii++)
    {
        bool flag = false;
        for (int i = 0;i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (Matrix[i][j] == search[ii][0])  // If you find potential good start point
                {
                    memset(vis, 0, sizeof(vis));
                    flag |= DFS_Floodfill_Find_Word(i, j, 0, search[ii]);
                }
            }
        }

        if (flag == false)
        {
            Positions.push_back(ii);
        }
    }
    string ans = "true";
    if (Positions.size() > 0) {
        ans = "";
        for (int i = 0; i < Positions.size(); i++) {
            ans += search[Positions[i]];
            if (i < Positions.size() - 1) ans += ",";
        }
    }
    return ans;
}

int main(void) {

    // keep this function call here
    string A[] = { "aaey, rrum, tgmn, ball", "all,ball,mur,raeymnl,rumk,tall,true,trum,yes" };
    //"all,ball,mur,raeymnl,tall,true,trum"
    //"all,ball,mur,raeymnl,rumk,tall,true,trum,yes"
    int arrLength = sizeof(A) / sizeof(*A);
    cout << MatrixChallenge(A, arrLength);
    return 0;

}