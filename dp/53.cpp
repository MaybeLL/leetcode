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
public:
    int maxSubArray(std::vector<int>& nums) {

        int res=*nums.begin();
        for(std::vector<int>::iterator i=nums.begin();i<nums.end();i++)
        {
            int imax=*i;
            for(std::vector<int>::iterator j=nums.end()-1;j>i;j--)
            {
                if (sum(nums,i,j)>imax)
                {
                    imax = sum(nums,i,j);
                }
            }
            if (imax>res)
            {
                res=imax;
            }
        }
        return res;
    }

//    int maxSubArray2(std::vector<int>& nums)
//    {
//        int res;
//        std::vector<std::vector<int>::iterator> idx = {};
//        for(std::vector<int>::iterator i=nums.begin();i<nums.end();i++){
//            if(*i>=0)
//            {
//                idx.push_back(i);
//            }
//        }
//
//        //全负
//        if(idx.empty())
//        {
//            //返回最大元素（）负数
//            for(std::vector<int>::iterator i=nums.begin();i<nums.end();i++)
//            {
//                if(*i>res)
//                {
//                    res=*i;
//                }
//            }
//            return res;
//        }
//    }
private:
//public:
    int sum(std::vector<int>& nums,std::vector<int>::iterator left,std::vector<int>::iterator right){
        int sum=0;
        for(std::vector<int>::iterator it=left;it<=right;it++)
        {
            sum+=*it;
        }
        return sum;
    }
};


