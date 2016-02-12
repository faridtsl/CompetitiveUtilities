#include <bits/stdc++.h>
#include <strings.h>

#define isNum(c) c<='9' && c>='0'
#define islettre(c) c<='z' && c>='a'
#define isLETTRE(c) c<='Z' && c>='A'
#define MS0(x) memset(x,0,sizeof(x))
#define MS(x,s) memset(x,s,sizeof(x))
#define drep(i,n) int i;for(i=0;i<n;i++)
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


int MetaBinarySearch(int s,vector<int> v){
	int i;
	int n = v.size();
	int lg;
	for(lg=1;(1<<lg) < n;lg++);
	lg--;
	i = (1<<(lg));
	while(v[i]!=s){
		if(v[i]>s){
			i = (i&(i-1));
		}
		lg--;
		if(lg==-1 && v[0]==s) return i;
		if(lg==-1) return -1;
		i |= (1<<(lg));
		if(i>=n) return -1;
	}
	return i;
}


int MetaBinarySearchV2(int s,vector<int> v){
	int index,curIndex,res=0;
	int n = v.size();
	int lg;
	for(lg=1;(1<<lg) < n;lg++);
	lg--;
	for(index = lg; index >=0;index --){
		curIndex = res + (1<<index);
		if(v[curIndex]==s) return curIndex;
		else if(v[curIndex]<s){
			res = curIndex;
		}
	}
	return -1;
}

int main(){
	freopen("a.in","r",stdin);
	int T,i,j,k;
	int A[] = {1, 3, 4, 6, 8, 9, 11, 23,1, 3, 4, 6, 8, 9, 11, 23};
	vi v(A,A+16);
	sort(all(v));
	rep(i,16) cout << "v[" << i << "] = " << v[i] << endl;
	cout << MetaBinarySearch(6,v) << endl;
	cout << MetaBinarySearch(23,v) << endl;
	cout << MetaBinarySearch(1,v) << endl;
	cout << MetaBinarySearch(2,v) << endl;
	cout << MetaBinarySearch(3,v) << endl; 
	cout << MetaBinarySearch(8,v) << endl; 
	cout << "V2 : " << endl;
	cout << MetaBinarySearchV2(6,v) << endl;
	cout << MetaBinarySearchV2(23,v) << endl;
	cout << MetaBinarySearchV2(1,v) << endl;
	cout << MetaBinarySearchV2(2,v) << endl;
	cout << MetaBinarySearchV2(3,v) << endl; 
	cout << MetaBinarySearchV2(8,v) << endl; 
}