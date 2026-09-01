class Solution {
    struct TrieNode {
        TrieNode* children[26] = {};
        string word = "";  
    };

    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& w : words) {
            TrieNode* cur = root;
            for (char c : w) {
                int i = c - 'a';
                if (!cur->children[i])
                    cur->children[i] = new TrieNode();
                cur = cur->children[i];
            }
            cur->word = w;  
        }
        return root;
    }

    void dfs(vector<vector<char>>& board, int r, int c,
             TrieNode* node, vector<string>& result) {
        int m = board.size(), n = board[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n) return;

        char ch = board[r][c];
        if (ch == '#') return;                    
        if (!node->children[ch - 'a']) return;    

        TrieNode* next = node->children[ch - 'a'];

        if (!next->word.empty()) {
            result.push_back(next->word);
            next->word = "";  
        }

        board[r][c] = '#';  

        dfs(board, r+1, c, next, result);
        dfs(board, r-1, c, next, result);
        dfs(board, r, c+1, next, result);
        dfs(board, r, c-1, next, result);

        board[r][c] = ch;   
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<string> result;
        int m = board.size(), n = board[0].size();

        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                dfs(board, r, c, root, result);

        return result;
    }
};