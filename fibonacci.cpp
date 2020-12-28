#include<bits/stdc++.h>

using namespace std;

int fibonacci_naive(int n) {
vector<int>fib(n+1);
fib[0]=0;
fib[1]=1;
for(int i=2;i<=n;i++)
{
  fib[i]=fib[i-1]+fib[i-2];
}
return fib[n];
}

int main() {
    int n = 0;
    std::cin >> n;

    std::cout << fibonacci_naive(n) << '\n';
    return 0;
}
