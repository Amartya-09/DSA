class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + ","
             + serialize(root->left)  + ","
             + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        queue<string> tokens;
        stringstream ss(data);
        string token;

        while (getline(ss, token, ','))
            tokens.push(token);

        return build(tokens);
    }

private:
    TreeNode* build(queue<string>& tokens) {
        string val = tokens.front(); tokens.pop();

        if (val == "#") return nullptr;

        TreeNode* node = new TreeNode(stoi(val));
        node->left  = build(tokens);
        node->right = build(tokens);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));