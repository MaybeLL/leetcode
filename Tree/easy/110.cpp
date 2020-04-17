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

using namespace std;

class Solution {
public:
    //左右子树高度差不大于1
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        bool r = (treeheight(root->left)-treeheight(root->right)>=-1)&&(treeheight(root->left)-treeheight(root->right)<=1);
        return (r)&&isBalanced(root->left)&&isBalanced(root->right);
    }

    int treeheight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return max(treeheight(root->left),treeheight(root->right))+1;
    }
};

