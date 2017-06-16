#include<iostream>
#include "Calc.hpp"

using namespace std;
using namespace ModernCppCI;

int main(int argc, char *argv[]){
   cout << "Creating Calc" << endl;
   
   Calc calc = Calc();

   cout << "2 + 2 = " << calc["+"](2, 2) << endl;

   return 0;
}