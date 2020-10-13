#include<bits/stdc++.h>
using namespace std;
int maxMoney(int gold[][4],int n,int m){
    int money[n][m]={0};
    for(int i=m-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(i==m-1){
                money[j][i]=gold[j][i];
            }
            else if(j==0){
                money[j][i] = gold[j][i]+max(money[j][i+1],money[j+1][i+1]);
            }
            else if(j==n-1){
                money[j][i] = gold[j][i]+max(money[j][i+1],money[j-1][i+1]);
            }
            else{
                money[j][i] = gold[j][i]+max(money[j+1][i+1],max(money[j][i+1],money[j-1][i+1]));
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<money[i][j]<<" ";
        cout<<endl;
    }
    int temp = money[0][0];
    for(int j=1;j<n;j++){
        temp = max(temp,money[j][0]);
    }
    return temp;
}
int main(){
    int gold[4][4]= { {1, 3, 1, 5},
                   {2, 2, 4, 1},
                   {5, 0, 2, 3},
                   {0, 6, 1, 2}};
    cout<<maxMoney(gold,4,4);

    return 0;
}