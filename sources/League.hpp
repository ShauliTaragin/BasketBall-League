//
// Created by shaul on 14/06/2022.
//
#pragma once
#include "Schedule.hpp"
#include "unordered_set"
#include "vector"
#include <bits/stdc++.h>
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
        League(const unordered_set<Team *>& received_teams) ;

        League() ;
        ~League();
        void Play_League() const;
        vector<string> leaders(size_t num_of_leaders);
        int longest_winning_streak();
        int longest_losing_streak();
        int teams_with_positive_ratio();
    };
}
