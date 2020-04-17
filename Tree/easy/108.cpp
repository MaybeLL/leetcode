//
// Created by 78540 on 2020/4/14.
//

#include <vector>
using namespace std;

//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//
//};

//报错stack_overflow
//class Solution {
//public:
//    //将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
//    //本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
//    //对于有序数组，其中间节点是平衡二叉树的根。根据这点
//    TreeNode* sortedArrayToBST(vector<int>& nums) {
//        TreeNode* root=helper(nums,0,nums.size()-1);
//        return root;
//    }
//    TreeNode* helper(vector<int>& nums,int left,int right) {
//        if(left==right){
//            return NULL;
//        }
//        int mid = (left+right)/2;
//        TreeNode* root = new TreeNode(nums[mid]);
//        root->left = helper(nums,left,mid-1);
//        root->right= helper(nums,mid+1,right);
//        return root;
//    }
//};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        int mid = nums.size()/2;
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> left_nums, right_nums;
        for(int i=0; i<mid; i++){
            left_nums.push_back(nums[i]);
        }
        for(int j=mid+1; j<nums.size(); j++){
            right_nums.push_back(nums[j]);
        }
        root->left = sortedArrayToBST(left_nums);
        root->right = sortedArrayToBST(right_nums);
        return root;
    }
};

