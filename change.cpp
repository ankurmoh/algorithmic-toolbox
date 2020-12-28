#include <iostream>

long long int get_change(long long int m) {
  long long int con=0;
  while(m>=10)
  {
    con++;
    m=m-10;
  }
  while(m>=5)
  {
    con++;
    m=m-5;
  }
  while(m>=1)
  {
    con++;
    m=m-1;
  }
  return con;
}

int main() {
  long long int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
