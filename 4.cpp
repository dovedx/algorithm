//题目：对矩阵的旋转90度

#include <iostream>
#include<vector>

using namespace std;
int main(){
    int m;
    cin>>m;

    vector<vector<int> >array(m,vector<int>(m));
     vector<vector<int> >array_T(m,vector<int>(m));
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>array[i][j];
        }
    }

    
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            array_T[j][m-i-1] = array[i][j];
            //cout<<array_T[j][m-i]<<" ";
        }
    }
    cout <<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<array_T[i][j]<<" ";
        }

        cout<<endl;
    }

}