#include <iostream>
#include <vector>
#include <map>
using namespace std;


typedef map<int,vector<int>> Graph;
typedef vector<int> List;

ostream& operator <<(ostream &os,List &l){
    os <<"[";
    for(auto a:l){
        os << a <<" ";
    }
    os <<"]";
    return os;

}
ostream& operator <<(ostream &os,Graph &g){
    for(auto[k,v]:g){
        os << "{[" << k << "]," << v << "}\n";
    }
    return os;
}   


pair<int,int> maximaDistancia(Graph &g,int key,int parent){
    pair<int,int> mx ={0,key};
    for(auto a:g[key]){

        if(a==parent) 
            continue;

        auto val = maximaDistancia(g,a,key);
        val.first++;

        if(val.first > mx.first){
            mx = val;
        }
    }

    return mx;
}

int solve(Graph &g){

    int start = g.begin()->first;

    auto v1 = maximaDistancia(g,start,-1);
    auto v2 = maximaDistancia(g,v1.second,-1);

    return v2.first;
}
int main(){
    int n,v,e;
    cin >> n;
    n--;
    Graph g;
    while(n--){
        cin >> v >> e;       
        g[v].push_back(e); 
        g[e].push_back(v);
    }
    cout << solve(g);
    
    return 0;
}