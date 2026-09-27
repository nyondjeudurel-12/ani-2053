# EXERCICE 12:(Le rejeu)

* L'objectif ici est d'enregistrer toutes les actions effectuées pendant une minute d'utilisation, avec leur horodatage, puis de les rejouer automatiquement sans utiliser le clavier.
Pour réaliser cette expérience, j'ai utilisé plusieurs actions :

```
enum class Action
{
    GAUCHE,
    DROITE,
    SAUT,
    TIR
};
```
*  voici le programme complet:
```
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <conio.h>

using namespace std;
using namespace chrono;

enum class Action
{
    GAUCHE,
    DROITE,
    SAUT,
    TIR
};

struct RecordedAction
{
    long long timestamp;
    Action action;
};

string actionToString(Action action)
{
    switch (action)
    {
    case Action::GAUCHE:
        return "GAUCHE";

    case Action::DROITE:
        return "DROITE";

    case Action::SAUT:
        return "SAUT";

    case Action::TIR:
        return "TIR";
    }

    return "INCONNUE";
}

Action stringToAction(const string &value)
{
    if (value == "GAUCHE")
        return Action::GAUCHE;

    if (value == "DROITE")
        return Action::DROITE;

    if (value == "SAUT")
        return Action::SAUT;

    return Action::TIR;
}

/*
    Les règles du programme ne connaissent pas le clavier.
    Elles reçoivent uniquement une action.
*/
void executeAction(Action action)
{
    switch (action)
    {
    case Action::GAUCHE:
        cout << "Action : le personnage va a gauche" << endl;
        break;

    case Action::DROITE:
        cout << "Action : le personnage va a droite" << endl;
        break;

    case Action::SAUT:
        cout << "Action : le personnage saute" << endl;
        break;

    case Action::TIR:
        cout << "Action : le personnage tire" << endl;
        break;
    }
}

void saveRecording(const vector<RecordedAction> &recording)
{
    ofstream file("recording.txt");

    for (const auto &event : recording)
    {
        file << event.timestamp << " "
             << actionToString(event.action) << endl;
    }

    file.close();
}

vector<RecordedAction> loadRecording()
{
    vector<RecordedAction> recording;

    ifstream file("recording.txt");

    long long timestamp;
    string action;

    while (file >> timestamp >> action)
    {
        recording.push_back(
            {
                timestamp,
                stringToAction(action)
            });
    }

    file.close();

    return recording;
}

void recordActions()
{
    vector<RecordedAction> recording;

    cout << "=== ENREGISTREMENT ===" << endl;
    cout << "Pendant 60 secondes :" << endl;
    cout << "A = gauche" << endl;
    cout << "D = droite" << endl;
    cout << "ESPACE = saut" << endl;
    cout << "F = tir" << endl;
    cout << endl;
    cout << "L'enregistrement commence..." << endl;

    auto start = steady_clock::now();

    while (duration_cast<seconds>(
               steady_clock::now() - start)
               .count() < 60)
    {
        if (_kbhit())
        {
            char key = _getch();

            auto timestamp = duration_cast<milliseconds>(
                                 steady_clock::now() - start)
                                 .count();

            if (key == 'a' || key == 'A')
            {
                recording.push_back(
                    {timestamp, Action::GAUCHE});

                executeAction(Action::GAUCHE);
            }
            else if (key == 'd' || key == 'D')
            {
                recording.push_back(
                    {timestamp, Action::DROITE});

                executeAction(Action::DROITE);
            }
            else if (key == ' ')
            {
                recording.push_back(
                    {timestamp, Action::SAUT});

                executeAction(Action::SAUT);
            }
            else if (key == 'f' || key == 'F')
            {
                recording.push_back(
                    {timestamp, Action::TIR});

                executeAction(Action::TIR);
            }
        }

        this_thread::sleep_for(milliseconds(10));
    }

    saveRecording(recording);

    cout << endl;
    cout << "=== ENREGISTREMENT TERMINE ===" << endl;
    cout << recording.size()
         << " actions ont ete enregistrees." << endl;

    cout << "Les actions ont ete sauvegardees dans recording.txt"
         << endl;
}

void replayActions()
{
    vector<RecordedAction> recording = loadRecording();

    cout << endl;
    cout << "=== RELECTURE ===" << endl;
    cout << "Aucune touche n'est necessaire." << endl;
    cout << recording.size()
         << " actions vont etre rejouees." << endl;
    cout << endl;

    if (recording.empty())
    {
        cout << "Aucune action a rejouer." << endl;
        return;
    }

    auto replayStart = steady_clock::now();

    for (const auto &event : recording)
    {
        while (duration_cast<milliseconds>(
                   steady_clock::now() - replayStart)
                   .count() < event.timestamp)
        {
            this_thread::sleep_for(milliseconds(1));
        }

        executeAction(event.action);
    }

    cout << endl;
    cout << "=== RELECTURE TERMINEE ===" << endl;
}

int main()
{
    recordActions();

    cout << endl;
    cout << "Appuyez sur Entree pour commencer la relecture..."
         << endl;

    cin.ignore();
    cin.get();

    replayActions();

    return 0;
}
```

Ces actions représentent les intentions du programme. Elles ne dépendent pas directement d'une touche particulière du clavier.

 * Enregistrement des actions
Pendant l'enregistrement, j'ai utilisé les touches suivantes :
```
A       -> GAUCHE
D       -> DROITE
ESPACE  -> SAUT
F       -> TIR
```

Chaque fois qu'une touche correspondant à une action est utilisée, je récupère le temps écoulé depuis le début de l'enregistrement.

* J'ai utilisé une structure pour enregistrer l'action et son horodatage :
```
struct RecordedAction
{
    long long timestamp;
    Action action;
};
```

* Par exemple, un enregistrement peut contenir :
```
1250 DROITE
2430 SAUT
3810 TIR
5200 GAUCHE
```

Le premier nombre correspond au temps écoulé en millisecondes depuis le début de l'enregistrement.
L'enregistrement dure une minute. Toutes les actions effectuées pendant cette période sont ajoutées dans une liste.

* Sauvegarde
Une fois la minute terminée, les actions enregistrées sont sauvegardées dans un fichier appelé :
```
recording.txt
```

Le fichier contient donc les actions ainsi que leur horodatage.
Cela permet de conserver exactement la séquence d'actions effectuée pendant l'utilisation du programme.

* Relecture
Après l'enregistrement, le programme charge le fichier recording.txt.
Il récupère chaque action ainsi que son horodatage.
Le programme attend ensuite le temps correspondant avant d'exécuter l'action.
Par exemple, si une action SAUT a été enregistrée à 2430 ms, le programme attend environ 2430 ms avant de déclencher cette action pendant la relecture.
Pendant cette étape, je ne touche plus au clavier.
Les actions sont directement envoyées aux règles du programme.

* Vérification

J'ai d'abord utilisé le programme normalement avec le clavier.
Les touches ont déclenché les actions suivantes :
```
A       -> GAUCHE
D       -> DROITE
ESPACE  -> SAUT
F       -> TIR
```

J'ai ensuite lancé la relecture de l'enregistrement.
Cette fois, aucune touche n'a été utilisée. Le programme a automatiquement rejoué les mêmes actions dans le même ordre et avec les mêmes temps.
Le comportement obtenu pendant la relecture correspond donc au comportement obtenu pendant l'enregistrement.

*  Ce que montre l'expérience

Cette expérience montre que les règles du programme ne dépendent plus directement du matériel.

Le clavier sert uniquement à produire les actions pendant l'enregistrement :

```
Clavier
   
Actions
   
Règles du programme
```

* Pendant la relecture, le clavier est remplacé par l'enregistrement :

```
Enregistrement
   
Actions
   
Règles du programme
```
Dans les deux cas, les règles reçoivent les mêmes actions.
Cela montre que le programme peut fonctionner indépendamment du périphérique qui a produit l'action.

* resultat tester:
```
=== ENREGISTREMENT ===
Pendant 60 secondes :
A = gauche
D = droite
ESPACE = saut
F = tir

L'enregistrement commence...
Action : le personnage va a gauche
Action : le personnage va a droite
Action : le personnage saute
Action : le personnage tire
Action : le personnage tire
Action : le personnage va a droite

=== ENREGISTREMENT TERMINE ===
6 actions ont ete enregistrees.
Les actions ont ete sauvegardees dans recording.txt

Appuyez sur Entree pour commencer la relecture...

 

=== RELECTURE ===
Aucune touche n'est necessaire.
6 actions vont etre rejouees.

Action : le personnage va a gauche
Action : le personnage va a droite
Action : le personnage saute
Action : le personnage tire
Action : le personnage tire
Action : le personnage va a droite

=== RELECTURE TERMINEE ===
```

Le programme a belle et bien lancer un compte a rebour de 60 secondes ou je devais choisir 6 actions avec le clavier dans cette section:
```
=== ENREGISTREMENT ===
Pendant 60 secondes :
A = gauche
D = droite
ESPACE = saut
F = tir

L'enregistrement commence...
Action : le personnage va a gauche
Action : le personnage va a droite
Action : le personnage saute
Action : le personnage tire
Action : le personnage tire
Action : le personnage va a droite
```
puis il a enregistre mes actions dans cette section apres les 60 secondes et a relancer automatiquement:
```
=== ENREGISTREMENT TERMINE ===
6 actions ont ete enregistrees.
Les actions ont ete sauvegardees dans recording.txt

Appuyez sur Entree pour commencer la relecture...

```

*  Conclusion:
***

Cet exercice m'a permis de comprendre l'intérêt de séparer les entrées matérielles des règles du programme. J'ai enregistré les actions effectuées pendant une minute avec leur horodatage, puis je les ai rejouées automatiquement sans utiliser le clavier.
Le fait que la relecture produise le même comportement montre que les règles utilisent les actions et non directement le matériel. Cela permet donc de remplacer le clavier ou un autre périphérique par une source d'actions enregistrées.
