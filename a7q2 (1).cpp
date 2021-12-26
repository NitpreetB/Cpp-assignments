/*
Authors: Chee Lam (Jacky) Lim & Nitpreet Bamra
Group: 6
Date: 2021-10-27
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

const double CONVERSION_LAT = 111.0;
const double DEG_TO_PI = 180.0;
const int MAXSPILL = 10;

void km (double & latitude, double & longitude) 
{
	double anglerad = 0;
	anglerad = latitude*(M_PI/DEG_TO_PI);

	latitude = latitude*CONVERSION_LAT;
	longitude = CONVERSION_LAT*cos(anglerad);
}

double distance (double x1, double x2, double y1, double y2) 
{
	double distance = 0;
	distance = sqrt((pow((x2-x1),2)) + (pow((y2-y1),2)));

	return distance;
}

bool overlap (double x1, double x2, double y1, double y2, double radius) 
{
	double alt_dist = 0;
	alt_dist = (distance(x1, x2, y1, y2) - radius);
 
	if (alt_dist <= radius) 
	{
		return true;
	} 
	else 
	{
		return false;
	}
}

bool location (double x1, double x2, double y1, double y2, double radius) 
{
	double dist_two = 0;
	dist_two = (distance(x1, x2, y1, y2));
	
	if (dist_two <= radius) 
	{
		return true;
	} 
	else 
	{
		return false;
	}
}

int main () 
{
	ifstream inFile1("spill.txt");
	ifstream inFile2("location.txt");
	if(!inFile1 || !inFile2) 
	{
		cout << "File could not be opened";
		return EXIT_FAILURE;
	}

	double latitude [MAXSPILL] = {0};
	double longitude [MAXSPILL] = {0};
	double radius [MAXSPILL] = {0};

	int index = 0, spill_num = 0, reaction_counter = 0;
	double location_x = 0, location_y = 0;
	string location_name = " ";

	inFile1 >> spill_num;

	while (inFile1 >> latitude[index] >> longitude[index] >> radius[index]) 
	{
		km(latitude[index], longitude[index]);
		index++;
	}

	while (inFile2 >> location_name >> location_x >> location_y) 
	{
		int spill_counter = 0;
		km(location_x, location_y);

		for (int counter = 0; counter < spill_num; counter++) 
		{
			if (location(location_x, latitude[counter], location_y,
			    longitude[counter], radius[counter]) == true) 
			{
				spill_counter++;
			}
		}

		if (spill_counter > 0) 
		{
			cout << setw(28) << location_name << ": affected by "
				 << spill_counter << " spill(s)" << endl;
		}
	}
	
	for (int x = 0; x < spill_num; x++)
	{
		for (int y = x + 1; y < spill_num; y++)
		{
		if (overlap(latitude[x], latitude[y], longitude[x], longitude[y],
		    radius [x]) == true) 
			{
				reaction_counter++;
			}
		}
	}

	cout << setw(48) <<  " The total number of reactions were " 
		 << reaction_counter << "."; 
		 
	inFile1.close();
	inFile2.close();
	return EXIT_SUCCESS;
}

/*
	            	WEEF_Lab: affected by 3 spill(s)
          Ryan_Favourite_Pub: affected by 5 spill(s)
                 Carol_House: affected by 3 spill(s)
                  WCI_School: affected by 3 spill(s)
        Grand_River_Hospital: affected by 3 spill(s)
                         RCH: affected by 3 spill(s)
                 SJAM_School: affected by 3 spill(s)
               Michael_House: affected by 1 spill(s)
   Waterloo_Regional_Airport: affected by 1 spill(s)
         Perimeter_Institute: affected by 2 spill(s)
          Waterloo_City_Hall: affected by 5 spill(s)
       Pineview_Nursing_Home: affected by 2 spill(s)
              Conestoga_Mall: affected by 1 spill(s)
                 Fiona_House: affected by 3 spill(s)
           St_Marys_Hospital: affected by 3 spill(s)
             The total number of reactions were 10.
*/
