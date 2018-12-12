#include <QLabel>
#include <iostream>
#include <QGridLayout>
#include <QtWidgets>
#include <QLineEdit>
#include <QObject>

#ifndef CoreLayout
#define CoreLayout

class NameButton: public QPushButton{
	Q_OBJECT
  public:
    NameButton();
  private:
	  QPushButton *nameButton;
};
#endif
