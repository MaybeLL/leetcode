//
// Created by 78540 on 2020/4/16.
//

#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* cur_p = root;
        stack<TreeNode*> mystack;
        vector<int> res;
        while(cur_p!=NULL||!mystack.empty()){
            while(cur_p!=NULL){
                mystack.push(cur_p);
                cur_p = cur_p->left;
            }
            cur_p = mystack.top();
            mystack.pop();
            res.push_back(cur_p->val);
            cur_p = cur_p->right;
        }
        return res;
    }
};