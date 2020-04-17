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
    //层序遍历
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return vector<vector<int>>();
        }
        queue<TreeNode*> curlevel;
        queue<TreeNode*> nextlevel;
        vector<vector<int>> res;
        TreeNode* p = root;
        nextlevel.push(p);
        while (!nextlevel.empty()){
            //使用swap()清空队列
            swap(curlevel,nextlevel);
            vector<int> vec;
            while (!curlevel.empty()){
                p = curlevel.front();
                curlevel.pop();
                vec.push_back(p->val);
                if(p->left!=NULL){
                    nextlevel.push(p->left);
                }
                if(p->right!=NULL){
                    nextlevel.push(p->right);
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};
