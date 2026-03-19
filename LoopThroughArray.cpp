#include <iostream>

using namespace std;


int main()
{
    //Declares and defines the array elements
    string elements[] = {"B123","C234","A345","C15","B177","G3003","C235","B179"};

    //Iterates through the array elements
    for(string element:elements){
        //Check whether the element starts with the character 'B'
        if(element[0] == 'B'){
            //Prints out the element that satisfies the condition to the console
            cout<<element<<endl;
        }
    }

    
    return 0;
}
