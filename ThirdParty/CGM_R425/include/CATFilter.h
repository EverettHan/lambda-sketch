#ifndef CATFilter_h
#define CATFilter_h

//********************************************************************
// CATIA Framework CATIAModelVisu (PPE)
// Copyright Dassault Systemes 1997
//********************************************************************
//
//  Abstract:
//  ---------
//    This is a basic class defining filter on model objet.
//    
//
//********************************************************************
//
//  Usage:  this class is used by vue component to filter the visualization
//  ------  in fonction of model criteria.
//
//********************************************************************
//
//  Inheritance:
//  ------------
//              CATFilter
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
#include "CATBaseUnknown.h"

class ExportedBySceneGraphManager CATFilter : public CATBaseUnknown
{
  CATDeclareClass;
  
  public:
  ///////
    
    enum Result { Ko, Neutral, Ok }; 
    
    CATFilter (void) ;
    virtual ~CATFilter (void) ;
    virtual CATFilter *Clone(void);
    
    // check if the filter is satisfied on the model object
    // ----------------------------------------------------
    
    virtual void BeforeRepBuild( CATBaseUnknown *object);
    virtual Result ApplyOnObject ( CATBaseUnknown *object ) = 0;
    virtual void AfterRepBuild( CATBaseUnknown *object);

    static CATFilter *GetCurrentFilter();
    static void SetCurrentFilter(CATFilter *);

  private:
  ////////

    static CATFilter *_currentFilter;
};


#endif
