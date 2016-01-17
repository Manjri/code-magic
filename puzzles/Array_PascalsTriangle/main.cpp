/**
 *     1
 *    1 1 
 *   1 2 1 
 *  1 3 3 1
 * 1 4 6 4 1
 *
 * This is how a Pascals traingle looks like
 * 
 * Generate a pascal's triangle given the number of rows
 *
 */


#include <iostream>
#include <vector>
#define NUM_ROWS 5

using namespace std;

class Solution{
	
	public: 

	vector< vector<int> > generate(int numRows){
	
		vector< vector<int> > result;

		if(numRows==0)
			return result;

		for(int i=0; i<numRows; i++){
		
			vector<int> temp;

			for(int j=0; j<=i; j++){
			
				if(i==0 || i==j)
					temp.push_back(1);
				else
					temp.push_back(result[i-1][j-1]+result[i-1][j]);
			
			}
			result.push_back(temp);
		}

		return result;
	}
};

int main(){

	Solution s;
	vector< vector<int> > result = s.generate(NUM_ROWS);

	for(int i=0; i<result.size(); i++){

		vector<int> temp = result[i];
	
		for(int j=0; j<temp.size(); j++)
			cout << temp[j] << " ";

		cout << endl;
	}

	return 0;
}

