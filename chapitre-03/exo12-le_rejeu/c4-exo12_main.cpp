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