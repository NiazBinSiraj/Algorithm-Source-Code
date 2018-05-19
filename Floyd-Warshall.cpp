#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define INF INT_MAX
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
#define valid(X,Y,R,C) X>=0 && X<R && Y>=0 && Y<C
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))
LL node,edge;
LL cost[110][110];

void floyd()
{
    for(int k=1; k<=node; k++)
    for(int i=1; i<=node; i++)
    for(int j=1; j<=node; j++) {
        if( cost[i][j] > (cost[i][k] + cost[k][j])) cost[i][j] = (cost[i][k] + cost[k][j]);
    }
    return;
}

int main()
{
    for(int i=0; i<110; i++){
        for(int j=0; j<110; j++){
            if(i==j) cost[i][j] = 0;
            else cost[i][j] = INF;
        }
    }

    int from,to;
    LL weight;
    cin >> node >> edge;
    for(int i=0; i<edge; i++)
    {
        cin>>from>>to>>weight;
        cost[from][to] = weight;
        cost[to][from] = weight;
    }
    floyd();

    cout << cost[1][node] <<endl;
    return 0;
}
