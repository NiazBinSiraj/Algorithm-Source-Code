#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define eps 0.00000001
#define pi 2*acos(0.0)
#define Fout freopen("output.txt","w",stdout)
#define Fin freopen("input.txt","r",stdin)
#define runtime printf("Run Time : %0.3lf seconds\n", clock()/(CLOCKS_PER_SEC*1.0))

template <class X>  X gcd(X a, X b)
{
    if(b==0) return a;
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

template <class X> X lcm(X a, X b)
{
    return (a*b)/gcd(a,b);
}

int main()
{
    ll a,b;
    cin >> a >> b;

    cout << lcm(a,b) <<endl;
    return 0;
}

