//
// Created by 78540 on 2020/4/20.
//
#include <vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};
// todo:最近公共祖先
class Solution {
public:
    //236. 二叉树的最近公共祖先
    //235.二叉搜索树的最近公共祖先
    //最近公共祖先特征：一定能把p，q节点分在左右子树
    //如果左边能查询到节点，右边查询不到，则在返回左边的
    //如果左右都能查询到子节点则
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //递归出口:查询到p，q任一节点
        if(!root||root ==p||root==q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left&&right){
            return root;
        }
        //若不是在左右子树，则都在左或都在右。
        return left ? left : right;
    }
};