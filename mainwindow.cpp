#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
#include "fstream"
#include <QDebug>

//#include <QFileDialog>
//#include <QTextStream>
//#include <QFile>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pixmap.fill(Qt::white);
    //
    ifstream fs("jordy.txt",ios::binary);
        string dir,name,labels;
        string *_labels=new string[30];
        int _y,nl;
        while( fs.read( (char *) & _y, sizeof( int )) ){ //a terminar el bloc de notas
            char* f0=new char[_y+2]; //el +2 es por el tamaño del string q ocupa y su \0
            fs.read( f0, _y );
            f0[_y]=0;
            dir=f0;
            delete []f0;

            fs.read( (char *) & _y, sizeof( int ));
            char* f1=new char[_y+2];
            fs.read( f1, _y );
            f1[_y]=0;
            name=f1;
            delete []f1;

            fs.read( (char *) & nl, sizeof( int ));
            for(int i=0;i<nl;i++){
                fs.read( (char *) & _y, sizeof( int ));
                char* f2=new char[_y+2];
                fs.read( f2, _y );
                f2[_y]=0;
                labels=f2;
                _labels[i]=labels;
                delete []f2;
            }

            Image im(name,dir,_labels);
            li.push_back(im);
            //delete []_labels;
        }
    //
    //qDebug() << "HOLAAAAA" ;
    if(li.begin()!=NULL){
        //
        linked_list<Image>::iterator it=li.begin();
        Image imag=*it;
        QPixmap a( QString::fromStdString(imag.date_path()) );
        pixmap=a;
        ui->text_labels_2->setText(" ");
        ui->text_labels_2->append("Nombre:");
        ui->text_labels_2->append( QString::fromStdString(imag.date_name()) );
        ui->text_labels_2->append("Path:");
        ui->text_labels_2->append( QString::fromStdString(imag.date_path()) );
        ui->text_labels_2->append("Labels:");
        int i=0;
        while( imag.date_label()[i] != "\0" ){
            ui->text_labels_2->append(QString::fromStdString(imag.date_label()[i]));
            i++;
        }//
    }
    else {
        QPixmap a;
        pixmap=a;
    }
    ui->label_image->setPixmap(pixmap);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_prev_clicked()
{
    pixmap.fill(Qt::white);
    linked_list<Image>::iterator it2=li.position("prev");
    Image imag=*it2;
    QPixmap z(QString::fromStdString(imag.date_path()));
    pixmap=z;
    ui->text_labels_2->setText(" ");
    ui->text_labels_2->append("Nombre:");
    ui->text_labels_2->append( QString::fromStdString(imag.date_name()) );
    ui->text_labels_2->append("Path:");
    ui->text_labels_2->append( QString::fromStdString(imag.date_path()) );
    ui->text_labels_2->append("Labels:");
    int i=0;
    while( imag.date_label()[i] != "\0" ){
        ui->text_labels_2->append(QString::fromStdString(imag.date_label()[i]));
        i++;
    }

    ui->label_image->setPixmap(pixmap);

}

void MainWindow::on_button_next_clicked()
{
    pixmap.fill(Qt::white);

    linked_list<Image>::iterator it2=li.position("next");
    Image imag=*it2;
    QPixmap z(QString::fromStdString(imag.date_path()));
    pixmap=z;
    ui->text_labels_2->setText(" ");
    ui->text_labels_2->append("Nombre:");
    ui->text_labels_2->append( QString::fromStdString(imag.date_name()) );
    ui->text_labels_2->append("Path:");
    ui->text_labels_2->append( QString::fromStdString(imag.date_path()) );
    ui->text_labels_2->append("Labels:");
    int i=0;
    while( imag.date_label()[i] != "\0" ){
        ui->text_labels_2->append(QString::fromStdString(imag.date_label()[i]));
        i++;
    }

    ui->label_image->setPixmap(pixmap);
}

void MainWindow::on_pushback_clicked()
{
    string *_labels=new string[30];   //:D
    QString qstrname=ui->line_name->text();
    QString qstrpath=ui->line_path->text();
    QString qstrlabels=ui->text_labels->toPlainText();
    int j=0;
    int m=0;
    for(int i=0;i<qstrlabels.size();i++){
        if(qstrlabels[i]=="\n"){
            if(j==0){
                qDebug()<<"entro";
                qDebug()<<i;
                string qstrlabel=qstrlabels.toStdString();
                QString aux=QString::fromStdString(qstrlabel.substr(j,i-j));
                j=i;
                _labels[m]=aux.toStdString();
                m++;
                ui->text_labels_2->append(aux);
            }
            else{
                //qDebug()<<"entro";
                //qDebug()<<i;
                string qstrlabel=qstrlabels.toStdString();
                QString aux=QString::fromStdString(qstrlabel.substr(j+1,i-j-1));
                j=i;
                _labels[m]=aux.toStdString();
                m++;
                ui->text_labels_2->append(aux);
            }
        }
    }
    //string qstrlabel=qstrlabels.toStdString();
    //qDebug()<<QString::fromStdString(qstrlabel.substr(0,3)); //substr(0,1) se refiere q leera el 0 hasta 1-1
    qDebug()<<qstrlabels;
    qDebug()<<qstrlabels.size();
    Image a(qstrname.toStdString(),qstrpath.toStdString(),_labels);
    qDebug()<<"entro2";
    li.push_back(a);
    /*QPixmap _a( QString::fromStdString(a.date_path()) );
    pixmap=_a;
    ui->label_image->setPixmap(pixmap);
    */
    qDebug()<<"entro";

    qDebug()<<"salio";

    linked_list<Image>::iterator iterz1=li.begin();
    Image aux=*iterz1;
    int i=0;
    while( aux.date_label()[i] != "\0" ){
        qDebug()<<QString::fromStdString(aux.date_label()[i]);
        i++;
    }

}

void MainWindow::on_pushfront_clicked()
{

    string *_labels=new string[30];   //R
    QString qstrname=ui->line_name->text();
    QString qstrpath=ui->line_path->text();
    QString qstrlabels=ui->text_labels->toPlainText();
    int j=0;
    int m=0;
    for(int i=0;i<qstrlabels.size();i++){
        if(qstrlabels[i]=="\n"){
            if(j==0){
                string qstrlabel=qstrlabels.toStdString();
                QString aux=QString::fromStdString(qstrlabel.substr(j,i-j));
                j=i;
                _labels[m]=aux.toStdString();
                m++;
            }
            else{
                string qstrlabel=qstrlabels.toStdString();
                QString aux=QString::fromStdString(qstrlabel.substr(j+1,i-j-1));
                j=i;
                _labels[m]=aux.toStdString();
                m++;
            }
        }
    }
    Image a(qstrname.toStdString(),qstrpath.toStdString(),_labels);
    li.push_front(a);
    delete []_labels;
}

void MainWindow::on_save_clicked()
{

    ofstream fs ("jordy.txt",ios::binary);
    linked_list<Image>::iterator it;

    it=li.begin();
    Image im;
    string str;
    int _y=0;
    while( it!=li.end() ){
        im=*it;
        str=im.date_path();
        _y=str.size();
        fs.write( (char *) &_y, sizeof( int ) ); //tamaño del string
        fs.write(str.c_str(),_y);

        str=im.date_name();
        _y=str.size();
        fs.write( (char *) &_y, sizeof( int ) );
        fs.write(str.c_str(),_y);

        int i=0;
        while(im.date_label()[i] != "\0"){
            i++;
        }
        fs.write( (char *) &_y, sizeof( int ) ); //total de labels a leer
        i=0;
        while( im.date_label()[i] != "\0" ){
            str=im.date_label()[i];
            _y=str.size();
            fs.write( (char *) &_y, sizeof( int ) ); //tamaño del string
            fs.write(str.c_str(),_y);
            i++;
        }
        ++it;
    }
    fs.close();


}

void MainWindow::on_Delete_clicked()
{
    Image a;
    linked_list<Image>::node aux(a,NULL,NULL);

}


void MainWindow::on_Reserva_clicked()
{
    DIR * direct;
    string dir="C:\Reserva";
    if(direct=opendir(dir.c_str())){
        closedir(direct); //encontro
    }
    else{
        string direccion_total="C:\Reserva";
        if( mkdir(direccion_total.c_str())==0 )qDebug()<<"\nCreada con exito";
        else qDebug()<<"\nHa ocurrido un error";

    }                      //no encontro
    FILE * archivo;
    string cadena,direccion_total,destino="C:\Reserva";

    ifstream fs("jordy.txt",ios::binary);
        int _y;
        fs.read( (char *) & _y, sizeof( int )); //a terminar el bloc de notas
        char* f0=new char[_y+2]; //el +2 es por el tamaño del string q ocupa y su \0
        fs.read( f0, _y );
        f0[_y]=0;
        direccion_total=f0;
        qDebug()<<QString::fromStdString(direccion_total);
        delete []f0;

    if(archivo=fopen(direccion_total.c_str(), "r")){
        cadena="copy "+ direccion_total + " " + destino;
        system(cadena.c_str());
    }
    else{

    }

}
