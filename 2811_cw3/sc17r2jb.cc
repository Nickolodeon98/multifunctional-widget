#include "globals.h"

#include <QLabel>

namespace{

class HelloWorldLabel : public QLabel{
public:
	HelloWorldLabel() : QLabel(){
		setText("Ryans Tab");
	}
};

INSTALL_TAB(HelloWorldLabel, "Ryan's Tab");

}
