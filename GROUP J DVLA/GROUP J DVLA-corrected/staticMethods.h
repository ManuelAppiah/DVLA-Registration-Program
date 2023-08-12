#ifndef STATICMETHODS_H_INCLUDED
#define STATICMETHODS_H_INCLUDED
#include <unistd.h>
//#include <string>


using namespace std;
class Static{
public:
static char takeUserChoice(char start,char ended,string erromsg="Please make a valid input"){
        char choice;
        cout<<"> ";
        while(!(choice>=start && choice <=ended) ){
            cin>>choice;
            if(choice>=start && choice <=ended){
                break;
            }else{
            cout<<erromsg<<endl;
            }
            fflush(stdin);
            cout<<endl;
        }
        return choice;
}
static string takeToUpper(string input){

    string result;
    for (char c : input) {
        result += toupper(c);
    }
    return result;
}
static void  smoothEffect(string text,int time=900){

for(auto a : text){
    cout<<a;
        usleep(time);
}
}

static string increaseDate(string date,char part,int amount){
    string rtn="";
    switch(part){
case 'm':
    {
        rtn=date.substr(0,date.size()-2);
        int mins=stoi(date.substr(date.size()-2,date.size()))+amount;
       //would make changes to hours
        rtn+=to_string(mins);
    }

    }
    return rtn;
}

static int calculateMinuteDifference(const std::string& time1, const std::string& time2) {
    std::istringstream iss1(time1);
    std::istringstream iss2(time2);

    int hour1, minute1, hour2, minute2;
    char delimiter;

    // Extract hours and minutes from the first time string
    iss1 >> hour1 >> delimiter >> minute1;

    // Extract hours and minutes from the second time string
    iss2 >> hour2 >> delimiter >> minute2;
    if(hour1!=hour2 && hour1-hour2>1){
        return -1;
    }
    // Calculate the minute difference
    int totalMinutes1 = (hour1 * 60) + minute1;
    int totalMinutes2 = (hour2 * 60) + minute2;

    return std::abs(totalMinutes1 - totalMinutes2);
}

static void reshowPromptForUtils(){
system("cls");
system("color 7");
cout<<setw(60)<<"DVLA GHANA"<<internal<<endl<<endl;
cout<<setw(60)<<"[1] Register User \t\t\t [2] Verify User License \n\n"<<
endl<<setw(55)<<"[3] Renew License \t\t\t [4] Read User Data \n\n"<<
endl<<setw(49)<<"[5] Compile Expired Users \t\t[6]Quit\n\n"<<endl;
}

static vector <string> breakWithDelims(string text,char del='-'){
    vector <string> rtnvalue;
    string tmpStr="";

    for(auto a:text){
        if(a!=del){
            tmpStr+=a;
        }
        if(a==del){

           rtnvalue.push_back(tmpStr);
           tmpStr="";
        }
    }

    return rtnvalue;

}
static string  getCurrenTime(){

         auto t=time(nullptr);//initialize the time object

        auto tm=*localtime(&t);//make call to os for local time

        ostringstream oss;//genric stream object to handle stringlike streams

        oss<<put_time(&tm,"%d/%m/%Y-%H:%M");//give the time stream to the ostream object

        string time=oss.str();

        return time;
}

static bool compareTimes(string current,string old,int offset){
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

    };




#endif // STATICMETHODS_H_INCLUDED
