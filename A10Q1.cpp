/*
Nitpreet Bamra and Shaery Khondokar
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX_ROW =200;
const int MAX_COL=79; 


int picture ( char image[MAX_ROW][MAX_COL], ifstream & fin )
{
	int height=0;
	int row=0;
	int col=0;
	char character;
	
	fin >>height;
	
	 while ( fin>>row>>col>>character)
	 image[row][col]=character;
	
	return height;	
}

void output ( char image[MAX_ROW][MAX_COL],int height, ostream & cout )
{

	for (int row = 0 ; row < height ; row++)
	{
		cout << endl;
	
		for (int col = 0 ; col<MAX_COL; col++)
		{
			cout << image[row][col];
		}	
	}
}

int main ()
{
	
	char image [MAX_ROW][MAX_COL]= {};
	
	int height = 0;
	string filename;
	
	cout<<"Enter filename";
	cin>>filename;
	ifstream fin (filename.c_str());
	
	if (!fin)
	{
		cout << "File not opened";
		return EXIT_FAILURE;
	}

	height=picture (image,fin);
	output(image,height, cout);
	
	

	return EXIT_SUCCESS;
	
	
}

/*

Enter filename homer_mapped.txt

                             __
                   _ ,___,-'",-=-.
       __,-- _ _,-'_)_  (""`'-._\ `.
    _,'  __ |,' ,-' __)  ,-     /. |
  ,'_,--'   |     -'  _)/         `\
,','      ,'       ,-'_,`           :
,'     ,-'       ,(,-(              :
     ,'       ,-' ,    _            ;
    /        ,-._/`---'            /
   /        (____)(----. )       ,'
  /         (      `.__,     /\ /,
 :           ;-.___         /__\/|
 |         ,'      `--.      -,\ |
 :        /            \    .__/
  \      (__            \    |_
   \       ,`-, *       /   _|,\
    \    ,'   `-.     ,'_,-'    \
   (_\,-'    ,'\")--,'-'       __\
    \       /  // ,'|      ,--'  `-.
     `-.    `-/ \'  |   _,'         `.
        `-._ /      `--'/             \
-hrr-      ,'           |              \
          /             |               \
       ,-'              |               /
      /                 |             -'

--------------------------------
Process exited after 22.64 seconds with return value 0
Press any key to continue . . .

Enter filename mickey_mapped.txt

                            _____
                        .d88888888bo.
                      .d8888888888888b.
                      8888888888888888b
                      888888888888888888
                      888888888888888888
                       Y8888888888888888
                 ,od888888888888888888P
              .'`Y8P'```'Y8888888888P'
            .'_   `  _     'Y88888888b
           /  _`    _ `      Y88888888b   ____
        _  | /  \  /  \      8888888888.d888888b.
       d8b | | /|  | /|      8888888888d8888888888b
      8888_\ \_|/  \_|/      d888888888888888888888b
      .Y8P  `'-.            d88888888888888888888888
     /          `          `      `Y8888888888888888
     |                        __    888888888888888P
      \                       / `   dPY8888888888P'
       '._                  .'     .'  `Y888888P`
          `"'-.,__    ___.-'    .-'
         jgs  `-._````  __..--'`

--------------------------------
Process exited after 12.3 seconds with return value 0
Press any key to continue . . .


Enter filename st_basils_mapped.txt

                            .
                            T
                           ( )
                          <===>
                           F|J
                           ===
                          J|||F
                          F|||J
                         /\/ \/\
                         F+++++J
                        J{}{|}{}F         .
                     .  F{}{|}{}J         T
          .          T J{}{}|{}{}F        ;;
          T         /|\F/\/\|/\/\J  .   ,;;;;.
         /:\      .'/|\\:=========F T ./;;;;;;\
       ./:/:/.   ///|||\\\"""""""" /x\T\;;;;;;/
      //:/:/:/\  \\\\|////..[ ]...xXXXx.|====|
      \:/:/:/:T7 :.:.:.:.:||[ ]|/xXXXXXx\|||||
      ::.:.:.:A. `;:;:;:;'=== ==\XXXXXXX/=====.
      `;""::/xxx\.|,|,|,| ( ) ( )| | | |.=..=.|
       :. :`\xxx/(_)(_)(_) _   _ | | | |'-''-'|
       :T-'-.:"":|"""""""|/ \ / \|=====|======|
       .A."""||_|| ,. .. || | | |/\/\/\/ | | ||
   :;:////\:::.'.| || || ||-| |-|/\/\/\+|+| | |
  ;:;;\////::::,='======='=============/\/\=====.
 :;:::;""":::::;:|__..,__|============/||\|\====|
 :::::;|=:::;:;::|,;:::::          |========|   |
 ::l42::::::(}:::::;::::::_________|========|___|__

--------------------------------
Process exited after 8.361 seconds with return value 0
Press any key to continue . . .


*/


 
