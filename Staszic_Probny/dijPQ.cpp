#include<bits/stdc++.h>

using namespace std;

//dis - odleglosc od startu / id - id wierzcholka docelowego
#define dis first
#define id second

//limit na dane +7
#define M 1000007
#define INF 1000000007

//nie chce mi sie pisac tak duzo
typedef pair<int, int> Pii;

//kolejka priorytetowa
priority_queue<Pii, vector<Pii>, greater<Pii> > Q;

//struktura wierzcholka grafu
//con - polaczenia / done - czy wierzcholek byl przejzany / d - odleglosc od startu
struct node
{
    vector<Pii> con;
    bool done = 0;
    int d = INF;
};

//tablica grafu
node V[M];

//dodawanie sasiadow
void add(int top, int d) {
    V[top].d = d;
    for(auto e : V[top].con) {
        if(!V[e.id].done) {
            Q.push({d+e.dis, e.id});
        }
    }
    V[top].done = 1;

}

//dijkstra
void dij(int x) {
    add(x, 0);
    while(!Q.empty()) {
        int d = Q.top().dis;
        int top = Q.top().id;
        Q.pop();
        if(!V[top].done) {
            add(top, d);
        }
    }
}

int n,m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    int a,b,c;
    for(int i = 0;i<m;i++) {
        cin>>a>>b>>c;
        V[a].con.push_back({c,b});
        V[b].con.push_back({c,a});
    }
    dij(1);
    for(int i = 1;i<=n;i++) {
        cout<<V[i].d<<" ";
    }
    cout<<"\n";
}
