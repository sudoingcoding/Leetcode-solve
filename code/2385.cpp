class Solution {
public:
    void parentList(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*>& parentNode,
                    TreeNode* parent = NULL) {
        if (!root)
            return;
        parentNode[root] = parent;
        parent = root;
        parentList(root->left, parentNode, parent);
        parentList(root->right, parentNode, parent);
    }

    TreeNode* findStart(TreeNode* root, int start) {
        if (!root)
            return NULL;
        if (root->val == start)
            return root;
        TreeNode* left = findStart(root->left, start);
        if (left)
            return left;
        TreeNode* right = findStart(root->right, start);
        if (right)
            return right;
        return NULL;
    }
    int srtInfect(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentNode){
        map<TreeNode*, bool> visited;
        queue<TreeNode*>q;
        int time=0;
        visited[root]=true;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            bool flag=false;
            for(int i=0;i<s;i++){
                TreeNode* front=q.front();
                q.pop();
                if(front->left && visited[front->left]==false){
                    q.push(front->left);
                    visited[front->left]=true;
                    flag=true;
                }
                if(front->right && visited[front->right]==false){
                    q.push(front->right);
                    visited[front->right]=true;
                    flag=true;
                }

                if(parentNode[front] && visited[parentNode[front]]==false) {
                    q.push(parentNode[front]);
                    visited[parentNode[front]]=true;
                    flag=true;
                }
            }
            if(flag) time++;
        }
        return time;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parentNode;
        parentList(root, parentNode);
        TreeNode* target = findStart(root,start);
        int time = srtInfect(target, parentNode);
        return time;
    }
};
