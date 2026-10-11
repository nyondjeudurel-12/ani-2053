
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// Transforme un chiffre hexadecimal en nombre
int convertirHex(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';

    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;

    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;

    return -1;
}

// Recupere les octets a partir de la chaine hexadecimale
vector<int> lireOctets(const string& texte)
{
    vector<int> octets;

    if (texte == "-")
        return octets;

    for (size_t i = 0; i + 1 < texte.size(); i += 2)
    {
        int premier = convertirHex(texte[i]);
        int second = convertirHex(texte[i + 1]);

        if (premier == -1 || second == -1)
            return {};

        octets.push_back(premier * 16 + second);
    }

    return octets;
}

// Verifie si les premiers octets correspondent a une signature
bool verifierSignature(const vector<int>& octets,
                       const vector<int>& signature)
{
    if (octets.size() < signature.size())
        return false;

    for (size_t i = 0; i < signature.size(); i++)
    {
        if (octets[i] != signature[i])
            return false;
    }

    return true;
}

// Cherche le format en suivant l'ordre donne dans l'enonce
string trouverFormat(long long taille, const vector<int>& octets)
{
    if (taille < 4)
        return "";

    if (taille >= 8 &&
        verifierSignature(octets, {0x89, 0x50, 0x4E, 0x47}))
        return "PNG";

    if (verifierSignature(octets, {0xFF, 0xD8, 0xFF}))
        return "JPEG";

    if (verifierSignature(octets, {0x42, 0x4D}))
        return "BMP";

    if (verifierSignature(octets, {0x71, 0x6F, 0x69, 0x66}))
        return "QOI";

    if (verifierSignature(octets, {0x47, 0x49, 0x46, 0x38}))
        return "GIF";

    // Signature des icones ICO et CUR
    if (octets.size() >= 4 &&
        octets[0] == 0x00 && octets[1] == 0x00 &&
        (octets[2] == 0x01 || octets[2] == 0x02) &&
        octets[3] == 0x00)
        return "ICO";

    if (taille >= 10 &&
        verifierSignature(octets, {0x23, 0x3F}))
        return "HDR";

    if (verifierSignature(octets, {0x76, 0x2F, 0x31, 0x01}))
        return "EXR";

    // Les formats PBM, PGM et PPM commencent par P1 a P6
    if (octets.size() >= 2 &&
        octets[0] == 0x50 &&
        octets[1] >= 0x31 && octets[1] <= 0x36)
    {
        if (octets[1] == 0x31 || octets[1] == 0x34)
            return "PBM";

        if (octets[1] == 0x32 || octets[1] == 0x35)
            return "PGM";

        return "PPM";
    }

    // Le TGA est reconnu avec son type d'image et sa taille
    if (taille >= 18 && octets.size() >= 3)
    {
        int type = octets[2];

        if (type == 0x00 || type == 0x01 || type == 0x02 ||
            type == 0x03 || type == 0x09 || type == 0x0A ||
            type == 0x0B)
            return "TGA";
    }

    // Pour le SVG, on ignore le BOM et les espaces au debut
    size_t debut = 0;

    if (verifierSignature(octets, {0xEF, 0xBB, 0xBF}))
        debut = 3;

    while (debut < octets.size() &&
           (octets[debut] == 0x20 || octets[debut] == 0x09 ||
            octets[debut] == 0x0A || octets[debut] == 0x0D))
    {
        debut++;
    }

    vector<int> reste(octets.begin() + debut, octets.end());

    if (verifierSignature(reste, {0x3C, 0x3F, 0x78, 0x6D, 0x6C}) ||
        verifierSignature(reste, {0x3C, 0x73, 0x76, 0x67}))
        return "SVG";

    return "";
}

// Recupere l'extension apres le dernier point
string trouverExtension(const string& nom)
{
    size_t position = nom.find_last_of('.');

    if (position == string::npos)
        return "";

    string extension = nom.substr(position + 1);

    // On met l'extension en minuscules
    transform(extension.begin(), extension.end(), extension.begin(),
        [](unsigned char c) {
            return static_cast<char>(tolower(c));
        });

    return extension;
}

// Compare l'extension avec le format reconnu
bool extensionValide(const string& format, const string& extension)
{
    if (format == "PNG") return extension == "png";
    if (format == "JPEG") return extension == "jpg" || extension == "jpeg";
    if (format == "BMP") return extension == "bmp";
    if (format == "QOI") return extension == "qoi";
    if (format == "GIF") return extension == "gif";
    if (format == "ICO") return extension == "ico" || extension == "cur";
    if (format == "HDR") return extension == "hdr";
    if (format == "EXR") return extension == "exr";
    if (format == "PBM") return extension == "pbm";
    if (format == "PGM") return extension == "pgm";
    if (format == "PPM") return extension == "ppm";
    if (format == "TGA") return extension == "tga";
    if (format == "SVG") return extension == "svg";

    return false;
}

int main()
{
    int nombre;
    cin >> nombre;

    int lus = 0;
    int mensonges = 0;
    int refuses = 0;

    // On traite les fichiers un par un
    for (int i = 0; i < nombre; i++)
    {
        string nom, hexadecimal;
        long long taille;

        cin >> nom >> taille >> hexadecimal;

        vector<int> octets = lireOctets(hexadecimal);
        string format = trouverFormat(taille, octets);

        // Aucun format reconnu
        if (format.empty())
        {
            cout << nom << " REFUSE\n";
            refuses++;
            continue;
        }

        lus++;

        string extension = trouverExtension(nom);

        if (extensionValide(format, extension))
        {
            cout << nom << " " << format << " OK\n";
        }
        else
        {
            cout << nom << " " << format << " MENT\n";
            mensonges++;
        }
    }

    // Bilan final
    cout << "LUS " << lus << '\n';
    cout << "MENSONGES " << mensonges << '\n';
    cout << "REFUSES " << refuses << '\n';

    return 0;
}

