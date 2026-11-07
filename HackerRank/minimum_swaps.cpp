#include <iostream>

int minimumSwaps (std::vector <int> arr) {
    size_t swaps = 0, n = arr.size ();

    for (size_t i = 0; i < n; i++)
        while (arr[i] != i + 1) {
            int correct_index = arr[i] - 1;
           std:: swap (arr[i], arr[correct_index]);
            swaps ++;
        }
        
    return swaps;
}

int main() {

int n;
std::cin>>n;

std::vector<int> arr(n);

for(int i=0;i<n;i++)
std::cin>>arr[i];

std::cout<<minimumSwaps(arr);
return 0;

}