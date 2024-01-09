class Solution {
public:
    void leafCheck(TreeNode* root, vector<int>& v) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            v.push_back(root->val);
            return;
        }
        leafCheck(root->left, v);
        leafCheck(root->right, v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2;
        leafCheck(root1, l1);
        leafCheck(root2, l2);
        if (l1.size() != l2.size()) {
            return false;
        }
        for (int i = 0; i < l1.size(); i++) {
            if (l1[i] != l2[i]) {
                return false;
            }
        }
        return true;
    }
};
