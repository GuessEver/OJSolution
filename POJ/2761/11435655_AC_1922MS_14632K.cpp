/*http://blog.csdn.net/jiangzh7
By Jiangzh*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100000+10;

int n,m;
int sorted[N];
struct Parti_Tree{int val,left;}val[20][N];

void build_tree(int d,int l,int r)
{
	if(l==r) return;
	int m=(l+r)>>1,same=m-l+1;
	int lcnt=l,rcnt=m+1;
	for(int i=l;i<=r;i++)
		if(val[d][i].val<sorted[m]) same--;
	for(int i=l;i<=r;i++)
	{
		int flag=0;
		if(val[d][i].val<sorted[m]||(val[d][i].val==sorted[m]&&same>0))
		{
			flag=1;
			val[d+1][lcnt++].val=val[d][i].val;
			if(val[d][i].val==sorted[m]) same--;
		}
		else val[d+1][rcnt++].val=val[d][i].val;
		val[d][i].left=val[d][i-1].left+flag;
	}
	build_tree(d+1,l,m);
	build_tree(d+1,m+1,r);
}

int kth(int d,int l,int r,int x,int y,int k)
{
	if(l==r) return val[d][l].val;
	int m=(l+r)>>1;
	int lx=val[d][x-1].left-val[d][l-1].left;//[l,x-1]to left
	int ly=val[d][y].left-val[d][x-1].left;//[x,y]to left
	int rx=(x-1)-l+1 - lx;//[l,x-1]to right
	int ry=y-x+1 - ly;//[x,y]to right
	if(ly>=k) return kth(d+1,l,m, l-1+lx+1 , l-1+lx+ly ,k);
	else return kth(d+1,m+1,r, m+1-1+rx+1 , m+1-1+rx+ry ,k-ly);
}

void work()
{
	int x,y,k;scanf("%d%d%d",&x,&y,&k);
	printf("%d\n",kth(0,1,n,x,y,k));
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&sorted[i]);
		val[0][i].val=sorted[i];
	}
	sort(sorted+1,sorted+1+n);
	build_tree(0,1,n);
	while(m--) work();
	return 0;
}
