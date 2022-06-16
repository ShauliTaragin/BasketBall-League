//
// Created by shaul on 16/06/2022.
//
#include "Game.hpp"
namespace taragin {
    Game::Game(Team *home, Team *away) : home_team(home), away_team(away) {
        Play();
    }


    void Game::Play() {
        int score_home = Score(55, 100, home_team);
        int score_away = Score(50, 100, away_team);
        // First add all game details to the both teams
        home_team->points_for += score_home;
        home_team->points_against += score_away;
        home_team->games_played++;
        away_team->points_for += score_away;
        away_team->points_against += score_home;
        away_team->games_played++;
        //determine the winner
        if (score_home >= score_away) {
            home_team->wins++;
            away_team->losses++;
            home_team->curr_longest_winning_streak++;
            away_team->curr_longest_losing_streak++;
            if (away_team->curr_longest_losing_streak > away_team->longest_losing_streak) {
                away_team->longest_losing_streak = away_team->curr_longest_losing_streak;
            }
            if (home_team->curr_longest_winning_streak > home_team->longest_winning_streak) {
                home_team->curr_longest_winning_streak = home_team->longest_winning_streak;
            }
            home_team->curr_longest_losing_streak = 0;
            away_team->curr_longest_winning_streak = 0;
        } else {
            home_team->losses++;
            away_team->wins++;
            away_team->curr_longest_winning_streak++;
            home_team->curr_longest_losing_streak++;
            if (home_team->curr_longest_losing_streak > home_team->longest_losing_streak) {
                home_team->longest_losing_streak = home_team->curr_longest_losing_streak;
            }
            if (away_team->curr_longest_winning_streak > away_team->longest_winning_streak) {
                away_team->longest_winning_streak = away_team->curr_longest_winning_streak;
            }
            away_team->curr_longest_losing_streak = 0;
            home_team->curr_longest_winning_streak = 0;
        }
    }

    int Game::Score(int first, int second, const Team *team) {
        int r = rand() % (second - first + 1) + first;
        return static_cast<int>(r + 10 * team->skill);
    }
}