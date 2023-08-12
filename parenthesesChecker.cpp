#include <bits/stdc++.h>
using namespace std;
// Time complexity - O(n)
// Space complexity - O(n)
bool isBalancedParentheses(string s){
	stack<char> stk;
	int size = s.size();
	for (int i = 0; i < size; ++i)
	{
		if(stk.empty()){
			stk.push(s[i]);
		}else if( (stk.top() == '(' && s[i] == ')') ||
					(stk.top() == '{' && s[i] == '}') ||
					(stk.top() == '[' && s[i] == ']') ){
			stk.pop();

		}else{
			stk.push(s[i]);
		}
	}

	if(stk.empty()){
		return true;
	}else{
		return false;
	}

}

int main () {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	    string str = "(()[])";
	    if(isBalancedParentheses(str)){
	    	cout<<"true"<<endl;
	    }else{
	    	cout<<"false"<<endl;
	    }


	return 0;
}