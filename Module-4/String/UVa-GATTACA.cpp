/*
 * Problem : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2507
 * Since time allowed is 7 seconds, Naive way of generating Suffix array is enough
 * Uses Naive suffix array construction of complexity O(n^2logn) [storing suffixes and sorting them]
 * Adjacent suffixes are then compared to find longest common prefix between them
 * To find frequency of LCP, KMP is used to find how many times LCP repeats
 * Complexity: O(n^2logn)+O(n^2)+O(n+m) = O(n^2logn)
 */

 

#include<bits/stdc++.h>
using namespace std;
#define P pair<int,string>

bool compare(const P &l, const P &r){
	string str1=l.second;
	string str2=r.second;
	if(str1.compare(str2)<0)
		return true;
	else
		return false;
}

vector<int> constructSuffixArray(string text){
	vector<P> suffixes;
	vector<int> suffixArray;
	int n=text.size();
	for(int i=0;i<n;i++){
		string suffix=text.substr(i);
		suffixes.push_back(make_pair(i,suffix));
	}
	sort(suffixes.begin(),suffixes.end(),compare);
	for(int i=0;i<n;i++){
		suffixArray.push_back(suffixes[i].first);
	}
	return suffixArray;
}

string longestCommonPrefix(vector<int> suffixArray, string text){
	int LCP_length=0,LCP_index=-1;
	string LCP;
	int ans=1;
	for(int i=0;i<suffixArray.size()-1;i++){
		string str1=text.substr(suffixArray[i]);
		string str2=text.substr(suffixArray[i+1]);
		int prefix_length=0;
		for(int j=0;j<str1.size();j++){
			if(j==str2.size() || str1[j]!=str2[j])
				break;
			prefix_length++;
		}
		if(prefix_length>LCP_length){
			LCP_index=suffixArray[i];
			LCP_length=prefix_length;
		}			
	}
	if(LCP_length>0)
		LCP=text.substr(LCP_index,LCP_length);
	else
		LCP="";
	return LCP;
}

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

int StringMatchingKMP(string pattern, string text){
    vector<int> LPS = construct_LPS(pattern);
    int i=0,j=0;
    int counter=0;
    while(i<text.size()){
        if(pattern[j]!=text[i])
                if(j==0)
                    i++;
                else
                    j=LPS[j-1];
        else
            j++,i++;
        if(j==pattern.size()){
            counter++;
            j=LPS[j-1];
        }           
    }
    return counter;
}


int main(){
	int test;
	cin>>test;
	while(test--){
		string text;
		cin>>text;
		vector<int> suffixArray= constructSuffixArray(text);
		string LCP=longestCommonPrefix(suffixArray,text);
		if(LCP.length()>0){
			int repetition=StringMatchingKMP(LCP,text);
			cout<<LCP<<" "<<repetition<<endl;
		}
		else
			cout<<"No repetitions found!\n";
	}	
}
