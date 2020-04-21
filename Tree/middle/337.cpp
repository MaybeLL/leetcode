//
// Created by 78540 on 2020/4/20.
//

//在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。
// 这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。
// 一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。
// 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
//
//计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

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
    //只要不相连就可以，并且应该盗。
    //考虑子树根一定要盗。
    //难点在于对于当前树取到最大财物的选择下，无法确定当前根节点盗没盗
    int rob(TreeNode* root) {
        if(!root){
            return 0;
        }
        int res = root->val;

    }

    //牛逼解法
//    class Solution {
//    public:
//        int rob(TreeNode* root) {
//            if(!root) return 0;
//            vector<int> res=robMax(root);
//            return max(res[0],res[1]);
//        }
//        vector<int> robMax(TreeNode* root){
//            if(!root) return vector<int>(2,0);
//            vector<int> left=robMax(root->left);
//            vector<int> right=robMax(root->right);
//            vector<int> res(2,0);
//            res[0]=max(left[0],left[1])+max(right[0],right[1]);
//            res[1]=left[0]+right[0]+root->val;
//            return res;
//        }
//    };

};
