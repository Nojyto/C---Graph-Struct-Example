#include <iostream>
#include <vector>
#include <stack>
#include <queue>
 
using namespace std;
 
class Graph {
private:
    int V;
    vector<vector<int>> adj;   
public:
    Graph(int V){
        this->V = V;
        adj.resize(V, vector<int>(0));
    }

    void addEdge(int v, int w){
        adj[v].push_back(w);
    }

    void BFS(int s){
        bool visited[V] = {0};

        queue<int> qu;
        qu.push(s);

        vector<int>::iterator itr;
        while(!qu.empty()){
            s = qu.front();
            qu.pop();

            cout << s << " ";

            for(itr = adj[s].begin(); itr != adj[s].end(); ++itr){
                if(!visited[*itr]){
                    visited[*itr] = true;
                    qu.push(*itr);
                }
            }
        }
    }

    void DFS(int s){
        bool visited[V] = {0};

        stack<int> st;
        st.push(s);

        vector<int>::iterator itr;
        while(!st.empty()){
            s = st.top();
            st.pop();

            if(!visited[s]) cout << s << " ";
            
            for(itr = adj[s].begin(); itr != adj[s].end(); ++itr){
                if(!visited[*itr]){
                    visited[s] = true;
                    st.push(*itr);                   
                }
            }        
        }
    }
};
 
int main(){
    Graph dg(5);
    dg.addEdge(0, 1); 
    dg.addEdge(0, 2); 
    dg.addEdge(0, 3);
    dg.addEdge(1, 2); 
    dg.addEdge(2, 4);
    dg.addEdge(3, 3); 
    dg.addEdge(4, 4);

    cout << "BFS: ";
    dg.BFS(0);

    cout << "\n";

    cout << "DFS: ";
    dg.DFS(0);
}