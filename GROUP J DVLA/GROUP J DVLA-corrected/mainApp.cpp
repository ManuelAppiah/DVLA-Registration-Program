#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <ostream>
#include <conio.h>
//user defined header files
#include "staticMethods.h"
#include "Driver.h"
#include "LicenceOffice.h"
#include "File_Operations.h"
#include "Utils.h"

using namespace std;

int main(){
    ///CREATE GENERIC OBJECTS AS CONTAINERS FOR READING AND WRITING
    Driver genericDriver;//GENERIC DRIVER OBJECT
    Office genericOffice;//GENERIC OFFICE OBJECT
    FileManager mainFileManager("DVLA.txt");

    Utility interFaceUtility(genericDriver,genericOffice,mainFileManager);///UTILITY CLASS DEFINED IN UTILS.H
    interFaceUtility.startingInterface();//CALLING STARTING INTERFACE OF UTILITY CLASS

return 0;}


