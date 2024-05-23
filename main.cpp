#include <iostream>
#include "ArraySum.h"

using namespace std;

int main()
{	
	srand(time(0));

	const int arr_size = 10000000;
	const int thread_count = 5;

	ArraySum arr;
	arr._init(arr_size);
	arr._setThreadCount(thread_count);

	auto start = chrono::system_clock::now();
	arr._MultithreadCalculate(thread_count);
	auto end = chrono::system_clock::now();
	long diff = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	std::cout << "Sum: " << arr.getSum() << ", Multithread(" << thread_count << " thread(s)),  Time(ms) : " << diff << std::endl;

	start = chrono::system_clock::now();
	arr._OnethreadCalculate();
	end = chrono::system_clock::now();
	diff = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	std::cout << "Sum: " << arr.getSum() << ", Single thread, Time(ms) : " << diff << std::endl;

	return 0;
}