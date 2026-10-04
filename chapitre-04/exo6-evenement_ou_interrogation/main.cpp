
#include <iostream>
#include <string>

int main()
{
    int v;
    int N;

    std::cin >> v >> N;

    int xe = 0;
    int xi = 0;

    bool space = false;
    bool left = false;
    bool right = false;

    int sautsEvenements = 0;
    int sautsInterrogation = 0;
    int manques = 0;

    for (int i = 1; i <= N; i++)
    {
        int k;
        std::cin >> k;

        bool appuiSpaceDansImage = false;

        for (int j = 0; j < k; j++)
        {
            std::string evenement;
            std::cin >> evenement;

            if (evenement.size() < 2)
            {
                continue;
            }

            char action = evenement[0];
            std::string touche = evenement.substr(1);

            if (touche == "SPACE")
            {
                if (action == '+')
                {
                    space = true;
                    sautsEvenements++;
                    appuiSpaceDansImage = true;
                }
                else if (action == '-')
                {
                    space = false;
                }
            }
            else if (touche == "RIGHT")
            {
                if (action == '+')
                {
                    right = true;
                    xe += v;
                }
                else if (action == '-')
                {
                    right = false;
                }
            }
            else if (touche == "LEFT")
            {
                if (action == '+')
                {
                    left = true;
                    xe -= v;
                }
                else if (action == '-')
                {
                    left = false;
                }
            }
        }

        if (space)
        {
            sautsInterrogation++;
        }

        if (right)
        {
            xi += v;
        }

        if (left)
        {
            xi -= v;
        }

        if (appuiSpaceDansImage && !space)
        {
            manques++;
        }

        std::cout << i << " " << xe << " " << xi << "\n";
    }

    std::cout << "SAUTS EVENEMENTS " << sautsEvenements << "\n";
    std::cout << "SAUTS INTERROGATION " << sautsInterrogation << "\n";
    std::cout << "MANQUES " << manques << "\n";

    return 0;
}

