#pragma once
#include <map>
#include "loadTable.hpp"

class loadData
{
    public:
    std::map<std::wstring, struct_tablename> m_tablename; // member
    bool LoadTables(std::string s);
    
}
