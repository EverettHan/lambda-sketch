/**
 * @level Private
 * @usage U1
 */
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef GENERIC_FACTORY_H
#define GENERIC_FACTORY_H

///////////////////////////////////////////////////////////////////////////////
//    PROJET:............CNEXT                                               //
//    FRAMEWORK:.........Object Modeler                                      //
//    AUTEUR:............Rodolphe AYMARD/Jean-Louis MALAVAL                  //
//    DATE:..............26/01/1996                                          //
//             -----------------------------------------------               //
//    AUTEUR:............                                                    //
//    MODIF:.............                                                    //
//    DATE:..............  /  /1995                                          //
///////////////////////////////////////////////////////////////////////////////

// ==========================================================================
//        Implementation des Life Cycle Object services de CORBA
// ==========================================================================

#include "CosLifeCycleServices.h"
#include "CATBaseUnknown.h"

// --------------------------------------------------------------------------
//                            Exceptions
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
//                       Interface  GenericFactory
// --------------------------------------------------------------------------

#include "CATOMY.h"
extern ExportedByCATOMY IID IID_GenericFactory ;

class ExportedByCATOMY GenericFactory : public CATBaseUnknown
{
  CATDeclareInterface;

 public:
   virtual unsigned char       supports     ( Key*      key      ) = 0 ;
   virtual CATBaseUnknown* create_object( Key*      key,
	          		              Criteria* criteria ) = 0 ;
} ;
  
// --------------------------------------------------------------------------
//                             Handler
// --------------------------------------------------------------------------

CATDeclareHandler( GenericFactory, CATBaseUnknown ) ;


#endif


