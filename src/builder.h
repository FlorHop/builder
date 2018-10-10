#ifndef __builder_h
#define __builder_h

using namespace std;

//  openfile.cpp
int openfile(string fname);

//  createdir.cpp
int  createdir(string dirname);

//  createsql.cpp
string SearchName(string fname,int begin,int end);
void CreateSql(string fname,string sqlname,int begin,int end);

//  log.cpp
int error(string str);
int worning(string str);
int normal(string str);

#endif