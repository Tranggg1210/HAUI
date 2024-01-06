#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int color[MAXN];
int degree[MAXN];
int saturation[MAXN];
bool visited[MAXN];

bool cmp(int u, int v) {
    if (saturation[u] != saturation[v]) {
        return saturation[u] > saturation[v];
    } else if (degree[u] != degree[v]) {
        return degree[u] > degree[v];
    } else {
        return u < v;
    }
}

void update_saturation(int u) {
    set<int> colors;
    for (int v : adj[u]) {
        colors.insert(color[v]);
    }
    saturation[u] = colors.size();
}

int main() {
    int n, m;
    cout<<"Nhap so dinh: ";cin>>n;
	cout<<"Nhap so canh: ";cin>>m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    
    int max_degree = -1, max_degree_vertex = -1;
    for (int i = 1; i <= n; i++) {
        if (degree[i] > max_degree) {
            max_degree = degree[i];
            max_degree_vertex = i;
        }
    }
    color[max_degree_vertex] = 1;
    visited[max_degree_vertex] = true;
    for (int v : adj[max_degree_vertex]) {
        degree[v]--;
        update_saturation(v);
    }

    
    int num_colored = 1;
    while (num_colored < n) {
        int u = -1;
        for (int i = 1; i <=n; i++) {
            if (!visited[i]) {
                if (u == -1 || cmp(i, u)) {
                    u = i;
                }
            }
        }
        
        set<int> used_colors;
        for (int v : adj[u]) {
            if (color[v] > 0) {
                used_colors.insert(color[v]);
            }
        }
        int min_color = 1;
        while (used_colors.count(min_color) > 0) {
            min_color++;
        }
        color[u] = min_color;
        visited[u] = true;
        num_colored++;

        
        for (int v : adj[u]) {
            if (!visited[v]) {
                degree[v]--;
                update_saturation(v);
            }
        }
    }

    
    for (int i = 1; i <= n; i++) {
        cout << "Mau cua dinh " << i << ": " << color[i] << endl;
    }

    return 0;
}

