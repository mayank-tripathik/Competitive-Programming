/*
 * Problem : https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1335
 * Appliaction of sieve with a simple modification. 
 * Push consecutive primes in a seperate list if they have difference of 2 
 */

#include<bits/stdc++.h>
using namespace std;
#define MAX 20000000
typedef pair<int,int> P;
vector<P> sieve(){
    vector<bool> isPrime(MAX,true);
    vector<P> twinPrimes;
    isPrime[0]=isPrime[1]=false;
    for(int i=4;i<MAX;i=i+2){
        isPrime[i]=false;
    }
    int previous=2,current;
    for(int i=3;i<MAX;i=i+2){
        if(isPrime[i]){
                current=i;
                if(current-previous==2)
                    twinPrimes.push_back(make_pair(previous,current));
                previous=current;
                for(int j=i*2;j<MAX;j=j+i){
                    isPrime[j]=false;
            }
        }
    }
    return twinPrimes;
}

int main(){
    int n;
    vector<P> twinPrimes=sieve();
    while(cin>>n){
        P primePair=twinPrimes[n-1];
        cout<<"("<<primePair.first<<", "<<primePair.second<<")"<<endl;
    }
}
