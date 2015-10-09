#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    string mName;
    int mAge;
    bool mIsMale;

    string GetName()
    {
        return mName;
    }

    int GetAge()
    {
        return mAge;
    }

    bool IsMale()
    {
        return mIsMale;
    }

    //ostream& operator << (ostream& out, const 

    Person(string pName = "", int pAge = 0, bool pIsMale = false):
    mName(pName), mAge(pAge), mIsMale(pIsMale)
    {
    }
    
};

class BaseballPlayer : public Person
{
public:
    double mBattingAvg;
    int mHomeRuns;

    double GetAvg()
    {
        return mBattingAvg;
    }

    int GetHomeRuns()
    {
        return mHomeRuns;
    }

    BaseballPlayer(string pName = "", int pAge = 0, bool pIsMale = false, double pBattingAvg = 0, int pHomeRuns = 0):
    Person(pName, pAge, pIsMale), mBattingAvg(pBattingAvg), mHomeRuns(pHomeRuns)
    {
    }

};

int main()
{
    Person nik("Nikhil", 29, true);
    Person foo();
    cout << nik.GetName() << endl;
    cout << nik.GetAge() << endl;

    BaseballPlayer joe("Joe",32, true, 105.2, 22);
    //joe.mName = "Joe";
    //joe.mAge = 23;

    cout << joe.GetName() << endl;
    cout << joe.GetAge() << endl;
    cout << joe.GetAvg() << endl;
    cout << joe.GetHomeRuns() << endl;

    return 0;
}