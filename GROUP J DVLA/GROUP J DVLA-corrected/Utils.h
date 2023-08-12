#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
//this class hold utilities for binding the objects Drive and office together
//it uses the fileManager class to enable storage/writing of the objects and retrieving them from memory

class Utility{
private:
    Driver drivObj;
    Office offObbj;
    FileManager fileObj;
public:

Utility(Driver dr,Office of,FileManager fbj):drivObj(dr),offObbj(of),fileObj(fbj){};    ///DEFINE CONSTRUCTOR FOR THE CLASS

//no-argument constructor ---didn't really use it
Utility(){};

 void startingInterface(void);//FUNCTION FOR STARTING INTERFACE PROMPT


void registerDriver(void);//TAKE USER DETAILS AND REGISTER THEM ONTO THE SYSTEM

void handleExpirey(void);//CHECK WETHER LICENSE IS VALID

bool compareTimes(string,string,int);//COMPARE TO TIME STRINGS

///END OF UTILITY CLASS
};

///FUNCTIONS DEFINED OUTSIDE THE UTILITY CLASS

void Utility::startingInterface(){
///welcome prompt
cout<<setw(60)<<"DVLA GHANA"<<internal<<endl<<endl;

///startup options prompt
cout<<setw(60)<<"[1] Register User \t\t\t [2] Verify User License \n\n"<<
endl<<setw(55)<<"[3] Renew License \t\t\t [4] Read User Data \n\n"<<
endl<<setw(49)<<"[5] Compile Expired Users \t\t[6]Quit\n\n"<<endl;

char input;//declare a character to take user choice /option

///DECISION CYCLE
do{
cout<<setw(15)<<"> ";
input=Static::takeUserChoice('1','6',"Please enter between 1- 6");;//take input
cout<<endl;

///switching between choices
switch(input){
case '1':
    registerDriver();
    break;
case '2':
    handleExpirey();
    break;

    ///CURLY BRACES AROUND SWITCH STATEMENTS TO SAVE SCOPPING PROBLEMS AS CPP DOESN'T ALLOW CROSS INITIALISATION
case '3':{
    ///RENEWING USER LINSENCE


    fileObj.readFromfile(drivObj,offObbj);//!!!load appropiate user first;
    int newValid=1;
    offObbj.showLicenceDetails();
    cout<<"Enter new validity (minutes) >  ";
    cin>>newValid;
    fileObj.updateFile(drivObj,offObbj);
    offObbj.renewLicense(Static::getCurrenTime(),newValid);
    fileObj.compileExpiredUsers();
    cout<<endl;
    fileObj.writeTofile(offObbj,drivObj,Static::getCurrenTime());
    break;
}

case '4':
{
       fileObj.readFromfile(drivObj,offObbj);
       drivObj.showDetails();
        offObbj.showLicenceDetails();
        break;
}
case '5':{
    cout<<"EXPIRED USERS COMPILED IN THE EXPIRED USERS.TXT FILE"<<endl;
    fileObj.compileExpiredUsers();
    break;
}
case '6':
    cout<<"Quitting ";///would add smoothing typing!!!
    Static::smoothEffect("...",85000);
    exit(1);
    break;
default:
    cout<<"Please make a valid input [1-6]"<<endl;

}
///end of switch statment

    cout<<endl<<endl<<setw(30)<<"Would you like to make another operation ?\n\t\t\t[Y] Yes [N] No ";
char opChoice;
opChoice=_getch();
///check if user would like to continue
if(toupper(opChoice)!='N'){
    Static::reshowPromptForUtils();
}else{
input='6';
}

}while(input!='6');///check if user quitted

///END OF FUNCTION
}


//FUNCTION TO REGISTER A NEW DRIVER
void Utility::registerDriver(){
    drivObj.getDetails();
    offObbj.getDetails();
    fileObj.writeTofile(offObbj,drivObj,Static::getCurrenTime());//date of issuance only at time of registration
    cout<<setw(50)<<"New user added successfully \a "<<endl;
}



void Utility::handleExpirey(){//FUNCTION TO CHECK EXPIRY OF DRIVER'S LINCESN
    string timeNow=Static::getCurrenTime();
    fileObj.readFromfile(drivObj,offObbj);
    string timeOfIssuance=offObbj.getDateOfIssue();
    //call the compare times function
   bool isValid=compareTimes(timeNow,timeOfIssuance,offObbj.getValidity());


    //compare the minutes and make decision
    if(isValid){
        cout<<"Your License is still valid"<<endl;
    }else{
        system("color 4f");
        ///would implement change between two times here
       // int timechange=stoi()
       int timDiff=Static::calculateMinuteDifference(timeNow.substr(timeNow.size()-4,timeNow.size()),timeOfIssuance.substr(timeOfIssuance.size()-4,timeOfIssuance.size()));
        if(timDiff==-1){
            cout<<"This License expired more than an hour ago"<<endl;
        }else{
            cout<<"This License expired "<<timDiff-1<<" minutes ago"<<endl;
        }
    }




    //offObbj.showLicenceDetai
    ///CAUSE EXPIRY IF THE LICENCE EXCEED THE NUMBER OF MINUTES
    //if(stoi(minuteNow)>stoi(offObbj)


}

bool Utility::compareTimes(string current,string old,int offset){
         int flag=0;
         string::iterator currentIterator =current.begin();
         string::iterator oldIterator=old.begin();
         while(*currentIterator !=':' && *oldIterator!=':'){
            if(*currentIterator ==*oldIterator){
                flag++;
            }
            currentIterator++;
            oldIterator++;
         }

         if(flag==13){//there are 12 characters before the minute and all should match up
                //get to the minute component
            string finMinute=current.substr(current.size()-2,current.size());
            string compareMinute=old.substr(current.size()-2,current.size());
           // cout<<"checked "<<stoi(finMinute)<<"against "<<stoi(compareMinute)+offset<<endl;

            if( (stoi(finMinute)-stoi(compareMinute)) <=offset){
                return true;
            }
         }
            return false;
         }
#endif // UTILS_H_INCLUDED
