#include <iostream>
using namespace std;

int binary_search(int *a, int left, int right) {
    if (left >= right - 1) { //Deal with the edge condition
        if ((left > 0) && (a[left] > a[left - 1] + 1))
            return (a[left] - 1);
        else
            return (a[left] + 1);
    }
    
    int mid = left + (right - left) / 2;
    
    if (mid - left < a[mid] - a[left])
        return binary_search(a, left, mid);
    else
        return binary_search(a, mid, right);

}

int main() {
    int a[10] = {0,2,3,4,5,6,7,8,9,10};
    cout << binary_search(a, 0, 9) << endl;
    
}