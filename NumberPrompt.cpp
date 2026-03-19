#include <iostream>
using namespace std;


int main()
{

    string  number;

    cout<<"Enter an integer value between 5 and 10"<<endl;
    cin>>number;

    while (number != "6" && number != "7" && number != "8" && number != "9")
    {
        cout<<"Sorry, you entered an invalid number, please try again"<<endl;
        cin>>number;
    }
    cout<<"Your input value ("<<number<<") has been accepted"<<endl;
    return 0;
}
