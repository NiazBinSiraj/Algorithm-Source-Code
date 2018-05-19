#include <bits/stdc++.h>
//#include "custom.h"
using namespace std;
#define MAX 1000000
#define INF INT_MAX
#define LL long long
#define ULL unsigned LL
#define EPS 0.00000001
#define PI acos(-1.0)
#define MOD 1000000007
#define PII pair<int,int>
#define PLL pair<LL,LL>
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

#define MX 15
int setA[MX] = {2,3,4,5};
vector <int> SumOfSubset;

void subsetSum(int position, int sum, int size)
{
    if(position == size) {SumOfSubset.push_back(sum); return;}
    subsetSum(position+1, sum+setA[position], size);
    subsetSum(position+1, sum, size);
    return;
}


int main()
{
    FAST;
    int size = SIZE(setA);
    subsetSum(0,0,size);
    return 0;
}
