#include <bits/stdc++.h>
using namespace std;
// Time complexity: O(n), 
// Space complexity: O(n).

void removeDuplicate(string s){
    stack<char>holder;
    for(int i=s.size()-1; i>=0; i--){
        if(holder.empty() || s[i] != holder.top()){
            holder.push(s[i]);
        }else{
            holder.pop();
        }
    }
    string ans;
    while(!holder.empty()){
        ans += holder.top();
        holder.pop();
    }
    if(ans.empty()){
        cout<<"-1"<<endl;
    }else{
        cout<<ans<<endl;
    }
    return;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    
    string s;
    cin>>s;
    removeDuplicate(s);

    return 0;
}