#include<bits/stdc++.h>
using namespace std;
#include "hci1.h"
#include <iostream>
#include "gitpp5.h"



class HCI_CREATEREPO : public HCI_ACTION{
public:
  HCI_CREATEREPO() : HCI_ACTION("Create Reprsitory") {}
private:
  void do_it()
  {
    out() << "Creating repository...\n";
    std::string path=".";
    try
    {
      GITPP::REPO r(GITPP::REPO::_create, path.c_str());
      out() << "Repository created.\n (Press escape to go to main menu)";
    }
    catch(GITPP::EXCEPTION const&)
    {
      out() << "Exception error. (Repository may already exist)\n";
    }

  }
};
HCI_CREATEREPO hci_createrepo;

//____________________________________PAGES ______________________________________________//
class LISTCONFIG_PAGE : public HCI_PAGE{
	using HCI_PAGE::HCI_PAGE;
public: // overrides
	void show(){
    GITPP::REPO r;

  	auto c=r.config();

    for(auto i : r.config()){
      std::cout << i.name() << "  ==  " << i.value() << "\n";
    }
	}
};


class COMMITLIST_PAGE : public HCI_PAGE{
	using HCI_PAGE::HCI_PAGE;
public: // overrides
	void show()
  {

    std::string path=".";
  	GITPP::REPO r(path.c_str());
    int a = 0;


    for(GITPP::BRANCH i : r.branches())
    {
      std::cout << a << " "<< i <<"\n" ;
      a = a + 1;
    }
    if(a>1)
    {
      string array[a];
      out() << "select a branch to display commits\n";
      a =0 ;
      for(GITPP::BRANCH i : r.branches())
      {
        std::cout << a << " "<< i <<"\n" ;
        a = a + 1;
      }
      // r.checkout("new_branch");
      // r.checkout("master");
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
      int countCommits = 0;

      for(auto i : r.commits())
      {
        countCommits = countCommits + 1;
      }

      if(countCommits==0)
      {
        out() << "Not Commits to display!\n";
      }
      else
      {
        out() << "Listing Commits...\n";
        int j = 0;

        for(auto i : r.commits())
        {
          if(j<10)
          {
            std::cout << (j+1)<<". <" << i <<"> <"<< i.signature().name() << "> <" << i.message() << "\n";
            j = j + 1;
          }
          else
          {
            break;
          }
        }
      }
    }
  }
};


class CONFIRREPO_PAGE : public HCI_PAGE{
	using HCI_PAGE::HCI_PAGE;
public: // overrides
	void show()
  {
    GITPP::REPO r;

    auto c=r.config();
    char letter='a';
    int a = 0;

    char setting[30][30] = {"user.email", "user.name", "core.bare",
    "user.stuff", "core.logallrefupdates", "core.repositoryformatversion",
    "user.email", "core.filemode", "user.name"};
    for(auto i : r.config())
    {
      std::cout <<letter << ". " << i.name() << " ==  " << i.value()<<"\n";
      letter=letter+1;
    }

    int n=getkey();
    std::cout << "Enter new variable: \n";
    string newVariable;
    std::getline (std::cin, newVariable);

    int x = 97;
    for(auto i : r.config())
    {
      if(n == x)
      {
        c[i.name()] = newVariable;
      }
      x=x+1;
    }

    }
};

//---------------------------------MENUS ------------------------------------
class NOGIT_MENU : public HCI_MENU
{
  public:
    explicit NOGIT_MENU(HCI_APPLICATION& ctx)
    : HCI_MENU(ctx, "nogit"){
      add('y', &hci_createrepo);
      add('n', &hci_quit);
      add(0x1b, &hci_esc);

    }
  public:
  void show(){
   out() << "********  NO GIT MENU  ********\n\n";
   HCI_MENU::show();
  }
  void enter(){
   while(true){
     try{
       HCI_MENU::enter();
       break;
     }catch( HCI_UP const&){
       continue;
     }
   }
  }
};



class HELLO_MENU : public HCI_MENU
{
  public:
	   explicit HELLO_MENU(HCI_APPLICATION& ctx)
  	    : HCI_MENU(ctx, "hello"), _page("list config"), _page1("list commits"), _page2("configure repository"){
        add('c', &_page);
        add('e', &_page2);
        add('l', &_page1);
        add(0x1b, &hci_esc);
        add('q', &hci_quit);
	     }


     public:
  	void show(){
  		out() << "Your git repository \n\n";
  		HCI_MENU::show();
  	}
  	void enter(){
  		while(true){
  			try{
  				HCI_MENU::enter();
  				break;
  			}catch( HCI_UP const&){
  				continue;
  			}
  		}
  	}
  private:
  	LISTCONFIG_PAGE _page;
    COMMITLIST_PAGE _page1;
    CONFIRREPO_PAGE _page2;
};


//---------------------------------------------------MAIN APPLICATION ---------------------------------------------------------------------------
class MAIN: public HCI_APPLICATION{
public:
	MAIN() : HCI_APPLICATION(), _main_menu(*this), _no_git_menu(*this) {
	}
public:
	void show(){
    std::string path=".";
    try
    {
      GITPP::REPO r(path.c_str());

      try
      {
        _main_menu.enter();
      }
      catch(HCI_ESCAPE const&)
      {
        // Escape pressed, exiting application
      }
    }

    catch(GITPP::EXCEPTION_CANT_FIND const&)
    {


      try
      {
        _no_git_menu.enter();
      }
      catch(HCI_ESCAPE const&)
      {
        try
        {
          GITPP::REPO r(path.c_str());
          _main_menu.enter();
        }
        catch(GITPP::EXCEPTION_CANT_FIND const&)
        {
          show();
        }
      }
    }
}
private:
	HELLO_MENU _main_menu;
  NOGIT_MENU _no_git_menu;

};

// the program starts here.
int main(int argc, char const *argv[])
{


  MAIN main;
  return main.exec();


}
