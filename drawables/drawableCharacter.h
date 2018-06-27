#ifndef DRAWABLECHARACTER_H
#define DRAWABLECHARACTER_H

#include "drawables/drawableObject.h"
#include "geom/character.h"

class DrawableCharacter
      : public Character,
        public DrawableObject
{
public:

   enum
   {
      DRAW_TRIMESH          = 0x00000001,
      DRAW_VERTICES         = 0x00000002,
      DRAW_FLAT             = 0x00000004,
      DRAW_SMOOTH           = 0x00000008,
      DRAW_WIREFRAME        = 0x00000010,
      DRAW_TEXTURE1D        = 0x00000020
   };

   DrawableCharacter();
   DrawableCharacter(const std::vector<double>   & vertices ,
                     const std::vector<int>      & tris   );

   ~DrawableCharacter();

   void init();
   void clear();

   //DrawableObject interface
   void draw()                             const;
   void drawRest()                         const;
   bool sceneCenter(cg3::Vec3d & center)   const;
   bool sceneRadius(double & radius)       const;

   //Rendering settings
   void activateCharacterRendering(bool activate);

   void activateSmoothColouration();
   void activateFlatColouration();
   void activateWireframe();
   void activateTexture1D();

   void updateTexture1D(std::vector<float> _textureScalars);

protected:

   int drawMode;

   unsigned int texture_id;
   std::vector<float> textureScalars;

};

#endif // DRAWABLECHARACTER_H
