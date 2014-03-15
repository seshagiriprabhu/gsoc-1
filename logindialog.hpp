#ifndef LOGINDIALOG_HPP
#define LOGINDIALOG_HPP

#include <QDialog>
#include <QStackedWidget>
#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>

class LoginDialog : public QDialog
{
    Q_OBJECT

private:
    QWidget *loginPageWidget;
    QWidget *registerPageWidget;
    QFrame *frame;
    QStackedWidget *stackedWidget;
    QPushButton *existingUser;
    QPushButton *newUser;

private slots:
    void on_sideLoginBtn_clicked(bool checked);
    void on_sideRegBtn_clicked(bool checked);
    void on_loginBtn_clicked();
    void on_regBtn_clicked();

public:
    LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
};

#endif // LOGINDIALOG_HPP
