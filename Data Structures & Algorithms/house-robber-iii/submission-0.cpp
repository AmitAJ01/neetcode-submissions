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
    int solve(TreeNode* root){
        if(!root) return 0;

        int res = root->val;
        if(root->left){
            res += solve(root->left->left) + solve(root->left->right);
        }
        if(root->right){
            res += solve(root->right->left) + solve(root->right->right);
        }

        return max(res, solve(root->left) + solve(root->right));
    }
    pair<int,int> robr(TreeNode* root){
        if(!root) return {0,0};

        auto leftpair = robr(root->left);
        auto rightpair = robr(root->right);

        int withRoot = root->val + leftpair.second + rightpair.second;
        int without = max(leftpair.first, leftpair.second) + 
                    max(rightpair.first, rightpair.second);

        return {withRoot, without};
    }
    int rob(TreeNode* root) {
        // return solve(root);
        auto ans = robr(root);
        return max(ans.first, ans.second);

    }
};