#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 20000 + 10;

int n,m,dra[N],kni[N];

void solve()
{

	for(int i = 1; i <= n; i++) scanf("%d", &dra[i]);
	for(int i = 1; i <= m; i++) scanf("%d", &kni[i]);
	std::sort(kni + 1, kni + 1 + m);
	std::sort(dra + 1, dra + 1 + n);
	int j = 1, res = 0, flag = 0;
	for(int i = 1; i <= m; i++)
	{
		if(kni[i] < dra[j]) continue;
		res += kni[i];
		if(++j == n+1) { flag = 1; break; }
	}
	if(flag) printf("%d\n", res);
	else printf("Loowater is doomed!\n");
}

int main()
{
	freopen("11292.in", "r", stdin);
	freopen("11292.out", "w", stdout);
	while(scanf("%d%d", &n, &m)==2 && n && m)
	{
		memset(dra, 0, sizeof(dra));
		memset(kni, 0, sizeof(kni));
		solve();
	}
	return 0;
}
