#include <iostream>
using namespace std;

//Noticed I had to write it multiple times so why not reuse it
double invalidTypeErrorHandler(string n){
    double length;
    while (!cin.good())
    {
        //Prints out an prompts the user to enter a valid number if the input is invalid
        cout<<"Invalid input for "<<n<<endl;
        cout<<"Please enter a valid "<<n<<": ";
        //Clears the error state of cin and ignores the rest of the input
        cin.clear();
        cin.ignore(1000, '\n');
        //Stores the new input in the length variable
        cin>>length;
        cout<<endl;
    }
    return length;
}

void areaOfSquare(){
    double length;
    cout<<"Enter the length of a side of the square : ";
    cin>>length;

    //Checks of an error occured assigning streams value
    if(cin.fail()){
        length = invalidTypeErrorHandler("length");//Handles the value and set the new one to length
    }
    cout<<"Area of the square = "<<length*length<<"\n"<<endl;
}

void areaOfRectangle(){
    double length,width;
    cout<<"Enter the Length of the rectangle : ";
    cin>>length;
    cout<<endl;
    if(cin.fail()){
        length = invalidTypeErrorHandler("length");
    }
    cout<<"Enter the Width of the rectangle : ";
    cin>>width;
    if(cin.fail()){
        width = invalidTypeErrorHandler("width");
    }
    cout<<"The Area of the rectangle is = "<<length*width<<"\n"<<endl;
}

void areaOfTriangle(){
    double baseLength,height;

    cout<<"Enter the base length of the triangle : ";
    cin>>baseLength;
    cout<<endl;
    if(cin.fail()){
        baseLength = invalidTypeErrorHandler("base length");
    }
    cout<<"Enter the height of the triangle : ";
    cin>>height;
    cout<<endl;
    if(cin.fail()){
        baseLength = invalidTypeErrorHandler("height");
    }
    cout<<"The Area of the rectangle is = "<<baseLength*height*0.5<<"\n"<<endl;
}


int main()
{


    string selection;
    bool exit = false;
    while (!exit)
    {
        //Selection Instructions
        cout<<"Please select the shape of the area you want to calculate"<<endl;
        cout<<"1. Square"<<endl;
        cout<<"2. Rectangle"<<endl;
        cout<<"3. Triangle"<<endl;
        cout<<"4. Quit Program"<<endl;

        //input section
        cout<<"Enter Selection : ";
        cin>>selection;
        cout<<endl;

        if(selection == "1"){
            areaOfSquare();
        }else if(selection == "2"){
            areaOfRectangle();
        }else if(selection == "3"){
            areaOfTriangle();
        }else if(selection == "4"){
            exit = true;
        }else{
            cout<<"Your input was : "<<selection<<" which is an invalid input"<<endl;
            cout<<"Please enter a valid input\n"<<endl;
        }
    }


    return 0;
}
