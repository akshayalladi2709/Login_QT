#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),
            this,SLOT(button()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button()
{
    QString name[]={"abs","aks","hay"};
    QString pass[]={"asd","sad","dsd"};

    QString uname=ui->lineEdit->text();
    QString upass=ui->lineEdit_2->text();

    bool found= false;

    for(int i=0;i<name->length();i++){
        if(uname == name[i] && upass == pass[i]){
            QMessageBox::information(this,"welcome",
                "User: "+name[i]+"\n"
                                     "u r logged");

            found=true;
            break;
        }
        else if(!found){
            QMessageBox::information(this,"Error","wrong credentials");
        }
    }
}

