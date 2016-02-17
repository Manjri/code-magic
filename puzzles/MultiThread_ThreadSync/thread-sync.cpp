#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

//globals
mutex m;
condition_variable cv;

//shared data
unsigned int count = 0;

bool t2_go = false;
bool t1_go = true;

void t1_main(){

	while(1){
		unique_lock<mutex> lk(m);
		cv.wait(lk, []{return t1_go;});
		cout << "In T1:" << ++count << endl;
		t1_go = false;
		t2_go = true;
		lk.unlock();
		cv.notify_one();
	}

}

void t2_main(){

	while(1){
		unique_lock<mutex> lk(m);
		cv.wait(lk, []{return t2_go;});
		cout << "In T2:" << ++count << endl;
		t2_go = false;
		t1_go = true;
		lk.unlock();
		cv.notify_one();
	}
}


int main(){

	cout << "In Main" << endl;
	thread t1(t1_main);
	thread t2(t2_main);
	t1.join();
	t2.join();

	return 0;

}







