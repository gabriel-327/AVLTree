#include <iostream>
#include <sstream>
#include "AVL.h"
using namespace std;

int main(){
    //insert "Adam" 12345678
    // printInorder
    // get entire line

    int num_ops;
    cin >> num_ops;
    string blank_space;
    getline(cin, blank_space);
    AVLTree tree;
    while(num_ops --){
        // Code from Jackie and Neil project breakdown video
        string line;
        getline(cin, line);

        istringstream inStream(line);

        // get command
        string command;
        getline(inStream, command, ' ');

        string next;
        string next2;


        if (command == "insert"){
            getline(inStream, next, '"');
            string name;
            getline(inStream, name, '"');
            getline(inStream, next2, ' ');


            if(!check_name(name)){
                cout << "unsuccessful" << endl;
                continue;  // is it break or continue
            }


            string number;
            getline(inStream, number);


            if(!check_number(number)){
                cout << "unsuccessful" << endl;
                continue;
            }

            if(number == ""){
                cout << "unsuccessful" << endl;
                continue;
            }
            // have insert return bool if it worked or did not work
            tree.insert(name, number);
            if(tree.getinsertworked()) {
                cout << "successful" << endl;
            }
            else{
                cout << "unsuccessful" << endl;
            }
        }
        else if(command == "remove"){
            string number;
            getline(inStream, number);


            if(!check_number(number)){
                cout << "unsuccessful" << endl;
                continue;
            }
            if(tree.remove(number)){
            cout << "successful" << endl;
                }
            else {
                cout << "unsuccessful" << endl;
            }

        }
        else if(command == "printInorder"){
            tree.inorder();
        }
        else if(command == "printPreorder"){
            tree.preorder();
        }
        else if(command == "printPostorder"){
            tree.postorder();
        }
        else if(command == "search"){
            string number;
            getline(inStream, number);
            if(check_number(number)){
                cout << tree.searchID(number) << endl;
                //find ID code
                continue;
            }
            string name = number;
            if(name[0] != '"'){
                cout << "unsuccessful" << endl;
                continue;
            }
            if(name[name.size()-1] != '"'){
                cout << "unsuccessful" << endl;
                continue;
            }
            name = name.substr(1, name.size() -2);
            if(check_name(name)) {
                tree.searchName(name);
                // find name code
                continue;
            }

            cout << "unsuccessful" << endl;

        }
        else if(command == "printLevelCount"){
            cout << tree.getLevelCount() << endl;
        }
        else if(command == "removeInorder"){
            string number;
            getline(inStream, number);
            bool should_continue =false;
            for(int i = 0; i < number.size(); i++){
                if(!isdigit(number[i])){
                    cout << "unsuccessful" << endl;
                    should_continue = true;
                    break;
                }
            }
            if(should_continue){
                continue;
            }
            if(tree.removeInorder(stoi(number))){
                cout << "successful" << endl;
            }
            else{
                cout << "unsuccessful" << endl;
            }
        }
        else{
            cout << "unsuccessful" << endl;
        }
    }
    return 0;
}