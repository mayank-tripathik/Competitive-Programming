/*
 * Problem: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1265
 */
 
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    int cases=0;
    while(cin>>str)
    {
        int query;
        cases++;
        int size=str.size();
        vector<int> cumul(size);
        if(str[0]=='0')
            cumul[0]=0;
        else
            cumul[0]=1;
        for(int i=1;i<size;i++){
            if(str[i]=='0')
                cumul[i]=cumul[i-1];
            else
                cumul[i]=cumul[i-1]+1;
        }
        cin>>query;
        cout<<"Case "<<cases<<":\n";
        while(query--)
        {
            int i,j,upper,lower;
            cin>>i>>j;
            if(i>j){
                upper=i;
                lower=j;
            }
            else {
                upper=j;
                lower=i;
            }
            if(upper==lower) 
                cout<<"Yes\n";
            else{
                int diff=cumul[upper]-cumul[lower];
                if(diff==0 && str[lower]==str[lower+1]){
                    cout<<"Yes\n";
                }
                    
                else{
                    if(diff==(upper-lower) && str[lower]==str[lower+1])
                        cout<<"Yes\n";
                    else
                        cout<<"No\n";
                }
            }
        }
    }
}
