//
// Created by 78540 on 2020/4/17.
//

//找到小镇的法官
//在一个小镇里，按从 1 到 N 标记了 N 个人。传言称，这些人中有一个是小镇上的秘密法官。
//
//如果小镇的法官真的存在，那么：
//
//小镇的法官不相信任何人。
//每个人（除了小镇法官外）都信任小镇的法官。
//只有一个人同时满足属性 1 和属性 2 。
//给定数组 trust，该数组由信任对 trust[i] = [a, b] 组成，表示标记为 a 的人信任标记为 b 的人。
//
//如果小镇存在秘密法官并且可以确定他的身份，请返回该法官的标记。否则，返回 -1。

#include <vector>
using namespace std;

class Solution {
public:
    //遍历找对于每个人,遍历trust数组,对信任他的人计数,为N-1则返回这个人.  O(n3)
    //超时
//    int findJudge(int N, vector<vector<int>>& trust) {
//        for(int i =1;i<N+1;i++){
//            int jishuqi =0;
//            bool no_trust_other = true;
//            for(auto t:trust){
//                if(t[1]==i){
//                    jishuqi++;
//                }
//                if(t[0]==i){
//                    no_trust_other = false;
//                    break;
//                }
//            }
//            if(jishuqi==N-1&&no_trust_other){
//                return i;
//            }
//        }
//        return -1;
//    }
    //对出度入度计数:法官是这样一个点：出度为0，并且入度为N-1.
//    int findJudge(int N, vector<vector<int>>& trust){
//        vector<bool> trust_other(N+1, false);
//        vector<int> counter(N+1, 0);
//        for(auto t:trust){
//            trust_other[t[0]] = true;
//            counter[t[1]]++;
//        }
//        for(int i = 1;i<=N;i++){
//            if(counter[i]==N-1&&!trust_other[i]){
//                return i;
//            }
//        }
//        return -1;
//    }

    //review:对信任积分:被信任+1分,信任别人-1分
    //信任分上限就是N-1,即其他人都信任他,他不信任他人
    //一旦信任他人,信任分的上限就达不到N-1了
    //所以法官就是信任分为N-1的人
    //auto会影响速度
    int findJudge(int N, vector<vector<int>>& trust){
        vector<int> trust_gain(N+1, 0);
        for(auto t:trust){
            trust_gain[t[0]]--;
            trust_gain[t[1]]++;
        }
        for(int i = 1;i<=N;i++){
            if(trust_gain[i]==N-1){
                return i;
            }
        }
        return -1;
    }
};