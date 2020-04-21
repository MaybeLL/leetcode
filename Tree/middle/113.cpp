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
    //根和左右子树的拼接
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur_path;
        helper(root,res,cur_path,sum);
        return res;
    }

    void helper(TreeNode* cur,vector<vector<int>> &res,vector<int> cur_path,int cur_sum){
        if(!cur){
            return;
        }
        if(!cur->left&&!cur->right){
            if(cur->val==cur_sum){
                cur_path.push_back(cur_sum);
                res.push_back(cur_path);
            }
            return;
        }
        cur_path.push_back(cur->val);
        //
        if(cur->left){
            helper(cur->left,res,cur_path,cur_sum-cur->val);
        }
        if(cur->right){
            helper(cur->right,res,cur_path,cur_sum-cur->val);
        }
    }
};
//class Solution {
//public:
//    vector<vector<int>> pathSum(TreeNode* root, int sum) {
//        vector<vector<int>> vec1;
//        vector<int>vec2;
//        solve(root,vec1,vec2,sum);
//        return vec1;
//    }
//    void solve(TreeNode *root,vector<vector<int>> &total,vector<int>thisTotal,int sum)
//    {
//        if(!root)
//            return;
//        sum-=root->val;
//        thisTotal.push_back(root->val);
//        if(!root->left&&!root->right&&sum==0)
//            total.push_back(thisTotal);
//        solve(root->left,total,thisTotal,sum);
//        solve(root->right,total,thisTotal,sum);
//    }
//};


