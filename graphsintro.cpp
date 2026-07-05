#include <iostream>
#include <vector> 
#include <queue>
#include <map>
#include <list> 

using namespace std ;

class Graph{
public:
    int V ;
    list<int> *l ;
    Graph(int val){
        V= val ;
        l = new list<int> [V] ;
    }

    void addedge(int u , int v){
        l[u].push_back(v) ;
        l[v].push_back(u) ;
    }
    void bfs(){
            queue<int> q;
            vector<bool> vis(V,false) ;
            q.push(0) ;
            vis[0]=true;
            while(q.size()>0){
                int curr = q.front();
                q.pop();
                cout<<curr<<" " ;
                for(int v : l[curr]){
                    if(!vis[v]){
                        vis[v]=true ;
                        q.push(v);
                    }
                }
            }
            cout<<endl;
    }
    void dfsHelper(int u,vector<bool>&vis){
        cout<<u<<" " ;
        vis[u]=true;
        for(int v : l[u]){
            if(!vis[v]){
                dfsHelper(v,vis);
            }
        }
    }
    void dfs(){
        int src = 0 ;
        vector<bool> vis(V,false);
        for(int i =0 ;i<V ;i++){
            if(!vis[i]){
                dfsHelper(i,vis) ; //this for loop is to cover the disconnected graphs also
            }
        }
        cout<<endl;
    }

    void printAlledges(){
        for(int i=0 ;i<V ;i++){
            cout<<i<<" : " ;
            for(int j : l[i]){
                cout<<j<<" ";
            }
            cout<<endl ;
        }
    }
};

int main(){
    Graph g(5) ;
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(1,3);
    // g.addedge(2,3);
    g.addedge(2,4);

    Graph h(7) ;
    h.addedge(0,2);
    h.addedge(2,1);
    h.addedge(1,3);
    h.addedge(1,4);
    h.addedge(4,5);
    h.addedge(4,6);
    h.addedge(5,6);

    Graph m(5);
    m.addedge(0,1);
    m.addedge(1,2);
    m.addedge(3,1);
    m.addedge(3,4);
    m.addedge(2,4);

    Graph n(6);
    n.addedge(0,1);
    n.addedge(1,2);
    n.addedge(2,3);
    n.addedge(3,4);
    n.addedge(4,5);
    n.addedge(0,5);


    // g.printAlledges() ;
    g.bfs();
    h.bfs();
    m.bfs();
    n.bfs();
    g.dfs();

}