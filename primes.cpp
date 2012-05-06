#include <iostream>
#include <fstream>
#include "primes.h"
using namespace std;

void save(int list[10000])
{
    ofstream savefile;
    savefile.open("prime_numbers.txt");
    for(int z(0); z<10000; z++)
	{
        savefile << list[z] << "\n";
	}
	savefile.close();
}

int calculate(int limit)
{
	int nbr (1);
	int divisor(1);
	int nbr_is_prime(0);
	int prime_storage[10000];
	int nbr_of_prime(0);
	while(nbr < limit)
	{
		nbr_is_prime = 1;
		int divisor_limit(nbr/3+1);
		while(divisor < divisor_limit)
		{
			if (nbr % divisor == 0){divisor = nbr; nbr_is_prime = 0;}
			divisor += 2;
		}
		if (nbr_is_prime == 1)
		{
		    cout << nbr << endl;
            prime_storage[nbr_of_prime] = nbr;
		    nbr_of_prime++;
        }
		divisor = 3;
		nbr += 2;
		if (nbr_of_prime % 10000 == 0)
		{
			save(prime_storage);
			nbr_of_prime = 0;
		}

	}
	save(prime_storage);
	return 0;
}
