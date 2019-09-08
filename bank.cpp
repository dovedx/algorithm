//题目：数组长度为n，元素取值范围为1-n，统计数组中元素出现的次数

// eg：a[]={6,2,4,1,2,5}
//输出：1出现次数：1
//     2出现次数：2
//     3出现次数：0
//     4出现次数：1
//     5出现次数：1
//     6出现次数：1

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n=6;
    
    int a[]={6,2,4,1,2,5};
    int i=0;
    int len = sizeof(a)/sizeof(a[0]);
    cout<<len<<endl;
    int count =0;
    while(i<n){
        count++;
        cout<<count<<":"<<i<<endl;
        int temp = a[i]-1;
        if(temp < 0){
            i++;
            continue;
        }
        else if(a[temp] > 0){
            a[i] = a[temp];
            a[temp] = -1;
        }
        else{
            a[i] =0;
            a[temp]--;
        }
    }
    for(int j=0;j<n;j++){
        cout<<j+1<<"出现次数："<< -a[j]<<endl;
    }

    cout<<count<<endl;
    return 0;

}