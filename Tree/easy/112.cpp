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
    //找节点类型，搜索类型
    //给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
    //说明: 叶子节点是指没有子节点的节点。
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return false;
        }
        if(root->left==NULL&&root->right==NULL){
            return (root->val==sum);
        }
        return (hasPathSum(root->left,sum-root->val))||(hasPathSum(root->right,sum-root->val));
    }
};