// Author Brett Holman
// Solution takes in one parameter and prints out the
#include <iostream>
#include <Math.h>
#include <iomanip>
#include <vector>
using namespace std;

const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499};

void calculatePrime(int num, vector<int> *values) {
  int debug = 0;
  for(int primeIndex = 0; num > 1 < num; ) {
    if(num % primes[primeIndex] == 0) {
      num /= primes[primeIndex];
      values->push_back(primes[primeIndex]);
      continue;
    }
    else {
      primeIndex++;
    }
  }
}

void printResults(bool isNegative, vector<int> *values) {
  for(int i = 0; i < values->size(); i++) {
    cout << values->at(i);
    if(i != values->size() - 1)
      cout << " X ";
  }
}

int main(const int argc, const char* argv[]) {

  bool isNegative;
  if(argc != 2) {
    cerr << "There can only be one and only one argument passed." << endl;
    return -1;
  }

  int value = std::atoi(*(argv + 1));

  // Prevents inputs such as "ff01", but does not prevent inputs such as "19ff"
  // "19ff" would be considered "19", checking for anything more would increase
  // runtime.
  if(value == 0 && (*(argv + 1))[0] != '0') {
      cerr << "You can not input a non-number" << endl;
      return -1;
  }

  if(value > 1000) {
      cerr << "This program only supports up to 1000" << endl;
      return -1;
  }

  isNegative = value < 0;
  vector<int> *results = new vector<int>();
  try {
    calculatePrime(value, results);
  } catch (exception e){cout << " here"; }
  //printResults(isNegative, results);

  delete results;
  return 0;
}
