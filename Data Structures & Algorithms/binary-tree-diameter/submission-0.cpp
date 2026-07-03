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
    int depth(TreeNode* root){
        if(!root) return 0;

        int op1 = depth(root->left);
        int op2 = depth(root->right);
        return 1+max(op1,op2);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);
        int op3 = depth(root->left) + depth(root->right);

        return max(op1, max(op2,op3));
    }
};
