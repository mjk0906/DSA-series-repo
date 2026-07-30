#include <iostream>
#include <vector>
using namespace std;

class DisjointSetunion {
public:
    int n;
    vector<int> par , rank ;

    DisjointSetunion(int n){
        this->n = n ;
        for(int i=0 ; i<n ; i++){
            par.push_back(i);
            rank.push_back(0);  
        }
    }

   int find(int x){
        if(par[x]==x) return x ;
        else return par[x]=find(par[x]);
    }
    void unionByRank(int a,int b){
        int parA = find(a);
        int parB = find(b);

        if(parA == parB) return ;
        if(rank[parA]==rank[parB]){
            par[parB]=parA ;
            rank[parA]++; //only here we have to increase the rank as both are equally long and upon additon one edge comes more
        }
        else if(rank[parA]>rank[parB]){
            par[parB]=parA;
        }
        else{
            par[parA]=parB ;
        }
    }
    void getInfo(){
        for(int i=0 ;i<n ;i++){
            cout<<par[i]<<" ";
        }
        cout<<endl;
        for(int i=0 ;i<n ;i++){
            cout<<rank[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
    DisjointSetunion dsu(6);

    dsu.unionByRank(0, 2);
    cout << dsu.find(2) << endl;

    dsu.unionByRank(1, 3);
    dsu.unionByRank(2, 5);
    dsu.unionByRank(0, 3);
    cout << dsu.find(2) << endl;

    dsu.unionByRank(0, 4);
    dsu.getInfo();  
    return 0;
}