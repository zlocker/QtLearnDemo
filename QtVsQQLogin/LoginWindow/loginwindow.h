#ifndef LoginWindow_H
#define LoginWindow_H

#include "basewindow.h"

namespace Ui {
	class LoginWindow;
}

// ��¼״̬;
typedef enum
{
	ONLINE = 1,     //����;
	ACTIVE,			//��Ծ;
	AWAY,           //�뿪;
	BUSY,           //æµ;
	NOT_DISTURB,	//�������;	
	HIDE,           //����;
	OFFLINE			//����;
}LoginState;

class LoginWindow : public BaseWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private:
    void initMyTitle() ;
	void initWindow();

private:
	Ui::LoginWindow *ui;
	// �����С���̰�ť;
	QPushButton* m_keyboardButton;

};

#endif // LoginWindow_H
