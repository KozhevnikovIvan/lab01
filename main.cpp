#include <iostream>
#include <thread>

using namespace std;

class A {
public:
  void operator()(int x, int y) { cout << "resulte: " << x * y; }
};

int main() {
  thread t1{[]() {
    int x, y;
    cin >> x >> y;
    cout << x * y;
  }};
  t1.join();
  cout << endl;
  int x, y;
  cin >> x >> y;
  A object;
  thread t2{object, x, y};
  t2.join();
  return 0;
}
