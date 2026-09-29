class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, array<bool, 9>> rows;
        unordered_map<int, array<bool, 9>> cols;

        unordered_map<int, array<bool, 9>> box;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int num = board[i][j] - '0';
                int box_index = ((i / 3) * 3) + (j / 3);

                if (rows[i][num-1] || cols[j][num-1] || box[box_index][num-1]) return false;

                rows[i][num-1] = cols[j][num-1] = true;
                box[box_index][num-1] = true;
            }
        }

        return true;
    }
};
