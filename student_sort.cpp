#include<iostream>
using namespace std;

int main()
{
int student[5];
int searchID;

cout<<"enter the 5 student marks:\n";
for(int i=0; i<5; i++)
{
cin>>student[i];
}
//sorting
for(int i=0; i<4; i++)
{
for(int j=0;j<4-i;j++)
{
if(student[j+1]>student[j])
{
int temp =student[j+1];
student[j+1]=student[j];
student[j]=temp;
}
}
}
cout<<"/student after sorting:\n";
for(int i=0; i<5; i++)
{
cout<<student[i]<<":";
}
return 0;
