#include "globals.h"
#include<bits/stdc++.h>
using namespace std;
//#include "hci1.h"
#include <string>
#include <iostream>
#include "gitpp.h"
#include <QLabel>
#include <QHBoxLayout>
#include <QtWidgets>
#include <QLineEdit>

namespace listCommit{

class HelloWorldLabel : public QLabel{
public:
	HelloWorldLabel() : QLabel(){
    QString str = listCommit->lineEdit->text();
    std::string path=".";
  	GITPP::REPO r(path.c_str());
    QHBoxLayout* h=new QHBoxLayout;
    int a = 0;


    for(auto i : r.branches())
    {
      // h->addWidget(new QLabel(i.name());
      a = a + 1;
    }

    if(a>1)
    {
      //string array[a];
      h->addWidget(new QLabel("select a branch to display commits\n"));

      a =0 ;
      for(auto i : r.branches())
      {
        std::cout << a << " "<< i <<"\n" ;
        a = a + 1;
      }
      //r.checkout("new_branch");
      //r.checkout("master");
      for(auto i : r.commits())
      {
        // std::cout << i.branch().name() << "\n";
        // if(i==array[ch])
        // {
        // }
      }
    }
    else
    {
      QLineEdit* textField=new QLineEdit();
      textField->setFont(QFont("TypeWriter", 25));

      // some grey default text
      textField->setPlaceholderText("some text");
      // textField->setReadOnly(false);
      textField->show();
      int countCommits = 0;

      for(auto i : r.commits())
      {
        countCommits = countCommits + 1;
      }



      if(countCommits==0)
      {
        h->addWidget(new QLabel("No Commits to display!\n"));
      }
      else
      {
        h->addWidget(new QLabel("Listing Commits...\n"));
        int j = 0;

        // tableWidget = new QTableWidget(this);
        // tableWidget->setRowCount(countCommits);
        // tableWidget->setColumnCount(3);

        for(auto i : r.commits())
        {
           if(j<10 && j<countCommits)
          {
            // QTableWidgetItem *newItem = new QTableWidgetItem(tr("%1").arg((row+1)*(column+1)));
            // tableWidget->setItem(row, column, newItem);

            std::string str = (std::to_string(j+1) + ". <" +"> <" + i.signature().name() +  "> <" + i.message() + "\n");
            QString qstr = QString::fromStdString(str);
            h->addWidget(new QLabel(qstr));
            j = j + 1;
          }
          else
          {
            break;
          }
        }
      }
    }


    setLayout(h);
	}
};

INSTALL_TAB(HelloWorldLabel, "Matt's");

}
