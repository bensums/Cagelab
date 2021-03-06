#ifndef GREENCOORDINATES_H
#define GREENCOORDINATES_H

#include "skinning/weights.h"
#include "geom/character.h"
#include "geom/cage.h"
#include "geom/vec3.h"
#include "skinning/cageSkinning.h"
#include <vector>

class GreenCoordinates:
      public CageSkinning
{
public:
   GreenCoordinates();
   GreenCoordinates(Character   * _character,
                    Cage        * _cage);
   ~GreenCoordinates();

      void deform();
      void deformPartial();

      bool generateCoords(); //cerca di impostarlo come statico



      inline Weights * getWeights();
      inline Weights * getWeightsF();

private:

   Weights * weightsV;
   Weights * weightsF;

   //Utilities methods for the calculation of coords and mesh deformation
   double gcTriInt(const cg3::Vec3d & p,
                   const cg3::Vec3d & t1,
                   const cg3::Vec3d & t2,
                   const cg3::Vec3d & eta);
   void calcScalingFactors();

   //Green cooordinate functions and scaling factors

   std::vector<double>               gcS; //Scaling factors
   std::vector<int>                  exitFaces;
};

#endif // GREENCOORDINATES_H
