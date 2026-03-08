/*Number Square
--------------
   1      1
   2      4
   3      9
   4     16
   5     25
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main() {

  int num;
  
  cout << "Number Square \n";
  cout << "--------------\n";
  
  for (num = 1; num <= 5; num++)
  {
      cout << setw(4) << num << setw(7) << (num * num) << endl; 
  }
  return 0;
}