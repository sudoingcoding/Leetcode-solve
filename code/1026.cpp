class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return findDiff(root, root->val, root->val);
    }

    int findDiff(TreeNode* root, int minValue, int maxValue) {
        if (!root) {
            return maxValue - minValue;
        }

        minValue = min(minValue, root->val);
        maxValue = max(maxValue, root->val);

        int leftDiff = findDiff(root->left, minValue, maxValue);
        int rightDiff = findDiff(root->right, minValue, maxValue);

        return max(leftDiff, rightDiff);
    }
};
