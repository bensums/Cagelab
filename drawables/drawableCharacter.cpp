#include "drawableCharacter.h"

#ifdef __APPLE__
#include <gl.h>
#else
#include <GL/gl.h>
#endif

#include "common/texture.h"

DrawableCharacter::DrawableCharacter()
   : Character()
{
   init();
}

DrawableCharacter::DrawableCharacter(const std::vector<double> & vertices  ,
                                     const std::vector<int>    & tris      )
   : Character(vertices, tris)
{
   init();
}

DrawableCharacter::~DrawableCharacter()
{

}

void DrawableCharacter::init()
{
   type           = TRIMESH;
   drawMode       = DRAW_TRIMESH | DRAW_SMOOTH;

   texture_id = 0;
}

void DrawableCharacter::clear()
{
   Character::clear();
}

void DrawableCharacter::draw() const
{
   if (drawMode & DRAW_TRIMESH)
   {
      if (drawMode & DRAW_SMOOTH)
      {
         glEnable(GL_LIGHTING);
         glShadeModel(GL_SMOOTH);
         glEnableClientState(GL_VERTEX_ARRAY);
         glVertexPointer(3, GL_DOUBLE, 0, vertices.data());
         glEnableClientState(GL_NORMAL_ARRAY);
         glNormalPointer(GL_DOUBLE, 0, verticesNorm.data());
         glColor3f(0.9,0.9,0.9);
         //glColor3f(0.53,0.60,0.85);
         glDrawElements(GL_TRIANGLES, tris.size(), GL_UNSIGNED_INT, tris.data());
         glDisableClientState(GL_NORMAL_ARRAY);
         glDisableClientState(GL_VERTEX_ARRAY);
      } else
      if (drawMode & DRAW_FLAT)
      {
         glEnable(GL_LIGHTING);
         glShadeModel(GL_FLAT);
         glEnableClientState(GL_VERTEX_ARRAY);
         glVertexPointer(3, GL_DOUBLE, 0, vertices.data());
         glEnableClientState(GL_NORMAL_ARRAY);
         glNormalPointer(GL_DOUBLE, 0, verticesNorm.data());
         glColor3f(1.0,1.0,1.0);
         glDrawElements(GL_TRIANGLES, tris.size(), GL_UNSIGNED_INT, tris.data());
         glDisableClientState(GL_NORMAL_ARRAY);
         glDisableClientState(GL_VERTEX_ARRAY);
      } else
      if (drawMode & DRAW_WIREFRAME)
      {
         glDisable(GL_LIGHTING);
         glShadeModel(GL_FLAT);
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         glLineWidth(0.1);
         glDepthRange(0.0, 1.0);
         glEnableClientState(GL_VERTEX_ARRAY);
         glVertexPointer(3, GL_DOUBLE, 0, vertices.data());
         glColor4f(0.8,0.8,0.8,0.5);
         glDrawElements(GL_TRIANGLES, tris.size(), GL_UNSIGNED_INT, tris.data());
         glDisableClientState(GL_VERTEX_ARRAY);
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      } else
      if (drawMode & DRAW_TEXTURE1D)
      {
         glEnable(GL_LIGHTING);
         glShadeModel(GL_SMOOTH);
         glEnableClientState(GL_VERTEX_ARRAY);
         glVertexPointer(3, GL_DOUBLE, 0, vertices.data());
         glEnableClientState(GL_NORMAL_ARRAY);
         glNormalPointer(GL_DOUBLE, 0, verticesNorm.data());
         glEnable(GL_TEXTURE_1D);
         glEnableClientState(GL_TEXTURE_COORD_ARRAY);
         glTexCoordPointer(1, GL_FLOAT, 0, textureScalars.data());
         glColor3f(1.0,1.0,1.0);
         glDrawElements(GL_TRIANGLES, tris.size(), GL_UNSIGNED_INT, tris.data());
         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
         glDisable(GL_TEXTURE_1D);
         glDisableClientState(GL_NORMAL_ARRAY);
         glDisableClientState(GL_VERTEX_ARRAY);
      }
   }
}

void DrawableCharacter::drawRest() const
{
   if (drawMode & DRAW_TRIMESH)
   {
      if (drawMode & DRAW_SMOOTH)
      {
         glEnable(GL_LIGHTING);
         glShadeModel(GL_SMOOTH);
         glEnableClientState(GL_VERTEX_ARRAY);
         glVertexPointer(3, GL_DOUBLE, 0, restPoseVertices.data());
         glEnableClientState(GL_NORMAL_ARRAY);
         glNormalPointer(GL_DOUBLE, 0, verticesNorm.data());
         glColor3f(0.9,0.9,0.9);
         //glColor3f(0.53,0.60,0.85);
         glDrawElements(GL_TRIANGLES, tris.size(), GL_UNSIGNED_INT, tris.data());
         glDisableClientState(GL_NORMAL_ARRAY);
         glDisableClientState(GL_VERTEX_ARRAY);
      } else
      if (drawMode & DRAW_FLAT)
      {
         glEnable(GL_LIGHTING);
         glShadeModel(GL_FLAT);
         glEnableClientState(GL_VERTEX_ARRAY);
         glVertexPointer(3, GL_DOUBLE, 0, restPoseVertices.data());
         glEnableClientState(GL_NORMAL_ARRAY);
         glNormalPointer(GL_DOUBLE, 0, verticesNorm.data());
         glColor3f(1.0,1.0,1.0);
         glDrawElements(GL_TRIANGLES, tris.size(), GL_UNSIGNED_INT, tris.data());
         glDisableClientState(GL_NORMAL_ARRAY);
         glDisableClientState(GL_VERTEX_ARRAY);
      } else
      if (drawMode & DRAW_WIREFRAME)
      {
         glDisable(GL_LIGHTING);
         glShadeModel(GL_FLAT);
         glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
         glLineWidth(0.1);
         glDepthRange(0.0, 1.0);
         glEnableClientState(GL_VERTEX_ARRAY);
         glVertexPointer(3, GL_DOUBLE, 0, restPoseVertices.data());
         glColor4f(0.8,0.8,0.8,0.5);
         glDrawElements(GL_TRIANGLES, tris.size(), GL_UNSIGNED_INT, tris.data());
         glDisableClientState(GL_VERTEX_ARRAY);
         glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      } else
      if (drawMode & DRAW_TEXTURE1D)
      {
         glEnable(GL_LIGHTING);
         glShadeModel(GL_SMOOTH);
         glEnableClientState(GL_VERTEX_ARRAY);
         glVertexPointer(3, GL_DOUBLE, 0, restPoseVertices.data());
         glEnableClientState(GL_NORMAL_ARRAY);
         glNormalPointer(GL_DOUBLE, 0, verticesNorm.data());
         glEnable(GL_TEXTURE_1D);
         glEnableClientState(GL_TEXTURE_COORD_ARRAY);
         glTexCoordPointer(1, GL_FLOAT, 0, textureScalars.data());
         glColor3f(1.0,1.0,1.0);
         glDrawElements(GL_TRIANGLES, tris.size(), GL_UNSIGNED_INT, tris.data());
         glDisableClientState(GL_TEXTURE_COORD_ARRAY);
         glDisable(GL_TEXTURE_1D);
         glDisableClientState(GL_NORMAL_ARRAY);
         glDisableClientState(GL_VERTEX_ARRAY);
      }
   }
}

bool DrawableCharacter::sceneCenter(cg3::Vec3d & center) const
{
   center = boundingBox.center();
   return true;
}

bool DrawableCharacter::sceneRadius(double & radius) const
{
   radius = boundingBox.diagonal();
   return true;
}

void DrawableCharacter::activateCharacterRendering(bool activate)
{
   if (activate)  drawMode |=  DRAW_TRIMESH;
   else           drawMode &= ~DRAW_TRIMESH;
}

void DrawableCharacter::activateSmoothColouration()
{
   drawMode &= ~DRAW_FLAT;
   drawMode |=  DRAW_SMOOTH;
   drawMode &= ~DRAW_WIREFRAME;
   drawMode &= ~DRAW_TEXTURE1D;
}

void DrawableCharacter::activateFlatColouration()
{
   drawMode |=  DRAW_FLAT;
   drawMode &= ~DRAW_SMOOTH;
   drawMode &= ~DRAW_WIREFRAME;
   drawMode &= ~DRAW_TEXTURE1D;
}

void DrawableCharacter::activateWireframe()
{
   drawMode &= ~DRAW_FLAT;
   drawMode &= ~DRAW_SMOOTH;
   drawMode |=  DRAW_WIREFRAME;
   drawMode &= ~DRAW_TEXTURE1D;
}

void DrawableCharacter::activateTexture1D()
{
   drawMode &= ~DRAW_FLAT;
   drawMode &= ~DRAW_SMOOTH;
   drawMode &= ~DRAW_WIREFRAME;
   drawMode |=  DRAW_TEXTURE1D;
}

void DrawableCharacter::updateTexture1D(std::vector<float> _textureScalars)
{
   textureScalars = _textureScalars;

   if (texture_id > 0)
   {
      glDeleteTextures(1, &texture_id);
   }

   glGenTextures(1, &texture_id);
   glBindTexture(GL_TEXTURE_1D, texture_id);

   glTexImage1D(GL_TEXTURE_1D, 0, GL_RGB, 256, 0, GL_RGB, GL_UNSIGNED_BYTE, texture1D);
   glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_R,     GL_REPEAT);
   //glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_R,     GL_CLAMP_TO_BORDER);
   glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}
