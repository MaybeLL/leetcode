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
    //二叉树是否对称
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return isMirror(root->left,root->right);
    }
    //两棵树是否镜像对称
    bool isMirror(TreeNode* p,TreeNode* q){
        if(p==NULL&&q==NULL){
            return true;
        }
        if(p!=NULL&&q!=NULL){
            return (p->val==q->val)&&isMirror(p->left,q->right)&&isMirror(p->right,q->left);
        }
        return false;
    }
};
