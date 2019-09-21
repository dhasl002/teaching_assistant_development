#include <iostream>
#include <fstream>
#include "staff.h"
#include "customer.h"

using namespace std;

int main()
{
    int staffLength = 0;
    int custLength = 0;

    ifstream staffIn("staff.txt");
    staffIn >> staffLength;
    staffIn.close();
    ifstream custIn("customers.txt");
    custIn >> custLength;
    custIn.close();

    Staff staffArr[staffLength];
    Customer custArr[custLength];

    readStaff(staffArr);
    readCustomers(custArr);

    printStaff(staffArr, staffLength);
    printCustomers(custArr, custLength);
    return 0;
}
