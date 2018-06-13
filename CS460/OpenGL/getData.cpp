/***

CS 460/560 Little Bighorn Project Data

data is in the form of a two dim matrix mvmtDataMatrix = [units][time]

with


rows indexed by units
and columns by time.


contrary to previous statements, 1:30pm is the
first time and 6:40pm is the last time so there are 32 columns.

[NOTE THAT THIS MEANS THERE WILL BE 32 TIME STEPS]

the
row order is as follows:

* (Custer's headquarters unit)
F
C
E
I
L
A (A, M & G are Reno's command)
M
G
H (H, D & K are Benteen's command)
D
K
B (packtrain guard)
packtrain (blank cavalry unit)
C (Crazy Horse,  Oglala warchief)
G (Gall, Hunkpapa warchief)
34 blank indian units


entries take the form of ....;x,y;;..... where x and y are the pixel
location of the CENTER of the unit. two ; together represent a null
entry meaning the unit does not move during that interval. a # means
that that particular cavalry unit will appear on the map for the first
time during the next interval. a $ means that a cavalry unit disappears
(all dead). only cavalry appear and disappear; the indians are all
present at the beginning and at the end. although Gall and Crazy Horse
are listed first, it might be a good idea to draw them last since indian
units overlap on numerous occasions and G and C are the only indian units
that have id's on them.


*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


string nameUnitsByRowNum(int unitRowNum);

int main () {

   string unitName = "custer'sRow"; // default Unit and Row 1
   vector<string> unitNameVector = {"*","F","C","E","I",
                                    "L","A","M","G","H",
                                    "D","K","B", "packtrain",
                                    "C","G"};

   int numOfBlankIndianUnits = 34;

   const string timeColStart = "13:30pm"; // default time
   const string timeColStop = "6:40pm"; // default time

   const double timeStart = 1.5; // floating point estimate
   const double timeEnd = 6.66; // floating point estimate

   const int numberOfCols = 32; // the discrete time slots

   const double avgWaitTime = numberOfCols / (timeEnd - timeStart);

   cout << "Avg wait time: " << avgWaitTime;



   int numberOfRows = 0;

   int x,y; // Grid Coords = Positions (Center of Unit)


   ifstream movmtData("movement.data");
   string unitRow = "";

   if(movmtData.is_open())
      {
      while(getline(movmtData,unitRow))
         {
            // Row counter
            numberOfRows++;

            // Get First Rows starting with #
            if((unitRow[0] == '#'))
            {
            // Print the x-coord start position for each unit
            cout << "(" << unitRow[2] << unitRow[3] << unitRow[4]
            << "," << unitRow[6] << unitRow[7] << ")" << endl;
            }

            // Get Rows starting with ;
            if((unitRow[0] == ';'))
            {

            }



            /// Get the units that move first
            if((unitRow[0] != '#') && (unitRow[0] != ';'))
            {
            // Print the x-coord start position for each unit
            cout << "(" << unitRow[0] << unitRow[1] << unitRow[2]
            << "," << unitRow[4] << unitRow[5] << unitRow[6] << ")" << endl;
            }

//            /// Alert when units are not moving
//            for(i in unitRow )
//            {
//                if i and i+1 == ";"
//            }
          }

      //cout << unitRow.length() << endl;
      }
      movmtData.close();

      cout << endl;
      cout << "The number of rows: " << numberOfRows << endl;
      for(int i = 0; i < numberOfRows; i++)
      {
          unitNameVector.push_back(nameUnitsByRowNum(i));
          cout << unitNameVector[i] << endl;
      }




      return 0;
}

string nameUnitsByRowNum(int unitRowNum)
{




}
