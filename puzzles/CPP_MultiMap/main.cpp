#include <iostream>
#include <map>
using namespace std;

void printMap(multimap<char,int> *map){

	multimap<char,int>::iterator it = map->begin();

	for(;it!=map->end();it++)
		cout << it->first << "-->" << it->second << endl;
}

int main(){

	multimap<char,int> mymm;

	mymm.insert(make_pair('x',10));
	mymm.insert(make_pair('y',20));
	mymm.insert(make_pair('z',30));
	mymm.insert(make_pair('z',40));
	printMap(&mymm);
	
	// erase 
	multimap<char,int>::iterator it = mymm.find('x');
	mymm.erase(it);
	mymm.erase(mymm.find('z'));
	
	cout << "After Erasing..." << endl;
	printMap(&mymm);


	return 0;

}

