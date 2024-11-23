#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Car {
public:
    string id;
    int x;
    int y;

    Car(string id, int x, int y) {
        this->id = id;
        this->x = x;
        this->y = y;
    }

    int dist() const {
        return (x*x) + (y*y);
    }
};

class CarCompare {
public:
    bool operator()(const Car A, const Car B) {
        return A.dist() < B.dist();
    }
};

void printKNearestCars(vector<Car> cars, int k) {
    priority_queue<Car, vector<Car>, CarCompare> maxHeap(cars.begin(), cars.begin() + k);

    for(int i = k; i < cars.size(); i++) {
        if(maxHeap.top().dist() > cars[i].dist()) {
            maxHeap.pop();
            maxHeap.push(cars[i]);
        }
    }

    while(!maxHeap.empty()) {
        cout << maxHeap.top().id << endl;
        maxHeap.pop();
    }
}


int main() {
    Car c1("cOne", 1, 1);
    Car c2("cTwo", 2, 1);
    Car c3("cThree", 3, 2);
    Car c4("cFour", 0, 1);
    Car c5("cFive", 2, 3);

    vector<Car> cars;
    cars.push_back(c1);
    cars.push_back(c2);
    cars.push_back(c3);
    cars.push_back(c4);
    cars.push_back(c5);

    printKNearestCars(cars, 3);

    return 0;
}
