#ifndef CATAndFilter_h
#define CATAndFilter_h

//********************************************************************
// CATIA Framework CATIAModelVisu (PPE)
// Copyright Dassault Systemes 1997
//********************************************************************
//
//  Abstract:
//  ---------
//    defines the and filter
//    
//
//********************************************************************
//
//  Usage:  used to implement filter composed of several composant
//  ------                   
//
//********************************************************************
//
//  Inheritance:
//  ------------
//              CATAndFilter
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
#include "list.h"

class ExportedBySceneGraphManager CATAndFilter : public CATFilter
{
  CATDeclareClass;
  
  public:
  ///////
    
    
    CATAndFilter (CATFilter *base1,CATFilter *base2) ;
    virtual ~CATAndFilter (void) ;
    
    void AddFilter ( CATFilter *base );
    void RemoveFilter ( CATFilter *base );
	list<CATFilter> GetFilters(void);
    virtual CATFilter *Clone(void);
    // check if the filter is satisfied on the model object
    // ----------------------------------------------------
    virtual void BeforeRepBuild(CATBaseUnknown *);
    virtual Result ApplyOnObject ( CATBaseUnknown *object );
    virtual void AfterRepBuild(CATBaseUnknown *);

  private:
  ////////

    list<CATFilter> _base;
};


#endif
