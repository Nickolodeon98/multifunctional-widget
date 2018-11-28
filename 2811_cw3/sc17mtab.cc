#include "globals.h"

#include <QLabel>

namespace{

class HelloWorldLabel : public QLabel{
public:
	HelloWorldLabel() : QLabel(){
		setText("New Tab");
	}
};

INSTALL_TAB(HelloWorldLabel, "List");

}
