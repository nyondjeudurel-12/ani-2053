#include <iostream>
#include <iomanip>
#include <NKWindow/Core/NkMain.h>
#include <NKCanvas/App/NkCanvasApp.h>
#include <NKCanvas/Renderer/Core/NkTransformable.h>
#include <NKCanvas/Renderer/Core/NkDrawable.h>
#include <NKCanvas/Renderer/Core/NkRenderStates.h>
#include <NKCanvas/Renderer/Targets/NkRenderTarget.h>
#include <NKCanvas/Renderer/Resources/NkSprite.h>
#include <NKCanvas/Renderer/Resources/NkTexture.h>

using namespace nkentseu;
using namespace nkentseu::renderer;

// 1. COMPOSITE : un objet qui contient un autre objet dessinable

class Composite : public NkTransformable, public NkDrawable
{
private:
    // Pointeur vers l'enfant.
    NkDrawable* mChild = nullptr;

public:
    // Définit l'enfant du composite.
    void SetChild(NkDrawable* child)
    {
        mChild = child;
    }

    // Transmet les transformations au niveau inférieur.
    void Draw(NkRenderTarget& target,
              const NkRenderStates& states) const override
    {
        if (mChild == nullptr)
            return;

        // Copie les états reçus.
        NkRenderStates local = states;

        // Ajoute la transformation de cet objet.
        local.transform *= GetTransform();

        // Dessine l'enfant avec les nouveaux états.
        target.Draw(*mChild, local);
    }
};

// 2. PROBE : mesure la position finale de l'origine


class Probe : public NkTransformable, public NkDrawable
{
private:
    NkVec2f* mResult = nullptr;

public:
    explicit Probe(NkVec2f* result)
        : mResult(result)
    {
    }

    void Draw(NkRenderTarget& target,
              const NkRenderStates& states) const override
    {
        (void)target;

        // Copie les états reçus.
        NkRenderStates local = states;

        // Compose la transformation avec celle du parent.
        local.transform *= GetTransform();

        // Transforme l'origine pour obtenir sa position finale.
        if (mResult != nullptr)
        {
            *mResult = local.transform.TransformPoint(
                NkVec2f{0.f, 0.f}
            );
        }
    }
};


// 3. BROKEN PROBE : reproduit l'ancien défaut


class BrokenProbe : public NkTransformable, public NkDrawable
{
private:
    NkVec2f* mResult = nullptr;

public:
    explicit BrokenProbe(NkVec2f* result)
        : mResult(result)
    {
    }

    void Draw(NkRenderTarget& target,
              const NkRenderStates& states) const override
    {
        (void)target;
        (void)states;

        // ERREUR volontaire :
        // On ignore complètement les transformations des parents.
        NkRenderStates local;

        // On conserve uniquement la transformation personnelle.
        local.transform = GetTransform();

        // On mesure la position obtenue avec cette transformation.
        if (mResult != nullptr)
        {
            *mResult = local.transform.TransformPoint(
                NkVec2f{0.f, 0.f}
            );
        }
    }
};


// 4. APPLICATION PRINCIPALE


class CompositeApp : public NkCanvasApp
{
private:

    // Texture et sprite utilisés pour la partie visuelle.
    NkTexture mTexture;
    NkSprite mSprite;

    // Hiérarchie visuelle :
    // Parent -> Milieu -> Sprite.
    Composite mParent;
    Composite mMiddle;

    // Hiérarchie de mesure correcte.
    Composite mProbeParent;
    Composite mProbeMiddle;
    Probe mProbe;

    // Hiérarchie qui reproduit le défaut.
    Composite mBrokenParent;
    Composite mBrokenMiddle;
    BrokenProbe mBrokenProbe;

    // Positions mesurées.
    NkVec2f mGoodResult{0.f, 0.f};
    NkVec2f mBrokenResult{0.f, 0.f};

    // Évite d'afficher les résultats à chaque image.
    bool mPrinted = false;

public:

    CompositeApp()
        : mProbe(&mGoodResult),
          mBrokenProbe(&mBrokenResult)
    {
    }

    
    // Initialisation
   

    bool OnInit() override
    {
        // Création d'une texture jaune de 32 x 32 pixels.
        if (!mTexture.Create(
                *Target().GetRenderer(),
                32,
                32,
                NkColor2D{255, 200, 0, 255}))
        {
            std::cerr << "Erreur : impossible de creer la texture."
                      << std::endl;
            return false;
        }

        // Affectation de la texture au sprite.
        mSprite.SetTexture(mTexture);

       
        // Hiérarchie visuelle : Parent -> Milieu -> Sprite
       

        // Position du premier niveau.
        mParent.SetPosition(100.f, 80.f);

        // Position et rotation du deuxième niveau.
        mMiddle.SetPosition(40.f, 20.f);
        mMiddle.SetRotation(math::NkAngle(90.f));

        // Position du sprite, troisième niveau.
        mSprite.SetPosition(10.f, 5.f);

        // Construction de la hiérarchie.
        mMiddle.SetChild(&mSprite);
        mParent.SetChild(&mMiddle);

        // Hiérarchie de mesure correcte

        mProbeParent.SetPosition(100.f, 80.f);

        mProbeMiddle.SetPosition(40.f, 20.f);
        mProbeMiddle.SetRotation(math::NkAngle(90.f));

        mProbe.SetPosition(10.f, 5.f);

        mProbeMiddle.SetChild(&mProbe);
        mProbeParent.SetChild(&mProbeMiddle);

        // Hiérarchie avec le défaut volontaire
      

        mBrokenParent.SetPosition(100.f, 80.f);

        mBrokenMiddle.SetPosition(40.f, 20.f);
        mBrokenMiddle.SetRotation(math::NkAngle(90.f));

        mBrokenProbe.SetPosition(10.f, 5.f);

        mBrokenMiddle.SetChild(&mBrokenProbe);
        mBrokenParent.SetChild(&mBrokenMiddle);

        return true;
    }

    // Affichage
   

    void OnRender(NkRenderWindow& target) override
    {
        // Nettoyage de la fenêtre.
        target.Clear(NkColor2D{18, 18, 24, 255});

        // Dessin de la hiérarchie visuelle.
        target.Draw(mParent);

        // Exécution des deux mesures.
        target.Draw(mProbeParent);
        target.Draw(mBrokenParent);

        // Affichage des résultats une seule fois.
        if (!mPrinted)
        {
            mPrinted = true;

            std::cout << std::fixed << std::setprecision(2);

            std::cout << "\n====================================\n";
            std::cout << "   EXERCICE 8 : LE COMPOSITE\n";
            std::cout << "====================================\n";

            std::cout << "\nLa hiérarchie :\n";
            std::cout << "Parent -> Milieu -> Sprite\n";

            std::cout << "\nAttendu :\n";
            std::cout << "(135.00, 110.00)\n";

            std::cout << "\nMesuré :\n";
            std::cout << "Probe correct : ("
                      << mGoodResult.x << ", "
                      << mGoodResult.y << ")\n";

            std::cout << "\nLe défaut :\n";
            std::cout << "Probe défectueux : ("
                      << mBrokenResult.x << ", "
                      << mBrokenResult.y << ")\n";

            std::cout << "====================================\n";
        }
    }
};

// 5. POINT D'ENTRÉE DE L'APPLICATION


int nkmain(const NkEntryState& state)
{
    return NkCanvasApp::Run<CompositeApp>(state);
}