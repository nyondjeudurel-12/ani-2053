#include <NKCanvas/App/NkCanvasApp.h>
#include <NKCanvas/Renderer/Core/NkIRenderer2D.h>
#include <NKImage/NKImage.h>
#include <NKThreading/NkPromise.h>
#include <NKThreading/NkThreadPool.h>
#include <NKThreading/NkFuture.h>
#include <NKTime/NkChrono.h>
#include <NKWindow/Core/NkMain.h>

#include <iostream>
#include <fstream>
#include <string>

using namespace nkentseu;
using namespace nkentseu::renderer;

// true : mode non bloquant IsReady()
// false : mode bloquant Get()
constexpr bool UTILISER_ISREADY = false;

// Chemin de l'image à charger.
constexpr const char* CHEMIN_IMAGE = "D:\\image.jpg";

// Fichier dans lequel enregistrer les mesures.
constexpr const char* FICHIER_RESULTATS = "cadence.txt";

class ApplicationFutur : public NkCanvasApp
{
private:
    // Un fil secondaire pour charger l'image.
    nkentseu::threading::NkThreadPool pool{1};

    // La promesse transmet l'image au fil principal.
    NkPromise<NkImage> promesse;
    NkFuture<NkImage> futur = promesse.GetFuture();

    // Chronomètre du chargement de l'image.
    NkChrono chronoImage;

    // Position du carré.
    float32 positionX = 0.0f;
    float32 positionY = 100.0f;

    // Compteurs de mises à jour.
    uint64 nombreImages = 0;
    uint64 imagesPendantChargement = 0;

    // Mesures en millisecondes.
    float64 dureeChargementMs = 0.0;
    float64 plusLongueMiseAJourMs = 0.0;

    // États du chargement.
    bool chargementDemarre = false;
    bool chargementTermine = false;
    bool imageValide = false;

    // Démarre le chargement dans le fil secondaire.
    void DemarrerChargement()
    {
        if (chargementDemarre)
            return;

        chargementDemarre = true;

        // Le chronomètre démarre juste avant le chargement.
        (void)chronoImage.Reset();

        pool.Enqueue([this]()
        {
            NkImage img;

            // Charge l'image depuis le disque.
            if (img.Load(CHEMIN_IMAGE))
            {
                promesse.SetValue(nkentseu::traits::NkMove(img));
            }
            else
            {
                // Transmet une image vide en cas d'échec.
                promesse.SetValue(NkImage{});
            }
        });

        if (!UTILISER_ISREADY)
        {
            // Get() attend ici la fin du chargement.
            const NkImage& resultat = futur.Get();

            // Mesure le temps écoulé jusqu'à la réception du résultat.
            dureeChargementMs =
                chronoImage.Elapsed().ToMilliseconds();

            imageValide = resultat.IsValid();
            chargementTermine = true;

            std::cout << "Chargement termine (version Get)." << std::endl;
            std::cout << "Image valide : "
                      << (imageValide ? "oui" : "non")
                      << std::endl;
        }
    }

public:
    bool OnInit() override
    {
        // Affiche le mode sélectionné.
        std::cout << "Application demarree." << std::endl;

        std::cout << "Mode utilise : "
                  << (UTILISER_ISREADY ? "IsReady" : "Get")
                  << std::endl;

        return true;
    }

    void OnUpdate(float32 deltaTime) override
    {
        // Mesure la durée de cette mise à jour.
        NkChrono chronoFrame;

        // Déplace le carré d'un pixel à chaque mise à jour.
        positionX += 1.0f;
        ++nombreImages;

        // Démarre le chargement après 60 mises à jour.
        if (nombreImages == 60)
        {
            DemarrerChargement();
        }

        // Vérifie si le chargement est toujours en cours.
        if (chargementDemarre && !chargementTermine)
        {
            if (UTILISER_ISREADY)
            {
                // IsReady() vérifie le résultat sans attendre.
                if (futur.IsReady())
                {
                    const NkImage& resultat = futur.Get();

                    // Mesure la durée totale du chargement.
                    dureeChargementMs =
                        chronoImage.Elapsed().ToMilliseconds();

                    imageValide = resultat.IsValid();
                    chargementTermine = true;

                    std::cout
                        << "Chargement termine (version IsReady)."
                        << std::endl;

                    std::cout << "Image valide : "
                              << (imageValide ? "oui" : "non")
                              << std::endl;
                }
                else
                {
                    // Compte les mises à jour pendant l'attente.
                    ++imagesPendantChargement;
                }
            }
        }

        // Mesure la durée de la mise à jour, attente Get() comprise.
        const float64 duree =
            chronoFrame.Elapsed().ToMilliseconds();

        if (duree > plusLongueMiseAJourMs)
        {
            plusLongueMiseAJourMs = duree;
        }

        (void)deltaTime;
    }

    void OnRender(NkRenderWindow& target) override
    {
        // Efface l'écran.
        target.Clear(NkColor2D::Black);

        // Récupère le renderer 2D.
        auto& renderer = target.GetRenderer2D();

        // Dessine un carré blanc de 40 x 40 pixels.
        renderer.DrawFilledRect(
            NkRect2f{positionX, positionY, 40.0f, 40.0f},
            NkColor2D::White
        );

        // Présente le rendu à l'écran.
        target.Display();
    }

    void OnShutdown() override
    {
        // Attend la fin du travail du fil secondaire.
        pool.Join();

        // Affiche les résultats dans la console.
        std::cout << "\n===== RESULTATS =====" << std::endl;

        std::cout << "Mode : "
                  << (UTILISER_ISREADY ? "IsReady" : "Get")
                  << std::endl;

        std::cout << "Image valide : "
                  << (imageValide ? "oui" : "non")
                  << std::endl;

        std::cout << "Duree de chargement (ms) : "
                  << dureeChargementMs
                  << std::endl;

        std::cout << "Nombre de mises a jour : "
                  << nombreImages
                  << std::endl;

        std::cout << "Mises a jour pendant le chargement : "
                  << imagesPendantChargement
                  << std::endl;

        std::cout << "Plus longue mise a jour (ms) : "
                  << plusLongueMiseAJourMs
                  << std::endl;

        // Ajoute les mesures au fichier pour conserver les deux tests.
        std::ofstream fichier(
            FICHIER_RESULTATS,
            std::ios::app
        );

        if (fichier.is_open())
        {
            fichier << "\n";

            fichier << "Image : " << CHEMIN_IMAGE << "\n\n";

            fichier << (UTILISER_ISREADY ? "IsReady :" : "Get :")
                    << "\n";

            fichier << "Duree de chargement : "
                    << dureeChargementMs << " ms\n";

            fichier << "Plus longue trame mesuree : "
                    << plusLongueMiseAJourMs << " ms\n";

            fichier << "Nombre de trames pendant le chargement : "
                    << imagesPendantChargement << "\n";

            fichier << "Nombre total de mises a jour : "
                    << nombreImages << "\n";

            fichier << "Image valide : "
                    << (imageValide ? "oui" : "non")
                    << "\n";

            fichier.close();

            std::cout << "Resultats ajoutes a "
                      << FICHIER_RESULTATS
                      << std::endl;
        }
        else
        {
            std::cerr << "Erreur : impossible d'ouvrir "
                      << FICHIER_RESULTATS
                      << std::endl;
        }
    }
};

int nkmain(const NkEntryState& state)
{
    ApplicationFutur app;
    return app.Run<ApplicationFutur>(state);
}

