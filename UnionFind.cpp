#include <bits/stdc++.h>
#include <strings.h>

#define isNum(c) c<='9' && c>='0'
#define islettre(c) c<='z' && c>='a'
#define isLETTRE(c) c<='Z' && c>='A'
#define MS0(x) memset(x,0,sizeof(x))
#define MS(x,s) memset(x,s,sizeof(x))
#define rep(i,n) for(i=0;i<n;i++)
#define rev(i,n) for(i=n;i>=0;i--)
#define repv(i,v) for(i=0;i<v.size();i++)
#define repa(i,a,n) for(i=a;i<n;i++)
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define NOT_VISITED 0
#define IS_VISITED 1
#define MOD 1000000009
#define COL 100002
#define trMap(c,i) for(map<char,int>::iterator i = (c).begin(); i != (c).end(); i++)
#define trSet(c,i) for(set< pair <int,char> >::iterator i = (c).begin(); i != (c).end(); i++)
#define PB(val) push_back(val)
#define abs(i) (i<0)?-i:i
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

class UnionFind{
	private : vi p,rank;
	public :
		UnionFind(int N){
			rank.assign(N,0);
			p.assign(N,0);
			int i;
			rep(i,N) p[i] = i;
		}
		int findSet(int i){ return (p[i]==i)?i:(p[i]=findSet(p[i])); }
		bool isSameSet(int i,int j){
			return findSet(i)==findSet(j);
		}
		void unionSet(int i,int j){
			if(!isSameSet(i,j)){
				int x = findSet(i), y = findSet(j);
				if(rank[x] > rank[y]) p[y] = x;
				else{
					p[x] = y;
					if(rank[x]==rank[y]) rank[y]++;
				}
			}
		}
};

int main(){
	freopen("a.in","r",stdin);
	
}