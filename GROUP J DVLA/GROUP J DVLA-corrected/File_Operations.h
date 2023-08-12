#ifndef FILE_OPERATIONS_H_INCLUDED
#define FILE_OPERATIONS_H_INCLUDED
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class FileManager{
private:
    string filePath;
public:
    FileManager(){};//NO ARGUMENT CONSTRUCTOR
    FileManager(string fpth):filePath(fpth){};//ANOTHER CONSTRUCTOR TAKING ONE ARG

    void writeTofile(Office &,Driver &,string date);//FUNCTION TO WRITE FROM OBJECTS TO FILE
    void readFromfile(Driver &drivObj,Office & offbj);//FUNCTION TO READ FROM OBJECTS TO FILE
    vector <string> breakWithDelims(string ,char);//FUNCTION TO BREAK THE LINE RECEIVED INTO ELEMENTS OF THE ARRAY
    vector <string> breakIntoLines(void);//FUNCTION TO COLLECT THE LINES OF THE FILES AND STORE IN AN ARREAY
    void updateFile(Driver &,Office &);//not really sure
    void compileExpiredUsers(void);//FUNCTION TO COLLECT ALL EXPIRED USERS AND SAVE THEM IN A FILE

};

///ANALAYSE AND BREAK THE FILE INPUT INTO LINES
vector <string> FileManager::breakIntoLines(){//function to return the fileStream DATA as lines ans store in a vector
vector <string> rtnVector ;
fstream file1;
file1.open(filePath,ios::in);
string temp;

while(!file1.eof()){//continue getting line until the eof is reached
    getline(file1,temp);
    if(temp.size()>0)//so that you don't push an empty line
     rtnVector.push_back(temp);

}
return rtnVector;
}

///ANALYSE AND OUTPUT THE USER DATA
vector <string> FileManager::breakWithDelims(string text,char del='-'){//FUNCTION TO BREAK DATA LINE INTO COMPONENTS
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



///store user data
void FileManager::writeTofile(Office & ofobj, Driver & drivobj,string date=""){
    ofstream outfle(filePath,ios::app);
    drivobj.getAllDetailsAtOnce(outfle);
    ofobj.getAllDetailsAtOnce(outfle);
    outfle<<date<<endl;

}

void FileManager::readFromfile(Driver &drivobj,Office &offobj){//MAKE A READ FROM THE FILE INTO THE OBJECTS
    enum toMapto {name,nationality,age,sex,licenceType,validity,licenceID,date};
    vector <string> readingLines=breakIntoLines();
    //ask if they'll like to search in file or select from a list---would implement later
    cout<<"Who's data would you like to analyze"<<endl;
    //cout<<readingLines.size()<<endl;

    for(int i=0;i<readingLines.size();i++){
       cout<<" ["<<i+1<<"] ";Static::smoothEffect(breakWithDelims(readingLines[i])[0]);
        cout<<endl;
    }
    int choice=0;
    cout<<">> ";
    cin>>choice;cout<<endl;
    if(choice-1>=0 && choice<=readingLines.size()){
        string line=readingLines[choice-1];
        vector <string> separatedInfo=breakWithDelims(line);

        //all this lines is to pass the arguments into the driver object from the file as
        //<<name<<"-"<<nationality<<"-"<<age<<"-"<<sex<<"-"
        //licenceType<<"-"<<validity<<"-"<<license_Id<<"-"
        drivobj=Driver(separatedInfo[name],stoi(separatedInfo[age]),separatedInfo[nationality],separatedInfo[sex]);//put the info int the driver object;

          //all this lines is to pass the arguments into the office object from the file as
        //    Office(string linctype,int val,string lincId,string issued)
        offobj=Office(separatedInfo[licenceType],stoi(separatedInfo[validity]),separatedInfo[licenceID],separatedInfo[date].append("-").append(line.substr(line.size()-5,line.size())));
        //7+8 to get the total date

    }

}

void FileManager::updateFile(Driver &drivobj,Office& offobj){
 ostringstream textStream;
drivobj.getAllDetailsAtOnce(textStream);
string dataToFind=textStream.str();
vector<string> lines=breakIntoLines();
ofstream tempfile("temp.txt");
for(int i=0;i<lines.size();i++){
    if(dataToFind==lines[i].substr(0,dataToFind.size())){
        //cout<<"Line stream : "<<lines[i]<<endl;
    }else{
    tempfile<<lines[i]<<endl;
    }
}
//close the file
tempfile.close();
//remove the original file
remove("DVLA.txt");
//rename the original file to the old file
rename("temp.txt","DVLA.txt");

}
void FileManager::compileExpiredUsers(){
   fstream file1;
    file1.open(filePath,ios::in);
    fstream file2;
    file2.open("Expired.txt",ios::out);
    string templine,overDate;
    int validity;
    while(getline(file1,templine)){
            if(templine.size()>0){
        overDate=templine.substr(templine.size()-16,16);

        validity=stoi(templine.substr(templine.size()-29,1));

            if(!Static::compareTimes(Static::getCurrenTime(),overDate,validity)){

            file2<<breakWithDelims(templine)[0]<<endl;
            }

        }else{

            //cout<<"none expired one"<<endl;
        }

    }
}


#endif // FILE_OPERATIONS_H_INCLUDED
