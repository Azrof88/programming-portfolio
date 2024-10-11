
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
    int x, y;

    // Overloading the < operator to compare by distance from origin
    bool operator<(const Point &other) const {
        return (x * x + y * y) > (other.x * other.x + other.y * other.y);
    }
};

// Overloading the < operator to create a max-heap based on distance from origin
    bool operator<(const Point &other) const {
        return (x * x + y * y) < (other.x * other.x + other.y * other.y);
    }

int main() {
    priority_queue<Point> pq;

    // Adding points to the priority queue
    pq.push({3, 4});  // Distance = 25
    pq.push({1, 1});  // Distance = 2
    pq.push({0, 2});  // Distance = 4

    // Removing points based on priority (closest to origin first)
    cout << "Points in order of distance from origin:\n";
    while (!pq.empty()) {
        Point p = pq.top();
        pq.pop();
        cout << "Point: (" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}
