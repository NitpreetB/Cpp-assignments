/*
Nitpreet Bamra
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
	
	cout << " please enter the number of terms in the series you want to use ";
	cin >> num ; 
	total = pi (num);
	cout << "if the seris has" << num 
		<< " terms than the approxomate value of pi is " << total; 	


	return EXIT_SUCCESS;
}


