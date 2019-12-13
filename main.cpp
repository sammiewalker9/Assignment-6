#include <iostream>
#include "Sorting.h"

using namespace std;

int main(int argc, char** argv){
  Sorting s;

  if (argc >= 2 ){
    string file = argv[1];
    s.readFile(file);
  }
  return 0;
}
