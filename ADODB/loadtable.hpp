#pragma once
#include <iostream>
#include <map>

#define SQL_query "select * from db.dbo.table"

struct struct_tablename
{
    public:
    std::wstring stringcode;
    double doublevalue;
};

class class_tablename
{
    public:
    std::map<<std::wstring, struct_tablename> GetData();
}
