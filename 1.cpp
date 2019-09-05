//题目：一个字符串S和一组单词dict，S是否可以被空格分割成一个单词序列，使得单词中所有的单词都是dict中的单词。
//eg：S=“leetcode”  dict={"leet","code"}
//返回True

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;
class Solution{
    public:
        bool worldBreak(string s,unordered_set<string> dict){
            int len = s.size();
            bool* dp = new bool[len+1];
            dp[0] = true;
            for(int pos=0;pos<=len;pos++){
                for(int i=0;dp[pos]&&i<len;i++){
                    if(dict.find(s.substr(pos,i-pos+1))!=dict.end()){
                        dp[i+1] = true;
                    }
                }
            }
            return dp[len];
        }

};



int main(){
	
    cout<<"hello world"<<endl;


}