class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;

        while (cur) {
            if (cur->left) {

                TreeNode* rightmost = cur->left;
                while (rightmost->right)
                    rightmost = rightmost->right;

                rightmost->right = cur->right;

                cur->right = cur->left;
                cur->left  = nullptr;
            }
            cur = cur->right;
        }
    }
};