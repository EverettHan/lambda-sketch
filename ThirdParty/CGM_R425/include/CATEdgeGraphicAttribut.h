#ifndef CATEdgeGraphicAttribut_h
#define CATEdgeGraphicAttribut_h

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
//  Usage: used by object which implement CATIEdgeGraphicProperties 
//  ------ 
//
//********************************************************************
//
//  Inheritance:
//  ------------
//            CATEdgeGraphicAttribut
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

class CATIEdgeGraphicProperties_var;

class ExportedByCATVisItf CATEdgeGraphicAttribut : public CATLineGraphicAttribut
{
  CATDeclareClass;

  public:
  ///////
    
    CATEdgeGraphicAttribut ();
    CATEdgeGraphicAttribut (unsigned long value);
    virtual ~CATEdgeGraphicAttribut (void) ;

    virtual void SetValue ( CATIEdgeGraphicProperties_var &value);

    virtual HRESULT MigrateToVisProperties (int iGeomType);

};

#endif
