/*
 * Problem : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3911
 * Application of KMP
 * Pattern will be the given string. Text will be the reverse of given text
 * Now apply KMP and calculate maximum length of matches
 */

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<int> construct_LPS(string pattern){
    vector<int> LPS(pattern.size());
    int j=0,i=1;
    while(i<pattern.size())
    {
        if(pattern[i]==pattern[j]){
            LPS[i]=j+1;
            i++;
            j++;
        }
            
        else
        {
            if(j==0)
                LPS[i]=0,i++;
            else
                j=LPS[j-1];
            
        }
    }
    return LPS;
    
}

string StringMatchingKMP(string pattern, string text){
    vector<int> LPS = construct_LPS(pattern);
    int i=0,j=0;
    int max_length=0;
    int length=0;
    while(i<text.size())
    {
        if(pattern[j]!=text[i]){
            if(length>max_length)
                max_length=length;
            if(j==0)
                    i++,length=0;
            else
                j=LPS[j-1],length=j;
        }                
        else
            j++,i++,length++;
        if(j==pattern.size())
        {
            return pattern;
        }           
    }
    if(length>max_length)
         max_length=length;
    return pattern.substr(0,max_length);
}

int main() {
    int test;
    cin>>test;
    while(test--){
        string text,pattern;
        cin>>pattern;
        text=pattern;
        reverse(text.begin(),text.end());
        string secret=StringMatchingKMP(pattern,text);
        reverse(secret.begin(),secret.end());
        cout<<secret<<endl;
    }
    
}
