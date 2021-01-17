#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (unsigned)!((int)0)
#define mo 1000000007
#define fo(i, n) for(ll i=0;i<n;i++)
typedef vector<int> vi;
typedef vector<ll> vl;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    string X = "", Y = "";
    cin>>X>>Y;
    int DP[X.length()+1][Y.length()+1]={0};
    for(int i=0;i<X.length()+1;i++){
        for(int j=0;j<Y.length()+1;j++){
            if(i==0||j==0)
                DP[i][j]=0;
            else if(X[i-1]==Y[j-1])
                DP[i][j]=DP[i-1][j-1]+1;
            else
                DP[i][j] = max(DP[i][j-1],DP[i-1][j]);
        }
    }
    cout<<DP[X.length()][Y.length()];
    return 0;
}