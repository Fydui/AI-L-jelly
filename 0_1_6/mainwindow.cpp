#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setform.h"
#include "ui_setform.h"
using namespace std;

//map <QString,QString> QAA;   //建立map
//map <QString,string>::iterator iter; //建立迭代器

extern QSqlDatabase db; //添加数据库驱动链接sqlite
QSqlQuery* query;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(360,640);    //固定窗口大小
    setWindowTitle(tr("凉果冻"));
    QString str = "你好啊~人类0v0~\n";
    ui->textBrowser->setStyleSheet("color: green"); //设置输出文字颜色
    ui->textBrowser->append(str);
    // map();
    Lsql();

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Lsql()
{
    db.open();
    db.setDatabaseName("LAI.db");   //打开数据库
    if(!db.open())
    {
        ui->textBrowser->setStyleSheet("无法打开数据库,不要乱动数据库啦");
    }
    query = new QSqlQuery;
    query->exec("CREATE TABLE LAI(ID INTEGER PRIMARY KEY AUTOINCREMENT,ASK TEXT, ANSWER TEXT)");    //建立表
    query->exec(QObject::tr("SELECT * FROM LAI ORDER BY ID ASC"));
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
/*
void MainWindow::map()  //添加map表
{
    QAA["你好"] = "你好";
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
    QAA["昆西昆西昆"]
            = "昆0v0";
    QAA["sin半角公式"]
            = "sinα/2 = ±√((1-cosα)/2)";

}
*/
/*
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
*/
void MainWindow::User_in()
{
    QString userin = ui->textEdit->toPlainText();
    QString useri = "你对凉果冻说: " + userin;
    ui->textBrowser->append(useri);
    ui->textBrowser->append("");
    QString usinq = "SELECT * FROM LAI WHERE ASK LIKE '";
    QString usinm = "%'";

    QString user_u = usinq+userin+usinm;
    QString uout;
    query->exec(user_u);
    QString userk = "凉果冻回答你: " ;

        while(query->next())
            uout = query->value(2).toString();

        if(uout == "")
            ui->textBrowser->append("你说啥啊~我听不懂呀~你可以教我说话滴~\n\n");

        else
            {
                uout =userk + uout;
                ui->textBrowser->append(uout);
                ui->textBrowser->append("\n");
            }

    ui->textEdit->clear();
}

void MainWindow::on_pushButton_3_clicked()
{
    /*
    QWidget* setting = new QWidget();
    setting->setWindowModality(Qt::ApplicationModal);   //禁用父窗口
    setting->show();
    setting->setWindowTitle(tr("设置"));
    */
    //setform->setWindowModality(Qt::ApplicationModal);   //禁用父窗口
    SetForm* setform = new SetForm();
    setform->show();
    setform->setWindowTitle(tr("设置"));
    setform->setFixedSize(360,640); //限制窗口大小

}
