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
    void login_layout(bool checked);
    void register_layout(bool checked);

public:
    LoginDialog(QWidget *parent = 0);
    ~LoginDialog();
};

#endif // LOGINDIALOG_HPP
