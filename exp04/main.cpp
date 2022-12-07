#include<iostream>
#include "mysql.h"
#include<string>
#include<cstdlib>

using namespace std;
MYSQL mysql;
int main()
{


	mysql_init(&mysql); // ·ÖÅä¾ä±ú
	/*MYSQL* mysql_real_connect(MYSQL * mysql, const char* host, const char* user,
		const char* passwd, const char* db, unsigned int port,
		const char* unix_socket, unsigned long client_flag)*/
	if (!mysql_real_connect(&mysql, "localhost", "root", "3514081wcy", "university", 3306, nullptr, 0))
	{
		cout << "connect fail" << endl;
	}
	else
	{
		cout << "connect success" << endl;
	}
	// mysql_query(&mysql, "set names gbk");
	string query;
	getline(cin, query);

	//command[j] = '\0';
	// cout << command;
	MYSQL_RES* res;
	MYSQL_ROW row;
	if (mysql_real_query(&mysql, query.c_str(), (unsigned long)query.length()))
	{
		cout << "query failure" << endl;
		cout << mysql_error(&mysql) << endl;
	}
	else
	{
		cout << "query success" << endl;
	}
	if (query.substr(0, 6) == "select") // ²éÑ¯
	{
		if (!(res = mysql_store_result(&mysql)))
		{
			cout << "Couldn't get result from " << mysql_error(&mysql) << endl;
		}
		MYSQL_FIELD* field;
		field = mysql_fetch_field(res);
		for (int i = 0; i < mysql_num_fields(res); i++)
		{
			cout << field[i].name << "\t";
		}
		cout << endl;
		while (row = mysql_fetch_row(res))
		{
			for (int i = 0; i < mysql_num_fields(res); i++)
			{
				cout << row[i] << '\t';
			}
			cout << endl;
		}
		// mysql_close(&mysql);
	}
	
	mysql_close(&mysql);
	system("pause");
	return 0;
}