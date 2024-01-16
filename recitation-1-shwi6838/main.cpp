#include "addEmployee.hpp"

int split(string inputString, char separator, string arr[],int size){
    
    arr[0]=inputString;
    int index=0; // index of the array
    int sepIndex=0; // index of the last separator found

    if(inputString=="") // check for empty input
    {
        return 0;
    }

    for(int i=0;i<inputString.length()+1;i++) // loop through input
    {
        if(inputString[i]==separator) //If separator is found
        {
            arr[index]=inputString.substr(sepIndex,i-sepIndex); //Add word created between separators at the index of the array
            sepIndex=i+1; // increase the separator index to start the next word 
            if(size==index+1) //check for bounds in size
            {
                return -1;
            }
            arr[index+1]=inputString.substr(sepIndex,i); //set up next index to start next word
            index++; //increase the index for array
        }
    }
    return index+1; //TReturns the number of splits + 1 to equal the number of words
}

int main(int argc, char *argv[])
{
    // check for number of arguments
    if (argc < 2)
    {
        cout << "file name missing" << endl;
        return -1;
    }

    string fileName = argv[1]; // TODO 1: collect the correct argument
    employee array[4];

    // open the file
    ifstream myfile;
    myfile.open(fileName);

    string line;
    string name;
    string emailid;
    string birthday;
    int length = 0;

    if (myfile.is_open()) // check existance of the file
    {
        // TODO 2:  Read each line from the file
        //           for each line do the following
        //               extract name, extract email, extract birthday
        //               call the addAemployee function to add them in the array
        while (getline(myfile, line))
        {
            string arr[4];
            if(split(line, ',', arr, 3) == 3)
            {
                name = arr[0];
                emailid = arr[1];
                birthday = arr[2];
                addAnEmployee(array, name, birthday, emailid, length);
                length++;
            }
        }
    }
    else
    {
        cout << "err: can not open file" << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        cout << "name:" << array[i].name << " email:" << array[i].email << " bday:" << array[i].birthday << endl;
    }

    return 0;
}