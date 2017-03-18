/*
 * Problem : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=117&page=show_problem&problem=2890
 * Simple application of Longest increasing subsequence problem
 * Complexity : O(n)
 */

#include<bits/stdc++.h>
using namespace std;

int longest_increasing_subsequence(vector<int> &arr,vector<int> &length){
    int n=arr.size();
    vector<int> T;
    T=length;
    int max_val=length[0];
    for(int i=1;i<n;i++){
        if(length[i]>max_val)
            max_val=length[i];
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                T[i]=max(T[i],(T[j]+length[i]));
                if(T[i]>max_val)
                    max_val=T[i];
            }            
        }
    }
    return max_val;
}

int longest_decreasing_subsequence(vector<int> &arr,vector<int> &length){
    int n=arr.size();
    vector<int> T;
    T=length;
    int max_val=length[0];
    for(int i=1;i<n;i++){
        if(length[i]>max_val)
            max_val=length[i];
        for(int j=0;j<i;j++){
            if(arr[j]>arr[i]){
                T[i]=max(T[i],(T[j]+length[i]));
                if(T[i]>max_val)
                    max_val=T[i];
            }            
        }
    }
    return max_val;
}

int main(){
    int test;
    cin>>test;
    int count=0;
    while(test--){
        int n;
        count++;
        cin>>n;
        vector<int> arr(n);
        vector<int> length(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=0;i<n;i++)
            cin>>length[i];
        int long_inc=longest_increasing_subsequence(arr,length);
        int long_dec=longest_decreasing_subsequence(arr,length);
        if(long_inc>=long_dec){
            printf("Case %d. Increasing (%d). Decreasing (%d).\n",count,long_inc,long_dec);
        }
        else{
            printf("Case %d. Decreasing (%d). Increasing (%d).\n",count,long_dec,long_inc);
        }
    }    
}
