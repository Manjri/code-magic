/*
 * majority.cpp
 *
 *  Created on: Feb 12, 2015
 *      Author: nikhil
 *      Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
 *
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution
{

private:
	unordered_map<int,int> returnCount(vector<int> &num)
	{
		unordered_map<int,int> mymap;
		vector<int>::iterator it;
		unordered_map<int,int>::iterator got;

		for(it=num.begin(); it!=num.end(); it++)
		{
			got = mymap.find(*it);
			if(got == mymap.end())
			{
				// element doesn't exist, add count
				mymap.insert(make_pair<int, int>((int)*it, (int)1));
			}
			else
			{
				got->second++;
			}
		}
		return mymap;
	}


public:
    int majorityElement(vector<int> &num)
    {
    	int element = 0;
    	unordered_map<int, int> myMap;
    	int elem_count = 0;
    	int majority = floor(num.size()/2);

    	// return count of each element
    	myMap = returnCount(num);

    	unordered_map<int, int>::const_iterator mapIter;

    	for(vector<int>::iterator it = num.begin(); it!=num.end(); it++)
    	{
			mapIter = myMap.find((int)*it);
			if(mapIter->second >= majority && mapIter->second > elem_count)
			{
			    elem_count = mapIter->second;
				element = mapIter->first;
			}
       	}

        return element;
    }

	int majorityElement_no_hash(vector<int> &num)
	{
		vector<int>::iterator it = num.begin();

		int major = it[0];
		int count = 1;

		for(unsigned int i=1; i<num.size();i++)
		{
			int element = it[i];
			if(!count)
			{
				count++;
				major=element;
			}
			else if(major==element)
			{
				count++;
			}
			else
				count--;

		}
		return major;

	}

};

int main()
{
	Solution s;
	vector<int> num;
	num.push_back(2);
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);

	cout << s.majorityElement_no_hash(num) << endl;

	return 0;
}
