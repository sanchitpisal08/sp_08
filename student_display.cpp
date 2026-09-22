include<iostream>
using namespace std;

int main()
{
int roll_no[5];

cout<<"enter roll no of 5 student:"<<endl;

for(int i=0; i<5; i++)
{
cout<<"enter roll no of student"<<(i+1)<<":";
cin>>roll_no[i];
}

cout<<"roll num entered by the user"<<endl;
for(int i=0;i<5;i++)
{
cout<<roll_no[i]<<endl;
}
return 0;
}
