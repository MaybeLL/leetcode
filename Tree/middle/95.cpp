//
// Created by 78540 on 2020/4/16.
//

#include <vector>
#include <stack>

using namespace std;


typedef struct TreeNode TreeNode;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
//    给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }

    vector<TreeNode*> helper(int left,int right){
        if(left>right){
            return vector<TreeNode*>();
        }
        if(left==right){
            TreeNode* node = new TreeNode(left);
            vector<TreeNode*> res;
            res.push_back(node);
            return res;
        } else{
            vector<TreeNode*> res;
            for(int i = left;i<=right;i++){
                vector<TreeNode*> tree;

                vector<TreeNode*> lefttree = helper(left,i-1);
                vector<TreeNode*> righttree = helper(i+1,right);
                if(!lefttree.empty()&&!righttree.empty()){
                    for(auto x:lefttree){
                        for(auto y :righttree){
                            TreeNode* rootnode = new TreeNode(i);
                            rootnode->left=x;
                            rootnode->right=y;
                            tree.push_back(rootnode);
                        }
                    }
                } else if (lefttree.empty()){
                    for(auto y :righttree){
                        TreeNode* rootnode = new TreeNode(i);
                        rootnode->right=y;
                        tree.push_back(rootnode);
                    }
                } else{
                    for(auto x:lefttree){
                        TreeNode* rootnode = new TreeNode(i);
                        rootnode->left=x;
                        tree.push_back(rootnode);
                    }
                }
                //拼接两个vector
                res.insert(res.end(),tree.begin(),tree.end());
            }
            return res;
        }
    }
};

