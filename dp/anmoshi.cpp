//
// Created by 78540 on 2020/3/18.
//

//一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。
// 在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。
// 给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。
//
//注意：本题相对原题稍作改动
//
//示例 1：
//
//输入： [1,2,3,1]
//输出： 4
//解释： 选择 1 号预约和 3 号预约，总时长 = 1 + 3 = 4。
//示例 2：
//
//输入： [2,7,9,3,1]
//输出： 12
//解释： 选择 1 号预约、 3 号预约和 5 号预约，总时长 = 2 + 9 + 1 = 12。

#include <vector>
using namespace std;

class Solution {
public:
    int massage(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        if(n==3){
            return max(nums[0]+nums[2],nums[1]);
        }else{
//            避免用vector
            int res1=nums[0];
            int res2=max(nums[0],nums[1]);
            int res3=max(nums[0]+nums[2],nums[1]);
            int res=0;
            for(int i = 4;i<n+1;i++){
                res = max(res3,res2+nums[i-1]);
                res2 = res3;
                res3 = res;
            }
            return res;
        }
    }
};