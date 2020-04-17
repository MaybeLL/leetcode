//
// Created by 78540 on 2020/4/14.
//
#include <vector>
#include <string>
using namespace std;

//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//
//};

//257.给定一个二叉树，返回所有从根节点到叶子节点的路径。["1->2->5", "1->3"]
//栈溢出
//class Solution {
//public:
//    vector<string> binaryTreePaths(TreeNode* root) {
//        vector<vector<int>> tmp = path_int(root);
//        if(tmp.empty()){
//            return vector<string>();
//        }
//        vector<string> res;
//        for(auto i = tmp.begin();i!=tmp.end();i++){
//            //每条路径转换为string
//            string _s;
//            for(auto j = i->begin();j!=i->end();j++){
//                //迭代器如何判断末尾
//                if(j==i->end()-1){
//                    _s+=to_string(*j);
//                } else{
//                    _s+=to_string(*j);
//                    _s+="->";
//                }
//            }
//            res.push_back(_s);
//        }
//        return res;
//    }
//
//    vector<vector<int>> path_int(TreeNode* root){
//        if(root==NULL){
//            return vector<vector<int>>();
//        }
//        if(root->left==NULL&&root->right==NULL){
//            vector<vector<int>> res = {{root->val}};
//            return res;
//        }
//        if(root->left!=NULL&&root->right!=NULL){
//            vector<vector<int>> res;
//            vector<vector<int>> left = path_int(root->left);
//            vector<vector<int>> right = path_int(root->right);
//
//            for(auto i =left.begin();i!=left.end();i++){
//                vector<int> lefttmp;
//                lefttmp.insert(lefttmp.end(), root->val);
//                lefttmp.insert(lefttmp.end(), *i->begin(), *i->end());
//                res.push_back(lefttmp);
//            }
//            for(auto j =right.begin();j!=right.end();j++){
//                vector<int> righttmp;
//                righttmp.insert(righttmp.end(), root->val);
//                righttmp.insert(righttmp.end(), *j->begin(), *j->end());
//                res.push_back(righttmp);
//            }
//            return res;
//        }
//        if(root->left!=NULL){
//            vector<vector<int>> res;
//            vector<vector<int>> left = path_int(root->left);
//
//            for(auto i =left.begin();i!=left.end();i++){
//                vector<int> lefttmp;
//                lefttmp.insert(lefttmp.end(), root->val);
//                lefttmp.insert(lefttmp.end(), *i->begin(), *i->end());
//                res.push_back(lefttmp);
//            }
//
//            return res;
//        }else{
//            vector<vector<int>> res;
//            vector<vector<int>> right = path_int(root->right);
//
//            for(auto j =right.begin();j!=right.end();j++){
//                vector<int> righttmp;
//                righttmp.insert(righttmp.end(), root->val);
//                righttmp.insert(righttmp.end(), *j->begin(), *j->end());
//                res.push_back(righttmp);
//            }
//            return res;
//        }
//
//    }
//
//};

//
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> tmp = path_int(root);
        if(tmp.empty()){
            return vector<string>();
        }
        vector<string> res;
        for(auto i = tmp.begin();i!=tmp.end();i++){
            //每条路径转换为string
            string _s;
            for(auto j = i->begin();j!=i->end();j++){
                //迭代器如何判断末尾
                if(j==i->end()-1){
                    _s+=to_string(*j);
                } else{
                    _s+=to_string(*j);
                    _s+="->";
                }
            }
            res.push_back(_s);
        }
        return res;
    }


    }

};