//
// Created by 78540 on 2020/4/14.
//

//给定一个二叉树，找出其最小深度。
//
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

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
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(root->left!=NULL&&root->right!=NULL){
            return min(minDepth(root->left),minDepth(root->right))+1;
        }
        if(root->left==NULL&&root->right==NULL){
            return 1;
        }
        if(root->left==NULL){
            return minDepth(root->right)+1;
        } else{
            return minDepth(root->left)+1;
        }
    }
};