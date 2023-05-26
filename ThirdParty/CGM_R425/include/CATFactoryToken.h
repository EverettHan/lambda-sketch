/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */

///////////////////////////////////////////////////////////////////////////////
// COPYRIGHT DASSAULT SYSTEMES  1996                                         //
// ========================================================================= //
//                                                                           //
// CATFactoryToken :                                                         //
//                                                                           //
// Class for Factory's declaration.                                          //
// ========================================================================= //
// Usage Notes:                                                              //
//                                                                           //
// This object register the relations :                                      //
//                                                                           //
//        Interface factory   <-->   Type of object to be created            //
//                                                                           //
// ========================================================================= //
// Jul. 96   Creation                                   J-L MALAVAL          //
///////////////////////////////////////////////////////////////////////////////

#ifndef CAT_FACTORY_TOKEN_H
#define CAT_FACTORY_TOKEN_H

#include "AD0XXBAS.h"

#include "CATString.h"

#include "CATLISTP_CATFactoryToken.h"

#ifndef NULL_String
#define NULL_String  CATString( "" )
#endif

#include "CATOmxUTF8String.h"
#include "CATOmxArray.h"
#include "CATBoolean.h"

// ==========================================================================
//                 Declaration of  CATFactoryToken  Class
// ==========================================================================
class CATFactoryToken;
typedef CATOmxArray<CATFactoryToken*,naive_manager> CATFactoryToken_array;

class ExportedByAD0XXBAS CATFactoryToken
{
  public :
    CATFactoryToken( const CATString& factoryName, const CATString& objectName ) ; 
    virtual ~CATFactoryToken() ;

    const CATString                     GetFactory() const ;
    const CATString                     GetObject() const ;
    
    static CATBoolean                   IsEmpty() ;
    /** Do not use this. */
    static CATFactoryToken*             GetHead() ;
    static void							RemoveAll() ;

    static CATLISTP( CATFactoryToken )* GetTokensFromObject ( const CATString& objectName ) ;
    static CATFactoryToken_array GetTokensFromObject2 ( const CATString& objectName ) ;

  protected :
    friend class CATFactoryTokenRegistry;

    CATFactoryToken( const CATFactoryToken& base ) ;
    CATFactoryToken& operator=( const CATFactoryToken& base ) ;

  private :
    CATOmxUTF8String  _factory ; 
    CATOmxUTF8String  _object ;

}; 


#endif 
