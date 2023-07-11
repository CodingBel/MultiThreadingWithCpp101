#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std::chrono; 
using namespace std; 

typedef unsigned long long ull; 
ull oddSum = 0; 
ull evenSum = 0; 

void findEven(ull start, ull end) {
	for (ull i = start; i <= end; i++) {
		if (i % 2 == 0)
			evenSum += i; 
	}
}

void findOdd(ull start, ull end) {
	for (ull i = start; i <= end; i++) {
		if (i % 2 != 0)
			oddSum += i;
	}
}

int main() {
	ull start = 0; 
	ull end = 1900000000; 

	auto startTime = high_resolution_clock::now(); 

	thread firstThread(findOdd, start, end);
	thread secondThread(findEven, start, end);

	firstThread.join(); 
	secondThread.join(); 

	//findOdd(start, end); 
	//findEven(start, end);

	auto stopTime = high_resolution_clock::now(); 

	auto duration = duration_cast <microseconds> (stopTime - startTime); 

	cout << "The Odd sum is: " << oddSum << endl; 
	cout << "The Even Sum is: " << evenSum << endl; 
	cout << "The program takes: " << duration.count() / 1000000 << " seconds" << endl;

	return 0; 
}










































