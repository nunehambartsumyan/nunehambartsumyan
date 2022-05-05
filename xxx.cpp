#include <iostream>
int gcd (int a , int b){
while (b!=0)
int c=0;
int c=a%b;
a=b;
b=c;
return a;
}
int main ()
{
int n,m,c;
std::cin>>n,m, c;
std::cout<< gcd(a);
return 0;
}

