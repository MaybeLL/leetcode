//
// Created by jixie on 2020/3/16.
//

//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//
//如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
//
//注意你不能在买入股票前卖出股票。
//
//示例 1:
//
//输入: [7,1,5,3,6,4]
//输出: 5
//解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
//示例 2:
//
//输入: [7,6,4,3,1]
//输出: 0
//解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。


#include  "iostream"
#include <vector>

using namespace std;

class Solution_121 {


//1.递归法  执行用时 :16 ms 在所有 C++ 提交中击败了28.98%的用户.
//递归方程和归并排序一样,根据主定理,时间复杂度O(nlogn)

//public:
//    int maxProfit(vector<int>& prices) {
//        int low=0;
//        int high=prices.size()-1;
//        cout<<high<<endl;
//        return getres(prices,low,high);
//    }
//
//public:
//
//    int getres(vector<int>& prices,int left,int right){
////        递归出口
//        if(left+1 == right){
//            return max(prices[right] - prices[left], 0);
//        } else if (left+1 > right){
//            return 0;
//        } else{
//            int mid = (left+right)/2;
//            int leftres = getres(prices,left,mid);
//            int rightres = getres(prices,mid+1,right);
//            int mid_res = midres(prices,left,right);
//            return max(max(leftres,mid_res),rightres);
//        }
//    }
//
//public:
//    int midres(vector<int>& prices,int low,int high){
////        找左边最小值
//        int mid = (low+high)/2;
//        int min = prices[low];
//        int maxnum = prices[high];
//        for (int i = low;i<=mid;i++){
//            if(prices[i]<min){
//                min = prices[i];
//            }
//        }
//        for (int i = mid+1;i <=high;i++){
//            if(prices[i] > maxnum){
//                maxnum = prices[i];
//            }
//        }
//        return max(maxnum - min, 0);
//    }

//-----------------------------------------------------------------------
//2.特殊方法  维护股票低价
//public:
//    int maxProfit(vector<int>& prices) {
//        int profit=0;
//        if(prices.size()!=0){
//            int minprice = prices[0];
//            for (int i=0;i<prices.size();i++){
//                profit = max(prices[i]-minprice,profit);
//                minprice = min(minprice,prices[i]);
//            }
//        }
//        return profit;
//    }

//    3.股票交易

};
