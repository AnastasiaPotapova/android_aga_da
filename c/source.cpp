#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100043;
vector<int> g[N];
int used[N];
int comp[N];
int cnt[N];
// for bipartite coloring
int color[N];

void dfs(int x, int c)
{
	if(used[x]) return;
	used[x] = 1;
	comp[x] = c;
	cnt[c]++;
	for(int i = 0; i < g[x].size(); i++)
	{
		int y = g[x][i];
		dfs(y, c);
	}
}

void dfs2color(int x, int c)
{
	if(color[x] != -1)
	{
		if(color[x] == c)
		{
			// the graph is not bipartite
		}
		return;
	}
	color[x] = c;
	for(int i = 0; i < g[x].size(); i++)
	{
		int y = g[x][i];
		dfs2color(y, 1 - c);
	}
}

// topological sorting

vector<int> order;
void dfs_toposort(int x)
{
	if(used[x]) return;
	used[x] = 1;
	for(int i = 0; i < g[x].size(); i++)
	{
		int y = g[x][i];
		dfs_toposort(y);
	}
	order.push_back(x);
}

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		// reading the graph
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		// for undirected graphs
		g[y].push_back(x);
	}

	int cc = 0;

	for(int i = 0; i < n; i++)
	{
		// connected components
		if(comp[i] == 0)
		{
			cc++;
			dfs(i, cc);
		}
	}

	// bipartite coloring
	for(int i = 0; i < n; i++)
		color[i] = -1;
	for(int i = 0; i < n; i++)
		if(color[i] == -1)
			dfs2color(i, 0);

	// topological sorting
	for(int i = 0; i < n; i++)
		used[i] = 0;
	for(int i = 0; i < n; i++)
		if(!used[i])
			dfs_toposort(i);
	return 0;
}