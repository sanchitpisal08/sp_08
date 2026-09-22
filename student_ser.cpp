include<iostream>
using namespace std;

int main()
{
int student[5];
int searchID;

cout<<"enter roll_no of 5 student:";
for(int i=0;i<5;i++)
{
cin>>student[i];
}
cout<<"enter roll no to search:";
cin>>searchID;
for(int i=0; i<5;i++)
{
if(student[i]==searchID)
{
cout<<"student found!";
return 0;
}
}
cout<<"student not found";
return 0;
}
