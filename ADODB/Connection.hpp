
#ifndef adodb_hpp
#define adodb_hpp

#include <iostream>
#include "C:\program files\common files\system\ado\msado15.tlh"

typedef ADODB::_RecordsetPtr RecPtr;
typedef ADODB::_ConnectionPtr CnnPtr;

class DataBase
{
    public:

    DataBase();
    ~DataBase();
    
    CnnPtr m_Con;
    bool Open();
    RecPtr Execute(const char *CmdStr);
    bool Close();
    
    const char *CnnStr = "DSN=DBname";
    const char *UserName = "shin";
    const char *Pwd = "1111";
}

std::string bstr_to_str(BSTR source);
std::wstring str_to_wstr(std::string str);
std::wstring bstr_to_wsrt(BSTR source);

