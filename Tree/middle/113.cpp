//
// Created by 78540 on 2020/4/16.
//

//给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
//
//说明: 叶子节点是指没有子节点的节点。

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

//很牛逼的思路
//递归函数尽量写成无返回值,采用传引用方式,来避免返回值

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> vec1;
        vector<int>vec2;
        solve(root,vec1,vec2,sum);
        return vec1;
    }
    void solve(TreeNode *root,vector<vector<int>> &total,vector<int>thisTotal,int sum)
    {
        if(!root)
            return;
        sum-=root->val;
        thisTotal.push_back(root->val);
        if(!root->left&&!root->right&&sum==0)
            total.push_back(thisTotal);
        solve(root->left,total,thisTotal,sum);
        solve(root->right,total,thisTotal,sum);
    }
};


//class Solution {
//public:
//    //根和左右子树的拼接
//    vector<vector<int>> pathSum(TreeNode* root, int sum) {
//        if(root==NULL){
//            vector<vector<int>> res;
//            return res;
//        }
//        if(root->left==NULL&&root->right==NULL){
//            if(root->val==sum){
//                vector<int> tmp(sum);
//                vector<vector<int>> res;
//                res.push_back(tmp);
//                return res;
//            } else{
//                vector<vector<int>> res;
//                return res;
//            }
//        }
//
//        vector<vector<int>> res;
//        if(root->left!=NULL){
//            vector<vector<int>> leftpaths = pathSum(root->left,sum-root->val);
//            for(auto leftpath:leftpaths){
//                vector<int> r(root->val);
//                r.insert(r.end(),leftpath.begin(),leftpath.end());
//                res.push_back(r);
//            }
//        }
//        if(root->right!=NULL){
//            vector<vector<int>> rightpaths = pathSum(root->right,sum-root->val);
//            for(auto rightpath:rightpaths){
//                vector<int> r(root->val);
//                r.insert(r.end(),rightpath.begin(),rightpath.end());
//                res.push_back(r);
//            }
//        }
//
//        return res;
//    }
//};