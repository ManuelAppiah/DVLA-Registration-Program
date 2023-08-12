#ifndef LICENCEOFFICE_H_INCLUDED
#define LICENCEOFFICE_H_INCLUDED
#include <iostream>
#include <time.h>
#include <vector>
void showLincInfo(string);//function to beautify the license number;
using namespace std;
class Office{

private:
    string licenceType;
    int validity;
    string license_Id;
    string dateOfIssue;//only at time of registration
public:

    Office(){license_Id=generateLicencPlateNum();};///zero argument constructor for office
    Office(string linctype,int val,string lincId,string issued):licenceType(linctype),validity(val),license_Id(lincId),dateOfIssue(issued){};

    string getDateOfIssue(){
    return dateOfIssue;
    }
    ///!!!implement a function to show validity in terms of date
    string getDateOfExpiry();
    int getValidity(){
    return validity;
    }


    //void IssueLinsence(){};//generate random validity in mins


    void renewLicense(string newDate,int newvalidity=1){
        dateOfIssue=newDate;
        validity=newvalidity;
    };
    void checkExpiry(){};//check if validity expired

    string generateLicencPlateNum(void);

    void showLicenceDetails(){
         cout<<setw(80)<<"**********LICENSE INFORMATION**************"<<endl<<endl;
        cout<<setw(55)<<"License Number : ";showLincInfo(license_Id);
        cout<<setw(55)<<"Validity :  "<<setw(1)<<validity<<" minute(s)"<<right<<endl;
        cout<<setw(55)<<"Licence Type :  "<<setw(1)<<licenceType<<endl;
        cout<<setw(55)<<"DateIssued :  "<<setw(5)<<dateOfIssue<<endl;
        cout<<setw(55)<<"Date Of Expiry :  "<<getDateOfExpiry()<<endl;
    }
      ostream & getAllDetailsAtOnce(ostream &streamject)
    {
        streamject<<licenceType<<"-"<<validity<<"-"<<license_Id<<"-";

        return streamject;
    }
    void getDetails(){
        vector <string> vehicleTypes={"cruisers",
        "minibusses, cross-country vehicle,get vehicles",
        "transports and medium products conveying vehicles",
        "transports, mentors and hefty products vehicles.",
        "agrarian, earth-moving, and modern gear"};

        cout<<"\n\n\n"<<endl;
        cout<<setw(60)<<"VECHILE TYPE "<<endl;
        for(int i=0;i<vehicleTypes.size();i++){
            cout<<setw(40)<<"["<<i+1<<"] "<<vehicleTypes[i]<<endl<<endl;
        }
        cout<<setw(40)<<" >: ";
        short intake=0;
        char conv=65;
        cin>>intake;

        //make sure user entered correctly

        if(intake >0 && intake< vehicleTypes.size()){
                conv+=intake-1;
               // cout<<"You have a class "<<conv<<" license"<<endl;
               licenceType=conv;
        }

        cout<<"Validity set to one minute"<<endl;
        validity=1;



    }

};
string Office::getDateOfExpiry(){
string rtn="";
rtn=Static::increaseDate(dateOfIssue,'m',validity);

return rtn;
}

string Office::generateLicencPlateNum(){
    srand(time(0));//generate a random number

    //random string for car plate characters
    vector <string > string_constants={"AS","GC","GS","GW","GR","GT"};
    //random string for car plate numbers
    vector <string > num_contants={"0","1","2","3","4","5","6","7","8","9"};

    string results="";
    results+=string_constants[rand()%string_constants.size()];

    while(results.size()<10){
        results+=num_contants[rand()%num_contants.size()];
    }

return results;
}
void showLincInfo(string lincInfo){
    cout<<lincInfo.substr(0,4)<<"-"<<lincInfo.substr(4,3)<<"-"<<lincInfo.substr(7,3);
    /*
for(int i=0;i<lincInfo.size();i++){
    if(i%3==0 && i!=0){
        cout<<" - ";
        cout<<lincInfo[i];
    }else{
    cout<<lincInfo[i];
    }
}*/
cout<<endl;
}
/*
Type A – cruisers.
Type B – minibusses, cross-country vehicle, get vehicles.
Type C – transports and medium products conveying vehicles.
Type D – transports, mentors and hefty products vehicles.
Type E – agrarian, earth-moving, and modern gear
*/

#endif // LICENCEOFFICE_H_INCLUDED
