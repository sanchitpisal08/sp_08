#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> token;

    cout<<"Enter token number of 5 customers:"<<endl;

    for(int i=0; i<5; i++)
    {
        cout<<"Enter token number of customer "<<(i+1)<<": ";
        int token_no;
        cin>>token_no;
        token.push(token_no);
    }

    cout<<"Customers will be served in this order:"<<endl;

    while(!token.empty())
    {
        cout<<"Serving customer with token number: "<<token.front()<<endl;
        token.pop();
    }

    return 0;
}
