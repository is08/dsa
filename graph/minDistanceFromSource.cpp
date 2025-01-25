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

    void addEdge(int i, int j, bool isDirected = false) {
        vertices[i].push_back(j);

        if(!isDirected) {
            vertices[j].push_back(i);
        }
    }

    void printList() {
        for(int i = 0; i < v; i++) {
            cout << i << " -> ";

            for(int elem: vertices[i]) {
                cout << elem << " ";
            }
            cout << endl;
        }
    }

    int getDistFromSource(int source, int dest) {
        queue<int> q;
        bool *visited = new bool[v]{0};
        int *dist = new int[v]{INT_MAX};
        int level = 0;

        q.push(source);
        visited[source] = true;

        while(!q.empty()) {
            int s = q.size();

            for(int i = 0; i < s; i++) {
                int f = q.front();
                q.pop();
                dist[f] = level;

                for(auto nbrs: vertices[f]) {
                    if(!visited[nbrs]) {
                        q.push(nbrs);
                        visited[nbrs] = true;
                    }
                }
            }
            level++;
        }

        return dist[dest];
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

    g->printList();

    cout << "distance bw 1 and 6 is " << g->getDistFromSource(1, 6) << endl;
    cout << "distance bw 0 and 6 is " << g->getDistFromSource(0, 6) << endl;
    return 0;
}
