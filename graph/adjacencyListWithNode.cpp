#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
using namespace std;

class Node {
public:
    string name;
    list<string> nbrs;

    Node(string name) {
        this->name = name;
    }
};

class Graph {
    unordered_map<string, Node*> nodes;

public:
    Graph(vector<string> cities) {
        for(int i = 0; i < cities.size(); i++) {
            nodes[cities[i]] = new Node(cities[i]);
        }
    }

    void addEdge(string x, string y, bool isDirected = true) {
        nodes[x]->nbrs.push_back(y);

        if(!isDirected) {
            nodes[y]->nbrs.push_back(x);
        }
    }


    void printList() {
        for(auto elem: nodes) {
            cout << elem.first << " -> ";
            Node* temp = elem.second;

            for(string city: temp->nbrs) {
                cout << city << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    vector<string> cities = {"Delhi", "London", "Paris", "New York"};
    Graph g(cities);

    g.addEdge("Delhi", "London");
    g.addEdge("New York", "London");
    g.addEdge("Delhi", "Paris");
    g.addEdge("Paris", "New York");

    g.printList();

    return 0;
}
