//
// Created by 78540 on 2020/4/16.
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

class Solution {
public:
    //锯齿层次遍历(有点像穿线)
    //设置一个方向flag,每遍历一层就翻转
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return vector<vector<int>>();
        }
        stack<TreeNode*> curlevel;
        stack<TreeNode*> nextlevel;
        vector<vector<int>> res;
        bool flag = true;
        TreeNode* p = root;
        nextlevel.push(p);
        while (!nextlevel.empty()){
            //使用swap()清空队列
            swap(curlevel,nextlevel);
            vector<int> vec;
            while (!curlevel.empty()){
                p = curlevel.top();
                curlevel.pop();
                vec.push_back(p->val);
                if(flag){
                    if(p->left!=NULL){
                        nextlevel.push(p->left);
                    }
                    if(p->right!=NULL){
                        nextlevel.push(p->right);
                    }
                }else{
                    if(p->right!=NULL){
                        nextlevel.push(p->right);
                    }
                    if(p->left!=NULL){
                        nextlevel.push(p->left);
                    }
                }
            }

            flag = !flag;
            res.push_back(vec);
        }
        return res;
    }

};