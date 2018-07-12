#include "animatorOperations.h"

#include "GUI/qtUtils.h"
#include "animation/animator.h"
#include "common/importFiles.h"
#include "common/exportFiles.h"
#include "drawables/drawableCage.h"
#include "skinning/cageSkinning.h"
#include "GUI/glCanvas.h"
#include "GUI/mainWindow.h"
#include "controller.h"
#include <QInputDialog>
#include <vector>


void initializeAnimator()
{
   Controller * c = Controller::get();

   if(c->isCageLoaded)
   {

      Animator * animator = new Animator(c->cage);
      c->animator = animator;

      //animator->populateKeyframesDebug((c->cage->getNumVertices())*3);
      c->isAnimatorInitialized = true;

   }
}


void loadAnimationFromFile()
{

   std::string filename;
   Controller * c = Controller::get();

   if (openFileSelectionDialog(filename, "Load Animation", "Text File (*.txt)"))
   {
      if(c->isAnimatorInitialized)
      {

         std::cout << "Loading animation: " << filename << std::endl;

         std::vector<double> t;
         std::vector<std::vector<double>> cageKeyframes;

         loadAnimation(filename.c_str(),
                       t,
                       cageKeyframes);

         c->animator->loadAnimation(t,cageKeyframes);
      }
   }
}

void saveAnimationToFile()
{

   std::string filename;
   Controller * c = Controller::get();

   if (openFileSaveDialog(filename, "Save Animation", "Text File (*.txt)"))
   {
      if(c->isAnimatorInitialized)
      {
         saveAnimation(filename.c_str(),
                       c->animator->getKeyframeTime(),
                       c->animator->getCageKeyframes());
      }
   }
}

void setNextKeyframe()
{
   Controller * c = Controller::get();

   if(c->isAnimatorInitialized)
   {
      c->animator->setNextPose();

      if(c->isCageSkinningInitialized)
      {
         c->cageSkinning->deform();
         c->cage->updateNormals();
      }

      c->glCanvas->refreshScene();
   }
}

void addKeyframe()
{
   Controller * c = Controller::get();
   if(c->isCageSkinningInitialized)
   {

      bool ok;
      double t = QInputDialog::getDouble(c->mainWindow, "Keyframe time (in seconds)",
                                        "Second: ", 0, 0, 2147483647, 1, &ok);
      if (ok && t>0)
      {

         const std::vector<double> & restCage = c->cage->getRestPoseVerticesVector();
         const std::vector<double> & actualCage = c->cage->getVerticesVector();
         std::vector<double> offsets(restCage.size());
         for(int i=0; i<restCage.size(); ++i)
         {
            offsets[i] = actualCage[i] - restCage[i];
         }

         c->animator->addKeyframe(t, offsets);
      }
   }
}
