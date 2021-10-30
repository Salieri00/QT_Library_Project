#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


bool LogIn(QString userName, QString userPassword); //Function to log in
bool isNumber (QString& str); //Function to check if number

bool NameFound =true;
bool  Passwordfound = true;
bool signin;

private:
    Ui::MainWindow *ui;
    QString userName;
    QString userPassword;
    int user = 0;
    QString Names [3] = {"Ahmed", "Mariam", "Eman"};
    int Passwords [3] = {1,2,3};
    QString IDs[3]= {"100", "101", "102"};
    QString userBalance;
    int Acc_Balance [3] = {0,0,0};
    QString BookName;
    int BookIndex = 0;
    int BookPrice [3] = {450, 390, 500};



private slots:
    void on_pushButton_SignIn_clicked();
    void on_pushButton_balance_clicked();
    void on_pushButton_buy_clicked();
    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
