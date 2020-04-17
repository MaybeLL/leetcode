//
// Created by 78540 on 2020/4/15.
//

#include <vector>
#include <stack>
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
    //找众数。孩子可以等于父
    vector<int> findMode(TreeNode* root) {
        TreeNode* cur_p = root;
        stack<TreeNode*> mystack;
        int last;
        int cur;
        int maxnum;
        bool flag= true;
        vector<int> res;
        while (cur_p!=NULL||!mystack.empty()){
            while (cur_p!=NULL){
                mystack.push(cur_p);
                cur_p = cur_p->left;
            }
            cur_p = mystack.top();
            mystack.pop();
            //出栈使用
            if(flag){
                last = cur_p->val;
                cur = 0;
                maxnum = 0;
                flag = false;
            }

            if(cur_p->val==last){
                cur++;
                if(cur==maxnum){
                    res.push_back(cur_p->val);
                }else if(cur>maxnum){
                    maxnum = cur;
                    res.clear();
                    res.push_back(cur_p->val);
                }

            } else{
                cur = 1;
                if(maxnum==1){
                    res.push_back(cur_p->val);
                }
                last = cur_p->val;
            }

            //转向
            cur_p = cur_p->right;
        }
        return res;
    }
};