#include <iostream>
#include <vector> 
#include <queue>
#include <map>
#include <list> 
#include <stack>

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
    bool isCycleDFS(int src,int par,vector<bool>&vis){
        vis[src]=true;
        for(int v : l[src]){
            if(!vis[v]){
                if(isCycleDFS(v,src,vis)){
                    return true ;
                }
            }else if(v!=par){
                return true ;
            }
        }
        return false ;
    }
    bool isCycleBFS(int src, vector<bool> vis){
        queue<pair<int,int>> q ;
        q.push({src,-1});
        vis[src] = true;
        while(q.size()>0){
            int u = q.front().first;
            int par = q.front().second ;
            q.pop();
            for(int v : l[u]){
                if(!vis[v]){
                    q.push({v,u});
                    vis[v]=true ;
                }else if(v!=par){
                    return true ;
                }
            }
        }
        return false ;
    }
    bool isCycle(){
        int src = 0 ;
        vector<bool> vis(V,false);
        for(int i=0 ;i<V ;i++){
            if(!vis[i]){
                if(isCycleBFS(src,vis)){
                    return true ;
                }
            }
        }
        return false ;
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
class GraphDir{
public:
    int V ;
    list<int> *l ;
    GraphDir(int val){
        V= val ;
        l = new list<int> [V] ;
    }

    void addedge(int u , int v){
        l[u].push_back(v) ;
    }

    bool isCycleDirdfs(int curr,vector<bool>& vis,vector<bool>& recPath){
        vis[curr]=true;
        recPath[curr]=true;

        for(int v : l[curr]){
            if(!vis[v]){
                if(isCycleDirdfs(v,vis,recPath)){
                    return true;
                }
            }
            if(recPath[v]){
                return true;
            }
        }
        recPath[curr]=false ;
        return false ;
    }
    bool isCycleDir(){
        vector<bool> vis(V,false);
        vector<bool> recPath(V,false);

        for(int i=0 ; i<V ; i++){
            if(!vis[i]){
                if(isCycleDirdfs(i,vis,recPath)){
                    return true;
                }
            }
        }
        return false ;
    }
    void dfsTopo(int curr,vector<bool> &vis,stack<int>& s){
        vis[curr]=true;
        for(int v : l[curr]){
            if(!vis[v]){
                dfsTopo(v,vis,s);
            }
        }
        s.push(curr);
    }
    void topoSort(){
        stack<int> s ;
        vector<bool> vis(V,false);

        for(int i=0 ;i<V ;i++){
            if(!vis[i]){
                dfsTopo(i,vis,s);
            }
        }
        while(s.size()>0){
            int curr = s.top();
            s.pop();
            cout<<curr<<" " ;
        }
        cout<<endl;
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

    GraphDir x(4);
    x.addedge(1,0);
    x.addedge(0,2);
    x.addedge(2,3);
    x.addedge(3,0);

    GraphDir e(6);
    e.addedge(3, 1);
    e.addedge(2, 3);
    e.addedge(4, 0);
    e.addedge(4, 1);
    e.addedge(5, 0);
    e.addedge(5, 3);
    // g.printAlledges() ;
    g.bfs();
    h.bfs();
    m.bfs();
    n.bfs();
    g.dfs();
 // cout<< g.isCycle() << endl ;
    cout<< x.isCycleDir() <<endl ;
    e.topoSort();

    return 0;
}