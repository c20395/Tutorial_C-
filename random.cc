/* Raises a 6-face dice randomly */

#include <iostream>
#include <random>
#include <vector>

using namespace std;

class Random_Integer {
  public:
  Random_Integer(int low,int high):dist(low,high) {}
  int operator()(){return dist(re);}
  private:
  default_random_engine re;
  uniform_int_distribution<> dist;
};

int main() 
{
  Random_Integer rnd(1,6);
  vector<int> histogram(6);

  for (int i=0;i!=200;i++) ++histogram[rnd()-1];

  for (auto item:histogram) std::cout << item << std::endl;
return 0;
}
