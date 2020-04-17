//
// Created by 78540 on 2020/4/14.
//
//计算给定二叉树的所有左叶子之和。
//
//示例：
//
//3
/// \
//  9  20
///  \
//   15   7
//
//在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    //计算左叶子之和。左叶子的特点：父节点的右指针为null. 遍历树，找左叶子。
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
            return 0;
        } else if (isleaves(root->left)){
            return root->left->val+sumOfLeftLeaves(root->right);
        }
        else{
            return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
        }

    }

    bool isleaves(TreeNode* root){
        if(root!=NULL&&root->left==NULL&&root->right==NULL){
            return true;
        } else{
            return false;
        }
    }
};

