#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


const int NUM_TOTAL = 50;
const int CALC_TOTAL = 25; 
int LOWESTSPOTMAX = 100;
int ARRAYFACTOR = -1;
int FULLPARKING = -1;

// b 

void read (ifstream & fincurr, ifstream & finadd, string namecurr [NUM_TOTAL], 
		int staffcurr [NUM_TOTAL], int parkingspot [NUM_TOTAL], int staffadd 
		[CALC_TOTAL], string nameadd [CALC_TOTAL] )
{
  int num=0; 
  int staff = 0, parknum = 0;
  int staffadd1 =0;
  string name = " ";
  string nameadd1 = " ";
  
	while (fincurr >> staff >> name >> parknum)
		{
		staffcurr [parknum+ARRAYFACTOR] = staff;   
		namecurr [parknum+ARRAYFACTOR] = name;
		parkingspot [parknum+ARRAYFACTOR] = parknum;  
		} 
	
	while ( finadd >> staffadd1 >> nameadd1)
		{
		staffadd [num] = staffadd1;
		nameadd [num] = nameadd1;
		num++;	
		}
  
  
}

// c

void removename (ifstream & finremove, string parkremove [CALC_TOTAL])
{
  
 int staff = 0;
 int num=0;
 string name = " ";

	 while ( finremove >> staff >> name)
	{
		parkremove [num] = name;
		num++;	
	}
			  
}

//d
void remove (string namecurr [NUM_TOTAL],  int parkingspot [NUM_TOTAL], 
			string nameRemove)
{

    for (int index=0 ; index<NUM_TOTAL; index++)
    {
      if (nameRemove == namecurr [index] )
      {
        namecurr [index] = " ";
        parkingspot[index]= 0;
      }
    }
  
}

// e
int lowestspot ( int parkingspot [NUM_TOTAL], int status)
{
	int lowspot= 0;
	lowspot = LOWESTSPOTMAX;
  
    if (status==1)
    {
      for (int index=0; index<CALC_TOTAL; index++)
      {
        if (parkingspot [index] == 0 && index < lowspot)
        {
		  lowspot=index;
        }
      }
    }
    else 
    {
      for (int index2 =CALC_TOTAL; index2<NUM_TOTAL; index2++) 
      {
        if (parkingspot [index2] == 0 && index2 < lowspot  )
        {
          lowspot = index2;
        }
      }
      
    }
  
  if ( lowspot == LOWESTSPOTMAX)
  {
    return FULLPARKING; 
  }
  else 
  {
  return lowspot; 
  }
}

//f 

bool full (string namecurr [NUM_TOTAL], int parkingspot [NUM_TOTAL], 
			int status, string name )
{

  int spot =0;
  spot = lowestspot (parkingspot, status);
  
  if (spot > FULLPARKING)
    {
    	namecurr [spot] = name; 
    	parkingspot [spot] = spot+1;
    	return true;
    } 
  else 
    {
    	return false; 
    } 

}

//g 
void movestaff (string namecurr [NUM_TOTAL], int staffcurr [NUM_TOTAL], 
				int parkingspot [NUM_TOTAL], int staffadd [CALC_TOTAL] )
{
  
  for (int index =0; index< NUM_TOTAL ; index ++)
  {
    if (staffcurr [index] >0 && parkingspot[index]>CALC_TOTAL )
    {
    	int statustwo = staffcurr [index];
    	string nametwo = namecurr [index];
    	remove (namecurr,parkingspot,nametwo);
		full (namecurr, parkingspot,statustwo, nametwo);
	}
  }

}

//h 

void output (ofstream & fileOut, string namecurr [NUM_TOTAL], 
			 int staffcurr [NUM_TOTAL], int parkingspot [NUM_TOTAL])
{
	for (int index =0; index < NUM_TOTAL ; index ++)
  	{
		fileOut << setw(20) << namecurr [index] << setw(5) 
		<< parkingspot [index] << endl;
	}
}
	

// i 

int main()
{
	
	ofstream fileOut ("parking_update.txt");
	ifstream finremove("parking_remove.txt");
	ifstream finadd("parking_add.txt");
	ifstream fincurr("parking_current.txt");
	
	if (!finremove || !finadd || !fincurr)
	{
		cout << "file not opened" << endl;
		return EXIT_FAILURE;
	}

	string namecurr [NUM_TOTAL];
	int staffcurr [NUM_TOTAL] = {0};
	int parkingspot [NUM_TOTAL] = {0};
	int staffadd [CALC_TOTAL] = {0};
	string nameadd [CALC_TOTAL];
	string parkremove [CALC_TOTAL]; 
	
	read (fincurr,finadd,namecurr,staffcurr,parkingspot, staffadd, nameadd);
	removename (finremove,parkremove);
	
	for (int index=0; index <CALC_TOTAL ; index++)
		{
		  remove (namecurr, parkingspot, parkremove[index]); 
		}
		
	movestaff(namecurr, staffcurr, parkingspot, staffadd );
	
	for (int index2=0; index2 <CALC_TOTAL ; index2++)
		{
		  if ((full (namecurr,  parkingspot, staffadd [index2],
		  nameadd [index2]))==false)
		  
		  {
		  	cout << nameadd [index2] <<endl;
		  }
		}
	
	output (fileOut, namecurr, staffcurr, parkingspot);
		
	
	finremove.close();
	finadd.close();
	fincurr.close();
	fileOut.close();
}

/*
Sample Console output 

Swayer_Tim
Sheng_Gloria

Sample File output

         Bishop_Bill    1
         Nairn_David    2
       Meunier_Sarah    3
        Dunbar_Fiona    4
           Lau_David    5
           Owen_Bill    6
      Lokker_Shirley    7
           Saad_John    8
       Trelford_Ryan    9
           Kim_Chuck   10
         Davison_Dan   11
     Kennings_Andrew   12
         Hasan_Anwar   13
       Brown_Natalie   14
      Patel_Muhammad   15
Chandrashekar_Naveen   16
  Stachowsky_Michael   17
         Babaee_Reza   18
                        0
      Harder_Douglas   20
        Consell_Ryan   21
                        0
       Mansour_Firas   23
      Cramer_Zachary   24
     Hamilton_Jordan   25
           Yeum_Alla   26
        English_Lisa   27
       Windsor_Harry   28
        Nassar_Ahmed   29
      Lacroix_Cheryl   30
     Hitchinson_Joan   31
            Reed_Jim   32
      Martins_Joshua   33
          Tung_Clive   34
    Ladouceur_Yvonne   35
            Oh_Henry   36
         Mansour_Ali   37
          Lim_Lilian   38
        Zurell_Katie   39
      Zhang_Yung-Yee   40
          Wiens_Rosa   41
            Chen_Ben   42
      El-Hag_William   43
          Mayer_Adam   44
         Parks_Flora   45
       Unger_Charles   46
       Zalewski_Mary   47
        Allen_Adrian   48
      ElShaSha_Ahmed   49
       Reddock_Julia   50
*/
