//
// Created by maybell on 2019/12/24.
//
//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//
//示例:
//
//输入: [-2,1,-3,4,-1,2,1,-5,4],
//输出: 6
//解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
//


//test:
//[1]:
// input: 正数
//output:全部

//分析：
//  ①具有最大和的连续子数组具有规律：任意的二划分，左右部分都大于等于0.
//  ②头尾元素大于等于0

//
#include "iostream"
#include <vector>
//using namespace std;

class Solution_53 {
//    1.暴力法
//public:
//    int maxSubArray(std::vector<int> &nums) {
//        int res = *nums.begin();
//        for (std::vector<int>::iterator i = nums.begin(); i < nums.end(); i++) {
//            int imax = 0;
//            for (std::vector<int>::iterator j = i; j < nums.end(); j++) {
//                imax += *j;
//                if (imax > res) {
//                    res = imax;
//                }
//            }
//        }
//        return res;
//    }

//  2.dp
//public:
//    int maxSubArray(std::vector<int> &nums) {
//        int sum = 0;
//        int ans = nums[0];
//        for(int i =0;i < nums.size();i++)
//        {
//            if(sum<=0)
//            {
//                sum = nums[i];
//                ans = (((ans) > (sum)) ? (ans) : (sum));
//            }
//            else
//            {
//                sum+=nums[i];
//                ans = ((ans) > (sum)) ? (ans) : (sum);
//            }
//        }
//        return ans;
//    }

//  3.分治法
//public:
//    int maxSubArray(std::vector<int> &nums) {
//
//        return ;
//    }
};





