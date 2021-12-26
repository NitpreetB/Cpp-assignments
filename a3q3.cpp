/*
Nitpreet Bamra 
Luke Johnston
*/

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
  //declaring variables
   
  double angle = 0.0, side1 = 0.0, side2=0.0; 
  
  cout << "Please input two side lengths and an angle" <<endl;
  cin >> side1 >> side2 >> angle;
  
  if (angle < 0 || angle > 180 || side1 < 0 || side2 < 0)
  {
    cout<< "Invalid input." <<endl; 
    cout<<"Please input two side lengths and an angle that is within the range"
    << endl;
    cin >> side1 >> side2 >> angle;
  }
  
  // output 
  
  if ( angle > 89.5 && angle < 90.5)
  {
    if (side1+0.1 == side2 || side1-0.1 == side2)
    {
      cout << "The paving stone is a square" << endl;
    }
    else 
    {
      cout << "The paving stone is a rectangle" << endl;
    }
  }
  else
  {
    cout << "the paving stone is a paralellogram"<<endl;
  }
  system  ("PAUSE");
  return EXIT_SUCCESS;
} 

/*
Please input two side lengths and an angle
-1 3 95
Invalid input. 
Please input two side lengths and an angle that is within the range

Please input two side lengths and an angle
2.1 2 89.9
The paving stone is a square

Please input two side lengths and an angle
5 8 90
The paving stone is a rectangle

Please input two side lengths and an angle
5 5 45
the paving stone is a paralellogram


*/