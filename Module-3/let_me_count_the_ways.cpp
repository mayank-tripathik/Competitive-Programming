#include<bits/stdc++.h>
using namespace std;

void set_matrix(int change,vector<vector<int64_t> > &matrix, int lowest_denomination){
    int n=matrix.size();
    for(int i=0;i<n;i++)
        matrix[i][0]=1;
    for(int j=1;j<=change;j++){
        if(j%lowest_denomination==0)
            matrix[0][j]=1;
    }
   
}

int64_t number_of_ways_of_getting_change(int change,vector<vector<int64_t> > &matrix,vector<int> &denomination){
    int n=matrix.size();
    set_matrix(change,matrix,denomination[0]);
    for(int i=1;i<n;i++){
        for(int j=1;j<=change;j++){
            if(j<denomination[i])
                matrix[i][j]=matrix[i-1][j];
            else
                matrix[i][j]=matrix[i][j-denomination[i]]+matrix[i-1][j];
        }     
    }
    return matrix[n-1][change];
}

int main(){
    int number_of_denominations,change;
    number_of_denominations=5;
    vector<int> denomination={1,5,10,25,50};
    while(cin>>change){
        vector<vector<int64_t> > matrix(number_of_denominations, vector<int64_t>(change+1));
        int64_t count=number_of_ways_of_getting_change(change,matrix,denomination);
        if(count==1){
            cout<<"There is only 1 way to produce "<<change<<" cents change.\n";
        }
        else{
            cout<<"There are "<<count<<" ways to produce "<<change<<" cents change.\n";
        }
    }
    
}
