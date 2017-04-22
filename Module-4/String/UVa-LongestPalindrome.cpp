/*
 * Problem : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2092
 * Since we can remove one or more characters to get the largest palindrome from string, the problem is reduced to 
 * finding longest palindromic subsequence (and NOT substring!) which can be easily solved by finding LCS of given
 * String and its reverse
 * Complexity : O(n^2) where n is the size of the string
 */

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int dp[1002][1002];

int longestPalindrome(string str1, string str2){
    int n=str1.size();
    for(int i=0;i<=n;i++)
        dp[i][0]=0,dp[0][i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][n];
    
}
int main() {
    int test;
    cin>>test;
    string str1;
    getline(cin,str1);
    while(test--){
        string str2;
        getline(cin,str1);
        str2=str1;
        memset(dp,0,sizeof(dp));
        reverse(str2.begin(),str2.end());
        cout<<longestPalindrome(str1,str2)<<endl;
    }
    
}
