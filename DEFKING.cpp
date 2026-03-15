#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> Grilla;
typedef vector<int> Fila;

int calcularArea(Grilla g,int f, int c){//O(w+h)
    int x,y;
    x = y = 0;
    for(int j = c; j < g[0].size() && g[f][j] < 1; j++)
        x++;
    for(int i = f; i < g.size() && g[i][c] < 1 ; i++)
        y++;
    return x*y;
}
int areaMasGrande(Grilla &g){
    int areaMaxima = 0;
    int n = g.size(), m = g[0].size();
    for(int i = 0 ; i < n ; i++ )
        for(int j = 0 ; j < m; j++) 
            if(g[i][j] == 0)
                areaMaxima = max(areaMaxima,calcularArea(g,i,j));
    return areaMaxima;
}

void ocupar(Grilla &g, int f, int c){//O(w+h)
    for(int i = 0; i < g.size(); i++){
        g[i][c] = 1;
    }
    for(int j = 0; j < g[0].size(); j++){
        g[f][j] = 1;
    }
}

ostream& operator<<(ostream&os,Grilla &g){
    for(auto &fila: g){
        for(auto &columna:fila)
            os << columna <<" ";
        os <<'\n';
    }
    os << '\n';
    return os ;
}

int solve(int t){
    int n,w,h;
    int x,y;
    while(t--){
        cin >> w >> h >> n;
        Grilla grilla(h,Fila(w));
        
        while(n--){//(n^2)
            cin >> y >> x;
            ocupar(grilla,x-1,y-1);
        }
        //cout << grilla;
        cout << areaMasGrande(grilla) << '\n'; 
    }
    return 0;
}






int main(){
    /*Grilla g(5,Fila(5));
    cout << g;
    ocupar(g,1,1);
    cout << g;
    cout << calcularArea(g,2,2);
    */
    int t;
    cin >> t;
    solve(t);
    return 0;
}