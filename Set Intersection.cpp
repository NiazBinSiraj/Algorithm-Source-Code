// set_intersection example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int main () {
  int first[] = {5,10,15,20,25,7};
  int second[] = {50,40,30,20,10,7};
  vector<int> v(10);
  vector<int>::iterator it;

  sort (first,first+6);
  sort (second,second+6);

  it=set_intersection (first, first+6, second, second+6, v.begin());

  v.resize(it-v.begin());

  cout << "The intersection has " << (v.size()) << " elements:\n";
  for (it=v.begin(); it!=v.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';

  return 0;
}
