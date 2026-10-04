
#include <iostream>
#include <string>
#include <vector>

struct Objet
{
    std::string nom;
    std::string parent;

    int tx;
    int ty;
    int angle;
    int echelle;

    int x;
    int y;
    int angleMonde;
    int echelleMonde;
    int profondeur;
};

int normaliserAngle(int angle)
{
    angle %= 360;

    if (angle < 0)
    {
        angle += 360;
    }

    return angle;
}

void calculerTransformation(Objet& objet, const std::vector<Objet>& objets)
{
    if (objet.parent == "-")
    {
        objet.x = objet.tx;
        objet.y = objet.ty;
        objet.angleMonde = normaliserAngle(objet.angle);
        objet.echelleMonde = objet.echelle;
        objet.profondeur = 1;
        return;
    }

    const Objet* parent = nullptr;

    for (const Objet& autre : objets)
    {
        if (autre.nom == objet.parent)
        {
            parent = &autre;
            break;
        }
    }

    int ax = objet.tx * parent->echelleMonde;
    int ay = objet.ty * parent->echelleMonde;

    int rx = ax;
    int ry = ay;

    switch (parent->angleMonde)
    {
        case 0:
            rx = ax;
            ry = ay;
            break;

        case 90:
            rx = -ay;
            ry = ax;
            break;

        case 180:
            rx = -ax;
            ry = -ay;
            break;

        case 270:
            rx = ay;
            ry = -ax;
            break;
    }

    objet.x = parent->x + rx;
    objet.y = parent->y + ry;

    objet.angleMonde =
        normaliserAngle(parent->angleMonde + objet.angle);

    objet.echelleMonde =
        parent->echelleMonde * objet.echelle;

    objet.profondeur =
        parent->profondeur + 1;
}

int main()
{
    int N;
    std::cin >> N;

    std::vector<Objet> objets;
    objets.reserve(N);

    int profondeurMax = 0;

    for (int i = 0; i < N; i++)
    {
        Objet objet;

        std::cin >> objet.nom
                 >> objet.parent
                 >> objet.tx
                 >> objet.ty
                 >> objet.angle
                 >> objet.echelle;

        calculerTransformation(objet, objets);

        if (objet.profondeur > profondeurMax)
        {
            profondeurMax = objet.profondeur;
        }

        objets.push_back(objet);
    }

    for (const Objet& objet : objets)
    {
        std::cout << objet.nom << " "
                  << objet.x << " "
                  << objet.y << " "
                  << objet.angleMonde << " "
                  << objet.echelleMonde << "\n";
    }

    std::cout << "PROFONDEUR " << profondeurMax << "\n";

    return 0;
}

