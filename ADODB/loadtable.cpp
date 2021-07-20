#include <ADODB.hpp>
#include <loadTable.hpp>
#include <string>

std::map<std::wstring, struct_tablename> class_tablename::GetData()
{
    std::map<std::wstring, struct_tablename> table;
    DataBase db;
    db.Open();
    RecPtr rec = db.Execute(SQL_query);
    
    if(rec!= NULL)
    {
        while(!rec->adoEOF)
        {
            struct_tablename data;
            data.stringcode = rec->Fields->GetItem("ColName1")->Value.bstrVal;
            data.doublevalue = rec->Fields->GetItem("ColName2")->Value;
            //data.towstring = std::to_wstring(rec->Fields->GetItem("ColName3")->Value.intVal);
            
            //std::wstring key = data.stringcode + L"_" + data.towstring;
            table[key] = data;
            rec->MoveNext();
        }
    }
    return table;
}
