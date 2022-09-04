/*
https://leetcode.com/problems/univalued-binary-tree/
Google-easy
A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.
*/
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        
        bool res= isUnivalTree(root->right) && root->right->val==root->val;
        if(res)
            res=res && isUnivalTree(root->left) && root->left->val==root->val;
        
        return res;
    }
};