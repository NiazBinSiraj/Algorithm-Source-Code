#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define MOD 1000000007
#define ck(XX) cout<<XX<<endl
#define set(XX,POS) XX|(1<<POS)
#define reset(XX,POS) XX&(~(1<<POS))
#define check(XX,POS) (bool)(XX&(1<<POS))
#define toggle(XX,POS) (XX^(1<<POS))
#define Fin freopen("input.txt","r",stdin)
#define Fout freopen("output.txt","w",stdout)
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
int node, edge;
vector <int> adj[1000];
int level[1000];
bool visited[1000];
int parent[1000];

void bfs(int source)
{
    MS(visited,0);
    MS(level,0);

    queue <int> Q;
    level[source] = 0;
    Q.push(source);
    visited[source] = 1;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            if(visited[adj[u][i]]==0)
            {
                level[adj[u][i]] = level[u]+1;
                Q.push(adj[u][i]);
                parent[adj[u][i]] = u;
                visited[adj[u][i]] = 1;
            }
        }
    }
    return;
}

void graph_input()
{
    int x,y;
    scanf("%d%d",&node,&edge);
    for(int i=1 ; i<=edge; i++)
    {
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void ShowPath(int source, int destiny)
{
    cout << "Path: "<<destiny;
    for(int i=destiny; parent[i] != source;)
    {
        cout<<" -> "<<parent[i];
        i = parent[i];
    }
    cout<<" -> "<<source<< endl;
    return;
}

int main()
{
    int s=1;
    //Fin;
    graph_input();
    bfs(4);
    ShowPath(4,1);
    return 0;
}
