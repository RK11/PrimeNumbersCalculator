#include <iostream>
#include "primes.h"
using namespace std;

int main()
{
	int limit(0);
	cout << "Limit : ";
	cin >> limit;
	calculate(limit);
	return 0;
}
