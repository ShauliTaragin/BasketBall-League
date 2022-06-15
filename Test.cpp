//
// Created by shaul on 09/05/2022.
//
#include "doctest.h"
#include "League.hpp"
#include "unordered_set"
using namespace taragin;

TEST_CASE("Test Leauge"){
    unordered_set<Team*> myTeams;
    myTeams.insert(new Team(1,"Golden State Warriors"));
    myTeams.insert(new Team(0.4 , "Boston Celtics"));
    myTeams.insert(new Team(0.5,"Brooklyn Nets"));
    myTeams.insert(new Team(0.3,"Denver Nuggets"));
    myTeams.insert(new Team(0.4,"Philadelphia 76ers"));
    myTeams.insert(new Team(0.5,"Minnesota Timberwolves"));
    myTeams.insert(new Team(0.3,"Chicago Bulls"));
    myTeams.insert(new Team(0.2,"Portland Trail Blazers"));
    myTeams.insert(new Team(0.5,"LA Clippers"));
    myTeams.insert(new Team(1,"Los Angeles Lakers"));
    myTeams.insert(new Team(0.7,"Milwaukee Bucks"));
    myTeams.insert(new Team(0.3,"Atlanta Hawks"));
    myTeams.insert(new Team(0.2,"Charlotte Hornets"));
    myTeams.insert(new Team(0.6,"Miami Heat"));
    myTeams.insert(new Team(0.8,"Phoenix Suns"));
    myTeams.insert(new Team(0.6,"Dallas Mavericks"));
    myTeams.insert(new Team(0.5,"Memphis Grizzlies"));
    myTeams.insert(new Team(0.3,"Utah Jazz"));
    myTeams.insert(new Team(0,"Washington Wizards"));
    myTeams.insert(new Team(0.1,"Oklahoma City Thunder"));
    auto * l = new League(myTeams);
    CHECK_THROWS(new Team(1.1 , "best team ever"));//skill not legal
    CHECK_THROWS(myTeams.insert(new Team(-1, "best team ever")));//skill not legal
    CHECK_NOTHROW(myTeams.insert(new Team(0.5 , "Seattle SuperSonics")));
    CHECK_THROWS(auto * l2 = new League(myTeams));//21 Teams in league
    vector<string> num_of_leaders = l->leaders(4);
    cout<<"Teams that are in the playoff are:  "<< '\n';
    for (const auto& playoff_team : num_of_leaders){
        cout<< playoff_team << endl;
    }
    CHECK_EQ(num_of_leaders.size() , 4);
    CHECK_THROWS(l->leaders(21));
    int lws =  l->longest_winning_streak();
    CHECK(lws<39);
    CHECK(lws>0);
    int lls =  l->longest_losing_streak();
    CHECK(lls<39);
    CHECK(lls>0);

}