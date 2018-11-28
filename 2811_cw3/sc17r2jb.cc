#include "globals.h"

#include <QLabel>

namespace{

class HelloWorldLabel : public QLabel{
public:
	HelloWorldLabel() : QLabel(){
		setText("hi hi hi");
	}
};

INSTALL_TAB(HelloWorldLabel, "Ryan's Tab");

}
