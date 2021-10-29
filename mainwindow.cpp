#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::LogIn(QString userName, QString userPassword) {

for (int i=0; i<=2;i++)
{
    if (userName==Names[i]){
        NameFound=true;
        break;}
    else {
        NameFound=false;
    }
}
for (int j=0; j<=3;j++)
{
    if (userPassword.toInt()==Passwords[j]){
        Passwordfound=true;
    break;}
    else {
        Passwordfound=false;
    }
}

if (NameFound==true && Passwordfound==true){
return true;
}
else
    return false;

}

void MainWindow::on_pushButton_SignIn_clicked()
{

    userName = ui->Label_Name->text();
    userPassword = ui->Label_Password->text();
    bool signin = LogIn (userName, userPassword);

    if (signin==true)
        ui->Label_LogIn_Message->setText("Signed in Successfully.");
        else {
        if (NameFound==true && Passwordfound==false)
            ui->Label_LogIn_Message->setText("Name is corrcet but password is wrong.");
        else if (NameFound == false)
            ui->Label_LogIn_Message->setText("Name does not exist.");



    }
}

