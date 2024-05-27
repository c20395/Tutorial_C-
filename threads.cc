#include <iostream>
#include <string>
#include <iterator>

#include <unistd.h>

#include <thread>

using namespace std;

void f1() {
  sleep(30);
  std::cout << "End of thread A" << std::endl;
  return;
}

void f2() {
  sleep(60);
  std::cout << "End of thread B" << std::endl;
  return;
}

using namespace std::chrono; 

void hires_sleep(int n) {
auto t0 = high_resolution_clock::now();
this_thread::sleep_for(milliseconds{n});
auto t1 = high_resolution_clock::now();
cout << duration_cast<nanoseconds>(t1-t0).count() << " nanoseconds passed\n";
return;
}

int main()
{
  thread t1 {f1};
  thread t2 {f2};

ostream_iterator<string> oo {cout};
  *++oo="Hello,";
  *++oo=" ";
  *++oo="world\n";

  hires_sleep(20);

std::cout << "Before starting thread A" << std::endl;
  t1.join();
  std::cout << "Before starting thread B" << std::endl;
  t2.join();
  std::cout << "After threads A and B" << std::endl;
  return 0;
}
