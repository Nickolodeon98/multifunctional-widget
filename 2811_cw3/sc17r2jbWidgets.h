#include <QLabel>
#include <iostream>
#include <QGridLayout>
#include <QtWidgets>
#include <QLineEdit>

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
