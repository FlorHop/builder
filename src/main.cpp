#include <iostream>
#include <string>
#include <fstream>
#include "builder.h"

using namespace std;
string FNAME;

int main(int argc, char const *argv[])
{
    string fname;
    cout << "Enter the file name of *.frm" << endl;;
    getline(cin,fname);
    openfile(fname);
    return 0;
}
