//
// Created by shaul on 14/06/2022.
//


#include "Team.hpp"
namespace taragin{
    class Game{
        Team * home_team;
        Team * away_team;
    public:
        Game(Team* home , Team* away): home_team(home) , away_team(away){}

        &Team Play(){
            int score_home = Score(55 , 100 , *home_team);
            int score_away = Score(50 , 100 , *away_team);

        }
        int Score(int first , int second , Team team){
                int r = (rand()%(B-A)) + A;
                return r;
        }
    };
}