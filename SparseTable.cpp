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

#define MAX_N 1000
#define MAX_LOG_N 10

class RMQ{
	private:
		int A[MAX_N], SpT[MAX_N][MAX_LOG_N];
	public:
		RMQ(int n,int _A[]){
			int i;
			rep(i,n){
				_A[i] = A[i];
				SpT[i][0] = i;
			}
			int j;
			for(j=1;(1<<j) <= n; j++){
				for(i=0; i+(1<<j)-1< n;i++){
					if(A[SpT[i][j-1]] < A[SpT[i+(1<<(j-1))][j-1]]){
						SpT[i][j] = SpT[i][j-1];
					}else{
						SpT[i][j] = SpT[i+(1<<(j-1))][j-1];
					}
				}
			}
		}
		int query(int i,int j){
			int k = (int) floor(log((double)j-i+1)/log(2.0));
			if(A[SpT[i][k]] <= A[SpT[j-(1<<k)+1][k]]) return SpT[i][k];
			else return SpT[j-(1<<k)+1][k];
		}

};

int main(){
	freopen("a.in","r",stdin);
	int arr[] = { 18, 17, 13, 19, 15, 11, 20 }; 
	vi A(arr, arr + 7);
	RMQ spt(7,arr);
	printf("RMQ(1, 3) = %d\n", spt.query(1, 3));
	printf("RMQ(4, 6) = %d\n", spt.query(4, 6));

}