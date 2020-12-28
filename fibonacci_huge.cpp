#include <bits/stdc++.h>
using namespace std;

long long int pisano(long long int m)
{
    long long int prev = 0;
    long long int curr = 1;
    long long int res = 0;

    for(long long int i = 0; i < m * m; i++)
    {
        long long int temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;

        if ((prev == 0) && (curr == 1))
            res = i + 1;
    }
    return res;
}

long long get_fibonacci_huge_naive(long long int n, long long int m)
{

    // Getting the period
    long long int pisanoPeriod = pisano(m);

    n = n % pisanoPeriod;

    long long int prev = 0;
    long long int curr = 1;

    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    for(long long int i = 0; i < n - 1; i++)
    {
        long long int temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;
    }
    return curr % m;
}

int main() {
    long long int n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
