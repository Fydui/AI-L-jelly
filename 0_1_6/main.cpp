#include "mainwindow.h"
#include <QApplication>
QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); //添加数据库驱动链接sqlite
int main(int argc, char *argv[])
{

    QTextCodec *xcodec = QTextCodec::codecForLocale() ;
        QString exeDir = xcodec->toUnicode( QByteArray(argv[0]) ) ;
        QString BKE_CURRENT_DIR = QFileInfo(exeDir).path() ;
        QStringList  libpath;
        libpath << BKE_CURRENT_DIR+QString::fromLocal8Bit("/plugins/platforms");
        libpath << BKE_CURRENT_DIR <<BKE_CURRENT_DIR+QString::fromLocal8Bit("/plugins/imageformats");
        libpath << BKE_CURRENT_DIR+QString::fromLocal8Bit("/plugins");
        libpath << QApplication::libraryPaths();
        QApplication::setLibraryPaths(libpath) ;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
