 #include <iostream>

 int progresia(int a, int d, int n) {

if(n==1)
return a;

return progresia(a,d,n-1) +d;

}

int main()
{
int a=2, d=3, n=5;

std::cout<< progresia(a,d,n);

return 0;

}