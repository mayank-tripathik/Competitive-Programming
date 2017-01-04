#include<bits/stdc++.h>
using namespace std;

char bracket_type(char c){
    if(c=='(' || c=='{' || c=='[')
        return 'l';
    else if(c==')' || c=='}' || c==']')
        return 'r';
    else
        return 'n';
}

char bracket_counterpart(char c){
    if(c==')')
        return '(';
    else if(c=='}')
        return '{';
    else
        return '[';
}

int main(){
    int test;
    cin>>test;
    while(test--){
        string expr;
        bool valid_expression=true;
        stack<char> mystack;
        cin>>expr;
        int size=expr.size();
        for(int i=0;i<size && valid_expression;i++)
        {
            char c=expr[i];
            if('l'==bracket_type(c))
            {
                mystack.push(c);
            }
            else if('r'==bracket_type(c))
            {
                if(!mystack.empty() && mystack.top()==bracket_counterpart(c)){
                    mystack.pop();
                }
                else{
                    valid_expression=false;
                }
                
            }
        }
        if(!mystack.empty() || (!valid_expression))
            cout<<"Expression Invalid/unbalanced\n";
        else
            cout<<"Expression Valid/Balanced\n";
    }
}
