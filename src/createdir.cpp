#include <string>
#include <iostream>
#include <direct.h>
#include <io.h>
#include "builder.h"
using namespace std;

int  createdir(string dirname);
/**
 * function:    void createdir(void)
 * description: mkdir  {$root}/document
 * calls:       
 * input:       void
 * output:      void
 * other:       
*/

int  createdir(string dirname)
{ 
	string dir = dirname;	// Directory called document
	if (access(dir.c_str(), 0) == -1)   // Decide whether to create
	{
		normal(dir+" is not existing,and now make it");
#ifdef WIN32
		int flag=mkdir(dir.c_str()); 
#endif
#ifdef linux 
		int flag=mkdir(dir.c_str(), 0777);
#endif
		if (flag == 0)
		{
			normal("make dir successfully");
		} else {
			error("make dir errorly");
			return -1;
		}
	}
	else
	{
		normal(dir + " is exists");
		// cout<<"now delete it"<<endl;
		// int flag=rmdir(dir.c_str());
		// if (flag == 0)
		// {
		// 	cout<<"delete it successfully"<<endl;
		// } else {
		// 	cout<<"delete it errorly"<<endl;
		// }
	}
	return 0;
}
