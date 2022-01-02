#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QTextStream>
#include "animal.cpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString ruta("/home/lv/Descargas/palili.dat");
    QString ruta_des("/home/lv/Descargas/palili_copy.dat");
    QFile *file = new QFile(ruta);
    QFile *file_des = new QFile(ruta_des);
    file->open(QFile :: ReadOnly | QFile::Text);
    file_des->open(QIODevice :: WriteOnly | QIODevice::Text);
    QTextStream pa(file);
    QTextStream pa_des(file_des);

    QString l1, l2, l3, l4;
    int l1int;
    int l2int;
    double l3int;
    double l4int;

    while(!pa.atEnd()){

        QString aux = file->readLine();

        QStringList l = aux.split("\t");

        l1 = l.at(0);
        l2 = l.at(1);
        l3 = l.at(3);
        l4 = l.at(5);



        l4.remove(l4.length()-1,2);

        l1int = l1.toDouble();
        l2int = l2.toDouble();
        l4int = l4.toDouble()*3.0;
        l3int = l3.toDouble()*2.0;

        l1 = QString::number(l1int, 'f', 6-l1.length()-2);
        l2 = QString::number(l2int, 'f', 6-l2.length()-2);
        l3 = QString::number(l3int, 'f', 6);
        l4 = QString::number(l4int, 'f', 6);

        qDebug() << l1;

        aux = l1 + "\t" + l2 + "\t\t" + l3 + "\t\t" + l4 + "\n";
        pa_des << aux;

        //l3.replace("\n","0");
        //l4.replace("\n","0");
        //aux.replace("\t",space);
        //qDebug() << aux << " " << l.length();



    }

    file->close();
    file_des->close();



    //return a.exec();

    a.quit();

}

