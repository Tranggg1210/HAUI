#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int> > readGraph() {
    int numVertices, numEdges;
    cout << "Nhap so dinh cua do thi: ";
    cin >> numVertices;
    cout << "Nhap so canh cua do thi: ";
    cin >> numEdges;

    vector<vector<int> > graph(numVertices);

    cout << "Nhap cac canh cua do thi:\n";
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    return graph;
}

void printColors(const vector<int>& colors) {
    cout << "\nMau cua cac dinh:\n";
    for (int vertex = 0; vertex < colors.size(); vertex++) {
        cout << "Dinh " << vertex + 1 << ": Mau " << colors[vertex] << "\n";
    }
}

vector<int> greedyColoring(const vector<vector<int> >& graph) {
    int numVertices = graph.size();
    vector<int> vertexColors(numVertices, -1);
    set<int> usedColors;
    int numUsedColors = 0;

    for (int vertex = 0; vertex < numVertices; vertex++) {
        for (int i = 0; i < graph[vertex].size(); i++) {
            int neighbor = graph[vertex][i];
            if (vertexColors[neighbor] != -1) {
                usedColors.insert(vertexColors[neighbor]);
            }
        }

        for (int color = 0; color < numVertices; color++) {
            if (usedColors.find(color) == usedColors.end()) {
                vertexColors[vertex] = color;
                numUsedColors = max(numUsedColors, color + 1); 
                break;
            }
        }

        usedColors.clear();
    }

    cout << "\nSo mau can dung: " << numUsedColors << "\n";
    return vertexColors;
}

int main() {
    vector<vector<int> > graph = readGraph();
    vector<int> colors = greedyColoring(graph);
    printColors(colors);
    return 0;
}


