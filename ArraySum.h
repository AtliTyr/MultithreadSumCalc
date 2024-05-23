#pragma once
#include <vector>
#include <random>
#include <thread>
#include <iostream>

using namespace std;

class ArraySum
{
private:
	vector<int> arr;
	int size;
	unsigned int res;
	int threadCount;
public:
	ArraySum();
	~ArraySum() = default;

	void _setThreadCount(int c);
	void _init(const int sz);
	void _clear();

	void _calculateInterval(int l, int r);
	void _OnethreadCalculate();
	void _MultithreadCalculate(int threadCount);

	void _display();
	unsigned int getSum() const;
};

