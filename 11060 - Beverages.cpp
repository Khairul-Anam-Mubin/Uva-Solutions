/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
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
#define Sqr(n)   (n*n)
#define Sort(v)  sort(v.begin(),v.end())
#define Mxe(v)   *max_element(v.begin(),v.end())
#define Mne(v)   *min_element(v.begin(),v.end())
#define Fill0(a) memset(a,0,sizeof(a))
#define Fin      freopen("input.txt","r",stdin)
#define Fout     freopen("output.txt","w",stdout)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
const double pi = acos(-1.0);

template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
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

#define MOD 1000000007
#define MAX -1000000007
#define MIN 1e12 + 7
#define INF 1e9
#define IINF 1e18

//int dx[] = {0,0,-1,1,-1,-1,1,1,0};
//int dy[] = {1,-1,0,0,-1,1,-1,1,0};

map <string , int> mp ;
map <int , string> ans ;
vector <string> vec ; 
vector <int> G[110] ;
int indegree[110] ;
void  KahnsAlgo(int nodes) {
	priority_queue <int> pq ;
	for(int i = 1 ; i <= nodes ; i++) {
		if(indegree[i] == 0)
			pq.push(-i) ;
	}
	while(!pq.empty()) {
		int u = -pq.top() ;
		pq.pop() ;
		vec.pb(ans[u]) ;
		for(int i = 0 ; i < G[u].size() ; i++) {
			int v = G[u][i] ;
			indegree[v]-- ;
			if(indegree[v] == 0)
				pq.push(-v) ;
		}
	}
}
int main() {
	int tc , t = 0 ; 
	while(cin >> tc) {
		for(int i = 0 ; i <= 105 ; i++)
			indegree[i] = 0 ;
		for(int i = 1 ; i <= tc ; i++){
			string str ;
			cin >> str ;
			mp[str] = i ;
			ans[i] = str ;
		}
		int n ; 
		cin >> n ;
		for(int i = 1 ; i <= n ; i++) {
			string s1 , s2 ;
			cin >> s1 >> s2 ;
			int u , v ;
			u = mp[s1] ;
			v = mp[s2] ;
			G[u].pb(v) ;
			indegree[v]++ ;
		}
		printf("Case #%d: Dilbert should drink beverages in this order:", ++t);
		KahnsAlgo(tc) ;
		for(int i = 0 ; i < vec.size() ; i++)
			cout << " " << vec[i] ;
		cout << ".\n\n" ; 
		for(int i = 0 ; i < 110 ; i++)
			G[i].clear() ;
		mp.clear() ;
		vec.clear() ;
	}
	return 0 ;
}
