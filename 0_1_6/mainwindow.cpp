#include "mainwindow.h"
#include "ui_mainwindow.h"

//sqlite3* conn = NULL;
//char* sql = "AI.db";

map<QString,string>QAA;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("凉果冻"));
    QString str = "你好啊~人类0v0~";
    ui->textBrowser->append(str);

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::map()
{

    QAA["你好"] = "你好啊";
    QAA["你叫啥"] = "凉果冻";


}


void MainWindow::on_pushButton_clicked()
{
    QString O = ui->textEdit->toPlainText();
    QString x = "";
    if(O == x)
    {
        QString str = "\n你想说啥你到是说啊,喵=v=";
        ui->textBrowser->append(str);
    }
    else
    {
        //ui->textBrowser->append("ahahahh");
        User_in();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    exit(0);
}


void MainWindow::User_in()
{

    while(1)
    {
        QString userin = ui->textEdit->toPlainText();    //获取用户输入
        map<QString,string>::iterator iter;
        iter = QAA.find(userin);
        if(iter != QAA.end())
        {
            ui->textBrowser->append(userin);
        }
        else
        {
            ui->textBrowser->append("未找到");
        }
    }
}


/*
SQLITE_API int MainWindow::Sqlite3_Open()
{
    const char *filename = NULL;   // Database filename (UTF-8)
    sqlite3 **conn = NULL;          // OUT: SQLite db handle
    return SQLITE_API int();
}

void MainWindow::Open_DB(char* sql)		//打开数据库
{
    char* err_msg = NULL;
    // char sql[200] = ""; //这东西干啥的我也不清楚==暂时注释掉

    // 打开数据库, 创建连接
    if (sqlite3_open(sql, &conn) != SQLITE_OK)
    {
        const char* sq =sqlite3_errmsg(conn);
        QString str = QString(QLatin1String(sq));
        ui->textBrowser->append("无法打开数据库,错误代码:");
        ui->textBrowser->append(str);

    }
    else
    {
        ui->textBrowser->append("成功打开数据库~");
    }
}

void MainWindow::Close_DB()	//关闭数据库
{
    char* err_msg = NULL;
    //char sql[200] = ""; //这东西干啥的我也不清楚==暂时注释掉

    // 关闭连接。
    if (sqlite3_close(conn) != SQLITE_OK)
    {
        const char* sq =sqlite3_errmsg(conn);
        QString str = QString(QLatin1String(sq));
        ui->textBrowser->append("无法关闭数据库,错误代码:");
        ui->textBrowser->append(str);
        exit(-1);
    }
    else
    {
        ui->textBrowser->append("成功关闭数据库~");
    }
}

void MainWindow::ExecSQL(char * sql)	//写完用这个添加数据库
{
    sqlite3_exec(conn, sql, UserResult, 0, 0);
}

char** MainWindow::SrawQuery(char * sql, int * row, int * column, char ** result)
{
    sqlite3_get_table(conn, sql, &result, row, column, 0);
    return result;
}

int MainWindow::UserResult(void *NotUsed, int argc, char **argv, char **azColName)	//将Selectuserd建造出来的数据输出存储
{

    //char* Arg_s[15];
    //char* Lv[2];
    for (int i = 0; i < argc; i++)
    {
        //cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << ". ";
        //Arg_s[i] = (argv[i] ? argv[i] : "NULL");
        //RetBu(Arg_s[i]);	//将属性传递出去
        //cout <<  Arg_s[i] << endl;
    }
    //Gcom::Save(Arg_s);

    cout << endl;

    return 0;
}

int MainWindow::SelectUser(int bu) //调出数据函数
{

    Open_DB(sql);

    char* cErrMsg = "";
    char s[4] = "";
    sprintf_s(s,"%d",bu);
    s[2] = ';';
    char d[100] = "SELECT * FROM SG WHERE ID = ";
    strcat_s(d, s);
    //cout << s;

    int res = sqlite3_exec(conn,d, UserResult, NULL, &cErrMsg);	//调用sqlite3_exec.直接往里输sql命令就好啦~

    if (res != SQLITE_OK)
    {
        //const char* sq =sqlite3_errmsg(conn);
        QString str = QString(QLatin1String(cErrMsg));
        ui->textBrowser->append("查询数据库失败:");
        ui->textBrowser->append(str);
        //cout << "查询失败: " << cErrMsg << endl;
        Close_DB();
        return false;
    }
    else
    {
        //
    }
    Close_DB();
    return 0;
}
*/
