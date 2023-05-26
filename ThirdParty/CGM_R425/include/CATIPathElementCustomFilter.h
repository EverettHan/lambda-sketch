//===================================================================
// COPYRIGHT  2017/04/24
//===================================================================
// CATIPathElementCustomFilter.cpp
// Header definition of class CATIPathElementCustomFilter
//===================================================================
//
// Usage notes: This interface enables application of a custom filter
//              on the CATVisContextualManager. The way to use it is :   
// 1. Implement the CheckHighlightPath/CheckPreHighightPath the way
//    the application wants, in a class deriving from this interface.
// 2. Set the pointer to the above implementation on the CATVisContextManager
//    using CATVisContextualManager::SetPathElementCustomFilter()
// 3. Once done with the filter usage , make sure you REMOVE this filter 
//    using RemovePathElementCustomFilter(). If not, this can lead to a crash !
//
//===================================================================
//  2017/04/24 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef CATIPathElementCustomFilter_H
#define CATIPathElementCustomFilter_H

#include "SceneGraphManager.h"
#include "CATPathElement.h"

class CATPathElement;

//-----------------------------------------------------------------------

extern ExportedBySceneGraphManager IID IID_CATIPathElementCustomFilter;


class ExportedBySceneGraphManager CATIPathElementCustomFilter : public CATBaseUnknown // Inheritance added at the insistence of the client DELEPPRDegUserFilter
{
 
CATDeclareInterface;

public:

  // This method enbables applications to implement their own filter on the selected CATPathElement. They have to provide
  // an implementation of this method which will be called by the CATVisContextualManager::SetSelection if a pointer 
  // to an implementation of this interface is set on the CATVisContextualManager using SetPathElementCustomFilter .
  // params :
  // iPathToCheck : Path to be checked.
  // oCheckedPath : Path filtered/checked by the application code. Note that the CATVisContextManager will clone this path and use it. Hence, 
  //                the application still owns the lifecycle of the oCheckedPath even after the call to CheckHighlightPath.
  
  virtual HRESULT CheckHighlightPath(CATPathElement *iPathToCheck, CATPathElement * &oCheckedPath) = 0;

  // virtual HRESULT CheckPreHighightPath(CATPathElement *iPathToCheck, CATPathElement * oCheckedPath) = 0; // NHD : No clarity yet whether to provide this method.



private:
// Copy constructor and equal operator
// -----------------------------------
//CATIPathElementCustomFilter (CATIPathElementCustomFilter &);
//CATIPathElementCustomFilter& operator=(CATIPathElementCustomFilter&);

};

//-----------------------------------------------------------------------

#endif

