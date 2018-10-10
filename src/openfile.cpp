/**
 *  time:       2018-9-28
 *  describe:   open file(cpt or frm) and send point 
 *  version:    v1.0
 *  author:     Flor
 *  email:      florhop410@gmail.com
*/
#include <iostream>
#include <fstream>
#include <string>
#include"string.h"
#include "builder.h"

using namespace std;

int openfile(string fname);

/*************************************************
Function:       opencpt(string fname)
Description:    open cpt and collect sql info 
Calls:          
Table Accessed: NULL
Table Updated:  NULL
Input:          address of cpt  
Output:         NULL
Return:         Structural of sqlinfo  array
Others:         begin:  <TableData n
                end:    ]]></Query>
*************************************************/
int openfile(string fname)
{
    // 创建用于保存SQL的文件夹 ./document
    string dirname = "./document";
    createdir(dirname);


    ifstream infile;
    ofstream outfile;
    infile.open(fname,ios::in);
    outfile.open(".\\document\\list.txt",ios::out | ios::app);    // 创建列表文件
    if(!infile)
    {
        error("open file of fail!");
        return -1;
    }
    if(!outfile)
    {
        error("create list.txt is fail!");
        return -1;
    }
    char* data = new char[1024];
    int begin = 0;
    int end = 0;
    int num = 1; // 记录SQL文件数量
    while(infile.getline(data,1024))  //逐行读取frm
    {
        int tmp = 0;
        int len = 0;
        int point = 0;
        while(data[len] != '\0') len++;
        while(tmp+12 <= len)
        {
            string cur_begin(&data[tmp],&data[tmp+12]);   // 截取与选取头相同字节数的字符串
            if(cur_begin == "<TableData n") //成功匹配头字符串
            {
                //  To avoid the warning of " ISO C++ says that these are ambiguous"
                point = infile.tellg();

                begin = point - len + tmp;
                while(infile.getline(data,1024))    //开始匹配对应尾字符串
                {
                    tmp = 0;
                    len = 0;
                    while(data[len] != '\0') len++; 
                    while(tmp+11 <= len)  
                    {
                        string cur_end(&data[tmp],&data[tmp+11]);
                        if(cur_end == "]]></Query>")
                        {
                            point = infile.tellg();
                            end = point - len + tmp - 1;
                            string s_begin = to_string(begin);
                            string s_end = to_string(end);
                            normal(string("The content is begin :" + s_begin) + string("-" + s_end));
                            outfile << to_string(num++) << ": " <<  SearchName(fname,begin,end) << endl;
                            normal("The sql " + SearchName(fname,begin,end) + " is create");
                            CreateSql(fname,SearchName(fname,begin,end),begin,end);
                            normal("input sql is finish.");
                            break;
                        }
                        tmp++;
                    }
                    memset(data,0,sizeof(data));
                    if (end > begin)
                    {
                        break;
                    }
                }   //匹配对应尾结束
                break;
            }
            tmp++;
        }
        memset(data,0,sizeof(data));
    }
    infile.close();
    outfile.close();
    delete [] data;
    return 0;
}
