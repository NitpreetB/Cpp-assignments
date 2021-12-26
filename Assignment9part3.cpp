#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>
using namespace std;

const double INT_TO_DOUBLE = 1.0;
const double MOVEDECIMAL =10.0; 

class Proper
{
  public:
    Properint()
	{
	    numerator1 = 1;
	    denominator1 = 2;	
	}
	
    Properint(int numerator, int denominator)
    {
	    numerator1 = numerator;
	    denominator1 = denominator;
	}
    
    int get_numerator()const
    {
    	return numerator1;
	}
	
    int get_denominator()const
    {
    	return denominator1;
	}
	
	void set_numerator(int numerator)
	{
		numerator1 = numerator;
	}
	
	void set_denominator(int denominator)
	{
		denominator1 = denominator;
	}
	
	bool check(int numerator, int denominator)
	{
		if (denominator1!=0 && (abs(numerator1)) < (abs(denominator1)))
	    {
	    	return true;
		}
		else
		{
			return false;
		}
	}
	
	double decimal(int decimalcount)
	{

		double number = (numerator1*(INT_TO_DOUBLE)/denominator1);
		double placeholder= number*(pow(MOVEDECIMAL,decimalcount));
		placeholder =round (placeholder);
		double newnum = (placeholder / pow(MOVEDECIMAL,decimalcount));
		
		
		return newnum ;
	}
	
	bool isExactlySame (Proper const & other)const
	{
		if (get_numerator() == other.get_numerator() && 
			get_denominator() == other.get_denominator())
		{
			return true;	
		}
		else 
		{
			return false;
		}
	}
	
	void output (ostream & out, double roundednum, double roundednum2)
	{
		out<< "the first rounded proper fraction is " << roundednum <<endl; 
		out << "the second rounded proper fraction is " <<roundednum2 <<endl;	
	}
	
  private:
    int numerator1,denominator1;
};

int main ()
{
	Proper frac1;
	Proper frac2;
	int numerator =0, denominator=0;
	int numerator1 =0, denominator2=0;
	int decimal1 =0, decimal2=0;
	double roundednum=0, roundednum2=0;
	
	cout << "Enter a numerator and a denominator of a fraction"<<endl;
	cin >> numerator>>denominator; 
	
	frac1.set_numerator(numerator);
	frac1.set_denominator(denominator);
	
	if (frac1.check(numerator,denominator) == true)
	{
		cout << "Enter the decimal number that you would like" 
		<<" the fraction to be rounded to" <<endl;
		cin >> decimal1; 
		roundednum =frac1.decimal(decimal1);
		
		cout<< "Enter a second numerator and second"
		<<" denominator of a proper fraction"<<endl;
		cin >> numerator1>>denominator2;
	
		frac2.set_numerator(numerator1);
		frac2.set_denominator(denominator2);
		
		if (frac2.check(numerator1,denominator2) == true)
		{
			cout << "enter the decimal number that you would like" 
			<<" the second fraction to be rounded to" <<endl;
			cin >> decimal2; 
			roundednum2 = frac2.decimal(decimal2);
			
			frac1.output(cout,roundednum,roundednum2);
		
				if ( frac1.isExactlySame(frac2) == true)
				{
					cout << "The two proper fractions are exactly the same"
						 <<endl;
				}
				else 
				{
					cout << "The two fractions are not the same" << endl;	
				}
		}
		else 
		{
			cout << "You did not enter a proper fraction" << endl;
		}	
	}
	else 
	{
		cout << "You did not enter a proper fraction" << endl;
	}
		
}


/*
enter a numerator and a denominator of a fraction
4  9
enter the decimal number that you would like the fraction to be rounded to
3
enter a second numerator and second denominator of a proper fraction
6 7
enter the decimal number that you would like the second fraction to be rounded to
3
the first rounded proper fraction is 0.444
the second rounded proper fraction is 0.857
the two fractions are not the same


enter a numerator and a denominator of a fraction
-3 -8
enter the decimal number that you would like the fraction to be rounded to
3
enter a second numerator and second denominator of a proper fraction
-7 18
enter the decimal number that you would like the second fraction to be rounded to
3
the first rounded proper fraction is 0.375
the second rounded proper fraction is -0.389
the two fractions are not the same


enter a numerator and a denominator of a fraction
1 3
enter the decimal number that you would like the fraction to be rounded to
3
enter a second numerator and second denominator of a proper fraction
1 3
enter the decimal number that you would like the second fraction to be rounded to
4
the first rounded proper fraction is 0.333
the second rounded proper fraction is 0.3333
the two proper fractions are exactly the same








*/

