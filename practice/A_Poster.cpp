#include <bits/stdc++.h>
using namespace std;

int main() {
int n,k;
cin>>n>>k;
string s;
cin>>s;
int l=k;
int r=n-k;
if(l<r)
{
for(int i=l;i<n;i++)
{
cout<<"RIGHT"<<endl;
}
for(int i=n-1;i>=0;i--)
{
cout<<"PRINT "<<s[n-i-1]<<endl;
cout<<"LEFT"<<endl;
}
}
else
{
for(int i=r;i>=0;i--)
{
cout<<"LEFT"<<endl;
}
for(int i=0;i<n;i--)
{
cout<<"PRINT "<<s[i]<<endl;
cout<<"RIGHT"<<endl;
}
}

}