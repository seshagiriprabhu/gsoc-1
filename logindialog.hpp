#ifndef LOGINDIALOG_HPP
#define LOGINDIALOG_HPP

#include <QDialog>
#include <QStackedWidget>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>

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
    QPushButton *registerButton;
    QPushButton *loginButton;
    QComboBox *userNameCombo;
    QLineEdit *password;
    QLineEdit *regUserName;
    QLineEdit *regPassword;
    QLabel *loginHint;
    QLabel *registerHint;

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
