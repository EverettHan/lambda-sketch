/**
 * @level Protected
 * @usage U5
 */

// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
//
//  Feb 2003  Creation: OGM
//===================================================================

#ifndef CATIV4ToV5ToCATProdCont_H
#define CATIV4ToV5ToCATProdCont_H

#include "AC0CATPL.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
  extern ExportedByAC0CATPL IID IID_CATIV4ToV5ToCATProdCont ;
#else
  extern "C" const IID IID_CATIV4ToV5ToCATProdCont ;
#endif

class CATFormat ;
class ListOfVarBaseUnknown ;

class ExportedByAC0CATPL CATIV4ToV5ToCATProdCont : public CATBaseUnknown
{
  CATDeclareInterface ;

  public :
    virtual HRESULT CreateBeforePasteData( const CATFormat*      iFormat,
                                           ListOfVarBaseUnknown* i_object_to_process,
                                           ListOfVarBaseUnknown* io_to_object,
                                           ListOfVarBaseUnknown* oFirstResult ) = 0 ;

    virtual HRESULT CreateAfterPasteData( const CATFormat*      iFormat,
                                          ListOfVarBaseUnknown* i_object_to_process,
                                          ListOfVarBaseUnknown* io_to_object,
                                          ListOfVarBaseUnknown* oFirstResult ) = 0 ;
} ;

#endif
