#include <queue>
#include <iostream>

using namespace std;

struct comparator {
    bool operator()(int i, int j) {
        return i > j;
    }
};

int main(int argc, char const *argv[])
{
    priority_queue<int, std::vector<int>, comparator> minHeap;
    
    minHeap.push(10);
    minHeap.push(5);
    minHeap.push(12);
    minHeap.push(3);
    minHeap.push(3);
    minHeap.push(4);
    
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    return 0;
}