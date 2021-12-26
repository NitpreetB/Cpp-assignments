/*
Nitpreet Bamra 
 	
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>
using namespace std;

const int MAX_TEA = 20;

class Tea
{
  public:
    Tea()
	{
	    privname = " ";
	    privherbal = 0 ;
		privstrength = 0; 	
	}
	
	Tea(string name, bool herbal, int strength)
    {
	    privname = name;
	    privherbal = herbal ;
		privstrength = strength; 
	}
    
    int get_strength()const
    {
    	return privstrength;
	}
	
	bool get_herbal () const
	{
		return privherbal;
	}
	
	string get_name () const
	{
		return privname;
	}
	
	void set_strength (int strength) 
	{
		privstrength = strength;
	}
	
	void set_herbal (int herbal) 
	{
		privherbal = herbal;
	}
	
	void set_name (string name) 
	{
		privname = name;
	}
	
	bool input (istream & in)
	{
		if (in ==cin)
		{}
		return in>>privname>>privherbal>>privstrength;
	}
	
	void output (ostream & out)
	{
		out << privname<<" "<<privherbal<<" "<<privstrength;
	}

	bool similar (Tea const & other)const
	{
		if (get_herbal () == other.get_herbal() && 
			get_strength() == other.get_strength())
		{
			return true;	
		}
		else 
		{
			return false;
		}
	}

  private:
    string privname;
    bool privherbal;
    int privstrength;
};

//c
int teanum (ifstream & tea, string teaname [MAX_TEA], bool herbaltea [MAX_TEA], int teastrength[MAX_TEA])
{
	string name = " ";
	bool herbal = 0;
	int strength = 0;
	int num = 0;
	
	while ( tea >> name >> herbal >> strength )
	{
		teaname [num] = name;
		herbaltea [num]= herbal;
		teastrength[num]= strength; 
		num ++;
	}
	
	return num;
}

//d 

void output (string teaname [MAX_TEA], bool herbaltea [MAX_TEA], int teastrength[MAX_TEA])
{
	
	
	
	
}


int main () 

{

	string name = " ";
	bool herbal = 0;
	int strength = 0;
	int num = 0;
	
	ifstream fileIn("tea.txt");
	if (!fileIn)
	{
		cout << "File not opened";
		return EXIT_FAILURE;
	}

	Tea teadata[MAX_TEA];

	while (teadata[num].input(fileIn))
	{
		num++;
	}
	
	teadata[3].output(cout);
	teadata[0].output(cout);
	teadata[20].output(cout);
	
	
	
	fileIn.close();
	return EXIT_SUCCESS;
}


