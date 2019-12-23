#include "LoginWindow.h"
#include "ui_LoginWindow.h"
#include <QPainter>
#include <QMovie>
#include <QHBoxLayout>
#include <QCursor>

LoginWindow::LoginWindow(QWidget *parent)
	: BaseWindow(parent)
	, ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
	initWindow();
	initMyTitle();
	this->loadStyleSheet(":/Resources/LoginWindow/LoginWindow.css");
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::initMyTitle()
{
	// ��Ϊ�����пؼ�����ˣ�����Ҫע��ؼ�raise()�����ĵ���˳��;
	m_titleBar->move(0, 0);
	m_titleBar->raise();
	m_titleBar->setBackgroundColor(0, 0, 0 , true);
	m_titleBar->setButtonType(MIN_BUTTON);
	m_titleBar->setTitleWidth(this->width());

	ui->pButtonArrow->raise();
}

void LoginWindow::initWindow()
{
	//����GIGͼ;
	QLabel* pBack = new QLabel(this);
	QMovie *movie = new QMovie();
	movie->setFileName(":/Resources/LoginWindow/back.gif");
	movie->start();
	movie->stop();
	pBack->setMovie(movie);
	movie->start();
	pBack->move(0, 0);

	//��ע��;
	ui->accountComboBox->setEditable(true);
	QLineEdit* lineEdit = ui->accountComboBox->lineEdit();
	lineEdit->setPlaceholderText(QStringLiteral("QQ����/�ֻ�/����"));

	ui->passwordEdit->setPlaceholderText(QStringLiteral("����"));

	// ������е�С���̰�ť;
	m_keyboardButton = new QPushButton();
	m_keyboardButton->setObjectName("pButtonKeyboard");
	m_keyboardButton->setFixedSize(QSize(16, 16));
	m_keyboardButton->setCursor(QCursor(Qt::PointingHandCursor));

	QHBoxLayout* passwordEditLayout = new QHBoxLayout();
	passwordEditLayout->addStretch();
	passwordEditLayout->addWidget(m_keyboardButton);
	passwordEditLayout->setSpacing(0);
	passwordEditLayout->setContentsMargins(0, 0, 8, 0);

	ui->passwordEdit->setLayout(passwordEditLayout);
	ui->passwordEdit->setTextMargins(0, 0, m_keyboardButton->width() + 12, 0);

	ui->userHead->setPixmap(QPixmap(":/Resources/LoginWindow/HeadImage.png"));
	ui->loginState->setIcon(QIcon(":/Resources/LoginWindow/LoginState/state_online.png"));
	ui->loginState->setIconSize(QSize(13, 13));
}