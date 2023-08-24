#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool checkParanthesis(string s, int &location){
    if(s.size() == 0)
        return true;
    stack<pair<char, int>> st;
    for (int i = 0; i < s.size(); i ++){
        if((s[i] == '[') || (s[i] == '{') || (s[i] == '('))
            st.push(make_pair(s[i], i));
        if(s[i] == '}'){
            if((!st.empty()) && (st.top().first == '{'))
                st.pop();
            else{
                location = i;
                return false;
            }
        }
        if (s[i] == ']')
        {
            if ((!st.empty()) && (st.top().first == '['))
                st.pop();
            else
            {
                location = i;
                return false;
            }
        }
        if (s[i] == ')')
        {
            if ((!st.empty()) && (st.top().first == '('))
                st.pop();
            else
            {
                location = i;
                return false;
            }
        }
    }
    if(!st.empty()){
        location = st.top().second;
        return false;
    }
    return true;
}
int main(){
    string s;
    cin >> s;
    int location = -1;
    if(checkParanthesis(s, location))
        cout << "Success";
    else
        cout << location + 1;
    return 0;
}