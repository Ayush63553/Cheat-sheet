#include <bits/stdc++.h>
using namespace std;

 string func(string str1, string str2, int n, int m, vector<vector<int>> &dp){
  for(int i=0;i<=n;i++){
    for(int j=0;j<=m;j++){
      if(i==0||j==0){
        dp[i][j]=0;
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(str1[i-1]==str2[j-1]){
        dp[i][j] = 1+dp[i-1][j-1];
      }
      else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  	string s="";
	int i=n;
	int j=m;
	while(i>0&&j>0){
		if(str1[i-1]==str2[j-1]){
			s.push_back(str1[i-1]);
			i--;
			j--;
		}
		else{
			if(dp[i-1][j]>dp[i][j-1]){
				i--;
			}
			else{
				j--;
			}
		}
	}
	reverse(s.begin(),s.end());
	return s;
}


int main() {
    string s1,s2;
    cin>>s1>>s2;
    int N=s1.size();
    int M=s2.size();
    vector<vector<int>> dp(N+1, vector<int>(M+1, -1));
    cout<< func(s1,s2,N,M,dp);	
    return 0;
}