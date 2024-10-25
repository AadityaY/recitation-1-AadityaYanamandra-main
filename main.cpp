#include "addEmployee.hpp"
#include "addEmployee.cpp"

int main(int argc, char *argv[])
{
    // check for number of arguments
    /*if (argc < 2)
    {
        cout << "file name missing" << endl;
        return -1;
    }*/

    string fileName = "employees.csv"; // TODO 1: get the file name from the command line parameters
    employee arr[4];

    // open the file
    ifstream myfile;
    myfile.open(fileName);

    string line;
    string name;
    string emailid;
    string birthday;
    string length;

    if (myfile.is_open()) // check that this file exists
    {
        // TODO 2:  Read each line from the file
        //          for each line do the following
        //               extract name, extract email, exract birthday
        //               call the addAnEmployee function to add them in the array
        int i = 0;
        while (getline(myfile, line))
        {
            stringstream ss;
            ss << line;
            length = line.length();
            name = line.substr(0, line.find(','));
            line.erase(0, line.find(',')+1);
            emailid = line.substr(0, line.find(','));
            line.erase(0, line.find(',')+1);
            birthday = line.substr(0, line.length());
            i = addAnEmployee(arr, name, birthday, emailid, i);
        }
    }
    else
    {
        cout << "err: can not open file" << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        cout << "name:" << arr[i].name << " email:" << arr[i].email << " bday:" << arr[i].birthday << endl;
    }

    return 0;
}