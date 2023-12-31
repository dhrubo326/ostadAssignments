#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(b)
// Space complexity: O(log(b)), 
int multiply(int a, int b) {
  if (b == 0) {
    return 0;
  } else if (b == 1) {
    return a;
  } else {
    return a + multiply(a, b - 1);
  }
}

int main() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 

    int a = 4;
    int b = 5;

    int product = multiply(a, b);

    cout << product << endl;

    return 0;
}

