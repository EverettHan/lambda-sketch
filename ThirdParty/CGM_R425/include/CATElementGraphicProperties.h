#ifndef CATElementGraphicProperties_H
#define CATElementGraphicProperties_H

//********************************************************************
// CATIA Version 5 Release 1 Framework CATIAModelVisu
// Copyright Dassault Systemes 1997
//********************************************************************
//
//  Abstract:
//  ---------
//    This implement CATIGraphicProperties on V4 element and on CATSpecObject
//    
//
//********************************************************************
//
//  Usage:  used for show and noshow command
//  ------ 
//
//********************************************************************
//
//  Inheritance:
//  ------------
//                CATElementGraphicProperties
//                  CATBaseUnknown (SYSTEM framework) 
//
//********************************************************************
//
//  Main Methods:
//  -------------
//
//********************************************************************
#include "CATBaseUnknown.h"
#include "CATExtIVisProperties.h"

#include "CATModelGraphicAttribut.h"
#include "CATIPointGraphicProperties.h"
#include "CATILineicGraphicProperties.h"
#include "CATIEdgeGraphicProperties.h"
#include "CATIMeshGraphicProperties.h"
#include "CATIAsmGraphicProperties.h"

#include "list.h"
#include "CATGraphicProperties.h"

class ExportedByCATGraphicProperties  CATElementGraphicProperties: public CATExtIVisProperties
{
  CATDeclareClass;
  
public:
    
  // Construction and destruction:
  // -----------------------------
    
  CATElementGraphicProperties();
  virtual ~CATElementGraphicProperties();
    
    
  // Other methods:
  // --------------

  virtual void SetColor     (int red, int green, int blue);
  virtual int  GetColor     (int &red, int &green, int &blue);
  virtual void ResetColor   ();

  virtual void SetOpacity   (int coeff);
  virtual int  GetOpacity   ();

  virtual void SetLineType  (int linetype);
  virtual int  GetLineType  ();

  virtual void SetThickness (int thickness);
  virtual int  GetThickness ();

  virtual void SetPointType (int pointtype);
  virtual int  GetPointType ();

  virtual void SetShowMode  (CATShowMode showmode);
  virtual CATShowMode  GetShowMode ();

  virtual void SetPickMode  (CATPickMode pickmode);
  virtual CATPickMode  GetPickMode ();

 
  virtual list<IID> *GetVisuInterface();
  virtual void SetVisuInterface(IID * iid);
  virtual void AddVisuInterface(IID * iid);
  virtual void RemVisuInterface(IID * iid);

  virtual void SetVisualizationMode(int mode);
  virtual int  GetVisualizationMode();

  virtual void SetIsoparsNumberInU(int number);
  virtual int  GetIsoparsNumberInU();

  virtual void SetIsoparsNumberInV(int number);
  virtual int  GetIsoparsNumberInV();

protected:

  void SendNotif();
  
  list<IID > *_IIDList;

private:
  CATModelGraphicAttribut _attribut;

};

#endif //CATElementGraphicProperties_H
