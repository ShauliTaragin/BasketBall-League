//
// Created by shaul on 14/06/2022.
//
#include <iostream>
#include <stdexcept>

using namespace std;

namespace taragin{
    class Team{
        double skill;
        string name;
    public:
        Team(double skill , string name):skill(skill) , name(name){
            if(skill>1 || skill<0){
                throw invalid_argument("skill between 0 and 1");
            }
        }
    };
}