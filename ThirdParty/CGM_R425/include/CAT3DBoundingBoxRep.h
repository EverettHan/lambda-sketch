#ifndef CAT3DBoundingBoxRep_H
#define CAT3DBoundingBoxRep_H

//******************************************************************************
// CATIA Version 5 Release 1 Framework VISUALIZATION
// Copyright Dassault Systemes 1996
//******************************************************************************
//  Abstract:
//  ---------
//******************************************************************************
//  Usage:
//  ------
//
//******************************************************************************
//  Inheritance:
//  ------------
//                CAT3DBoundingBoxRep
//                  CAT3DBagRep
//                    CAT3DRep
//                      CATRep
//                        CATExtend (SYSTEM Framework).
//
//******************************************************************************
//  Main Methods:
//  -------------
//    
//
//******************************************************************************
 
#include "SGInfra.h"
#include "CAT3DFinalBagRep.h"
#include "CAT3DCustomRep.h"
#include "CAT3DBoundingSphere.h"
#include "CATRepPath.h"



class ExportedBySGInfra CAT3DBoundingBoxRep : public CAT3DFinalBagRep
{
  // Marshalling information:
  // ------------------------
  friend class CATMarshallable3DBagRep;
  friend class CATVrmlMaker3DBagRep;
  friend class CATVrml2Maker3DBagRep;
 

  CATDeclareClass;
  
public:
  // Constructors
  static CAT3DBoundingBoxRep* CreateRep();
  static CAT3DBoundingBoxRep* CreateRep(CAT3DRep *rep,CATRepPath *path=NULL);
  static CAT3DBoundingBoxRep* CreateRep(CAT3DBoundingSphere *sphere);

protected:

  /** @deprecated R417 : Use CreateRep instead.*/
  CAT3DBoundingBoxRep();
  /** @deprecated R417 : Use CreateRep instead.*/
  CAT3DBoundingBoxRep(CAT3DRep *rep,CATRepPath *path=NULL);
  /** @deprecated R417 : Use CreateRep instead.*/
  CAT3DBoundingBoxRep(CAT3DBoundingSphere *sphere);
  
  //Destructors
  ~CAT3DBoundingBoxRep();

public:

  CAT3DRep *GetEnclosedRep();
  

  // Create the rep of the bounding box
  // input: 'width' : length along x-axis
  //        'height' : length along y-axis
  //        'depth' : length along z-axis
  void CreateBox(CATMathPointf &center,float width,float height, float depth);

  virtual void Destroy();

private :

  // the rep holding edges    
  CAT3DCustomRep *_Box;
  // the enclosed rep
  CAT3DRep *_EnclosedRep;
 
};



#endif
