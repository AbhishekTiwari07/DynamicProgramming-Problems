#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (unsigned)!((int)0)
#define mo 1000000007
#define fo(i, n) for(ll i=0;i<n;i++)
typedef vector<int> vi;
typedef vector<ll> vl;

int DP[10000][10000]={0};

int LCS(string s1,int m, string s2, int n){
    if(n==0||m==0)
        return 0;
    else if(s1[m-1]==s2[n-1])
        DP[m][n] = LCS(s1,m-1,s2,n-1)+1;
    else
        DP[m][n] =  max(LCS(s1,m,s2,n-1),LCS(s1,m-1,s2,n));
        
    return DP[m][n];
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    string X = "", Y = "";
    cin>>X>>Y;
    cout<<LCS(X,X.length(),Y,Y.length());
    return 0;
}