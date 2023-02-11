#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

typedef struct
{
    int row;
    int col;
} Cell;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const 
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if(hash1 != hash2) {
            return hash1 ^ hash2;
        }
        return hash1;
    }
};

pair<int,int> parent[1000][1000];
// unordered_map<pair<int, int>, pair<int, int>, hash_pair> parent;

Cell findStart(vector<string> board, int r, int c)
{
    Cell A;
    A.row = -1;
    for (int i = 0; i < r; i++)
    {
        if (A.row != -1)
        {
            break;
        }
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == 'A')
            {
                A.row = i;
                A.col = j;
                break;
            }
        }
    }
    return A;
}

string backtrace(pair<int, int> start, pair<int, int> end) {
    string path;
    // for(auto it = parent.begin(); it != parent.end(); it++) {
    //     cout << it->first.first << " " << it->first.second << "->" << it->second.first << " " << it->second.second << endl;
    // }
    // return path;

    pair<int, int> cur = end;
    // cout << "start: " << start.first << " " << start.second << endl;
     while(!(cur.first == start.first && cur.second == start.second)){
        pair<int, int> pre = parent[cur.first][cur.second];
        // cout << cur.first << ' ' << cur.second << endl; 
        if(pre.first + 1 == cur.first) {
            path.append("D");
        }
        if(pre.first - 1 == cur.first) {
            path.append("U");
        }
        if(pre.second - 1 == cur.second) {
            path.append("L");
        }
        if(pre.second + 1 == cur.second) {
            path.append("R");
        }
        cur = pre;
    };
    

    reverse(path.begin(), path.end());
    return path;
}


Cell bfs(vector<string> &board, int r, int c)
{

    Cell start = findStart(board, r, c);
    // printf("Start: %d %d\n", start.row, start.col);
    queue<Cell> queue;
    bool explored[1000][1000];
    for(int i = 0; i < 1000; i++)
        for(int j = 0; j < 1000; j++)
            explored[i][j] = false;
    queue.push(start);

    while (!queue.empty())
    {
        Cell cur = queue.front();
        queue.pop();
        int row, col;
        row = cur.row;
        col = cur.col;
        
        // printf("In: %d %d\n", row, col);
        explored[row][col] = true;
        if (board[row][col] == 'B')
            return cur;

        if (row > 0 && !explored[row-1][col] && board[row-1][col] != '#' )
        {
            Cell cell;
            auto pr1 = make_pair(row, col);
            cell.row = row - 1;
            cell.col = col;
            auto pr2 = make_pair(cell.row, cell.col);
            parent[pr2.first][pr2.second] = pr1;
            queue.push(cell);
            explored[cell.row][cell.col] = true;
        }
        if (row < r - 1 && !explored[row+1][col] && board[row+1][col] != '#' )
        {
            Cell cell;
            auto pr1 = make_pair(row, col);

            cell.row = row + 1;
            cell.col = col;
            auto pr2 = make_pair(cell.row, cell.col);
            parent[pr2.first][pr2.second] = pr1;

            queue.push(cell);
            explored[cell.row][cell.col] = true;
        }

        if (col > 0 && !explored[row][col-1] && board[row][col-1] != '#' )
        {
            Cell cell;
            auto pr1 = make_pair(row, col);

            cell.row = row;
            cell.col = col - 1;
            auto pr2 = make_pair(cell.row, cell.col);
            parent[pr2.first][pr2.second] = pr1;

            queue.push(cell);
            explored[cell.row][cell.col] = true;

        }
        if (col < c - 1 && !explored[row][col+1] && board[row][col+1] != '#' )
        {
            Cell cell;
            auto pr1 = make_pair(row, col);

            cell.row = row;
            cell.col = col + 1;
            auto pr2 = make_pair(cell.row, cell.col);
            parent[pr2.first][pr2.second] = pr1;

            queue.push(cell);
            explored[cell.row][cell.col] = true;

        }
    }
    Cell dummy = {-1, -1};
    return dummy;
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<string> board;
    for (int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        board.push_back(s);
    }
    // for(int i = 0; i < r; i++) {
    //     for(int j =0; j < c; j++) {
    //         cout << board[i][j];
    //     }
    //     cout << endl;
    // }
    Cell res = bfs(board,r,c);

    Cell startCell = findStart(board, r, c);
    if(res.row != -1) {
        cout << "YES\n";
        
        pair<int,int> start = make_pair(startCell.row, startCell.col);
        pair<int,int> end = make_pair(res.row,res.col);
        string ans = backtrace(start, end);
        cout << ans.size() << endl;
        cout << ans << endl;
    }
    else {
        cout << "NO\n";
    }
}
