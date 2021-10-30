#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QtCore>

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
int i,j;
for (i=0; i<=2;i++)
{
    if (userName==Names[i]){
        NameFound=true;
        break;}
    else {
        NameFound=false;
    }
}
for (j=0; j<=3;j++)
{
    if (userPassword.toInt()==Passwords[j] && i==j){
        Passwordfound=true;
        user = j;
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
    signin = LogIn (userName, userPassword);

    if (signin==true)
        ui->Label_LogIn_Message->setText("Signed in Successfully.");
        else {
        if (NameFound==true && Passwordfound==false)
            ui->Label_LogIn_Message->setText("Name is corrcet but password is wrong.");
        else if (NameFound == false)
            ui->Label_LogIn_Message->setText("Name does not exist.");

    }
}

//bool MainWindow::isNumber(QString& str)
//{
//if (str> ":" || str < "~" || str > " " || str < "/")
//    return false;
//            else
//                return true;

//}

void MainWindow::on_pushButton_balance_clicked()
{
    if (signin==false)
        ui->lineEdit_balance->setText("Sign in first to procced.");
   else {
        ui->Label_ID_Reveal->setText(IDs[user]);
        //ui->Label_Balance_Reveal->setText(QString::number(Acc_Balance[user]));
        userBalance = ui->lineEdit_balance->text();
        Acc_Balance [user] = userBalance.toInt();

        if (userBalance.toInt()>0){

            ui->Label_Balance_Reveal->setText(userBalance);
            ui->lineEdit_balance->setText("");
           }

        else{
            ui->Label_Balance_Reveal->setText("Please Enter Positve Numbers Only.");
}

}}


void MainWindow::on_pushButton_buy_clicked()
{
    if (signin==false){
        ui->label_price->setText("Sign in first to procced.");}
    else {
        if (Acc_Balance [user]<BookPrice[BookIndex])
         ui->label_price->setText("Please Recharge Your Balance First.");
    else {

            Acc_Balance[user] -= BookPrice[BookIndex];
            ui->label_price->setText("Book Purchased.");
            ui->Label_Balance_Reveal->setText(QString::number(Acc_Balance[user]));

        }


    }



}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->comboBox->currentText();
    BookIndex = ui->comboBox->currentIndex();
    ui->label_price->setText(QString::number(BookPrice[BookIndex]));
}


void MainWindow::on_pushButton_clicked()
{
   if(signin == true)  {
    NameFound = false;
    Passwordfound = false;
    signin =false;
    ui->Label_LogIn_Message->setText("Signed out Successfully.");
   }
    else
       ui->Label_LogIn_Message->setText("You are already Signed out.");

}

