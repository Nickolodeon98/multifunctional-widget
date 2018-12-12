#include "globals.h"

#include <QLabel>
#include <QWidget>

namespace{

class HelloWorldLabel : public QLabel{
// public:
// 	HelloWorldLabel() : QLabel(){
// 		setText("Seunghwan Tab");
// 	}
public:
	HelloWorldLabel() : QLabel(){
		QLabel * example = new QLabel("This is a widget example");
		example->show();
	}
};


// class StatisticsWidget : public QLabel{
// public:
// 	StatisticsWidget() : QLabel(){
// 		QLabel * example = new QLabel("This is a widget example");
// 		example->show();
// 	}
// };

INSTALL_TAB(HelloWorldLabel, "Seunghwan's Tab");
// INSTALL_TAB(StatisticsWidget, "Seunghwan's Tab");

}
