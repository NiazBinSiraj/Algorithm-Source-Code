//BFS in 2D grid
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
#define valid(X,Y,R,C) X>=0 && X<R && Y>=0 && Y<C
int fr[] = {1,-1,0,0};
int fc[] = {0,0,1,-1};
int r,c;
int cell[100][100];
int level[100][100];
bool visited[100][100];

struct node{
    int row;
    int col;
};

void bfs(int sr, int sc)
{
    node n;
    n.row = sr;
    n.col = sc;
    queue <node> Q;

    level[sr][sc] = 0;
    visited[sr][sc] = 1;
    Q.push(n);

    while(!Q.empty())
    {
        node u = Q.front();
        Q.pop();

        for(int i=0; i<4; i++)
        {
            int nr=u.row+fr[i];
            int nc=u.col+fc[i];

            if(valid(nr,nc,r,c) && cell[nr][nc] != -1 && visited[nr][nc] == 0)
            {
                node t;
                t.row = nr;
                t.col = nc;

                Q.push(t);
                level[nr][nc] = level[u.row][u.col]+1;
                visited[nr][nc] = 1;
            }
        }
    }
    return;
}

int main()
{
    //scanf("%d%d",&r,&c);
    while(1){
    scanf("%d%d",&r,&c);
    bfs(0,0);
    cout <<level[3][6]<<endl;
    }
    return 0;
}
