/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define SAVERESULT "insert into SAVE.dbo.RESULT (col1, col2) values @str"

class RESULT
{
    public:
    void Run(std::wstring recordid, LoadData *act);
    void Save();
    std::vector<std::map<std::string, std::string>> result;
}


void Run//~~
{
    calculate ~~
    
    m["col1"] = ~~
    m["col2"] = ~~
    m["col3"] = ~~
    
    result.push_back(m);
}

void Result::Save()
{
    std::string str = "";
    
    for(int i = 0; i <r.size(); i++)
    {
        str = str + "(" + r[i]["col1"] + "," + r[i]["col2"] + "),";
    }
    str =str.substr(0, str.length()-1);
    
    DataBase db;
    db.Open();
    
    std:string strSQL = SAVERESULT;
    boost::replace_all(strSQL, "@str", str);
    db.Execute(strSQL.c_str());
}

int main()
{
    // ~~ 
    LoadData act;
    // ~~
    
    Result result;

    // ~~
    result.Run(recordid[i], &act); // *act pointing &act = value
    
    
    
}

