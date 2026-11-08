#include <iostream>
#include <string>
#include <array>
#include <algorithm>

// Les cinq membres spéciaux, dans l'ordre demandé.
enum Membre
{
    DESTRUCTEUR,
    COPIE,
    AFFECTATION_COPIE,
    DEPLACEMENT,
    AFFECTATION_DEPLACEMENT
};

// Les différents états possibles.
enum Etat
{
    ABSENT,
    ECRIT,
    DEFAUT,
    SUPPRIME
};

// Convertit un état en texte pour l'affichage.
std::string nomEtat(Etat etat)
{
    switch (etat)
    {
        case ABSENT: return "ABSENT";
        case ECRIT: return "ECRIT";
        case DEFAUT: return "DEFAUT";
        case SUPPRIME: return "SUPPRIME";
    }

    return "ABSENT";
}

// Vérifie si une chaîne se termine par un suffixe donné.
bool seTerminePar(const std::string& texte,
                  const std::string& suffixe)
{
    return texte.size() >= suffixe.size()
        && texte.compare(
            texte.size() - suffixe.size(),
            suffixe.size(),
            suffixe
        ) == 0;
}

// Détermine l'état d'un membre reconnu.
Etat determinerEtat(const std::string& ligne)
{
    if (seTerminePar(ligne, "=delete;"))
    {
        return SUPPRIME;
    }

    if (seTerminePar(ligne, "=default;"))
    {
        return DEFAUT;
    }

    return ECRIT;
}

// Vérifie si une ligne commence par un préfixe.
bool commencePar(const std::string& ligne,
                 const std::string& prefixe)
{
    return ligne.compare(0, prefixe.size(), prefixe) == 0;
}

// Vérifie une déclaration de copie sans confondre & et &&.
bool estCopie(const std::string& ligne,
              const std::string& prefixe)
{
    return commencePar(ligne, prefixe)
        && (ligne.size() == prefixe.size()
            || ligne[prefixe.size()] != '&');
}

// Retire tous les espaces d'une ligne.
void retirerEspaces(std::string& ligne)
{
    ligne.erase(
        std::remove(ligne.begin(), ligne.end(), ' '),
        ligne.end()
    );
}

// Vérifie si une ligne contient une déclaration de destructeur.
bool estDestructeur(const std::string& ligne,
                    const std::string& nomClasse)
{
    return ligne.find("~" + nomClasse + "(")
        != std::string::npos;
}

// Analyse une ligne et identifie le membre correspondant.
int reconnaitreMembre(const std::string& ligne,
                      const std::string& nomClasse)
{
    // Destructeur.
    if (estDestructeur(ligne, nomClasse))
    {
        return DESTRUCTEUR;
    }

    // Construction de copie.
    const std::string copie =
        nomClasse + "(const" + nomClasse + "&";

    if (estCopie(ligne, copie))
    {
        return COPIE;
    }

    // Affectation par copie.
    const std::string affectationCopie =
        nomClasse + "&operator=(const" + nomClasse + "&";

    if (estCopie(ligne, affectationCopie))
    {
        return AFFECTATION_COPIE;
    }

    // Construction par déplacement.
    const std::string deplacement =
        nomClasse + "(" + nomClasse + "&&";

    if (commencePar(ligne, deplacement))
    {
        return DEPLACEMENT;
    }

    // Affectation par déplacement.
    const std::string affectationDeplacement =
        nomClasse + "&operator=(" + nomClasse + "&&";

    if (commencePar(ligne, affectationDeplacement))
    {
        return AFFECTATION_DEPLACEMENT;
    }

    return -1;
}

int main()
{
    std::string nomClasse;

    // Lecture du nom de la classe.
    if (!std::getline(std::cin, nomClasse))
    {
        return 0;
    }

    retirerEspaces(nomClasse);

    // Les cinq membres commencent à l'état ABSENT.
    std::array<Etat, 5> etats = {
        ABSENT, ABSENT, ABSENT, ABSENT, ABSENT
    };

    std::string ligne;

    // Lecture de toutes les déclarations.
    while (std::getline(std::cin, ligne))
    {
        // Suppression du commentaire.
        const std::size_t positionCommentaire =
            ligne.find("//");

        if (positionCommentaire != std::string::npos)
        {
            ligne.erase(positionCommentaire);
        }

        // Suppression des espaces.
        retirerEspaces(ligne);

        // Une ligne vide est ignorée.
        if (ligne.empty())
        {
            continue;
        }

        // Recherche du membre déclaré.
        const int membre =
            reconnaitreMembre(ligne, nomClasse);

        if (membre != -1)
        {
            etats[membre] = determinerEtat(ligne);
        }
    }

    // Noms des membres dans l'ordre imposé.
    const std::array<std::string, 5> noms = {
        "DESTRUCTEUR",
        "COPIE",
        "AFFECTATION_COPIE",
        "DEPLACEMENT",
        "AFFECTATION_DEPLACEMENT"
    };

    // Affichage des cinq états.
    for (std::size_t i = 0; i < etats.size(); ++i)
    {
        std::cout << noms[i] << " "
                  << nomEtat(etats[i]) << '\n';
    }

    // Comptage des membres déclarés.
    int nombreDeclares = 0;

    for (Etat etat : etats)
    {
        if (etat != ABSENT)
        {
            ++nombreDeclares;
        }
    }

    // Vérification de la présence des déplacements.
    const bool aDeplacement =
        etats[DEPLACEMENT] != ABSENT
        || etats[AFFECTATION_DEPLACEMENT] != ABSENT;

    // Détermination de la règle suivie.
    std::string regle;

    if (nombreDeclares == 0)
    {
        regle = "ZERO";
    }
    else if (nombreDeclares == 5)
    {
        regle = "CINQ";
    }
    else if (
        etats[DESTRUCTEUR] != ABSENT
        && etats[COPIE] != ABSENT
        && etats[AFFECTATION_COPIE] != ABSENT
        && !aDeplacement
    )
    {
        regle = "TROIS";
    }
    else
    {
        regle = "INCOMPLETE";
    }

    std::cout << "REGLE " << regle << '\n';

    // Affichage des membres manquants si la règle est incomplète.
    if (regle == "INCOMPLETE")
    {
        const int limite = aDeplacement ? 5 : 3;

        for (int i = 0; i < limite; ++i)
        {
            if (etats[i] == ABSENT)
            {
                std::cout << "MANQUE " << noms[i] << '\n';
            }
        }
    }

    // Détermination de la possession.
    const bool possede = etats[DESTRUCTEUR] == ECRIT;

    std::cout << "POSSEDE "
              << (possede ? "OUI" : "NON") << '\n';

    // Détermination de l'unicité.
    const bool unique =
        etats[COPIE] == SUPPRIME
        && (etats[DEPLACEMENT] == ECRIT
            || etats[DEPLACEMENT] == DEFAUT);

    std::cout << "UNIQUE "
              << (unique ? "OUI" : "NON") << '\n';

    return 0;
}