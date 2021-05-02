#include <QCoreApplication>
#include <QSettings>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSettings reg("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);
    QVariant value = reg.value("键名1");
    if (value.canConvert<QString>())
    {
        qDebug() << value.toString();
    }
    value = reg.value("键名2");
    if (value.canConvert<int>())
    {
        qDebug() << value.toInt();
    }
    return a.exec();
}
