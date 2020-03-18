//
// Created by 78540 on 2020/3/18.
//
#include <vector>
#include <iostream>
using namespace std;

//要求返回数组：设置双工作指针
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxsum=nums[0];
        int pleft=0,left = 0,right=0;
        for(int i = 0;i<nums.size();i++){
            if(sum<=0){
                sum=nums[i];
                pleft = i;
                if(sum>maxsum){
                    maxsum = sum;
                }
            }else{
                sum +=nums[i];
                if (sum>maxsum){
                    maxsum = sum;
                    right = i;
                    left = pleft;
                }
            }
        }
        cout<<left<<","<<right<<endl;
        return maxsum;
    }
};