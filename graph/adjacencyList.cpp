#include<iostream>
#include<list>
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
};


int main () {
    Graph *g = new Graph(6);
    g->addEdge(0, 1);
    g->addEdge(0, 4);
    g->addEdge(2, 1);
    g->addEdge(3, 4);
    g->addEdge(4, 5);
    g->addEdge(2, 3);
    g->addEdge(3, 5);

    g->printList();
    return 0;
}
