#include "globals.h"

#include <QLabel>

namespace{

class HelloWorldLabel : public QLabel{
public:
	HelloWorldLabel() : QLabel(){
		setText("Seunghwan Tab");
	}
};

INSTALL_TAB(HelloWorldLabel, "Seunghwan's Tab");

}
