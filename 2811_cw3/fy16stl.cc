#include "globals.h"

#include <QLabel>

namespace{

class HelloWorldLabel : public QLabel{
public:
	HelloWorldLabel() : QLabel(){
		setText("Cyrus's Tab");
	}
};

INSTALL_TAB(HelloWorldLabel, "Cyrus's Tab");

}
