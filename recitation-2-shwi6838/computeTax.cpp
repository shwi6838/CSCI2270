#include <iostream>
#include <string>

#include "taxinfo.hpp"

using namespace std;

int main(int argc, char *argv[]) {

    if (argc < 3){
        cout << "missing command line arguments" << endl;
        return -1;
    }

    // TODO 2: Collect salary "inSalary" and tax rate "inTaxRate" from command line arguments
    float inSalary = stof(argv[1]);
    float inTaxRate = stof(argv[2]);
    

    // TODO 3: Assign data to TaxInfo variable
    TaxInfo taxCalc;
    taxCalc.salary = inSalary;
    taxCalc.tax_rate = inTaxRate;


    // TODO 4: Compute Tax using only pointer access
    TaxInfo *ptr;
    ptr = &taxCalc;

    float tax = ptr->salary * (ptr->tax_rate / 100);


    // TODO 5: Print salary, tax rate, and tax.
    cout << "Salary: " << ptr->salary << "$" << endl;
    cout << "Tax Rate: " << ptr->tax_rate << "%" << endl;
    cout << "Tax Incurred: " << tax << "$" << endl;
   

   return 0;
}
