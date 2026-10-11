
#include <iostream>
#include <string>

using namespace std;

// Donne les caracteristiques de chaque format
bool informationsFormat(const string& format, int& octets,
                        bool& couleur, bool& alpha, bool& flottants)
{
    if (format == "GRAY8")
    {
        octets = 1;
        couleur = false;
        alpha = false;
        flottants = false;
    }
    else if (format == "GRAY_A16")
    {
        octets = 2;
        couleur = false;
        alpha = true;
        flottants = false;
    }
    else if (format == "RGB24")
    {
        octets = 3;
        couleur = true;
        alpha = false;
        flottants = false;
    }
    else if (format == "RGBA32")
    {
        octets = 4;
        couleur = true;
        alpha = true;
        flottants = false;
    }
    else if (format == "RGB96F")
    {
        octets = 12;
        couleur = true;
        alpha = false;
        flottants = true;
    }
    else if (format == "RGBA128F")
    {
        octets = 16;
        couleur = true;
        alpha = true;
        flottants = true;
    }
    else
    {
        return false;
    }

    return true;
}

int main()
{
    long long largeur, hauteur;
    cin >> largeur >> hauteur;

    int nombre;
    cin >> nombre;

    long long total = 0;
    int sansPerte = 0;
    int refuses = 0;

    for (int i = 0; i < nombre; i++)
    {
        string source, cible;
        cin >> source >> cible;

        int octetsSource, octetsCible;
        bool couleurSource, alphaSource, flottantsSource;
        bool couleurCible, alphaCible, flottantsCible;

        // On recupere les informations des deux formats
        bool sourceValide = informationsFormat(
            source, octetsSource, couleurSource,
            alphaSource, flottantsSource);

        bool cibleValide = informationsFormat(
            cible, octetsCible, couleurCible,
            alphaCible, flottantsCible);

        if (!sourceValide || !cibleValide)
        {
            cout << source << " " << cible << " REFUSE\n";
            refuses++;
            continue;
        }

        // Calcul de la memoire necessaire
        long long pixels = largeur * hauteur;
        long long memoireSource = pixels * octetsSource;
        long long memoireCible = pixels * octetsCible;

        string pertes = "";

        // On ajoute les pertes dans l'ordre demande
        if (alphaSource && !alphaCible)
            pertes = "TRANSPARENCE";

        if (couleurSource && !couleurCible)
        {
            if (!pertes.empty())
                pertes += "+";

            pertes += "COULEUR";
        }

        if (flottantsSource && !flottantsCible)
        {
            if (!pertes.empty())
                pertes += "+";

            pertes += "ETENDUE";
        }

        if (pertes.empty())
        {
            pertes = "AUCUNE";
            sansPerte++;
        }

        // Affichage du resultat de la conversion
        cout << source << " " << cible << " "
             << memoireSource << " " << memoireCible << " "
             << pertes << '\n';

        total += memoireCible;
    }

    // Bilan de toutes les conversions
    cout << "TOTAL " << total << '\n';
    cout << "SANS_PERTE " << sansPerte << '\n';
    cout << "REFUSES " << refuses << '\n';

    return 0;
}

