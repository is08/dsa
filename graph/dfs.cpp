#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph {
    int v;
    list<int> *vertices;

public:
    Graph(int v) {
        this->v = v;
        vertices = new list<int>[v];
    }

    void addEdge(int source, int dest) {
        vertices[source].push_back(dest);
        vertices[dest].push_back(source);
    }

    void printList() {
        for(int i = 0; i < v; i++) {
            cout << i << " -> ";

            for(auto elem: vertices[i]) {
                cout << elem << " ";
            }
            cout << endl;
        }
    }

    void dfsHelper(int node, bool *visited) {
        if(visited[node]) {
            return;
        }

        cout << node << " ";
        visited[node] = true;

        for(auto elem: vertices[node]) {
            dfsHelper(elem, visited);
        }
    }

    void dfs(int source) {
        bool *visited = new bool[v]{0};
        dfsHelper(source, visited);
    }
};

int main () {
    Graph *g = new Graph(7);
    g->addEdge(0, 1);
    g->addEdge(0, 4);
    g->addEdge(2, 1);
    g->addEdge(3, 4);
    g->addEdge(4, 5);
    g->addEdge(2, 3);
    g->addEdge(3, 5);
    g->addEdge(5, 6);

    //g->printList();
    g->dfs(1);
    return 0;
}
