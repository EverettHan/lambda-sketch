#ifndef CATShowFilter_h
#define CATShowFilter_h

//********************************************************************
// CATIA Framework CATIAModelVisu (PPE)
// Copyright Dassault Systemes 1997
//********************************************************************
//
//  Abstract:
//  ---------
//    defines the show filter ( check if element has show propertie 
//                              via CATIGraphicProperties )
//    
//
//********************************************************************
//
//  Usage:  used by visualization
//  ------ 
//
//********************************************************************
//
//  Inheritance:
//  ------------
//              CATShowFilter
//               CATFilter
//                CATBaseUnknown (SYSTEM framework)
//
//********************************************************************
//
//  Main Methods:
//  -------------
//              ApplyOnObject ( CATBaseUnknown * )
//
//********************************************************************

#include "SceneGraphManager.h"
#include "CATFilter.h"

class ExportedBySceneGraphManager CATShowFilter : public CATFilter
{
  CATDeclareClass;
  
  public:
  ///////
    
    
    CATShowFilter (void) ;
    virtual ~CATShowFilter (void) ;
    virtual CATFilter *Clone(void);
  
    
    
    // check if the filter is satisfied on the model object
    // ----------------------------------------------------
    
    virtual Result ApplyOnObject ( CATBaseUnknown *object );
};


#endif
