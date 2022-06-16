//
// Created by shaul on 14/06/2022.
//
#include "Game.hpp"
#include "Team.hpp"
#include "unordered_set"
using namespace std;
namespace taragin {
    class Schedule {
    public:
        explicit Schedule( const unordered_set<Team *>& teams){
            for (auto home_team : teams) {
                for (auto away_team : teams) {
                    if (home_team==away_team){
                        continue;
                    }
                    Game game(home_team, away_team);
                }
            }
        }
        ~Schedule()= default;
    };


}