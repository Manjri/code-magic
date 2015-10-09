/**
 
LeetCcode - Meeting Room
 
Given an array of meeting time intervals consisting of start and
end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.
*/


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */



class Solution {
public:
    struct less_than_start
    {
        inline bool operator() (const Interval& a, const Interval& b)
        {
            return (a.start < b.start);
        }
    };
    
    bool canAttendMeetings(vector<Interval>& intervals)
    {
        int len = intervals.size();
        
        sort(intervals.begin(), intervals.end(), less_than_start());
        
        for(int i=1; i<len; i++)
        {
            if(intervals[i].start < intervals[i-1].end)
                return false;
        }
        
        return true;
    }
};