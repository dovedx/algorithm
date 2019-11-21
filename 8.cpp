#include<string>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int dp_stone(vector<int> piles){
    int n = piles.size();
    
    vector<vector<vector<int > > >dp(n);
    for(int i=0;i<n;++i){
        dp[i].resize(n);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j].resize(2);
            dp[i][j][0]=0;
            dp[i][j][1]=0;
        }
        
    }
    cout<<"n:"<<n<<endl;
    
    cout<<"step 1"<<endl;
    //沿对角线遍历矩阵初始化base状态
    for(int i=0;i<n;i++){
        dp[i][i][0]= piles[i];
        dp[i][i][1]=  0;
    }
    for(int l=2;l<=n;l++){
        for(int i=0;i<=n-l;i++){
            int j = l+i-1;
            int left = piles[i]+dp[i+1][j][1];
            int right= piles[j]+dp[i][j-1][1];
            cout<<right<<":"<<left<<endl;
            dp[i][j][0] = max(left,right );
            cout<<"dp[i][j][0]"<<dp[i][j][0]<<endl;
            if(left>right){
                dp[i][j][1]= dp[i+1][j][0];
            }
            else{
                dp[i][j][1] = dp[i][j-1][0];
            }

        }
    }
    cout<<dp[0][3][0]<<"..."<<dp[0][3][1]<<endl;
    int result = dp[0][3][0] - dp[0][3][1];
    return result;
}

int main(){
    vector<int >piles(4);
    int a[]={3,9,1,2};
    for(int i=0;i<4;i++){
        piles[i]=a[i];
    }
    int result = dp_stone(piles);
    cout << "result:"<<result<<endl;
    cout<<"..."<<endl;
}