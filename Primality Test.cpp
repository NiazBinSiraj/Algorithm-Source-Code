//Primality Testing Algorithm
//Time Complexity O(sqrt(n))
//Eligible checking Range 1 to 10^16

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi 2*acos(0.0)

//Primality Testing Function
bool is_prime(ll n)
{
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2 == 0 || n%3 == 0) return false;

    for(ll i=5;i*i<=n;i+=6)
        if(n%i == 0 || n%(i+2) == 0) return false;

    return true;
}


//Main Function
int main()
{
    ll n;
    cin >> n;
    if(is_prime(n)) cout <<n<<" is prime."<<endl;
    else cout <<n<<" is not prime."<<endl;

    return 0;
}
