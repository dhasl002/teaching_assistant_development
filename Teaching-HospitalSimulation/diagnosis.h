#ifndef DIAGNOSIS_H_INCLUDED
#define DIAGNOSIS_H_INCLUDED
#include <stdio.h>#include <fstream>
using namespace std;

class diagnosis{
public:
    int id;
    string disease_name;

    diagnosis(int newID, string newDiseaseName);
    diagnosis();
};
void initializeDiagnosis(diagnosis diagnosisArr[]);
#endif // DIAGNOSIS_H_INCLUDED
