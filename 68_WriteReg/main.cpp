#include <QCoreApplication>
#include <QSettings>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSettings reg("HKEY_CURRENT_USER\\Software\\Qt01", QSettings::NativeFormat);
    reg.setValue("键名1", "值001");
    reg.setValue("键名2", 1);
    return a.exec();
}
