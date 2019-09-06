//题目：螺旋打印矩阵-1
//...


#include <iostream>
#include<vector>

using namespace std;
void setMatrix(vector<vector<int> >&M, int x,int y,int start,int n,int really_start ){

    if(n<0){
        return;
    }
    if(n==1){
        M[y][x]=1;
        return ;
    }
    // cout<<"....."<<endl;
    //下边
    for(int i=x;i<x+n-1;i++){
        if(start>really_start){
            M[y][i]=0;
        }
        else{
            M[y][i]=start;
        }
         
        start--;
    }
    
    //右边
    for(int j=y;j>y-n+1;j--){
        if(start > really_start){
            M[j][x+n-1]= 0;
        }
        else{
            M[j][x+n-1]= start;
        }
        
        start--;
    }

    //上面
    for(int i=x+n-1;i>x;i--){
        if(start > really_start){
             M[y-n+1][i]=0;
        }
        else{
             M[y-n+1][i]=start;
        }
       
        start--;
    }
    //左边
    for(int i=y-n+1;i<y;i++){
        if(start > really_start){
            M[y-n+1][i]=0;
        }
        else{
            M[i][x]=start;
        }
        
        start--;
    }
    setMatrix(M,x+1,y-1,start,n-2,really_start);//递归遍历
} 


int main(){
   int number;
   cin>>number;
   int i=1;
    while(1){
        if((i*i)<number)
        {
            i++;
        }
        else if((i*i)>=number){
            break;
        }
    }

    int m=i;
    
    vector<vector<int> > array(m,vector<int>(m));
    int start = m*m;
    int x =0;
    int y =m-1;
    
    setMatrix(array,x,y,start,m,number);
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout << array[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
