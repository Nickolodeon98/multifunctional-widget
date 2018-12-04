#include <QLabel>
#include <iostream>
#include <QGridLayout>
#include <QtWidgets>
#include <QLineEdit>

#ifndef CoreLayout
#define CoreLayout

class NameEdit: public QPushButton{
	Q_OBJECT
  public:
    NameEdit();
  private:
	  QPushButton *nameEdit;
};
#endif
