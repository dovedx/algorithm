//题目：螺旋打印矩阵-1
//...
//1  2  3  4 
//12 13 14 5 
//11 16 15 6 
//10 9  8  7 

#include <iostream>
#include<vector>

using namespace std;
void setMatrix(vector<vector<int> >&M, int x,int y,int start,int n ){

    if(n<0){
        return;
    }
    // cout<<"....."<<endl;
    //上边
    for(int j=x;j<x+n-1;j++){
        M[y][j]=start; 
        start++;
    }
    
    //右边
    for(int i=y;i<y+n-1;i++){
        M[i][x+n-1]= start;
        start++;
    }

    //下面
    for(int j=x+n-1;j>x;j--){
        M[y+n-1][j]=start;
        start++;
    }
    //左边
    for(int i=y+n-1;i>y;i--){
        M[i][x]=start;
        start++;
    }
    setMatrix(M,x+1,y+1,start,n-2);//递归遍历
} 


int main(){
   
    int m;
    cin>>m;
    vector<vector<int> > array(m,vector<int>(m));
    setMatrix(array,0,0,1,m);
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout << array[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
