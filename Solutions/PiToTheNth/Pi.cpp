// Author Brett Holman
// Solution takes in one parameter and prints out pi to that number of decimal places (max of 45).  
#include <iostream>
#include <Math.h>
#include <iomanip>
using namespace std;

int main(const int argc, const char* argv[]) {
  // The name of the program is always passed in. 
  if(argc != 2) {
    cerr << "There can only be one and only one argument passed." << endl;
    return -1;
  }
  
  int decimalPlaces = std::atoi(*(argv + 1));
  
  // Prevents inputs such as "ff01", but does not prevent inputs such as "19ff"
  // "19ff" would be considered "19"
  if(decimalPlaces == 0 && (*(argv + 1))[0] != '0') {
      cerr << "You can not input a non-number" << endl;
      return -1;
  }
  
  if(decimalPlaces < 0) {
      cerr << "You can not print a negative number of decimal places" << endl;
      return -1;
  }
  
  if(decimalPlaces > 45) {
    cerr << "The program only supports a maximum of 45 decimal places" << endl;
    return -1;
  }

  // arccos(-1) == pi
  // decimalPlaces + 1 includes "3."
  cout << "The result is: " << endl << std::setprecision(decimalPlaces + 1) << acos(-1) << endl;

  return 0;   
}
