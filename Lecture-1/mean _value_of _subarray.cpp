/*
 * Problem statement:
 * Given an array of N integers, find the subarray of size k whose mean is the smallest where 1<=k<=N. Return the starting 
   position of the subaray and the corresponding mean value.
 */
 


#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test--){
        int j,n,sum_upto_k=0,k,pos;
        float mean,smallest_mean;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=0;i<k;i++)
            sum_upto_k+=arr[i];
        mean=sum_upto_k*1.0/k;
         cout<<mean<<endl;
        smallest_mean=mean;
        j=-1;
        for(int i=k;i<n;i++){
            j++;
            sum_upto_k-=arr[j];
            sum_upto_k+=arr[i];
            mean=sum_upto_k*1.0/k;
            if(mean<smallest_mean){
                smallest_mean=mean;
                pos=j+1;
            }
            cout<<mean<<endl;
        }
        cout<<"starting position: "<<pos<<" and mean_value:"<<smallest_mean<<endl;
    }
     
}
