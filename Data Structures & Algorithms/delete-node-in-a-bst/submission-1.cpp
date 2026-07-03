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
    TreeNode* findRmost(TreeNode* root){
        while(root->right) root=root->right;
        return root;
    }
    TreeNode* remove(TreeNode* root){
        if(!root->left) return root->right;
        else if(!root->right) return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* leftsRightmostChild = findRmost(root->left);

        leftsRightmostChild->right = rightChild;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val==key) return remove(root);

        TreeNode* temp = root;
        while(temp){
            if(temp->val > key){
                if(temp->left && temp->left->val==key){
                    temp->left = remove(temp->left);
                    break;
                }
                else temp = temp->left;
            }
            else{
                if(temp->right && temp->right->val == key){
                    temp->right = remove(temp->right);
                    break;
                }
                else temp=temp->right;
            }
        }
        return root;
    }
};