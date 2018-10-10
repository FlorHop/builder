/**
 *  time:       2018-9-28
 *  describe:   recive point to create sql
 *  version:    v1.0
 *  author:     Flor
 *  email:      florhop410@gmail.com
*/
#include <iostream>
#include <string>
#include <fstream>
#include"string.h"
#include "builder.h"

using namespace std;

string SearchName(string fname,int begin,int end);
void CreateSql(string fname,string sqlname,int begin,int end);

string SearchName(string fname,int begin,int end)
{
    ifstream infile;
    char data[1024];
    infile.open(fname,ios::in);
    infile.seekg(begin,ios::beg);
    infile.getline(data,1024);
    int len = 0;
    int tmp = 0;
    int flag = 0;
    while(data[len] != '\0') len++;
    while(tmp < len)
    {
        if(data[tmp] == '"' && flag++ && flag == 2)
        {
            string sql(&data[16],&data[tmp]);
            return sql;
        }
        tmp++;
    }
    infile.close();
}

void CreateSql(string fname,string sqlname,int begin,int end)
{
    ofstream outfile;
    ifstream infile;
    outfile.open(".\\document\\" + sqlname+ ".sql",ios::out|ios::trunc);
    if(!outfile)
    {
        error("Create sql (name:" + sqlname + ") is fail!");
    }
    infile.open(fname,ios::in);
    infile.seekg(begin,ios::beg);
    char* data = new char[1024];
    int len = 0;
    while(infile.getline(data,1024))    // <Query>
    {
        len = 0;
        while(data[len] != '\0') len++;
        string cur(&data[0],&data[len]);
        if(cur == "<Query>")
        {
            int flag = 0;
            while(infile.tellg() < end && infile.getline(data,1024))
            {
                if(flag == 0)
                {
                    flag++;
                    string rp_str = data;
                    outfile << rp_str.erase(0,9) << endl;
                    memset(data,0,sizeof(data));
                }
                else
                {
                    outfile << data << endl;
                    memset(data,'\0',sizeof(data));
                }
            }
            break;
        }
        cur.erase(0);
        memset(data,'\0',sizeof(data));
    }
    fstream ffile;      // replace ]]></Query use ' '
    ffile.open(".\\document\\" + sqlname+ ".sql",ios::in | ios::out);
    ffile.seekg(-13,ios::end);
    ffile << "              ";
    ffile.close();
    infile.close();
    outfile.close();
    delete [] data;
}