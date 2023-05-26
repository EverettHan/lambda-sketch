#ifndef CATILayersAndFilters_H
#define CATILayersAndFilters_H

// COPYRIGHT DASSAULT SYSTEMES 2000

///////////////////////////////////////////////////////////////////////////////
//    CATILayersAndFilters.h                                               //
///////////////////////////////////////////////////////////////////////////////
//    PROJET:............CNEXT                                               //
//    FRAMEWORK:.........ApplicationFrame                                  //
//    AUTEUR:............Eric Ropars                                         //
//    DATE:..............24/01/1997                                          //
//             -----------------------------------------------               //
//    AUTEUR:............                                                    //
//    MODIF:.............                                                    //
//    DATE:..............  /  /1997                                          //
///////////////////////////////////////////////////////////////////////////////

// ==========================================================================
//
// Interface for Layer management on Features
//
// ==========================================================================

#include "CATBaseUnknown.h"
#include "CATAfrFoundation.h"


#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATAfrFoundation IID IID_CATILayersAndFilters;
#else
extern "C" const IID IID_CATILayersAndFilters;
#endif

//===================================================================================
//              CATILayersAndFilters :  D E C L A R A T I O N S
//===================================================================================

#include "CATUnicodeString.h"

class CATLayersFilter;
class CATListPtrCATLayer;
class CATListPtrCATLayersFilter;

class ExportedByCATAfrFoundation CATILayersAndFilters : public CATBaseUnknown
{
  
  CATDeclareInterface;
  
  
public:

    virtual int  IsLayerVisible (int layerId) = 0;

    virtual void SetCurrentFilter(CATLayersFilter * pFilter) = 0;

    virtual void SetCurrentLayer (int layer) = 0;

    virtual void SetListOfLayers (CATListPtrCATLayer * ipLayerList) = 0;

    virtual void SetListOfFilters (CATListPtrCATLayersFilter * ipFilterList) = 0;

    virtual int GetCurrentLayer() = 0;

    virtual HRESULT GetListOfLayers (CATListPtrCATLayer * iopLayerList) = 0;

    virtual HRESULT GetListOfFilters (CATListPtrCATLayersFilter * iopFilterList) = 0;

    virtual HRESULT GetCurrentFilter (CATUnicodeString & oFilterName) = 0;

  
} ;

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATILayersAndFilters, CATBaseUnknown ) ;

#endif
