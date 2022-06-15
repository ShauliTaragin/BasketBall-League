//
// Created by shaul on 15/06/2022.
//
#include "League.hpp"
#include "unordered_set"
#include <iostream>
using namespace std;

namespace taragin {
    League::League(const unordered_set<Team *> &received_teams) {
        this->num_of_teams = 0;
        if (received_teams.size() > 20) {
            throw invalid_argument("too many teams");
        }
        for (auto team: received_teams) {
            teams.insert(team);
            num_of_teams++;
        }
        while (num_of_teams < 20) {
            teams.insert(new Team{0.6, to_string(num_of_teams)});
        }
        Play_League();
    }

    League::League() {
        this->num_of_teams = 0;
        while (num_of_teams < 20) {
            teams.insert(new Team{0.6, to_string(num_of_teams)});
        }
        Play_League();
    }

    void League:: Play_League() const {
        Schedule schedule(this->teams);
    }

    vector<string> League:: leaders(size_t num_of_leaders) {
        if(num_of_leaders>20|| num_of_leaders<1){
            throw invalid_argument("bad");
        }
        vector<Team *> temp;
        for (auto team:this->teams) {
            temp.emplace_back(team);
        }
        sort(temp.begin(),temp.end());
        vector<string> to_ret;
        for (size_t i = num_of_leaders-1; i >0 ; i--) {
            to_ret.emplace_back(temp.at(i)->name);
        }
        to_ret.emplace_back(temp.at(0)->name);
        return to_ret;
    }

    int League::longest_winning_streak() {
        int temp = 0;
        string t;
        for(auto team: this->teams){
            if(team->longest_winning_streak>temp){
                temp = team->longest_winning_streak;
                t= team->name;
            }
        }
        cout<< "Team with longest winning streak was: " <<t << "  with: " << temp << " wins \n";
        return temp;
    }

    int League::longest_losing_streak() {
        int temp = 0;
        string t;
        for(auto team: this->teams){
            if(team->longest_losing_streak>temp){
                temp = team->longest_losing_streak;
                t= team->name;
            }
        }
        cout<< "Team with longest losing streak was: " <<t << "  with: " << temp << " wins \n";
        return temp;
    }
    int League::teams_with_positive_ratio() {
        int temp = 0;
        for(auto team: this->teams){
            if(team->points_for>team->points_against){
                temp++;
            }
        }
        return temp;
    }
}

