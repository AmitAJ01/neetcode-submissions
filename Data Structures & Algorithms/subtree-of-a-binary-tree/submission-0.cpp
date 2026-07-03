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
    
    bool compare(TreeNode* a, TreeNode* b){
        if(!a && !b) return true;
        if((!a && b) || (a && !b)) return false;
        if(a->val != b->val) return false;

        bool left = compare(a->left, b->left);
        bool right = compare(a->right, b->right);
        return left && right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> s;
        if(root) s.push(root);
        bool ans = false;
        while(!s.empty()){
            TreeNode* curr=s.top();
            s.pop();
            if(curr->val==subRoot->val) ans = ans || compare(curr, subRoot);

            if(curr->right) s.push(curr->right);
            if(curr->left) s.push(curr->left);
        } 
        return ans;
    }
};