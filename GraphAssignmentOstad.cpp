#include <bits/stdc++.h>
using namespace std;

void bfs(int node,vector<int>adjlist[],vector<int>&vis)
{
    vis[node] = 1;
    queue<int> q;
    q.push(node);
   
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
       
        for(auto it:adjlist[temp])
        {
            if(!vis[it])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
       
    }
   
   
}
int solve(int A, vector<vector<int>> &B) {
   
    int n = B.size();

    vector<int> adjlist[A];    
    for(int i=0;i<n;i++)
    {
        adjlist[B[i][0]-1].push_back(B[i][1]-1);
        adjlist[B[i][1]-1].push_back(B[i][0]-1);
    }
   
   
    vector<int> vis(A,0);
   
    int ans = 0;
    for(int i=0;i<A;i++)
    {
        if(!vis[i])
        {
            ans++;
            bfs(i,adjlist,vis);
        }
       
    }
   
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int A = 4;
    vector<vector<int>>B = {{1,2},{2,3}};
   
   auto ans = solve(A, B);

   cout<<ans;

    return 0;
}

