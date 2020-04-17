//
// Created by 78540 on 2020/4/16.
//

//按逆序数排序. 不改变原顺序,是稳定的.

#include <iostream>
#include  <string>
#include <stack>
#include <vector>

using namespace std;



typedef struct node node;
struct node{
    string s;
    int nixushu;
    node(){

    }
    node(string str){
        s = str;
        int res=0;

        for(int i =0;i<s.length();i++){
            if(s[i]==s[i+1]){
                continue;
            }
            for(int j =i+1;j<s.length();j++){
                if(s[i]>s[j]){
                    res++;
                }
            }

        }
        nixushu = res;
    }
};

void charu(vector<node> &ready,node _insert){
    bool flag = false;
    for(auto i =ready.begin();i!=ready.end();i++){
        if(_insert.nixushu<i->nixushu){
            ready.insert(i,_insert);
            flag = true;
            break;
        }
    }
    if(!flag){
        ready.push_back(_insert);
    }
}

//int main() {
//    int n,m;
//    vector<node> dna;
////    cout<<"请输入字符串长度n和个数m:";
//    cin>>n>>m;
////    cout<<endl<<"请输入字符串:"<<endl;
//    for(int i =0;i<m;i++){
//        string _insert;
//        cin>>_insert;
//        node _tmp= node(_insert);
//        charu(dna,_tmp);
//    }
//
//    for(auto x: dna){
//        cout<<x.s<<endl;
//    }
//    return 0;
//
//}
