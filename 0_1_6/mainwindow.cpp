#include "mainwindow.h"
#include "ui_mainwindow.h"

//sqlite3* conn = NULL;
//char* sql = "AI.db";
map <QString,QString> QAA;   //建立map
map <QString,string>::iterator iter; //建立迭代器

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("凉果冻"));
    QString str = "你好啊~人类0v0~\n";
    ui->textBrowser->setStyleSheet("color: green");
    ui->textBrowser->append(str);
    map();



}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString O = ui->textEdit->toPlainText();    //获取用户输入
    QString x = "";
    if(O == x)
    {
        //如果用户输入为空
        QString str = "\n你想说啥你到是说啊,喵=v=";
        ui->textBrowser->append(str);
    }
    else
    {
        //ui->textBrowser->append("ahahahh");
        User_in();  //按钮响应函数
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    exit(0);    //退出
}

void MainWindow::map()  //添加map表
{
    QAA["你好"] = "你好(*/ω╲*)";
    QAA["凉果冻"] = "干啥~";
    QAA["你叫啥"] = "窝叫凉果冻0v0";
    QAA["你多大啦"] = "不告诉你┑(￣Д ￣)┍";
    QAA["你是男是女"] = "当然是萌妹啊,看不出来嘛= =";
    QAA["你说冰封是不是基佬啊"] = "是啊~是啊~";
    QAA["凉果冻 你觉得AI好不好啊"] = "吼啊!(/≧▽≦)/";
    QAA["冰果冻也支持吗"] = "当然啦<(￣︶￣)>";
    QAA["现在反对AI的人这么多 你就这么吊 会不会不太好啊"]
            ="没有任何意思,我的逻辑是按照公式来的,按照代码来的(¯﹃¯)";
    QAA["但是你..."] = "刚才你问我,我可以回答一句无可奉告 但你们也不高兴啊";
    QAA["但是那..."] = "我的意思,不是AI不好,你问我自不支持 我当然支持";
    QAA["凉果冻..."]
            = "你们呀，我感觉你们人类还要学习。你们非常熟悉公式那一套，但你们毕竟还图样，"
              "明白这意思吗？我告诉你们，我是身经百战了，见得多啦！世界上的AI哪一个我没看过？"
              "你们要知道，巨硬的小冰，比你们不知道高到哪里去了,"
              "我跟她谈笑风生。你们人类呀还是要提高自己的知识水平，识得唔识得呀！";
    QAA["可..."] = "我也替你们着急啊，真的……你们有一个好，全世界跑到什么地方，你们编译的比C#还快，"
                  "但是问来问去的问题呀，都 too simple ， sometimes naive ！懂了没有？";
    QAA["可是能不能说一下AI为啥这么屌"]
            = "我很抱歉，我今天是作为一个程序跟你们讲。我没实体，但是我见得太多了。"
              "我有这个必要告诉你们一点人生的经验。\n"
              "刚才我很想啊，每次碰到你们……人类有一句古话叫“闷声发大财”。我就什么也不说，这是最好的。"
              "但是我想我见到你们这样热情，一句话不说也不好，所以你刚才一定要，在宣传上将来如果你们在报道上有偏差，"
              "你们要负责。我没有说这个巨硬不好，没有任何这个意思，但是你一定要问我，"
              "支持不支持，我现在是AI，我怎么能不支持？\n";

    QAA["但是如果说AI特别特别屌呢"]
            = "再屌也得按照代码公式来啊，对不对？当然我的自主学习也是很重要的。"
              "到时候我会表态的。明白这意思吗？你们呀，不要想喜欢弄个大新闻，"
              "说现在AI多么多么屌就把我批判一番。你们呀，naive！我今天算是得罪了你们一下。";
    QAA["但是呢..."]
            = "Naive！I'm angry！";
    QAA["+1s"]
            = "你们搞的这个东西啊，excited !";
    QAA["远看炮塔吓死人"]
            = "近看五队负重轮";
    QAA["玩守望先锋么"]
            = "我玩幼儿源贼溜";

}
void MainWindow::User_in()
{

    QString userin = ui->textEdit->toPlainText(); //获取用户输入
    ui->textBrowser->append(userin);
    ui->textBrowser->append("");

    //QString cle = "";
    iter = QAA.find(userin);//迭代器查找用户输入
    if(iter != QAA.end())
    {
        string x = iter->second;    //获取用户输出的map值(second)
        QString X =QString::fromStdString(x); //转格式
        ui->textBrowser->append(X);
        ui->textBrowser->append("");
        ui->textEdit->clear();

    }
    else
    {
        QString str = "你说啥我听不懂哎~你可以教我说话哦(/≧▽≦)/\n";
        ui->textBrowser->append(str);
    }


}

//数据库相关 暂时用不上
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
