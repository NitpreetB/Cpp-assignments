/*
Nitpreet Bamra and Shaery Khondokar 
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

double pi (int num)
{
	if (num != 1)
	return ((4*pow((-1),num-1))/((2*num)-1) + pi(num-1));
	else 
	return ((4*pow((-1),num-1))/((2*num)-1));
	
}

int main () 
{

	int num = 0;
	double total = 0;
	
	cout << "Please enter the number of terms in the series you want to use "
			<<endl;
	cin >> num ; 
	total = pi (num);
	cout << "If the series has " << num 
		<< " terms then the approximate value of pi is " <<fixed
		<< setprecision(6)<< total; 	

	return EXIT_SUCCESS;
}

/*

Please enter the number of terms in the series you want to use
10
If the series has 10 terms then the approximate value of pi is 3.041840
--------------------------------
Process exited after 4.706 seconds with return value 0
Press any key to continue . . .


Please enter the number of terms in the series you want to use
100
If the series has 100 terms then the approximate value of pi is 3.131593
--------------------------------
Process exited after 3.484 seconds with return value 0
Press any key to continue . . .


Please enter the number of terms in the series you want to use
1000
If the series has 1000 terms then the approximate value of pi is 3.140593
--------------------------------
Process exited after 3.592 seconds with return value 0
Press any key to continue . . .


Please enter the number of terms in the series you want to use
10000
If the series has 10000 terms then the approximate value of pi is 3.141493
--------------------------------
Process exited after 7.416 seconds with return value 0
Press any key to continue . . .




*/

 
