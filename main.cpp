#include "QCoreApplication"

//добавлено >>
#include "QDebug" //для вывода информации в консоли программы Qt через использование "qDebug() <<"


using namespace std;//подключение стандартной библиотеки функций для ввода и вывода информации стандартными средствами C++
#include "iostream" //для ввода и вывода информации стандартными средствами C++
#include "string" //для работы с данными типа string в C++

#include "QtSql/QSqlDatabase" //для создания объектов для подключения и работы баз данных в программе Qt
#include "QSqlQuery" //для создания объектов для работы SQL-запросов
#include "QSqlError" //для получения информации о возможных ошибках при работе с базами данных

#include "QTextCodec" //для кодировки символов
//Russian users often have their documents in KOI8-R or Windows-1251.




//<< добавлено
int main(int argc, char *argv[])
{
QCoreApplication a(argc, argv);
//добавлено >>

//подключение и открытие существующей базы данных
//драйвер для работы с БД
QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//здесь должен быть путь к самой БД!!!
db.setDatabaseName("/home/mishanyya/databaseexample/examplebdfordbwork");
//открывает файл, указанный в db.setDatabaseName();
db.open();


//создание запроса
QSqlQuery query( db );

//работает без ввода данных
/*
query.prepare("SELECT * FROM basetable WHERE number=?");
query.bindValue(0, 2);

//работает без ввода данных
query.prepare("SELECT * FROM basetable WHERE number LIKE :number");
query.bindValue(":number", 2);
*/

//ввод значения
string stroka;//строка C++
cout << "Введите строку:";
cin >> stroka;//в тип string на C++ войдет набор символов до первого пробела!
QString Qstroka = QString::fromStdString(stroka);//перевод строки C++ в строку QString
//работает с вводом данных
query.prepare("SELECT * FROM basetable WHERE number LIKE :number");
query.bindValue(":number", Qstroka);
query.exec();


//вывод результата запроса
qDebug() << "Вывод результата запроса:";
   while (query.next()) {
       QString number = query.value(0).toString();
       QString content = query.value(1).toString();
       QString content1 = query.value(2).toString();
       QString content2 = query.value(3).toString();
       QString content3 = query.value(4).toString();
       qDebug() << number << "|"<< content<< "|"<< content1<< "|"<< content2<< "|"<< content3;
   }









int x,y;//в тип char поместится только один символ
//вводим значение
//endl - перевод на новую строку
cout << "Введите символ:"<< endl;
cin >> x;
y=x*x; //возведение в квадрат

cout << "x*x = " << y<< endl;//вывод результата










//создает запрос
QSqlQuery query1( db );
query1.prepare("INSERT INTO basetable (number,name,fone,automodel,price) VALUES (NULL,?,?,?,?)");
query1.bindValue(0, Qstroka);//bindValue(номер значения, само значение)
query1.bindValue(1, x);
query1.bindValue(2, y);
query1.bindValue(3, x-y);
query1.exec();



//создает запрос
QSqlQuery query2( db );
query2.prepare("SELECT * FROM basetable");
query2.bindValue(":number", Qstroka);
query2.exec();


//вывод результата запроса
qDebug() << "Вывод последней записи в результате запроса:";
   query2.last();
       QString number = query2.value(0).toString();
       QString content = query2.value(1).toString();
       QString content1 = query2.value(2).toString();
       QString content2 = query2.value(3).toString();
       QString content3 = query2.value(4).toString();
       qDebug() << number << "|"<< content<< "|"<< content1<< "|"<< content2<< "|"<< content3;






//просто для информации, это не обязательно!
qDebug() <<"isOpen="<<db.isOpen();//если текстовый файл открыт
qDebug() <<"connection DB exists="<< db.isValid();// если соединение осуществлено успешно
qDebug() <<"available drivers="<<QSqlDatabase::drivers();// выводит список доступных драйверов для различных баз данных
qDebug() <<"errors="<<db.lastError().text();//список возможных ошибок
//конец кода работы с существующей БД



//<< добавлено


return a.exec();
}


