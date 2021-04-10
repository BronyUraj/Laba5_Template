#include "Header.h"
#include <iostream>
using namespace std;

int main() {
	Queue<int> Q1 = 5;
	Queue<string> Q2("Test1");
	Q1.push(123);
	Q2.push("Test2");
	cout << Q1 << endl;
	cout << Q2 << endl;
	return 0;
}