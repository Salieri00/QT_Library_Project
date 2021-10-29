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

bool NameFound =true;
        bool  Passwordfound = true;

private:
    Ui::MainWindow *ui;
    QString userName;
    QString userPassword;
    QString Names [3] = {"Ahmed", "Mariam", "Eman"};
    int Passwords [3] = {1,2,3};


private slots:
    void on_pushButton_SignIn_clicked();


};
#endif // MAINWINDOW_H
