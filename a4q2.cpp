/*
	Nitpreet Bamra
	Catherine Hsu
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int MIN_BASE = 3;
const int MAX_BASE = 9;
const int TRUNK_NUM = 4;

int main () 
{

	int base = 0;
	cout << "How many asterisks is in the base of your tree? ";
	cin >> base;

	do 
	{
		if ((base < MIN_BASE || base > MAX_BASE) || base%2==0)
		{
			cout << "Invalid input! Try again." << endl;
			cin >> base;
		}
	} while ((base < MIN_BASE || base > MAX_BASE) || base%2==0);
	
if (base==3)
{
cout<< setw(base-1) << "*" << endl;
cout<< "***" <<endl;
}
else if (base ==5 )
{
cout<< setw(base-2) << "*" << endl;
cout<< setw(base-1) << "***" <<endl;
cout<<  "*****" << endl;

}
else if (base == 7)
{
cout<< setw(base-3) << "*" << endl;
cout<< setw(base-2) <<  "***" <<endl;
cout<< setw(base-1) << "*****" << endl;	
cout<< "*******" << endl;	
}	
else 
{
cout<< setw(base-4) << "*" << endl;
cout<< setw(base-3) << "***" <<endl;
cout<< setw(base-2) << "*****" << endl;	
cout<< setw(base-1) << "*******" << endl;
cout<<"*********" << endl;
}

// outputs the trunk
	
	for (int row = 0; row < TRUNK_NUM ; row++)
	{
		cout << setw((base/2)+1) << "*";
		cout << setw((base/2)+1) << endl;
		
	}
	
}
/*
How many asterisks is in the base of your tree? 2
Invalid input! Try again.
4
Invalid input! Try again.
11
Invalid input! Try again.
3
 *
***
 *
 *
 *
 *
 
 How many asterisks is in the base of your tree? 5
  *
 ***
*****
  *
  *
  *
  *
  
  


*/
