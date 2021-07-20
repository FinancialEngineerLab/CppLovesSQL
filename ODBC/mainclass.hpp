#include <windows.h>

#include <sqlext.h>

#include <stdio.h>


class PODBC {

    SQLHENV henv;

    SQLHDBC hdbc;

    SQLHSTMT hstmt;

    SQLRETURN retcode;

    // For specific error

    SQLSMALLINT length;

    SQLINTEGER rec = 0, native;

    SQLCHAR state[7], message[256];

public:

    void AllocateHandles();

    void ConnectDataSource();

    void ExecuteStatementDirect(SQLCHAR* sql);

    void PrepareStatement(SQLCHAR* sql);

    void ExecuteStatement();

    void RetrieveResult();

    void DisconnectDataSource();

};
