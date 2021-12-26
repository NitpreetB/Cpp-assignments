/*
Nitpreet Bamra 
Kareem Mansour 	
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>
using namespace std;

// declare constants 
const double PAVING_SQ_M = 19.50; 
const double FENCING_SQ_M = 27.00; 
const double GATE = 150.00;
const double ADMINISTRATION = 45.00;
const double HST = (0.13);

//function 1
double triPerim (double side1, double side2, double side3)
{
	double perim = 0;
	perim = side1+side2+side3;
	return perim;
}

double triArea( double side1, double side2, double side3 )
{
    double Area=0, semiperim =0;
	semiperim = triPerim( side1, side2, side3);
    semiperim /= 2.0;
    Area = sqrt((semiperim * (semiperim - side1) * (semiperim - side2)* 
	(semiperim - side3)));
    return Area;
	
}


double quadPerim(double side1, double side2, double side3, double side4)
{
    double quadPerimeter = side1 + side2 + side3 + side4;
    return quadPerimeter;
}

// function 4

double quadArea (double side1, double side2, double diagonal)
{
	
	double quadarea=0; 
	quadarea= (triArea (side1, side2, diagonal))*2;
	return quadarea;
}

//function 5

double fencecost (double accFenceLen)
{
	double fencecost = 0;
	
	if (accFenceLen>0)
	{
	fencecost =accFenceLen*FENCING_SQ_M + GATE;		
	}
	else 
	{
	fencecost =0;	
	}
	return fencecost;
}


int main () 

{

	ofstream fileOut ("output.txt");
	
	fileOut << setw(5) << "Job#" << setw(7) << "Fence" << setw(17) 
	    << "ActualPavedArea" << setw(10) << "PaveCost" << setw(20) 
	    << "ActualFenceLength" << setw(11) << "FenceCost" << setw(11) 
	    << "Taxes" << setw(15) << "Total" << endl;
	
	
	ifstream fileIn("Sep_Jobs.txt");
	if (!fileIn)
	{
		cout << "File not opened";
		return EXIT_FAILURE;
	}

	bool fencing = true; 
	double actualPaved = 0,  paveCost = 0 ,  accFenceLen = 0;
	double fenceCost = 0, taxes = 0,  totalCost = 0, Jobnum = 0;
	double side1 =0,  side2=0,  side3=0,  side4=0;
	double diagonal = 0;
	string shape = " ";

	while (fileIn>>Jobnum>> fencing >> shape)
		{
	
		if ( shape == "quad")
		{
			fileIn >> side1 >> side2 >> diagonal >> side3 >> side4;		
			actualPaved = ceil(quadArea(side1, side2, diagonal));
				if ( fencing == true)
				{
				accFenceLen = quadPerim(side1, side2, side3, side4);
				fenceCost = fencecost (accFenceLen);	
				}
				else 
				{
				accFenceLen = 0;
				fenceCost = fencecost (accFenceLen);	
				}		
		}
		else 
		{
			fileIn >> side1 >> side2 >> side3;
			actualPaved = ceil(triArea( side1,side2,side3));	
		
			if ( fencing == true)
					{
					accFenceLen = triPerim(side1, side2, side3);
					fenceCost = fencecost (accFenceLen);		
					}
					else 
					{
					accFenceLen = 0;
					fenceCost = fencecost (accFenceLen);		
					}
		}
		paveCost = actualPaved * PAVING_SQ_M;
		taxes = (fenceCost + paveCost + ADMINISTRATION)*HST;
		totalCost = fenceCost + paveCost + ADMINISTRATION + taxes;
		
		fileOut << fixed << setprecision(0) <<  setw(5) << Jobnum  
			<< setw(7) << fencing << setprecision(2) << setw(15) << actualPaved 
			<< setw(12) << paveCost << setw(18) << accFenceLen << setw(12) 
			<< fenceCost << setw(12) << taxes << setw(16) << totalCost <<endl;

		}
	
	fileIn.close();
	fileOut.close();
	
	
	return EXIT_SUCCESS;
}


