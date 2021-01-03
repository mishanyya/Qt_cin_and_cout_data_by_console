#include <QCoreApplication>

#include <QTextCodec>
#include <iostream>

using namespace std;//Подключение стандартной библиотеки функций

int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);

#ifdef Q_OS_WIN32
QTextCodec::setCodecForLocale(QTextCodec::codecForName("IBM 866"));
#endif

#ifdef Q_OS_LINUX
QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
#endif
//Ваш код начинается отсюда

char x;//в тип char поместится только один символ
//вводим значение
cout << QString::fromUtf8("Введите значение:").toLocal8Bit().data() << endl;
cin >> x;
//выведем результат
cout << QString::fromUtf8("Ваше значение: ").toLocal8Bit().data() << x << endl;

//Ваш код заканчивается здесь
return a.exec();
}
