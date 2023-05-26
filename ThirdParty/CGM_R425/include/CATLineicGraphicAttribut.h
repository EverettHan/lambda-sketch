#ifndef CATLineicGraphicAttribut_h
#define CATLineicGraphicAttribut_h

//********************************************************************
// CATIA Framework CATIAModelVisu (PPE)
// Copyright Dassault Systemes 1997
//********************************************************************
//
//  Abstract:
//  ---------
//    This defines lineic graphic attribut 
//    
//
//********************************************************************
//
//  Usage: used by object which implement CATILineicGraphicProperties 
//  ------ 
//
//********************************************************************
//
//  Inheritance:
//  ------------
//            CATLineicGraphicAttribut
//              CATLineGraphicAttribut
//                CATBaseUnknown (SYSTEM framework)
//
//********************************************************************
//
//  Main Methods:
//  -------------
//
//********************************************************************
#include "CATVisItf.h"
#include "CATLineGraphicAttribut.h"
#include "CATDataType.h"

class CATILineicGraphicProperties_var;

class ExportedByCATVisItf CATLineicGraphicAttribut : public CATLineGraphicAttribut
{
  CATDeclareClass;

  public:
  ///////
    
    CATLineicGraphicAttribut ();
    CATLineicGraphicAttribut (CATULONG32 value);
    virtual ~CATLineicGraphicAttribut (void) ;

    virtual void SetValue ( CATILineicGraphicProperties_var &value);

    virtual HRESULT MigrateToVisProperties (int iGeomType);

};

#endif
