#include <iostream>
#include <string>
int  repeatedstr(std::string s, int n ){

int q=0;

for(int i=0; i<s.length();i++){
if(s[i]=='a')
q++;
}

int h=n/s.length();
int r=n%s.length();

int m=0;
for(int i=0;i<r;i++){
if(s[i]=='a')
m++;}
return q*h+m;


}

int main() {
std::string s;
int n;
std::cin>>s>>n;

std::cout<<repeatedstr(s, n);
return 0;


}