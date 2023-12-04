#include <bits/stdc++.h>
using namespace std;

 int solve(vector<int> arr, int i, int j, vector<vector<int>> &dp){
    int mini=INT_MAX;
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(i>=j){
        return 0;
    }
    else{
        for(int k=i;k<=j-1;k++){
            int ans = solve(arr,i,k,dp)+solve(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j];
            mini = min(mini, ans);
        }
    }
    return dp[i][j] = mini;
}

int main() {
    int N;
    cin>>N;
    vector<int> arr(N);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    vector<vector<int>> v(N+1, vector<int>(N+1,-1));
    cout<< solve(arr,1,N-1,v);
    return 0;
}