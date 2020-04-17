//
// Created by 78540 on 2020/4/14.
//

//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//
//};

class Solution {
public:
    //翻转一个二叉树
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }

        TreeNode* tmp =root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};