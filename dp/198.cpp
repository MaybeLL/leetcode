//
// Created by jixie on 2020/3/17.
//

//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//
//给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
//
//示例 1:
//
//输入: [1,2,3,1]
//输出: 4
//解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
//     偷窃到的最高金额 = 1 + 3 = 4 。
//示例 2:
//
//输入: [2,7,9,3,1]
//输出: 12
//解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
//     偷窃到的最高金额 = 2 + 9 + 1 = 12 。

#include  "iostream"
#include <vector>

using namespace std;

class Solution_198 {
//    1.dp数组 执行用时 :4 ms, 在所有 C++ 提交中击败了66.42%的用户
public:
    int rob(vector<int> &nums) {
        int len = nums.size();
        if (len <= 0) {
            return 0;
        } else if (len == 1) {
            return nums[0];
        } else if (len == 2) {
            return max(nums[0], nums[1]);
        } else if (len == 3) {
            return max(nums[0] + nums[2], nums[1]);
        } else {
            vector<int> res;
            res.push_back(nums[0]);
            res.push_back(max(nums[0], nums[1]));
            res.push_back(max(nums[0] + nums[2], nums[1]));
            for (int i = 3; i < len; i++) {
                res.push_back(max(res[i - 2] + nums[i], res[i - 1]));
            }
            return res[len - 1];
        }
    }
};