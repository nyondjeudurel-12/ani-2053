#include <iostream>
#include <string>
#include <algorithm>

struct Point
{
    int x;
    int y;
};

int main()
{
    int n;
    std::cin >> n;

    int refuses = 0;

    for (int i = 0; i < n; ++i)
    {
        std::string nom;
        int w;
        int h;
        int px;
        int py;
        int ox;
        int oy;
        int sx;
        int sy;
        int angle;

        std::cin >> nom >> w >> h >> px >> py
                 >> ox >> oy >> sx >> sy >> angle;

        int normalise = angle % 360;

        if (normalise < 0)
        {
            normalise += 360;
        }

        if (normalise % 90 != 0)
        {
            std::cout << nom << " ANGLE REFUSE\n";
            ++refuses;
            continue;
        }

        int c = 0;
        int s = 0;

        if (normalise == 0)
        {
            c = 1;
            s = 0;
        }
        else if (normalise == 90)
        {
            c = 0;
            s = 1;
        }
        else if (normalise == 180)
        {
            c = -1;
            s = 0;
        }
        else if (normalise == 270)
        {
            c = 0;
            s = -1;
        }

        Point locaux[4] = {
            {0, 0},
            {w, 0},
            {w, h},
            {0, h}
        };

        Point coins[4];

        for (int j = 0; j < 4; ++j)
        {
            int ax = (locaux[j].x - ox) * sx;
            int ay = (locaux[j].y - oy) * sy;

            int rx = ax * c - ay * s;
            int ry = ax * s + ay * c;

            coins[j].x = px + rx;
            coins[j].y = py + ry;
        }

        int minx = coins[0].x;
        int maxx = coins[0].x;
        int miny = coins[0].y;
        int maxy = coins[0].y;

        for (int j = 1; j < 4; ++j)
        {
            minx = std::min(minx, coins[j].x);
            maxx = std::max(maxx, coins[j].x);
            miny = std::min(miny, coins[j].y);
            maxy = std::max(maxy, coins[j].y);
        }

        std::cout << nom << " COINS";

        for (int j = 0; j < 4; ++j)
        {
            std::cout << " " << coins[j].x << " " << coins[j].y;
        }

        std::cout << "\n";

        std::cout << nom << " BOITE "
                  << minx << " " << miny << " "
                  << maxx << " " << maxy << "\n";
    }

    std::cout << "REFUSES " << refuses << "\n";

    return 0;
}