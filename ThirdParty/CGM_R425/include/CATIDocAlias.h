/* -*-c++-*- */
#ifndef CATIDocAlias_h
#define CATIDocAlias_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
* @level Private
* @usage U5
*/


#include "CATUnicodeString.h"

#include "AD0XXBAS.h"

extern ExportedByAD0XXBAS IID IID_CATIDocAlias ;

/**
* @nodoc
* Interface to manage the suffix of the document's file names.
* <b> Role: </b> the string defined in the dictionnary for adhesion
* to CATIDocAlias is the one which appears in File/New panel, it does 
* not correspond to the late type of the document which is generally the string 
* given by GiveDocSuffix.
* @see CATInit, CATIPersistent
*/
class ExportedByAD0XXBAS CATIDocAlias : public CATBaseUnknown
{
  CATDeclareInterface;

public:
  /**
   * @nodoc
   * Returns the suffix of the document's file names.
   * <br><b> Note: </b> this suffix usually corresponds to the late type defining the
   * document for adhesion to interfaces such as CATInit or CATIPersistent.
   */
 virtual CATUnicodeString GiveDocSuffix() =0 ;
    
};

// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( CATIDocAlias, CATBaseUnknown ) ;


#endif
