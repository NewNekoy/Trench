#ifndef SQL_Gestion_H
#define SQL_Gestion_H

#include <iostream>
#include <windows.h>
#include <mysql.h>

using namespace std;

class SQL_Gestion
{
public:
    SQL_Gestion();
    ~SQL_Gestion(){};

    void GETTER(string query);
    void EXECUTE(string query);
    bool checkConnection(string username, string password);

private:
    MYSQL *con;
};

#endif // SQL_Gestion_H
