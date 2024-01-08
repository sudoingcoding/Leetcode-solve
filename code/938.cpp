class Solution {
public:
    int sum = 0;

    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr)
            return 0;

        if (root->val >= low && root->val <= high) {
            sum += root->val;
            rangeSumBST(root->left, low, high);
            rangeSumBST(root->right, low, high);
        } else if (root->val < low) {
            rangeSumBST(root->right, low, high);
        } else if (root->val > high) {
            rangeSumBST(root->left, low, high);
        }
        return sum;
    }
};
