//
// Created by 78540 on 2020/4/14.
//

#include <vector>
#include <queue>
using namespace std;

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
    //给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
    //思路：先正常层次遍历，再把数组倒序。层次遍历需要队列。
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        //遍历每层，得到一个vector<int> ,插入到 vector<vector<int>>
        if(root==NULL){
            vector<vector<int>> res;
            return res;
        }
        TreeNode* p = root;
        queue<TreeNode*> nextLevelqueue;
        nextLevelqueue.push(p);
        vector<vector<int>> top2bottom;
        while(!nextLevelqueue.empty()){
            queue<TreeNode*> cur_queue;
//            cur_queue = nextLevelqueue;
//            nextLevelqueue.clear();
            swap(cur_queue,nextLevelqueue);
            vector<int> level;
            while (!cur_queue.empty()){
                p = cur_queue.front();
                cur_queue.pop();
                level.push_back(p->val);
                if(p->left!=NULL){
                    nextLevelqueue.push(p->left);
                }
                if(p->right!=NULL){
                    nextLevelqueue.push(p->right);
                }
            }
            top2bottom.push_back(level);
        }

        vector<vector<int>> res;
        vector<vector<int>>::iterator it;
        for(auto it=top2bottom.rbegin();it!=top2bottom.rend();it++){
            res.push_back(*it);
        }
        return res;
    }
};

