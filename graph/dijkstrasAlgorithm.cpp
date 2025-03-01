#include<iostream>
#include<list>
#include<vector>
#include<set>
using namespace std;

class Graph {
    int v;
    list<pair<int, int>> *vertices;

 public:
    Graph(int v) {
        this->v = v;
        vertices = new list<pair<int, int>>[v];
    }

    void addEdge(int source, int dest, int weight) {
        vertices[source].push_back({dest, weight});
        vertices[dest].push_back({source, weight});
    }

    void printGraph() {
        for(int i = 0; i < v; i++) {
            cout << i << " -> ";

            for(auto elem: vertices[i]) {
                cout << elem.first << "." << elem.second << " " ;
            }
            cout << endl;
        }
    }

    int dijkstrasAlgo(int source, int dest) {
        vector<int> dist(v, INT_MAX);
        set<pair<int, int>> mapped;

        dist[source] = 0;
        mapped.insert({dist[source], source});

        while(!mapped.empty()) {
            pair<int, int> curr = *mapped.begin();
            int currNode = curr.second;
            int distanceTillNow = curr.first;
            mapped.erase(*mapped.begin());

            for(pair<int, int> nbr: vertices[curr.second]) {
                int nbrNode = nbr.first;
                int distanceOfNbrFromCurr = nbr.second;

                int tempDist = distanceTillNow + distanceOfNbrFromCurr;

                if(tempDist < dist[nbrNode]) {
                    if(mapped.find({dist[nbrNode], nbrNode}) != mapped.end()) {
                        mapped.erase({dist[nbrNode], nbrNode});
                    }
                    dist[nbrNode] = tempDist;
                    mapped.insert({dist[nbrNode], nbrNode});
                }
            }
        }

        return dist[dest];
    }
};

int main() {
    Graph *g = new Graph(5);
    g->addEdge(0, 1, 1);
    g->addEdge(0, 2, 4);
    g->addEdge(0, 3, 7);
    g->addEdge(1, 2, 1);
    g->addEdge(2, 3, 2);
    g->addEdge(3, 4, 3);

    cout << g->dijkstrasAlgo(0, 4);

    return 0;
}
