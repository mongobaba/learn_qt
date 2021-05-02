#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QStringList list = QSqlDatabase::drivers();
    for (auto& s : list)
    {
        qDebug() << s;
    }
    return a.exec();
}
