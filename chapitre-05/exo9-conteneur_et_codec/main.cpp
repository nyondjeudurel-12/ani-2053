#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Piste {
    string type;
    string code;
};

struct Fichier {
    string nom;
    string octets;
    vector<Piste> pistes;
    string conteneur;
};

string reconnaitreConteneur(const string& octets) {
    int n = static_cast<int>(octets.size() / 2);

    if (n >= 12 && octets.substr(8, 8) == "66747970")
        return "MP4";

    if (n >= 4 && octets.substr(0, 8) == "1A45DFA3")
        return "WEBM";

    if (n >= 12 &&
        octets.substr(0, 8) == "52494646" &&
        octets.substr(16, 8) == "57415645")
        return "WAV";

    if (n >= 4 && octets.substr(0, 8) == "4F676753")
        return "OGG";

    if (n >= 4 && octets.substr(0, 8) == "664C6143")
        return "FLAC";

    if (n >= 3 && octets.substr(0, 6) == "494433")
        return "MP3";

    if (n >= 2 &&
        octets.substr(0, 2) == "FF" &&
        stoi(octets.substr(2, 2), nullptr, 16) >= 224)
        return "MP3";

    return "INCONNU";
}

string nomCodec(const string& code) {
    if (code == "mp4a") return "aac";
    if (code == "Opus" || code == "opus") return "opus";
    if (code == "avc1" || code == "avc3") return "h264";
    if (code == "hvc1" || code == "hev1") return "h265";
    if (code == "vp08") return "vp8";
    if (code == "vp09") return "vp9";
    if (code == "mp4v") return "mpeg4";
    if (code == ".mp3") return "mp3";
    if (code == "twos" || code == "sowt" || code == "lpcm")
        return "pcm";

    return code;
}

bool codecLisible(const string& code) {
    return code == "mjpa" ||
           code == "jpeg" ||
           code == "MJPG" ||
           code == "avc1" ||
           code == "avc3" ||
           code == "hvc1" ||
           code == "hev1" ||
           code == "av01";
}

int main() {
    int N;
    cin >> N;

    int nombreMP4 = 0;
    int nombreLisibles = 0;
    int nombreInconnus = 0;

    for (int i = 0; i < N; ++i) {
        Fichier fichier;
        int P;

        cin >> fichier.nom >> fichier.octets >> P;

        if (fichier.octets == "-")
            fichier.octets = "";

        for (int j = 0; j < P; ++j) {
            Piste piste;
            cin >> piste.type >> piste.code;
            fichier.pistes.push_back(piste);
        }

        fichier.conteneur = reconnaitreConteneur(fichier.octets);

        cout << fichier.nom << " " << fichier.conteneur << '\n';

        if (fichier.conteneur == "MP4") {
            ++nombreMP4;

            bool premierePisteVideoTrouvee = false;
            string verdict = "SANS_IMAGE";

            for (int j = 0; j < static_cast<int>(fichier.pistes.size()); ++j) {
                const Piste& piste = fichier.pistes[j];

                string type = piste.type == "vide" ? "VIDEO" : "AUDIO";

                cout << fichier.nom << " PISTE " << j + 1 << " "
                     << type << " " << nomCodec(piste.code) << '\n';

                if (piste.type == "vide" && !premierePisteVideoTrouvee) {
                    premierePisteVideoTrouvee = true;

                    if (codecLisible(piste.code))
                        verdict = "LISIBLE";
                    else
                        verdict = "ECHEC";
                }
            }

            cout << fichier.nom << " LECTEUR " << verdict << '\n';

            if (verdict == "LISIBLE")
                ++nombreLisibles;
        }

        if (fichier.conteneur == "INCONNU")
            ++nombreInconnus;
    }

    cout << "MP4 " << nombreMP4 << '\n';
    cout << "LISIBLES " << nombreLisibles << '\n';
    cout << "INCONNUS " << nombreInconnus << '\n';

    return 0;
}