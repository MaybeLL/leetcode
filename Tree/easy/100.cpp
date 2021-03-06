//
// Created by 78540 on 2020/4/14.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /**
给定两个二叉树，编写一个函数来检验它们是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
*/

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//
// };
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p!=NULL&&q!=NULL){
            return (p->val==q->val)&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
        } else if (p==NULL&&q==NULL){
            return true;
        } else{
            return false;
        }
    }
};
