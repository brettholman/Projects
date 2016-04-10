#include <iostream>
#include <Math.h>
#include <iomanip>
using namespace std;

const float pi = acos(-1);

float getPiToTheNth(int decimalPlaces) {
  cout << std::setprecision(decimalPlaces);
  return pi;
}

int main(const int argc, const char** argv) {
  // The name of the program is always passed in. 
  if(argc != 2) {
    cerr << "There can only be one and only one argument passed." << endl;
    return -1;
  }
  
  int decimalPlaces = std::atoi(*(argv + 1));

  if(decimalPlaces > 100) {
    cerr << "The program only supports a maximum of 100 decimal places" << endl;
    return -1;
  }

  cout << "The result is: " << endl << getPiToTheNth(decimalPlaces) << endl;;

  return 0;   
}
