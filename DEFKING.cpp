#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> Grilla;
typedef vector<int> Fila;

ostream& operator<<(ostream&os,Grilla &g){
    for(auto &fila: g){
        for(auto &columna:fila)
            os << columna <<" ";
        os <<'\n';
    }
    os << '\n';
    return os ;
}
ostream& operator<<(ostream&os,Fila fila){
    for(auto &columna:fila)
        os << columna <<" ";
    os <<'\n';    
    return os ;
}
int diferenciaMasGrande(Fila &f){
    int mx = 0;
    for(int i = 1; i < f.size(); i++)
        mx = max(mx, f[i] - f[i-1] - 1);
    return mx;
}
int solve(int t){
    int n,w,h;
    int x,y;

    while(t--){
        cin >> w >> h >> n;

        Fila xs,ys;
        xs.reserve(n+2);
        ys.reserve(n+2);

        xs.push_back(0);
        xs.push_back(w+1);

        ys.push_back(0);
        ys.push_back(h+1);

        while(n--){
            cin >> x >> y;
            xs.push_back(x);
            ys.push_back(y);
        }

        sort(xs.begin(),xs.end());
        sort(ys.begin(),ys.end());

        cout << diferenciaMasGrande(xs) * diferenciaMasGrande(ys) << '\n';
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
