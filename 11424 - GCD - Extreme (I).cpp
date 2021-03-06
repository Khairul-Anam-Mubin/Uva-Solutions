/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>

#define pb       push_back
#define MP       make_pair
#define Sort(v)  sort(v.begin(),v.end())
#define Mxe(v)   *max_element(v.begin(),v.end())
#define Mne(v)   *min_element(v.begin(),v.end())
#define Fill0(a) memset(a,0,sizeof(a))
#define Fin      freopen("input.txt","r",stdin)
#define Fout     freopen("output.txt","w",stdout)
#define precision(a) cout << fixed << setprecision(a) 
#define Fast     fasrerIO()

using namespace std;

template <typename T> T Sqr(T x) { T n = x * x ; return n ;}
template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
template <typename T> T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template <typename T> T exgcd(T a,T b,T &x,T &y) {if(a<0){T d=exgcd(-a,b,x,y);x=-x;return d;}   if(b<0){T d=exgcd(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=exgcd(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template <typename T> typename std::vector<T>::iterator insert_sorted (std :: vector<T> & vec, T const& item) {return vec.insert (std::upper_bound( vec.begin(), vec.end(), item ), item);}
template <typename T> T isperfectsq(T x){ T n = sqrt(x); return ((n * n == x)?1:0);}


char uplowch(char ch){if(ch >= 'A' &&  ch <= 'Z') ch += 32; return ch;}
char lowupch(char ch){if(ch >= 'a' &&  ch <= 'z') ch -= 32; return ch;}
bool isalpha(char ch){if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return true; return false;}
int strtoint(string str){stringstream ss(str);int x = 0;ss >> x ;return x ;}
string intostr(int x){stringstream ss; ss << x; string str = ss.str(); return str;}
vector<string> linetostr(string str){string s; vector <string> v ;istringstream is(str); while(is >> s)v.pb(s);return v;}
void fasrerIO() {ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0) ;}

#define INF 2147483647
#define IINF 9223372036854775807
#define WHITE 0 
#define GRAY 1
#define BLACK 2
#define eps 1e-9

typedef unsigned long long ull;
typedef long long ll;
const double pi = acos(-1.0);

//int dx[] = {0,0,-1,1,-1,-1,1,1,0};
//int dy[] = {1,-1,0,0,-1,1,-1,1,0};
//int dx[] = {0 , 0 , -1 , 1} ; // right , left , for , back
//int dy[] = {1 , -1 , 0 , 0} ; 
//scanf(" %[^\n]", str) ;
//ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0) ;

#define mx 500
ll dp[200010] ;
bool isp[mx + 10] ;
vector <ll> prime ;
void sieve() {
    isp[0] = 1 ;
    isp[1] = 1 ;
    for(ll i = 4 ; i < mx ; i += 2) 
        isp[i] = 1 ;
    for(ll i = 3 ; i * i < mx ; i += 2) {
        if(!isp[i]) {
            for(ll j = i * i ; j < mx ; j += i + i ) {
                isp[j] = 1 ;
            }
        }
    }
    prime.pb(2LL) ;
    for(ll i = 3 ; i < mx ; i += 2)
        if(!isp[i])
            prime.pb(i) ;
}
ll GcdSum(ll x) {
    ll sq = sqrt(x) ;
    ll ans = 1LL ; 
    for(ll i = 0 ; i < prime.size() && prime[i] <= sq ; i++) {
        if(x % prime[i] == 0) {
            ll p = 0LL ;
            while(x % prime[i] == 0) {
                x /= prime[i] ;
                p++ ;
            }
            sq = sqrt(x) ;
            ans *= (((p + 1LL) * Pow(prime[i] , p)) - (p * Pow(prime[i] , p - 1LL))) ; 
        }
    }
    if(x != 1) {
        ans *= ((2 * x) - 1) ; 
    }
    return ans ;
}
int main() {
    sieve() ;
    for(ll i = 1 ; i < 200001 ; i++)
        dp[i] = GcdSum(i) - i ;
    dp[0] = 0LL ;
    for(ll i = 1 ; i < 200001 ; i++)
        dp[i] += dp[i - 1] ;
    ll n ;
    while(scanf("%lld",&n) == 1 && n) {
        printf("%lld\n",dp[n]) ;
    }
    return 0 ;  
}
