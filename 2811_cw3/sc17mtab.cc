#include "globals.h"

#include <QLabel>
#include <string>
#include <iostream>
#include <string>

#include "gitpp.h"
#include <QGridLayout>
#include <QtWidgets>
#include <QLineEdit>

namespace listCommits{

class HelloWorldLabel : public QLabel{
public:
	HelloWorldLabel() : QLabel(){
    std::string path=".";
  	GITPP::REPO r(path.c_str());

    int a = 0;
    for(GITPP::BRANCH i : r.branches())
    {
      a = a + 1;
    }

    QGridLayout* layout = new QGridLayout();
    QLabel *labels[a];
    QLineEdit *lineEdits[a];
    QLabel *branchInfo[a];

    if(a>1)
    {
      int count = 0;

      for(auto i : r.branches())
      {
        labels[count] = new QLabel(tr("%1:").arg(count + 1));
        branchInfo[count] = new QLabel("QUACK QUACK");              //CHANGE TO BE POPUALTED BY BRANCH NAME

        layout->addWidget(labels[count], count + 1, 0);
        layout->addWidget(branchInfo[count], count + 1, 1);

        count = count + 1;
      }

      QLineEdit* textField=new QLineEdit();
  		textField->setFont(QFont("Typewriter", 15));
  		textField->setPlaceholderText("Select Branch Name...");

      layout->addWidget(textField, count+1, 0);
      // std::string str = std::to_string(a);
      // QLabel* label = new QLabel("str");
      // layout->addWidget(label,a,0);
      // ) << "select a branch to display commits\n";


      // a = 0;
      // for(GITPP::BRANCH i : r.branches())
      // {
      //   std::cout << a << " "<< i <<"\n" ;
      //   a = a + 1;
      // }

      // r.checkout("new_branch");
      // r.checkout("master");

      int j = 0;
      for(auto i : r.commits())
      {
        if(j<10)
        {
          labels[j] = new QLabel(tr("%1:").arg(j + 1));
          lineEdits[j] = new QLineEdit;
          layout->addWidget(labels[j], j + 1, 0);
          layout->addWidget(lineEdits[j], j + 1, 1);
          // QLabel* label = new QLabel("str");
          // std::cout << (j+1)<<". <" << i <<"> <"<< i.signature().name() << "> <" << i.message() << "\n";
          j = j + 1;
        }
        else
        {
          break;
        }
      }
    }
    else
    {
      int countCommits = 0;
      for(auto i : r.commits())
      {
        countCommits = countCommits + 1;
      }

      if(countCommits==0)
      {
        labels[0] = new QLabel("Not Commits to display!");
        labels[1] = new QLabel("Add commits to display!");

        layout->addWidget(labels[0], 0, 0);
        layout->addWidget(labels[1], 1, 0);


      }
      else
      {
        int j = 0;
        for(auto i : r.commits())
        {
          if(j<10)
          {
            labels[j] = new QLabel(tr("%1:").arg(j + 1));
            lineEdits[j] = new QLineEdit;
            layout->addWidget(labels[j], j + 1, 0);
            layout->addWidget(lineEdits[j], j + 1, 1);
            // QLabel* label = new QLabel("str");
            // std::cout << (j+1)<<". <" << i <<"> <"<< i.signature().name() << "> <" << i.message() << "\n";
            j = j + 1;
          }
          else
          {
            break;
          }
        }
      }
    }
		setLayout(layout);
	}
};

INSTALL_TAB(HelloWorldLabel, __FILE__);

}
