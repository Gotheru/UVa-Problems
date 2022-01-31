// 11463 - Commandos

#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

void resuelveCaso(int c) {
	int N, R;
	scanf("%d %d", &N, &R);
	vector<vector<int>> g(N, vector<int>(N, INF));
	while (R--) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a][b] = 1;
		g[b][a] = 1;
	}
	for (int i = 0; i < N; ++i) g[i][i] = 0;
	for (int k = 0; k < N; ++k)
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

	int res = 0;
	int s, d; scanf("%d %d", &s, &d);
	for (int i = 0; i < N; ++i) {
		res = max(res, g[s][i] + g[i][d]);
	}

	printf("Case %d: %d\n", c, res);
}

int main() {
	int nCasos;
	scanf("%d", &nCasos);
	for (int i = 1; i <= nCasos; ++i) resuelveCaso(i);
	return 0;
}
