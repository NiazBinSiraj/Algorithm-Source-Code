#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define EPS 0.00000001
#define PI 2*acos(0.0)
#define MOD 1000000007LL
#define pii pair<int,int>
#define pll pair<LL,LL>
#define ck(XX) cout<<XX<<endl
#define set(XX,POS) XX|(1<<POS)
#define reset(XX,POS) XX&(~(1<<POS))
#define check(XX,POS) (bool)(XX&(1<<POS))
#define toggle(XX,POS) (XX^(1<<POS))
#define Fin freopen("input.txt","r",stdin)
#define Fout freopen("output.txt","w",stdout)
#define MS(ARRAY,VALUE) memset(ARRAY,VALUE,sizeof(ARRAY))
#define RT printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))

pclass Euclid {
public:
    long long x, y, d;
    Euclid() {}
    Euclid(long long _x, long long _y, long long _d) : x(_x), y(_y), d(_d) {}
};

Euclid egcd(long long a, long long b) {
    if(!b) return Euclid(1, 0, a);
    Euclid r = egcd(b, a % b);
    return Euclid(r.y, r.x - a / b * r.y, r.d);
}

long long ModInverse(long long a, long long n) {
    Euclid t = egcd(a, n);
    if(t.d > 1) return 0;
    long long r = t.x % n;
    return (r < 0 ? r + n : r);
}


int main()
{
    LL ans;
    ans = ModInverse(3,MOD);
    ck(ans);
    return 0;
}
