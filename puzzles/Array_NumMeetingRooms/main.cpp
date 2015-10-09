#include <iostream>
#include <map>
#include <vector>
using namespace std;

/**
Leetcode:
 
 Given an array of meeting time intervals consisting of start and end times 
 [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
 
 For example,
 Given [[0, 30],[5, 10],[15, 20]],
 return 2
 */


//Definition of Interval
struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


class Solution{
    
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> changes;
        for (auto i : intervals) {
            changes[i.start] += 1;
            changes[i.end] -= 1;
        }
        int rooms = 0, maxrooms = 0;
        for (auto change : changes)
            maxrooms = max(maxrooms, rooms += change.second);
        return maxrooms;
    }
    
    
};

int main()
{
    Solution s;
    vector<Interval> vec;
    vec.push_back(Interval(4,9));
    vec.push_back(Interval(4,17));
    vec.push_back(Interval(9,10));
    
    cout << "Number of Meeting Rooms: " << s.minMeetingRooms(vec) <<endl;
    
    return 0;
}

