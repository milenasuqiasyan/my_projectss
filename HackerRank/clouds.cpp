#include <iostream>

int jumps(int n, int arr[]) {

    
int  j=0, i=0;

while(i<n-1){
if(i+2<n && arr[i+2]==0){
i+=2;}

else {
i++;}

 j++;
}

 return j;

}

int main() {
int n;
std::cin>>n;
int arr[101];
for(int i=0;i<n;i++)
std::cin>>arr[i];
std::cout<< jumps(n, arr);
return 0;

}