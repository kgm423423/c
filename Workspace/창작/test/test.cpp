#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

struct Pos
{
    int x;
    int y;
};

vector<Pos> route;

int main() {

    route.push_back({0,0});
    route.push_back({1,1});

    route.erase(route.begin());

    Pos nextPos = route[route.size()-1];

    printf("%d %d %d", nextPos.x, nextPos.y, route.size());



	return 0;
}
