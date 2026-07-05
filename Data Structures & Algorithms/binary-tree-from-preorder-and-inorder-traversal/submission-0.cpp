/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& preIdx,
    int instart, int inend, map<int,int>& inMap){
        if(preorder.size()<=preIdx || instart > inend) return NULL;

        int curr = preorder[preIdx];
        preIdx++;
        TreeNode* root = new TreeNode(curr);

        int inIdx = inMap[curr];
        root->left = solve(preorder,inorder,preIdx,instart,inIdx-1,inMap);
        root->right = solve(preorder,inorder,preIdx,inIdx+1,inend,inMap);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inMap;
        int n = inorder.size();
        for(int i=0; i<n; i++){
            inMap[inorder[i]] = i;
        }
        int preIdx=0;
        return solve(preorder,inorder,preIdx,0,n-1,inMap);
    }
};
