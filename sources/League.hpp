//
// Created by shaul on 14/06/2022.
//
#pragma once
#include "Schedule.hpp"
#include "unordered_set"

using namespace std;

namespace taragin {
    class League {
    public:
        unordered_set<Team *> teams;
        int num_of_teams;

        /**
         * Constructor for methods 2 and 3
         * @param received_teams
         */
        League(const unordered_set<Team *> received_teams) {
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

        League() {
            this->num_of_teams = 0;
            while (num_of_teams < 20) {
                teams.insert(new Team{0.6, to_string(num_of_teams)});
            }
            Play_League();
        }
        void Play_League(){
            Schedule schedule(this->teams);
        }
    };
}
