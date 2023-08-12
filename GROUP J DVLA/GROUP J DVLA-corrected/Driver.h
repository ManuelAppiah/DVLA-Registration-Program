#ifndef DRIVER_H_INCLUDED
#define DRIVER_H_INCLUDED
#include <iostream>

using namespace std;

class Driver{
private:
    string name;
    int age;
   // string birthDate;-work on later
    string nationality;
    string sex;

public:
    Driver(){};
    Driver(string nm,int ag,string nat,string sx):name(nm),age(ag),nationality(nat),sex(sx){};

    ostream & getAllDetailsAtOnce(ostream &streamject)
    {
        streamject<<name<<"-"<<nationality<<"-"<<age<<"-"<<sex<<"-";
        return streamject;
    }

    void showDetails (void){
        cout<<setw(80)<<"**********PERSONAL INFORMATION**************"<<endl;
        cout<<endl<<endl;
        cout<<setw(50)<<"Name "<<setw(20)<<Static::takeToUpper(name)<<internal<<endl;
        cout<<setw(50)<<"Age "<<setw(20)<<age<<right<<endl;
        cout<<setw(50)<<"Sex "<<setw(20)<<sex<<endl;
        cout<<setw(50)<<"Nationality "<<setw(20)<<Static::takeToUpper(nationality)<<endl;
        cout<<endl<<endl<<endl;

    }


    void getDetails(){

        cout<<"Please enter your name :";
        fflush(stdin);
        getline(cin,name);
        cout<<endl;
        cout<<"Please enter your age :";cin>>age;
         cout<<endl;
        cout<<"Please enter your nationality :";cin>>nationality;
         cout<<endl;
         cout<<"Enter Sex [M] Male [F] Female"<<endl;   cin>>sex;


    }

};




#endif // DRIVER_H_INCLUDED
