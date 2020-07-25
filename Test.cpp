#include "doctest.h"
#include "range.hpp"
#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace itertools;
using namespace std;


TEST_CASE("Test Range")
{
    vector<int> result = {5,6,7,8};
    int j = 0;
    for(int i : range(5,9))
    {
                CHECK(i == result.at(j));
        ++j;
    }
            CHECK(j == 4);


    j = 0;
    result.clear();
    result = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    for(int i : range(0,21))
    {
                CHECK(i == result.at(j));
        ++j;
    }
            CHECK(j == 21);

    j = 0;
    result.clear();
    result = {5,5};

    for(int i : range(5,5))
    {
                CHECK(0==1); // dont need to get
    }

}
