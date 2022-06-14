//
// Created by shaul on 14/06/2022.
//
#pragma once
#include <iostream>
#include <stdexcept>
#include <utility>

using namespace std;

namespace taragin{
    class Team{
    public:
        double skill;
        string name;
        int games_played;
        int wins;
        int losses;
        int points_for;
        int points_against;
        int longest_winning_streak;
        int longest_losing_streak;
        Team(double skill , string name):skill(skill) , name(std::move(name)),games_played(0)
        ,wins(0) , losses(0),points_for(0),points_against(0),longest_losing_streak(0),longest_winning_streak(0){
            if(skill>1 || skill<0){
                throw invalid_argument("skill between 0 and 1");
            }

        }
        bool operator==(const Team* a) const{
            return a->name == this->name;
        }
    };
}