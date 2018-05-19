#include <bits/stdc++.h>
//#include "custom.h"
using namespace std;
#define MAX 1000000
#define INF INT_MAX
#define LL long long
#define ULL unsigned LL
#define EPS 0.00000001
#define PI acos(-1.0)
#define MOD 100000007LL
#define pii pair<int,int>
#define pll pair<LL,LL>
#define ck(XX) cout<<XX<<endl
#define Set(XX,PS) XX|(1<<PS)
#define Reset(XX,PS) XX&(~(1<<PS))
#define Toggle(XX,PS) (XX^(1<<PS))
#define Check(XX,PS) (bool)(XX&(1<<PS))
#define SORT(v) sort(v.begin(),v.end())
#define REVERSE(V) reverse(v.begin(),v.end())
#define Fin freopen("input.txt","r",stdin)
#define Fout freopen("output.txt","w",stdout)
#define VALID(X,Y,R,C) X>=0 && X<R && Y>=0 && Y<C
#define SIZE(ARRAY) sizeof(ARRAY)/sizeof(ARRAY[0])
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))

vector <int> adj[10010];
char color[10010];
int parent[10010];
bool is_cyclic;

void dfs(int source)
{
    color[source] = 'G';

    for(int i=0; i<adj[source].size(); i++)
    {
        if(color[adj[source][i]] == 'G' && parent[source] != adj[source][i]) is_cyclic = true;
        else if(color[adj[source][i]] == 'W')  {parent[adj[source][i]] = source; dfs(adj[source][i]);}
    }

    color[source] = 'B';
    return;
}


int main()
{
    FAST;

    is_cyclic = false;
    for(int i=0; i<10010; i++) {adj[i].clear(); color[i]='W'; parent[i]=0;}

    int edge,x,y;
    cin >> edge;

    for(int i=0; i<edge; i++)
    {
        cin >>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    parent[1] = 1;
    dfs(1);

    if(is_cyclic == true) printf("Is Cyclic\n");
    else printf("Not Cyclic\n");

    return 0;
}
