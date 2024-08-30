
class Solution{
public:
vector<vector<int>> res;
    
    bool check(int i, int j, vector<vector<char>>& board) {
        int x = i , y = j;
        // up
        while(x >= 0){
            if(board[x][y] == 'Q'){
                return false;
            }
            x--;
        }
        // left diag up
        x = i;
        while(x >= 0 && y >= 0){
            if(board[x][y] == 'Q') return false;
            x--;
            y--;
        }
        // right diag up
        x = i , y = j;
        while(x >= 0 && y < board.size()){
            if(board[x][y] == 'Q') return false;
            x--;
            y++;
        }
        return true;
    }
    void insertBoard(vector<vector<char>>& board){
        vector<int> row;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[j][i] == 'Q'){
                    row.push_back(j+1);
                    break;
                }
            }
        }
        if(row.size() == board.size()){
            res.push_back(row);
        }
    }
    
    void solve(int i, int n, vector<vector<char>> &board) {
        if(i >= n){
            insertBoard(board);
            return;
        }
        
        for(int j=0; j<board.size(); j++){
            if(check(i, j,board)){
                board[i][j] = 'Q';
                solve(i+1,n, board);
                board[i][j] = '-';
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<char>> board(n, vector<char>(n, '-'));
        
        solve(0, n, board);
        sort(res.begin(), res.end());
        return res;
    }
};
