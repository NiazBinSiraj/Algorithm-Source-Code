//LightOJ 1117-Helping Cicada
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
struct subset
{
    ULL element;
    char sign;

    subset() {};
    subset(ULL element_, char sign_) {element = element_; sign = sign_;}
};


ULL gcd(ULL a, ULL b)
{
    if(b==0) return a;
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

ULL lcm(ULL a, ULL b)
{
    return (a*b)/gcd(a,b);
}

vector <subset> subsetA;
void subsetGenerate(vector<ULL>v, ULL position, ULL element, ULL size, ULL noe)
{
    if(position == size)
    {
        if(noe == 0) return;
        if(noe%2 == 0) subsetA.push_back(subset(element,'-'));
        else subsetA.push_back(subset(element,'+'));
        return;
    }

    subsetGenerate(v, position+1, lcm(element,v[position]), size, noe+1);
    subsetGenerate(v, position+1, element, size, noe);

    return;
}



int main()
{
    FAST;
    //Fin;
    //Fout;
    ULL tc, cn=0;
    cin >> tc;
    while(tc--)
    {
        subsetA.clear();
        ULL n,m;
        cin >>n>>m;

        vector <ULL> setA;
        for(ULL i=0; i<m; i++) {ULL temp; cin>>temp; setA.push_back(temp);}
        subsetGenerate(setA,0,1,setA.size(),0);

        ULL ans=0;
        for(ULL i=0; i<subsetA.size(); i++)
        {
            ULL temp = n/subsetA[i].element;
            if(subsetA[i].sign == '+') ans += temp;
            else ans -= temp;
        }

        ans = n-ans;
        printf("Case %llu: %llu\n", ++cn, ans);
    }

    return 0;
}
