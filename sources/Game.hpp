//
// Created by shaul on 14/06/2022.
//


#include "Team.hpp"
using namespace std;

namespace taragin{
    class Game{
        Team * home_team;
        Team * away_team;
    public:
        Game(Team* home , Team* away);
        ~Game()= default;

        void Play();
        static int Score(int first , int second , const Team* team);
    };

}