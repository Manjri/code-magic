#include <iostream>
using namespace std;

class StatusCallback
{
public:
    virtual void updateStatus(int oState, int nState) = 0;
};

class MyStatus : StatusCallback
{
private:
    int result;


public:
    void updateStatus(int oState, int nState)
    {
        if(oState < nState)
            result = 0;
        else
            result = 1;
    }

    MyStatus()
    {
        result = -1;
    }

    int getResult()
    {
        return result;
    }

};

int main()
{
    MyStatus m;
    int res;

    m.updateStatus(2,1);
    res = m.getResult();

    return 0;
}

