/*
Nitpreet Bamra and Shaery Khondokar	
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
		out << privname<<" "<<privherbal<<" "<<privstrength<<endl;
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

// Function C
int teanum (ifstream & fileIn, Tea teadata[MAX_TEA])
{
	int num = 0;
	
	while (teadata[num].input(fileIn))
	{
		num++;
	}
	
	return num;
}

//Function D

void print (Tea teadata[MAX_TEA], Tea favouriteTea, int teaNum, ostream & cout)
{
		bool similar = false; 
		
	
		for (int index = 0 ; index < teaNum; index ++)
		{
			if (favouriteTea.similar(teadata[index]) == true)
			{
				teadata[index].output(cout);
			}
		}

}


int main () 

{
	 int teaNum=0;
	
	 Tea teadata[MAX_TEA];
	 Tea earlGrey;
	 Tea peppermint;
	 
	 peppermint.set_herbal(1);
	 peppermint.set_strength(2);
	 
	 earlGrey.set_herbal(0);
	 earlGrey.set_strength(3);


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

	teaNum=teanum(fileIn,teadata);	
	cout << "The flavours that are similar to Carols morning tea are:"<< endl;
	print (teadata, earlGrey, teaNum,cout);
	
	cout << "The flavours that are similar to Carols afternoon tea are:"<< endl;
	print (teadata, peppermint, teaNum,cout);
	
	fileIn.close();
	return EXIT_SUCCESS;
}

/*

The flavours that are similar to Carols morning tea are
Jasmine_Green 0 3
The flavours that are similar to Carols afternoon tea are
Orange_Passionfruit 1 2
Kiwi_Lime 1 2


*/
