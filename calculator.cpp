#include<iostream>
using namespace std;
void calculator(void)
{
float x,y;
char ch;
cout<<"enter first number : ";
cin>>x;
cout<<"enter an operator(+,-,*,/) : ";
cin>>ch;
cout<<"enter second number : ";
cin>>y;
switch(ch)
{
    case '+':
    {
        cout<<"Result : "<<x+y;
        break;
    }
    case '-':
    {
        cout<<"Result : "<<x-y;
        break;
    }
    case '*':
    {
        cout<<"Result : "<<x*y;
        break;
    }
    case '/':
    {
        if(y==0)
        {
            cout<<"Division is not allowed ";
        }
        else
        {
        cout<<"Result : "<<x/y;
        }
        break;
    }
    default:
    {
        cout<<"Invalid operator!";
        break;
    }
}
}
int main()
{
    char ch;
    do{
calculator();
cout<<"\nDo you want to perform more operation ?(y/n) : ";
cin>>ch;
    }
    while(ch=='y' || ch=='Y');
    return 0;
}