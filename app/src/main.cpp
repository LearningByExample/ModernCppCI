#include "calc.hpp"
#include <iostream>

using namespace std;
using namespace ModernCppCI;

int main(int argc, char *argv[]) {
  cout << "Creating Calc" << endl;

  Calc calc = Calc();

  cout << "1 + 2 * 5 - 1 / 4 = " << calc[1]["+"][2]["*"][5]["-"][1]["/"][4] << endl;

  return 0;
}
