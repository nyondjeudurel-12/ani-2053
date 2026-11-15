#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

struct Image
{
    std::string nom;
    bool selectionnee = false;
};

// Affiche une liste de noms ou AUCUN si elle est vide.
void afficherListe(const std::string& conception,
                   const std::string& type,
                   const std::vector<std::string>& noms)
{
    std::cout << conception << " " << type;

    if (noms.empty())
    {
        std::cout << " AUCUN";
    }
    else
    {
        for (const std::string& nom : noms)
        {
            std::cout << " " << nom;
        }
    }

    std::cout << '\n';
}

// Récupère les noms des images sélectionnées, dans l'ordre de la planche.
std::vector<std::string> obtenirSelection(
    const std::vector<Image>& planche,
    const std::set<int>& indices,
    const std::set<std::string>& identifiants,
    int conception)
{
    std::vector<std::string> resultat;

    for (std::size_t i = 0; i < planche.size(); ++i)
    {
        bool choisie = false;

        if (conception == 0)
        {
            choisie = planche[i].selectionnee;
        }
        else if (conception == 1)
        {
            choisie = indices.count(static_cast<int>(i)) > 0;
        }
        else
        {
            choisie = identifiants.count(planche[i].nom) > 0;
        }

        if (choisie)
        {
            resultat.push_back(planche[i].nom);
        }
    }

    return resultat;
}

int main()
{
    // Les trois planches commencent vides.
    std::vector<Image> dansItem;
    std::vector<Image> parIndex;
    std::vector<Image> parId;

    // Les deux conceptions externes conservent leur sélection.
    std::set<int> indicesGardes;
    std::set<std::string> identifiantsGardes;

    std::string commande;

    // Les opérations sont lues jusqu'à la fin de l'entrée.
    while (std::cin >> commande)
    {
        if (commande == "AJOUTE")
        {
            std::string nom;
            std::cin >> nom;

            dansItem.push_back({nom, false});
            parIndex.push_back({nom, false});
            parId.push_back({nom, false});
        }
        else if (commande == "CLIC")
        {
            int index;
            std::cin >> index;

            // DANS_ITEM : on vide puis on sélectionne l'image valide.
            for (Image& image : dansItem)
            {
                image.selectionnee = false;
            }

            if (index >= 0 &&
                static_cast<std::size_t>(index) < dansItem.size())
            {
                dansItem[index].selectionnee = true;
            }

            // PAR_INDEX : on vide puis on garde l'index valide.
            indicesGardes.clear();

            if (index >= 0 &&
                static_cast<std::size_t>(index) < parIndex.size())
            {
                indicesGardes.insert(index);
            }

            // PAR_ID : on vide puis on garde le nom de l'image valide.
            identifiantsGardes.clear();

            if (index >= 0 &&
                static_cast<std::size_t>(index) < parId.size())
            {
                identifiantsGardes.insert(parId[index].nom);
            }
        }
        else if (commande == "AJOUTE_SEL")
        {
            int index;
            std::cin >> index;

            if (index >= 0 &&
                static_cast<std::size_t>(index) < dansItem.size())
            {
                dansItem[index].selectionnee = true;
            }

            if (index >= 0 &&
                static_cast<std::size_t>(index) < parIndex.size())
            {
                indicesGardes.insert(index);
            }

            if (index >= 0 &&
                static_cast<std::size_t>(index) < parId.size())
            {
                identifiantsGardes.insert(parId[index].nom);
            }
        }
        else if (commande == "ECHANGE")
        {
            int i;
            int j;
            std::cin >> i >> j;

            // Chaque conception échange les images de sa propre planche.
            if (i >= 0 && j >= 0 &&
                static_cast<std::size_t>(i) < dansItem.size() &&
                static_cast<std::size_t>(j) < dansItem.size())
            {
                std::swap(dansItem[i], dansItem[j]);
            }

            if (i >= 0 && j >= 0 &&
                static_cast<std::size_t>(i) < parIndex.size() &&
                static_cast<std::size_t>(j) < parIndex.size())
            {
                std::swap(parIndex[i], parIndex[j]);
            }

            if (i >= 0 && j >= 0 &&
                static_cast<std::size_t>(i) < parId.size() &&
                static_cast<std::size_t>(j) < parId.size())
            {
                std::swap(parId[i], parId[j]);
            }
        }
        else if (commande == "RETIRE")
        {
            int index;
            std::cin >> index;

            // DANS_ITEM : retirer l'image, avec son éventuel drapeau.
            if (index >= 0 &&
                static_cast<std::size_t>(index) < dansItem.size())
            {
                dansItem.erase(dansItem.begin() + index);
            }

            // PAR_INDEX : retirer l'image sans modifier les index gardés.
            if (index >= 0 &&
                static_cast<std::size_t>(index) < parIndex.size())
            {
                parIndex.erase(parIndex.begin() + index);
            }

            // PAR_ID : retirer l'image sans modifier les noms gardés.
            if (index >= 0 &&
                static_cast<std::size_t>(index) < parId.size())
            {
                parId.erase(parId.begin() + index);
            }
        }
        else if (commande == "SUPPRIME")
        {
            // DANS_ITEM : retirer toutes les images marquées.
            dansItem.erase(
                std::remove_if(
                    dansItem.begin(),
                    dansItem.end(),
                    [](const Image& image)
                    {
                        return image.selectionnee;
                    }),
                dansItem.end());

            // PAR_INDEX : retirer les images aux positions gardées.
            for (int i = static_cast<int>(parIndex.size()) - 1; i >= 0; --i)
            {
                if (indicesGardes.count(i) > 0)
                {
                    parIndex.erase(parIndex.begin() + i);
                }
            }

            // PAR_ID : retirer les images dont le nom est gardé.
            parId.erase(
                std::remove_if(
                    parId.begin(),
                    parId.end(),
                    [&identifiantsGardes](const Image& image)
                    {
                        return identifiantsGardes.count(image.nom) > 0;
                    }),
                parId.end());

            // Les trois sélections sont ensuite vidées.
            indicesGardes.clear();
            identifiantsGardes.clear();
        }
    }

    // Récupérer les sélections dans l'ordre de chaque planche.
    const std::vector<std::string> selectionItem =
        obtenirSelection(dansItem, indicesGardes, identifiantsGardes, 0);

    const std::vector<std::string> selectionIndex =
        obtenirSelection(parIndex, indicesGardes, identifiantsGardes, 1);

    const std::vector<std::string> selectionId =
        obtenirSelection(parId, indicesGardes, identifiantsGardes, 2);

    // Récupérer les noms des images de chaque planche.
    std::vector<std::string> nomsItem;
    std::vector<std::string> nomsIndex;
    std::vector<std::string> nomsId;

    for (const Image& image : dansItem)
    {
        nomsItem.push_back(image.nom);
    }

    for (const Image& image : parIndex)
    {
        nomsIndex.push_back(image.nom);
    }

    for (const Image& image : parId)
    {
        nomsId.push_back(image.nom);
    }

    // Afficher les résultats des trois conceptions.
    afficherListe("DANS_ITEM", "PLANCHE", nomsItem);
    afficherListe("DANS_ITEM", "SELECTION", selectionItem);

    afficherListe("PAR_INDEX", "PLANCHE", nomsIndex);
    afficherListe("PAR_INDEX", "SELECTION", selectionIndex);

    afficherListe("PAR_ID", "PLANCHE", nomsId);
    afficherListe("PAR_ID", "SELECTION", selectionId);

    // Comparer chaque conception avec DANS_ITEM.
    std::vector<std::string> erreurs;

    if (nomsIndex != nomsItem || selectionIndex != selectionItem)
    {
        erreurs.push_back("PAR_INDEX");
    }

    if (nomsId != nomsItem || selectionId != selectionItem)
    {
        erreurs.push_back("PAR_ID");
    }

    std::cout << "FAUX";

    if (erreurs.empty())
    {
        std::cout << " AUCUN";
    }
    else
    {
        for (const std::string& nom : erreurs)
        {
            std::cout << " " << nom;
        }
    }

    std::cout << '\n';

    return 0;
}