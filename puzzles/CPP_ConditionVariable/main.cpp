#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

// globals
mutex m;
condition_variable cv;

// shared data
string data;

// sync flags
bool ready = false;
bool processed = false;

void worker_thread(){

	// wait till mail() sends data
	// we still need to grab a lock!
	unique_lock<mutex> lk(m);
	cv.wait(lk, []{return ready;});

	// after wait we own the lock!
	// main needs to wait till worker thread completes
	cout << "Worker thread is processing data\n";
	data += " after processing";

	// send data back to main()
	processed = true;
	cout << "Worker thread signals data processing completed\n";


	// Manual unlocking is done before notifying to avoid waking up
	// the waiting thread only to block again
	lk.unlock();
	cv.notify_one();
	
}



int main(){

	thread worker(worker_thread);
	data = "Example data";

	// send data to worker thread
	{
		lock_guard<mutex> lk(m);
		ready = true;
		cout << "main() signals data ready for processing\n";
	}
	// inform the worker thread that it can proceed
	cv.notify_one();

	// wait for the worker to complete
	{
		unique_lock<mutex> lk(m);
		cv.wait(lk, []{return processed;});
	}

	cout << "Back in main(), data = " << data << '\n';

	worker.join();

}

