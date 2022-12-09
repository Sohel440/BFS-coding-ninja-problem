
#include<unordered_map>
#include<list>
#include<queue>
#include<set>

void prepairAdj(    unordered_map <int , set<int > > &adj, vector<pair<int, int>> &edges ){
    
    
    for (int  i =0 ; i <edges.size() ; i ++ ){
        int u = edges[i].first;
        int v = edges[i] . second;
        
        
        adj[u].insert(v);
        adj[v]. insert(u);
        
    }
}

void bfs (  unordered_map <int , set<int > > &adj,unordered_map<int , bool> &visited, vector<int> &ans , int node){
    queue<int> q;
    q.push(node);
    visited[node] == 1;
    
    while(!q.empty()){
     int frontNode = q.front();
        q.pop();
        // store front node in to ans 
        ans.push_back(frontNode);
        // traverse  
        for(auto i :adj[frontNode]){
            
            if(!visited[i])
            q.push(i);
            visited[i] == 1;
        } 
     
    }
   
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    unordered_map <int , set<int > > adj;
    vector <int > ans;
    unordered_map<int , bool> visited;
    
    prepairAdj(adj ,edges);
        
        // traverse all component of a graph 
        
        for (int i = 0 ; i < vertex ; i ++){
            
            if (!visited[i]){
                bfs(adj , visited , ans , i);
            }
            
            
        }
    return ans;
}
