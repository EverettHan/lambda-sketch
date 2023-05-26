// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATILocatorSet_H
#define CATILocatorSet_H
//--------------------------------------------------------------------------
// Author:  Didier LARUEL
// Date  :  10/02/97
// Objective:
//               Manipulate Set of "Locators"
//
//               This is implemented using CATLocatorSet Implementation
//               working with any Object having DS Locators.
//
//               This is used for CATIA_LINK_FORMAT Object Set
//
//--------------------------------------------------------------------------

/**
 * @level Private
 * @usage U3
 */

#include <CATBaseUnknown.h>
#include <CATBaseUnknowns.h>
#include <CATIBindParameters.h>

#include <CP0CLIP.h>
extern ExportedByCP0CLIP IID IID_CATILocatorSet ;

//preparation a la migration var
#ifndef VarBaseUnknown
#define VarBaseUnknown CATBaseUnknown_ptr
#endif
#ifndef NULL_varBaseUnknown
#define NULL_varBaseUnknown  NULL
#endif
#ifndef ListOfVarBaseUnknown
#define ListOfVarBaseUnknown CATLISTP(CATBaseUnknown)
#endif

class ExportedByCP0CLIP CATILocatorSet: public CATBaseUnknown
{
  CATDeclareInterface;
 public:


  //defines/query  reference objects
  virtual VarBaseUnknown FromReferenceObject(CATIBindParameters* p=NULL) const = 0;
  virtual ListOfVarBaseUnknown ListRelativeReferences(CATIBindParameters* p=NULL) const= 0;
  virtual int AddRelativeReference(VarBaseUnknown o)= 0;
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATILocatorSet, CATBaseUnknown ) ;

#endif
