#include <iostream>
#include <vector>
#include <algorithm>

long long int MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long int max_product = 0;
    long long int n = numbers.size(),first=-1,second=-1;

    for (int i = 0; i < n; ++i)
    {
      if((first == -1) || (numbers[i]>first))
      {
        second=first;
        first=numbers[i];
      }
      else if((second == -1) || ((numbers[i]<=first) && (numbers[i]>second)))
      {
        second = numbers[i];
      }
    }
    if((first == 0) || (second == 0))
      {
        return 0;
      }
    max_product = first*second;
    return max_product;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
