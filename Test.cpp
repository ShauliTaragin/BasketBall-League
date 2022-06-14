//
// Created by shaul on 09/05/2022.
//
#include "doctest.h"
#include "sources/Game.hpp"

using namespace taragin;
using namespace std;
TEST_CASE ("NBA")
{
    CHECK_NOTHROW(Team goldenstate(0.9 , "golden state"));
}


