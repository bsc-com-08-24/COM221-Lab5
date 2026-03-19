#include <iostream>
#include <cstdlib>//contains the rand() and srand() functions
#include<ctime>
using namespace std;



int main()
{
    //use the current time as the seed of rand function for truly random values
    srand(time(0));

    //for storing the random value
    int daysUntilExpiration = 1+rand()%11;//generates a random number between 0 and 11
    

    if(daysUntilExpiration <= 10){
        if(daysUntilExpiration > 5)
        {
            cout<<"Your subscription will expire soon. Renew now!"<<endl;
        }else if(daysUntilExpiration != 1 && daysUntilExpiration != 0)
        {
            cout<<"Your subscription will expire in "<<daysUntilExpiration<<" days."<<endl;
            cout<<"Renew now and save 10%!"<<endl;
        }else if(daysUntilExpiration == 1)
        {
            cout<<"Your subscription will expire in a day."<<endl;
            cout<<"Renew now and save 20%"<<endl;
        }else{
            cout<<"Your subscription has expired"<<endl;//will never execute unless daysUntilExpiration = rand()%11 no + 1
        }  
    }else
    {            
        cout<<"Your subscription is active"<<endl;//will never be true unless daysUntilExpiration = rand()% 12+
    }
      
    
    return 0;
}
