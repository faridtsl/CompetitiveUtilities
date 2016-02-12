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

class SegmentTree{
	private:
		vi tree,A;
		int size;
		int left(int p){ return p << 1;}
		int right(int p){ return left(p)+1;}
		void build(int p,int b,int e){
			if(b==e){
				tree[p] = b;
				return;
			}
			int r = right(p);
			int l = left(p);
			build(l,b,(e+b)/2);
			build(r,(e+b)/2 + 1,e);
			tree[p] = (A[tree[r]] < A[tree[l]]) ? tree[r] : tree[l];
			return;
		}
		int rmq(int p, int L, int R, int i, int j) { 
			if (i > R || j < L) 
				return -1;
			if (L >= i && R <= j) 
				return tree[p];

			int p1 = rmq(left(p) , L , (L+R) / 2, i, j);
			int p2 = rmq(right(p), (L+R) / 2 + 1, R , i, j);

			if (p1 == -1) return p2; 
			if (p2 == -1) return p1;
			return (A[p1] <= A[p2]) ? p1 : p2;
		}
	public:
		SegmentTree(vi &_A){
			size = (int)_A.size();
			A = _A;
			tree.assign(size*4,0);
			build(1,0,size-1);
		}
		int rmq(int l,int r){
			return rmq(1,0,size-1,l,r);
		}
};

int main(){
	freopen("a.in","r",stdin);
	int arr[] = { 18, 17, 13, 19, 15, 11, 20 }; 
	vi A(arr, arr + 7);
	SegmentTree st(A);
	printf("RMQ(1, 3) = %d\n", st.rmq(1, 3));
	printf("RMQ(4, 6) = %d\n", st.rmq(4, 6));
}