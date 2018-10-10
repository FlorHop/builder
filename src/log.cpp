/**
 *  time:       2018-9-28
 *  describe:   record the error info and write it on log
 *  version:    v1.0
 *  author:     Flor
 *  email:      florhop410@gmail.com
*/
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int error(string str);
int worning(string str);
int normal(string str);

int error(string str)
{
    ofstream outfile;
    SYSTEMTIME sys; 
    GetLocalTime(&sys); 
    outfile.open(".\\builder.log",ios::out|ios::app);
    outfile << "[Time]:" << sys.wYear << "-" << sys.wMonth  << "-" << sys.wDay  << " "   << sys.wHour << ":" << sys.wMinute << ":" << sys.wSecond << "." << sys.wMilliseconds << "  ";
    outfile << "Error: ";    
    outfile << str << endl;
    outfile.close();
    return -1;
}

int worning(string str)
{
    ofstream outfile;
    SYSTEMTIME sys; 
    GetLocalTime(&sys); 
    outfile.open(".\\builder.log",ios::out|ios::app);
    outfile << "[Time]:" << sys.wYear << "-" << sys.wMonth  << "-" << sys.wDay  << " "   << sys.wHour << ":" << sys.wMinute << ":" << sys.wSecond << "." << sys.wMilliseconds << "  ";
    outfile << "Worning: ";    
    outfile << str << endl;
    outfile.close();
    return 1;
}

int normal(string str)
{
    ofstream outfile;
    SYSTEMTIME sys; 
    GetLocalTime(&sys); 
    outfile.open(".\\builder.log",ios::out|ios::app);
    outfile << "[Time]:" << sys.wYear << "-" << sys.wMonth  << "-" << sys.wDay  << " "   << sys.wHour << ":" << sys.wMinute << ":" << sys.wSecond << "." << sys.wMilliseconds << "  ";
    outfile << "Normal: ";
    outfile << str << endl;
    outfile.close();
    return 0;
}