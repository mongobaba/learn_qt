#include <QCoreApplication>
#include <QSettings>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSettings reg("HKEY_CURRENT_USER\\Software\\Microsoft\\Internet Explorer\\Main", QSettings::NativeFormat);
    reg.setValue("Start Page", "http://www.baidu.com");
    std::cout << "success" << std::endl;
    return a.exec();
}
