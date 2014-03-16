#include "logindialog.hpp"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QWidget>
#include <QLine>
#include <QPalette>
#include <QDebug>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
{
    loginPageWidget = new QWidget;
    registerPageWidget = new QWidget;

    QString pageButtonCSS =
                "QPushButton {"
                "margin: 1px;"
                "border-color: #6BC260;"
                "border-style: outset;"
                "border-radius: 3px;"
                "font-size: 11px;"
                "border-width: 0.2px;"
                "color: white;"
                "font-weight: bold;"
                "background-color: #6BC260;"
                "}"
                "QPushButton:hover {"
                "background-color: #0BC260;"
                "}";

    QString sideLayoutButtonCSS =
            "QPushButton {"
            "border-image:url(:/icons/arrowuc.png);"
            "color: #7B7C7F;"
            "padding-right: 20%;"
            "font-weight: bold;"
            "font-size: 11px;"
            "}"
            "QPushButton:checked {"
            "color: #FFF;"
            "border-image: url(:/icons/arrow.png);"
            "}";
    QString hintCSS =
            "QLabel {"
            "color: red"
            "}";

    QVBoxLayout *loginPageLayout = new QVBoxLayout();
    QLabel *userNameLabel = new QLabel(tr("&Nickname"));
    userNameCombo = new QComboBox(this);
    userNameCombo->setMaximumHeight(20);
    userNameCombo->setFixedHeight(30);
    userNameCombo->setMaximumWidth(190);
    userNameCombo->setFixedWidth(200);
    userNameLabel->setBuddy(userNameCombo);

    QLabel *passwordLabel = new QLabel(tr("&Password"));
    password = new QLineEdit(this);
    password->setMaximumHeight(20);
    password->setFixedHeight(30);
    password->setMaximumWidth(190);
    password->setFixedWidth(200);
    password->setEchoMode(QLineEdit::Password);
    passwordLabel->setBuddy(password);

    QVBoxLayout *loginBtnSpacerLayout = new QVBoxLayout();
    loginBtnSpacerLayout->addSpacerItem(new QSpacerItem(1, 30));

    QHBoxLayout *loginBtnLayout = new QHBoxLayout();
    loginButton = new QPushButton(tr("&Login"), this);
    loginButton->setMaximumHeight(30);
    loginButton->setFixedHeight(30);
    loginButton->setMaximumWidth(80);
    loginButton->setFixedWidth(80);
    loginButton->setCursor(Qt::PointingHandCursor);
    loginButton->setStyleSheet(pageButtonCSS);
    loginBtnLayout->addSpacerItem(new QSpacerItem(120,1));
    loginBtnLayout->addWidget(loginButton);

    loginHint = new QLabel;
    loginHint->setAlignment(Qt::AlignHCenter);
    loginHint->setStyleSheet(hintCSS);

    loginPageLayout->addWidget(userNameLabel);
    loginPageLayout->addWidget(userNameCombo);
    loginPageLayout->addSpacerItem(new QSpacerItem(1, 20));
    loginPageLayout->addWidget(passwordLabel);
    loginPageLayout->addWidget(password);
    loginPageLayout->addLayout(loginBtnSpacerLayout);
    loginPageLayout->addWidget(loginHint);
    loginPageLayout->addLayout(loginBtnLayout);
    loginPageLayout->setContentsMargins(-10,0,0,0);
    loginPageLayout->setAlignment(Qt::AlignCenter);
    loginPageWidget->setLayout(loginPageLayout);

    QVBoxLayout *registerPageLayout = new QVBoxLayout();
    QLabel *regUserNameLabel = new QLabel(tr("Create &Nickname"));
    regUserName = new QLineEdit(this);
    regUserName->setMaximumHeight(20);
    regUserName->setFixedHeight(30);
    regUserName->setMaximumWidth(190);
    regUserName->setFixedWidth(200);
    regUserNameLabel->setBuddy(regUserName);

    QLabel *regPasswordLabel = new QLabel(tr("Create &Password"));
    regPassword = new QLineEdit(this);
    regPassword->setMaximumHeight(20);
    regPassword->setFixedHeight(30);
    regPassword->setMaximumWidth(190);
    regPassword->setFixedWidth(200);
    regPassword->setEchoMode(QLineEdit::Password);
    regPasswordLabel->setBuddy(regPassword);

    QVBoxLayout *regBtnSpacerLayout = new QVBoxLayout();
    regBtnSpacerLayout->addSpacerItem(new QSpacerItem(1, 30));

    QHBoxLayout *regBtnLayout = new QHBoxLayout();
    registerButton = new QPushButton(tr("&Create Account"), this);
    registerButton->setMaximumHeight(30);
    registerButton->setFixedHeight(30);
    registerButton->setMaximumWidth(100);
    registerButton->setFixedWidth(120);
    registerButton->setCursor(Qt::PointingHandCursor);
    registerButton->setStyleSheet(pageButtonCSS);

    regBtnLayout->addSpacerItem(new QSpacerItem(80, 1));
    regBtnLayout->addWidget(registerButton);

    registerHint = new QLabel;
    registerHint->setStyleSheet(hintCSS);
    registerHint->setAlignment(Qt::AlignHCenter);

    registerPageLayout->addWidget(regUserNameLabel);
    registerPageLayout->addWidget(regUserName);
    registerPageLayout->addSpacerItem(new QSpacerItem(1, 20));
    registerPageLayout->addWidget(regPasswordLabel);
    registerPageLayout->addWidget(regPassword);
    registerPageLayout->addLayout(regBtnSpacerLayout);
    registerPageLayout->addWidget(registerHint);
    registerPageLayout->addLayout(regBtnLayout);
    registerPageLayout->setContentsMargins(-10,0,0,0);
    registerPageLayout->setAlignment(Qt::AlignCenter);
    registerPageWidget->setLayout(registerPageLayout);


    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(registerPageWidget);
    stackedWidget->addWidget(loginPageWidget);
    stackedWidget->setContentsMargins(0,0,30,0);

    QLabel *toxLogo = new QLabel(this);
    toxLogo->setPixmap(QPixmap(":/icons/toxlogo.png"));

    QWidget *horizontalLineWidget = new QWidget();
    horizontalLineWidget->setFixedHeight(1);
    horizontalLineWidget->setMaximumWidth(160);
    horizontalLineWidget->setFixedWidth(165);
    horizontalLineWidget->setStyleSheet(QString("background-color:#4B4C4F;"));

    existingUser = new QPushButton(tr("Existing User"), this);
    existingUser->setMinimumHeight(25);
    existingUser->isCheckable();
    existingUser->setCheckable(true);
    existingUser->setCursor(Qt::PointingHandCursor);

    existingUser->setStyleSheet(sideLayoutButtonCSS);
    newUser = new QPushButton(tr("New User"), this);
    newUser->setMinimumHeight(25);
    newUser->isCheckable();
    newUser->setCheckable(true);
    newUser->setCursor(Qt::PointingHandCursor);
    newUser->setStyleSheet(sideLayoutButtonCSS);

    existingUser->setAutoExclusive(true);
    newUser->setAutoExclusive(true);

    connect(existingUser, &QPushButton::toggled, this, &LoginDialog::on_sideLoginBtn_clicked);
    connect(newUser, &QPushButton::toggled, this, &LoginDialog::on_sideRegBtn_clicked);
    connect(loginButton, &QPushButton::clicked, this, &LoginDialog::on_loginBtn_clicked);
    connect(registerButton, &QPushButton::clicked, this, &LoginDialog::on_regBtn_clicked);

    QVBoxLayout *sideLayout = new QVBoxLayout();
    sideLayout->addWidget(toxLogo);
    sideLayout->addWidget(existingUser);
    sideLayout->addWidget(horizontalLineWidget);
    sideLayout->addWidget(newUser);

    frame = new QFrame();
    frame->setMinimumHeight(250);
    frame->setMinimumWidth(200);
    frame->setStyleSheet("QFrame{border-image:url(:/icons/arrowuc.png);}");
    frame->setAutoFillBackground(true);
    frame->setContentsMargins(0,0,0,0);
    frame->setLayout(sideLayout);

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(frame);
    mainLayout->addWidget(stackedWidget);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    existingUser->setChecked(true);
    this->setLayout(mainLayout);
    setWindowIcon(QIcon(":/icons/icon64.png"));
    setWindowTitle("Tox Login");
}

LoginDialog::~LoginDialog()
{

}

void LoginDialog::on_sideLoginBtn_clicked(bool checked)
{
    if (checked == true) {
        stackedWidget->setCurrentWidget(loginPageWidget);
    }
}

void LoginDialog::on_sideRegBtn_clicked(bool checked)
{
    if (checked == true) {
        stackedWidget->setCurrentWidget(registerPageWidget);
    }
}

void LoginDialog::on_loginBtn_clicked()
{
    if (password->text().isEmpty()) {
        loginHint->setText(tr("Empty Password"));
    } else {
        loginHint->setText(tr(""));
    }

    // call the login validation function
}

void LoginDialog::on_regBtn_clicked()
{
    if (regPassword->text().isEmpty()) {
        registerHint->setText(tr("Empty Password"));
    } else if (regUserName->text().isEmpty()) {
        registerHint->setText(tr("Empty Password"));
    } else {
        registerHint->setText(tr(""));
    }
    // call the registration function
}
