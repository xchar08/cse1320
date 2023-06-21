#include "Monster.hpp"

#include <fstream>
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_menu(){
    cout << "\n1. Add Monster\n";
    cout << "2. Load Monsters from CSV\n";
    cout << "3. Begin Combat\n";
    cout << "4. Exit\n> ";
}

int main(){
    int selection = 0;
    std::unordered_map<std::string, Monster> monster_list;
    Monster m;
    while (selection != -1) {
            print_menu();
            cin >> selection;
        switch (selection){
            case 1: {
                cout << "Enter a name: ";
                cin >> m.name();
                cout << "Enter a type: ";
                cin >> m.mtype();
                cout << "Enter a hp: ";
                cin >> m.hp();
                cout << "Enter an ac: ";
                cin >> m.ac();
                cout << "Enter a strength: ";
                cin >> m.strength();
                cout << "Enter a dexterity: ";
                cin >> m.dexterity();
                cout << "Enter a constitution: ";
                cin >> m.constitution();
                monster_list.emplace(m.name(),m);    
                break; 
            }
            case 2: {
                string fname;
                string line;
                Monster mons;
                cout << "Enter a file path: " << endl;
                cin >> fname;
                ifstream mcsv(fname);
                if(mcsv.is_open()){
                    
                    cout << "File is open!" << endl;
                    getline(mcsv, line);
                    while(getline(mcsv, line)){
                        mons.loadFromCSV(line);
                        //cout << mons.name() << "=>" << mons;
                        monster_list.emplace(mons.name(), mons);
                        
                    }   
                    cout << "Loaded!" << endl;
                }else{
                    cout << "Could not open file!" << endl;
                }
                mcsv.close();
                break;
            }           
            case 3:{
                //grabbing monsters
                string m1;
                string m2;
                cout << "Enter a monster name: ";
                cin >> m1;

                while(monster_list.count(m1) <= 0){
                    cin >> m1;
                }

                cout << "Enter a monster name: ";
                cin >> m2;

                while(monster_list.count(m2) <= 0){
                    cin >> m2;
                }

                cout << "Monsters Selected!" << endl;
                //cout << monster_list.at(m1).hp() << "<=>" << monster_list.at(m2).hp() << endl;
                //combat (damage)
                while(monster_list.at(m1).hp()>0 && monster_list.at(m2).hp()>0){
                    if(monster_list.at(m2).hp()>0){
                        if(monster_list.at(m1).hp()>0){
                            monster_list.at(m1).attack(monster_list.at(m2));
                            //cout << monster_list.at(m1).hp() << "<=>" << monster_list.at(m2).hp() << endl;
                        }  
                    }
                    if(monster_list.at(m1).hp()>0){
                        if(monster_list.at(m2).hp()>0){
                           monster_list.at(m2).attack(monster_list.at(m1));
                           //cout << monster_list.at(m1).hp() << "<=>" << monster_list.at(m2).hp() << endl;
                        }  
                    }
                }
                //Winner statement
                if(monster_list.at(m1).hp()>0){
                    cout << "Monster 1 Wins!";
                }else if(monster_list.at(m2).hp()>0){
                    cout << "Monster 2 Wins!";
                }  
                //breaks if it doesn't find anything   
            }
            case 4:
                break;
            default:
                selection = -1;
                break;
        }
    }
}