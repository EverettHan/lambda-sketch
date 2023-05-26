#ifndef CATModifyMatrix_h
#define CATModifyMatrix_h

#include "SceneGraphManager.h"
#include "CATModifyGeometry.h"
#include "CAT4x4Matrix.h"
#include "CAT3x3Matrix.h"

//
// CATIA Version 5 Release 1 Framework Visualization
// Copyright Dassault Systemes 1996
//------------------------------------------------------------------------------
// Abstract :   used to notify a positionnement modification of an element
//              
//              
//------------------------------------------------------------------------------
// Usage :      these objects are created by model objects, and dispatch by
//              "container". They are supposed to show the evolution of the
//              state of a model. 
//              This family of events is not model dependant. (i.e. the kind
//              of generic operation on "models" is not model type dependant)
//              Only the identification of the model object on which the 
//              operation occured is model dependant.
//              
//------------------------------------------------------------------------------
// Main methods :
//              IsAKindOf(const char *) : 
//
//------------------------------------------------------------------------------
// Class :      CATModifyMatrix
//                 CATModify
//------------------------------------------------------------------------------



class ExportedBySceneGraphManager CATModifyMatrix : public CATModifyGeometry
{
  CATDeclareClass;

  public:

    //   for a 3D modification
    //   matrix contains a [3][3] composant and a translation composant.
    //   a11 a12 a13 t1
    //   a21 a22 a23 t2
    //   a31 a32 a33 t3
    //   0   0   0   1

    //   for a 2D modification
    //   matrix contains a [2][2] composant and a translation composant.
    //   a11 a12 t1 x
    //   a21 a22 t2 x
    //   0   0   1  x
    //   x   x   x  x
  

    CATModifyMatrix(void *modelId, const float matrix[4][4], int iRelativeMode = 0 );
    CATModifyMatrix(void *modelId, const double matrixd[4][4], int iRelativeMode = 0);
    virtual ~CATModifyMatrix();
    
    const float** GetMatrix() const; // To be deprecated
    const void GetMatrix(float[16]) const;
    const void GetMatrix(double[16]) const;
    CAT4x4Matrix Get4x4Matrix() const;
    CAT3x3Matrix Get3x3Matrix() const;

    // clone the notification
    virtual CATModelNotification* Clone ();

    const int IsRelativeMode () const;


  protected:
    float _matrix[4][4]; // NHD Now we pass to doubles all the time, we will comment this line shortly
    double _matrixD[4][4];

    int _RelativeMode;  // 0 to set the new matrix, 1 to multiply the new matrix by the actual
    
};

#endif
