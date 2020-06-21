#include "head.h"

vector<record> getRecordByTime(string time, string username)
{
    MYSQL *con;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char dbuser[30] = "root";
    char dbpasswd[30] = "123456";
    char dbip[30] = "localhost";
    char dbname[50] = "userDB";
    int rt; 
    unsigned int t;
    int count = 0;
    con = mysql_init((MYSQL *)0);
    if (con != NULL && mysql_real_connect(con, dbip, dbuser, dbpasswd, dbname, 3306, NULL, 0))
    {
        cout<<"connect successfully"<<endl;
    }
    else
    {
        MessageBoxA(NULL, "Unable to connect the database,check your configuration!", "", NULL);
    }
    string selectString = "select * from record where time= " + time + " and name= " + username;
    rt = mysql_real_query(con, selectString, strlen(selectString));
    if (rt)
    {
        cout << mysql_error(con) << endl;
    }
    else
    {
        cout << selectString + " is  executed" << endl;
    }
    res = mysql_store_result(con); //将结果保存在res结构体中
    vector<record> vec;
    while (row = mysql_fetch_row(res))
    {
        record r1;
        r1.amount = row[0];
        r1.time = row[1];
        r1.type = row[2];
        r1.name = row[3];
        r1.inorout = row[4];
        vec.push_back(r1);
    }
    mysql_free_result(res);
    mysql_close(con);
    system("pause");
    return 0;        
}