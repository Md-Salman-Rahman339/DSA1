#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adj[N];
bool visited[N];

void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<" Visiting node: "<<u<<endl;
        for(int v:adj[u]){
            if(visited[v]==true) continue;
            q.push(v);
            visited[v]=true;
        }
    }
}

int main(){
 int n,m;
 cin>>n>>m;
 for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
 }


int cc=0;
for(int i=1;i<=n;i++){
    if(visited[i]) continue;
    bfs(i);
    cc++;
}
cout<<"Number of connected components :"<<cc<<endl;


 return 0;
}