#include <ADODB.hpp>

// belows are standardized template //

DataBase::DataBase()
{
    ::Colnitialize(NULL);
    m_Con = NULL;
}

// ODBC functions //
bool DataBase::Open()
{
    HRESULT hr;
    try
    {
        if(m_Con != NULL)
        {
            return 0;
        }
        hr = m_Con.CreateInstance(_uuidof(ADODB::Connection));
        m_Con -> CommandTimeout=0;
        m_Con -> ConnectionTimeout = 0;
        m_Con -> Open(this->CnnStr, this->UserName, this->Pwd, NULL); //Important!
    }
    catch (_com_error &e)
    {
        std::cout << e.ErrorMessage() << std::endl;
        return 0;
    }
    return 1;
}

bool DataBase::Close()
{
    if(m_Con==NULL)
    {
        return 0;
    }
    
    try
    {
        m_Con -> Close();
        m_Con = NULL;
    }
    catch(_com_error &e)
    {
        std::cout << e.ErrorMessage() << std::endl;
        return 0;
    }
    return S_OK;
    }
}

// *CmdStr Declared pointing to &A
// A pointed by *CmdStr = Value , *CmdStr =Value, &A pointed by *CmdStr= Address
// &CmdStr = Address, CmdStr = Address //
// TIP: array variable : *var = [], delete[].
RecPtr DataBase::Execute(const char *CmdStr)
{
    try
    {
        if(m_Conn == NULL)
        {
            return NULL;
        }
        retrun m_Con ->Excute(CmdStr, NULL, ADODB::adCmdText); // CmdStr = Address
    }
    catch (_com_error &e)
    {
        std::cout << e.ErrorMessage() << std::endl;
        return NULL;
    }
}

DataBase::~DataBase()
{
    try
    {
        if(m_Con)
        {
            m_Con->close();
            m_Con = NULL
        }
        ::CoUnitialize();
    }
    catch (_com_error &e)
    {
        std::cout << e.ErrorMessage() << std::endl;
    }
}

// converting functions //

std::string bstr_to_str(BSTR source)
{
    _bstr_t wrapped_bstr = _bstr_t(source);
    int length = wrapped_bstr.length();
    char *char_array = new char[length];
    strcpy_s(char_array, length + 1, wrapped_bstr);
    return char_array;
}

std::wstring str_to_wsrt(std::string str)
{
    std::wstring w = L"";
    w.assign(str.begin(), str.end());
    return w;
}

// TIP: array variable : *var = [], delete[].
std::wstring bstr_to_wstr(BSTR source)
{
    std::wstring w;
    _bstr_t wrapped_bstr = _bstr_t(source);
    int length = wrapped_bstr.length();
    char *char_array = new char[length];
    
    strcpy_s(char_array, length +1, wrapped_bstr);
    std::string str= bstr_to_str(source);
    w = str_to_wstr(str);
    return w;
}
