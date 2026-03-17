#include <iostream>
#include <vector>
using namespace std;
int main()
{
  vector<int> v1 = {10, 20, 30, 40};
  vector<string> v2 = {"Kerla", "Bbsr", "Delhi"};

  // How to access vector elements?
  // 1. using [] it does not check for bound checking
  for (int i = 0; i < v1.size(); i++)
    cout << v1[i] << " ";
  cout << endl;
  // 2. using at()
  try
  {
    for (int i = 0; i < v1.size(); i++)
      cout << v1.at(i) << " ";
    cout << endl;
  }
  catch (std::out_of_range e)
  {
    cout << "Array out of Index Exception" << endl;
  }
  // 3. using implicit iterator | using range-for loop
  for (auto x : v2)
    cout << x << " ";
  cout << endl;
  // 4. using Explicit iterator
  vector<string>::iterator it;
  for (it = v2.begin(); it != v2.end(); it++)
    cout << *it << " ";
  cout << endl;  
  return 0;
}