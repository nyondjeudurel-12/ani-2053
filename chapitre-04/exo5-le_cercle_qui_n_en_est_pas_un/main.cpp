
#include <iostream>
#include <cmath>

int main()
{
    const double pi = 3.141592653589793;

    int N;
    std::cin >> N;

    int visibles = 0;
    int refuses = 0;

    for (int i = 0; i < N; i++)
    {
        int r;
        int n;

        std::cin >> r >> n;

        if (n < 3)
        {
            std::cout << r << " " << n << " REFUSE\n";
            refuses++;
            continue;
        }

        double g = r * (1.0 - std::cos(pi / n));

        int ecart = static_cast<int>(std::floor(g * 1000.0));

        if (g == 0.0)
        {
            std::cout << r << " " << n << " "
                      << ecart << " JAMAIS\n";
            continue;
        }

        int zoom = static_cast<int>(std::ceil(100.0 / g));

        if (zoom <= 100)
        {
            std::cout << r << " " << n << " "
                      << ecart << " " << zoom << " VISIBLE\n";
            visibles++;
        }
        else
        {
            std::cout << r << " " << n << " "
                      << ecart << " " << zoom << " INVISIBLE\n";
        }
    }

    std::cout << "VISIBLES " << visibles << "\n";
    std::cout << "REFUSES " << refuses << "\n";

    return 0;
}

