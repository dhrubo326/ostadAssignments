//TC: O(N + E), SC: O(N)
int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    unordered_set<int> st;
    for(auto v: B){
        st.insert(v[0]);
        st.insert(v[1]);
    }
    int N = st.size();
    vector<vector<int> > graph(N+1);
    for(auto v: B){
        graph[v[0]].push_back(v[1]);
        graph[v[1]].push_back(v[0]);
        v.clear();
    }
    vector<int> visited(N+1, 0);
    queue<pair<int,int>> q; // <count of 1, node>
    q.push(make_pair(A[0], 1));
    int count = 0;
    while(!q.empty()){
        auto nd = q.front();
        q.pop();
        visited[nd.second] = 1;
        if(graph[nd.second].size() == 1 && nd.first <= C){
            count++;
        }
        for(auto e: graph[nd.second]){
            if(visited[e] == 0){
                q.push(make_pair(nd.first + A[e-1], e));
            }
        }
    }
    return count;
}