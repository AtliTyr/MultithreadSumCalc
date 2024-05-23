#include "ArraySum.h"

ArraySum::ArraySum()
{
	threadCount = 1;
	res = 0;
	size = 0;
}

void ArraySum::_setThreadCount(int c)
{
	if (c <= 0)
		return;

	threadCount = c;
}
void ArraySum::_init(const int sz)
{
	if (sz <= 0)
		return;

	_clear();
	size = sz;
	for (int i = 0; i < size; i++)
	{
		arr.push_back(rand() % 10 + 1);
	}
}

void ArraySum::_clear()
{
	arr.clear();
}

void ArraySum::_calculateInterval(int l, int r)
{
	int sum = 0;
	for (int i = l; i < r; i++)
	{
		sum += arr[i];
	}
	res += sum;
}
void ArraySum::_OnethreadCalculate()
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += arr[i];
	res = sum;
}
void ArraySum::_MultithreadCalculate(int threadCount)
{
	std::vector<std::thread> thr_arr;
	const int p = size / threadCount;

	int l = 0;
	int r = 0;

	res = 0;

	for (int i = 0; i < threadCount; i++)
	{
		if (i == threadCount - 1)
			r = size;
		else
			r += p;
		std::thread t(&ArraySum::_calculateInterval, this, l, r);
		thr_arr.push_back(std::move(t));

		l += p;
	}

	for (auto& t : thr_arr)
	{
		if (t.joinable())
			t.join();
	}

}

void ArraySum::_display()
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
unsigned int ArraySum::getSum() const
{
	return res;
}