/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATLISTV_sequence_octetH
#define CATLISTV_sequence_octetH

/**
  * @CAA2Required
  * 
  */


///////////////////////////////////////////////////////////////////////////////
//    PROJET:............CNEXT                                               //
//    FRAMEWORK:.........ObjectModelerBase                                   //
//    AUTEUR:............Benoit PAGET                                        //
//    DATE:..............14/08/1998                                          //
///////////////////////////////////////////////////////////////////////////////


// --------------------------------------------------------------------------
//                       Clean previous functions requests
// --------------------------------------------------------------------------

#include "CATLISTV_Clean.h"


// --------------------------------------------------------------------------
//                       Require needed functions
// --------------------------------------------------------------------------

#define CATLISTV_RemovePosition
#define CATLISTV_MinimalFunct
#undef CATLISTV_eqOP
#undef CATLISTV_neOP

// --------------------------------------------------------------------------
//                                  Get macros
// --------------------------------------------------------------------------

#include "CATLISTV_Declare.h"

// --------------------------------------------------------------------------
//                              Exported by module
// --------------------------------------------------------------------------

#include "CATOMY.h"

// --------------------------------------------------------------------------
//                       Generate interface of collection-class
// --------------------------------------------------------------------------

#include "sequence_octet.h"

/**
  * @collection CATLISTV(sequence_octet)
  * Collection class for sequence_octet.
  * Refer to the articles dealing with collections in the encyclopedia.
  */

#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByCATOMY

CATLISTV_DECLARE( SEQUENCE(octet) )


#endif



