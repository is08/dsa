#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Graph {
  int v;
  list<int> *vertices;

public:
    Graph(int v) {
        this->v = v;
        this->vertices = new list<int>[v];
    }

    void addEdge(int source, int dest) {
        vertices[source].push_back(dest);
    }

    void printGraph() {
        for(int i = 0; i < v; i++) {
            cout << i << "->";
            for(auto elem: vertices[i]) {
                cout << elem << " ";
            }
            cout << endl;
        }
    }

    bool dfs(int curr, vector<bool> &visited, vector<bool> &stack) {
        visited[curr] = true;
        stack[curr] = true;

        for(auto elem: vertices[curr]) {
            if(!visited[elem]) {
                if(dfs(elem, visited, stack)) {
                    return true;
                }
            }
            else if(visited[elem] && stack[elem]) {
                return true;
            }
        }

        stack[curr] = false;
        return false;
    }

    bool contains_cycle() {
        vector<bool> visited(v, 0);
        vector<bool> stack(v, 0);

        for(int i = 0; i < v; i++) {
            if(!visited[i]) {
                if(dfs(i, visited, stack)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    int v = 5;
    vector<pair <int, int>> edges;
    edges.push_back({0, 1});
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    edges.push_back({3, 0});
    edges.push_back({3, 4});

    Graph *g = new Graph(v);

    for(int i = 0; i < edges.size(); i++) {
        g->addEdge(edges[i].first, edges[i].second);
    }

    g->printGraph();
    cout << g->contains_cycle() << endl;

    return 0;
}
