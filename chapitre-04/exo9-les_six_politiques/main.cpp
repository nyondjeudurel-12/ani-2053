
#include <iostream>
#include <string>

using int64 = long long;

int64 arrondi(int64 a, int64 b)
{
    return (2 * a + b) / (2 * b);
}

int main()
{
    int64 RW;
    int64 RH;
    int64 AW;
    int64 AH;
    int64 W;
    int64 H;

    std::cin >> RW >> RH >> AW >> AH >> W >> H;

    bool reference = (RW != 0 && RH != 0);

    int64 bandes = 0;

    // FOLLOW_WINDOW
    {
        int64 vx = 0;
        int64 vy = 0;
        int64 vw = W;
        int64 vh = H;
        int64 mw = W;
        int64 mh = H;

        std::cout << "FOLLOW_WINDOW "
                  << vx << " " << vy << " "
                  << vw << " " << vh << " "
                  << mw << " " << mh << "\n";
    }

    // STRETCH
    {
        int64 vx = 0;
        int64 vy = 0;
        int64 vw = W;
        int64 vh = H;
        int64 mw = W;
        int64 mh = H;

        if (reference)
        {
            mw = RW;
            mh = RH;
        }

        std::cout << "STRETCH "
                  << vx << " " << vy << " "
                  << vw << " " << vh << " "
                  << mw << " " << mh << "\n";
    }

    // FIT_LETTERBOX
    int64 fitVx = 0;
    int64 fitVy = 0;
    int64 fitVw = W;
    int64 fitVh = H;
    int64 fitMw = W;
    int64 fitMh = H;

    if (reference)
    {
        fitMw = RW;
        fitMh = RH;

        if (W * RH <= H * RW)
        {
            fitVw = W;
            fitVh = arrondi(RH * W, RW);
        }
        else
        {
            fitVh = H;
            fitVw = arrondi(RW * H, RH);
        }

        fitVx = (W - fitVw) / 2;
        fitVy = (H - fitVh) / 2;
    }

    std::cout << "FIT_LETTERBOX "
              << fitVx << " " << fitVy << " "
              << fitVw << " " << fitVh << " "
              << fitMw << " " << fitMh << "\n";

    if (fitVw < W || fitVh < H)
    {
        bandes++;
    }

    // INTEGER_SCALE
    int64 integerVx = 0;
    int64 integerVy = 0;
    int64 integerVw = W;
    int64 integerVh = H;
    int64 integerMw = W;
    int64 integerMh = H;

    if (reference)
    {
        integerMw = RW;
        integerMh = RH;

        if (W >= RW && H >= RH)
        {
            int64 k1 = W / RW;
            int64 k2 = H / RH;
            int64 k = (k1 < k2) ? k1 : k2;

            if (k > 0)
            {
                integerVw = RW * k;
                integerVh = RH * k;

                integerVx = (W - integerVw) / 2;
                integerVy = (H - integerVh) / 2;
            }
            else
            {
                integerVw = fitVw;
                integerVh = fitVh;
                integerVx = fitVx;
                integerVy = fitVy;
            }
        }
        else
        {
            integerVw = fitVw;
            integerVh = fitVh;
            integerVx = fitVx;
            integerVy = fitVy;
        }
    }

    std::cout << "INTEGER_SCALE "
              << integerVx << " " << integerVy << " "
              << integerVw << " " << integerVh << " "
              << integerMw << " " << integerMh << "\n";

    if (integerVw < W || integerVh < H)
    {
        bandes++;
    }

    // FIT_CROP
    int64 cropVx = 0;
    int64 cropVy = 0;
    int64 cropVw = W;
    int64 cropVh = H;
    int64 cropMw = W;
    int64 cropMh = H;

    if (reference)
    {
        cropMw = RW;
        cropMh = RH;

        if (W * RH > H * RW)
        {
            cropMw = RW;
            cropMh = arrondi(RW * H, W);
        }
        else
        {
            cropMw = arrondi(RH * W, H);
            cropMh = RH;
        }
    }

    std::cout << "FIT_CROP "
              << cropVx << " " << cropVy << " "
              << cropVw << " " << cropVh << " "
              << cropMw << " " << cropMh << "\n";

    // MANUAL
    int64 manualVx = 0;
    int64 manualVy = 0;
    int64 manualVw = AW;
    int64 manualVh = AH;
    int64 manualMw = AW;
    int64 manualMh = AH;

    std::cout << "MANUAL "
              << manualVx << " " << manualVy << " "
              << manualVw << " " << manualVh << " "
              << manualMw << " " << manualMh << "\n";

    if (manualVw < W || manualVh < H)
    {
        bandes++;
    }

    bool deformation = false;

    if (reference && W * RH != H * RW)
    {
        deformation = true;
    }

    std::cout << "BANDES " << bandes << "\n";

    if (deformation)
    {
        std::cout << "DEFORMATION OUI\n";
    }
    else
    {
        std::cout << "DEFORMATION NON\n";
    }

    return 0;
}
