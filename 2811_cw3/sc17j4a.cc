#include "globals.h"

#include <QLabel>

namespace{

class HelloWorldLabel : public QLabel{
public:
	HelloWorldLabel() : QLabel(){
		setText("Jacks Tab");
	}
};

INSTALL_TAB(HelloWorldLabel, "Jack's Tab");

}
