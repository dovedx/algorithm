//1-A
//2-B


#include<string>
#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        int DP(string str){
                int length = str.size();
                if(str[0]=='0'){
                    return 0;
                }
                vector<int>dp(length+1,0);
                dp[0]=1;
                dp[1]=1;

                for(int i=2;i<length+1;i++){
                    if(str[i-1]!='0'){
                        
                        dp[i] +=dp[i-1];
                    }
                    if( (str[i-2]=='1'||str[i-2]=='2')&& (str[i-1]<='6') ){

                        dp[i] += dp[i-2];
                    }
                    
                }
                return dp[length];
            
        }
};

int main(){

    string str="123126";
    Solution* A = new Solution();
    int result = A->DP(str);

    cout<<result<<endl;
    return 0;
}




