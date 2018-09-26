#include<bits/stdc++.h>
//zone
//Those who cannot face the opponent in front, can never face the opponent beyond !
using namespace std;
vector<int>graph[(int) 1e6+5];
vector<int>revgraph[(int) 1e6+5];
stack<int> s;
//vector<int> silnie[(int) 1e6+5];
int l = 0;
bool mrk[(int) 1e6+5];
map<int, int> keep;

void dfs(int src)
{
    mrk[src] = true;
    for(int i = 0 ; i < graph[src].size() ;i++)
    {
        if(!mrk[graph[src][i]])
        {
            dfs(graph[src][i]);
        }
    }
    s.push(src);
}
void dfs2(int src)
{
    mrk[src] = true;
//    silnie[l].push_back(src);
    keep[src] = l;
    for(int i = 0 ; i< revgraph[src].size(); i++)
    {
        if(!mrk[revgraph[src][i]])
        {
            dfs2(revgraph[src][i]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v;
    cin >> v;
    v++;
    int e;
    cin >> e;
    int x,y;
    int i;
    for(i = 0 ; i < e ; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        revgraph[y].push_back(x);
    }
    for(i = 0 ; i < v; i++)
    {
        mrk[i] = false;
    }
    for(i = 0 ; i < v; i++)
    {
        if(!mrk[i])
        {
            dfs(i);
        }
    }
    //NOW reversing graph's dfs;
    for(i = 0 ; i < v ; i++)
    {
        mrk[i] = false;
    }

    while(!s.empty())
    {
        int tmp = s.top();
        s.pop();
        if(!mrk[tmp])
        {
            dfs2(tmp);
            l ++;
        }
    }

//    for (int k = 0; k < silnie->size(); ++k) {
//        for (int m = 0; m < silnie[k].size(); ++m) {
//            cout << silnie[k][m] << " ";
//        }
//        cout << "\n";
//    }

    int z;
    cin >> z;

    for (int j = 0; j < z; ++j) {
        int a, b;
        cin >> a >> b;

        if (keep[a] == keep[b]){
            cout << "Tak\n";
        } else cout << "Nie\n";
    }

    return 0;
}