#include <iostream>
;

int sockmerchant(int n, int arr[]){

int m[101]={0};

for(int i=0; i<n;i++){
m[arr[i]]++;
}

int q=0;
for(int i=0;i<101;i++) {
q+=m[i]/2;
}
return q;
}

int main(){
    int n;
    std::cin>>n;

    int arr[100];

for(int i=0;i<n;i++){
std::cin>>arr[i];}
std::cout<< sockmerchant(n, arr);

return 0;

}