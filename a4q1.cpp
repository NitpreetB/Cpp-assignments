/*
	Nitpreet Bamra
	Catherine Hsu
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>

using namespace std;

const double COST_KM = 2.6;
const double DISCOUNT = 0.75; 
const int COST_LEG = 15;

int main()
{
	ofstream fileOut ("report.txt");
	fileOut << setw(5) << "trip#" << setw(5) << "VIP" << setw(7) << "Stops" 
	<< setw(10) << "tripDist" << setw(10) << "tripCost" << setw(11) 
	<< "totalDist" << setw(11) << "totalCost" << endl;
	
	ifstream fileIn("taxi.txt");
	if (!fileIn)
	{
		cout << "File not opened";
		return EXIT_FAILURE;
	}
	
	int numTrips = 0, numStops = 0, tripNum = 0;
	bool vip = true;
	double xcoord1 = 0, ycoord1 = 0, xcoord2 = 0, ycoord2 = 0; 
	double totalDistance = 0, legDistance = 0, tripDistance = 0;
	double totalCost = 0, legCost = 0, tripCost = 0;
	double leastCost = 0, longestTrip = 0;
	
	while (fileIn>>vip>>numStops)
	{
		tripNum++;
		tripDistance = 0;
		tripCost = 0;
		for (int stopNum = 0; stopNum <= numStops; stopNum++) 
		{
			legCost = 0;
			legDistance = 0;
			if (!(stopNum == numStops)) 
			{
				fileIn >> xcoord2 >> ycoord2;
			}
			else 
			{
				xcoord2 = 0;
				ycoord2 = 0;
			}
			legDistance = 
			sqrt((pow(xcoord2 - xcoord1, 2)) + (pow(ycoord2 - ycoord1, 2)));
			tripDistance += legDistance;
			
			if (!(stopNum == numStops))
			{
				legCost = COST_KM * legDistance + COST_LEG;
			}
			else 
			{
				legCost = COST_KM * legDistance;
			}
			tripCost += legCost;
			
			xcoord1 = xcoord2;
			ycoord1 = ycoord2;
		}
		
		if (vip == 1) 
		{
			tripCost = tripCost * DISCOUNT;
		}
		if (tripNum <= 4 || (tripNum-4)%10 == 0)
			fileOut << fixed << setprecision(2) <<  setw(5) << tripNum 
			<< setw(5) << vip << setw(7) << numStops << setw(10) 
			<< tripDistance << setw(10) << tripCost;
		

			
		if (tripCost < leastCost || tripNum == 1)
		{
			leastCost = tripCost;	
		}
		if (tripDistance > longestTrip)
		{
			longestTrip = tripDistance;
		}
		
		totalDistance += tripDistance;
		totalCost += tripCost;
	if (tripNum <= 4 || (tripNum-4)%10 == 0)
			fileOut << setw(11) << totalDistance << setw(11) << totalCost 
			<< endl;
	}
	fileOut << "Cumulative Distance Travelled for all of August: " 
	<< totalDistance << endl;
	fileOut 
	<< "Cumulative amount collected from all customers for all of August: " 
	<< totalCost << endl;
	fileOut << "Length of the longest trip: " << longestTrip << endl;
	fileOut << "Cost of Least Expensive Trip: " << leastCost << endl;

}
/*
trip#  VIP  Stops  tripDist  tripCost  totalDist  totalCost
    1    0      1     20.40     68.04      20.40      68.04
    2    1      2     13.07     47.98      33.47     116.02
    3    0      4     40.72    165.86      74.18     281.88
    4    0      3     25.83    112.16     100.02     394.05
   14    0      4     26.46    128.79     410.38    1636.09
   24    1      2     25.01     71.27     752.64    2900.09
   34    0      3     21.75    101.55    1053.62    4052.71
   44    0      2     19.87     81.66    1307.69    4972.96
   54    0      5     33.90    163.14    1597.49    6030.68
   64    0      2     19.57     80.89    1874.82    7079.54
   74    1      2     13.53     48.88    2142.17    8064.27
Cumulative Distance Travelled for all of August: 2244.10
Cumulative amount collected from all customers for all of August: 8435.45
Length of the longest trip: 51.39
Cost of Least Expensive Trip: 38.95
*/
