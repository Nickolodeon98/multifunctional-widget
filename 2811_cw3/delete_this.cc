class GIT_LCONFIG : public HCI_PAGE{ //prints out info
    using HCI_PAGE::HCI_PAGE;
public: // overrides
    void show(){
        GITPP::REPO r;

        std::cout << "List Configuration\n\n";

        for(auto i : r.config()){
            if (i.name() != "remote.origin.fetch" && i.name() != "user.stuff"){
                std::cout << i.name() << ": " << i.value() << "\n";
            }
        }
        std::cout << "\n";
    }
};

class GIT_CONFIG : public HCI_PAGE{ //gets new info
    using HCI_PAGE::HCI_PAGE;
public: // overrides
    char newName[20], newEmail[30];

    void show(){
        GITPP::REPO r;

        std::cout << "Configure Repository\n\n";

        std::cout << "Name: ";
        std::cin.getline(newName, 20);
        r.config()["user.name"] = newName;																			//collect username with this

        std::cout << "Email: ";
        std::cin.getline(newEmail, 30);
        r.config()["user.email"] = newEmail;																		//collect email with this

        std::cout << "\n";
    }
};
