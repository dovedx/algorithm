

//题目：求数组中，任意连续数串相乘,得到的最大的积。

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int multi_max(vector<int>& array){
    int len = array.size();
    vector<int> max_dp(len,0);
    vector<int> min_dp(len,0);

    max_dp[0] = array[0];
    min_dp[0] = array[0];
    int max_value = max_dp[0];
    for(int i=1;i<len;i++){
        max_dp[i] = max(max(max_dp[i-1]*array[i],min_dp[i-1]*array[i]),array[i]);
        min_dp[i] = min(max(max_dp[i-1]*array[i],min_dp[i-1]*array[i]),array[i]);
        if(max_dp[i] >max_value ){
            max_value = max_dp[i];
        }
    }
    return max_value;



}