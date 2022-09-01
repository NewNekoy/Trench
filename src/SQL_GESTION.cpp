#include "SQL_Gestion.h"

void finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

SQL_Gestion::SQL_Gestion()
{
    con = mysql_init(NULL);

    if (con == NULL)
    {
        cout << mysql_error(con) << endl;
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "user", "password", "db", 0, NULL, 0) == NULL)
    {
        finish_with_error(con);
    }
}

void SQL_Gestion::GETTER(string query)
{
    if (mysql_query(con, query.c_str()))
    {
        finish_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);

    if (result == NULL)
    {
        finish_with_error(con);
    }

    int num_fields  = mysql_num_fields(result);

    MYSQL_ROW row;

    while (row = mysql_fetch_row(result))
    {
        for(int i = 0; i < num_fields; i++)
        {
            cout << row[i] ? row[i] : "NULL";
            cout << " ";
        }

        cout << endl;
    }

    mysql_free_result(result);
}

bool SQL_Gestion::checkConnection(string username, string password)
{
	string query = "SELECT * FROM Account WHERE username = '" + username + "' AND password = '" + password + "'";
	mysql_query(con, query.c_str());

	MYSQL_RES *res = mysql_use_result(con);
	MYSQL_ROW row = mysql_fetch_row(res);

	mysql_free_result(res);

	if (row) return true;
	else return false;
}

void SQL_Gestion::EXECUTE(string query)
{
    if (mysql_query(con, query.c_str()))
        finish_with_error(con);
}
