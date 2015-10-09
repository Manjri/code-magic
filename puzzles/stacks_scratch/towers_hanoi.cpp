#include <iostream>
#include <stack>
#include <vector>

using namespace std;


class Tower
{
private:
    stack<int> disks;
    int idx;

public:
    Tower(int i)
    {
        idx = i;
    }

    void add(int d)
    {
        if(!disks.empty() && disks.top() <= d)
        {
            cout << "Error placing disks" << d << endl;
        }
        else
        {
            disks.push(d);
        }
    }

    int index()
    {
        return idx;
    }

    void moveTopTo(Tower& t)
    {
        int topElement = disks.top();
        disks.pop();
        t.add(topElement);
        cout << "Move disk " << topElement << " from " << index() << " to " << t.index() << endl;
    }

    void moveDisks(int n, Tower& destination, Tower& buffer)
    {
        if( n > 0)
        {
            moveDisks(n-1, buffer, destination);
            moveTopTo(destination);
            buffer.moveDisks(n-1, destination, *this);
        }
    }

};

vector<Tower> towers;

int main()
{
    int n = 3;
    towers.reserve(n);    

    for(int i=0; i < n; i++)
    {
        towers.push_back(Tower(i));
    }

    for(int i=n-1; i >=0; i--)
    {
        towers[0].add(i);
    }

    towers[0].moveDisks(n, towers[2], towers[1]);

    return 0;
}