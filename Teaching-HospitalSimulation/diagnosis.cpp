#include "diagnosis.h"
#include <stdio.h>#include <iostream>
#include <stdlib.h>

using namespace std;

//constructor with parameters
diagnosis::diagnosis(int newID, string newDiseaseName)
{
    id = newID;
    disease_name = newDiseaseName;
}
//default constructor
diagnosis::diagnosis()
{
    id = -1;
    disease_name = "";
}
//read in diagnosis information to data structure
void initializeDiagnosis(diagnosis diagnosisArr[])
{
    int num = 0;
    string disease = "";
    ifstream inFile;
    inFile.open("Diagnosis.txt");
    inFile >> num;
    for(int i = 0; i < num; i++)
    {
        getline(inFile, disease);
        diagnosisArr[i] = diagnosis(num, disease);
    }
    inFile.close();
}
