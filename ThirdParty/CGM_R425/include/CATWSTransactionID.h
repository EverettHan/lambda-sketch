/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2003  
//-----------------------------------------------------------------------------
// class CATIWSTransactionID :
// 
// Type definitions for transaction identifiers used for Warm Start 
//
//-----------------------------------------------------------------------------
// Creation by User led
//-----------------------------------------------------------------------------

#ifndef CATWSTRANSACTIONID_H
#define CATWSTRANSACTIONID_H

/**
 * @level Private
 * @usage U1
 */

#include "CATOmbWarmStart.h"

// WARNING before changing this typedef, update the classes where transaction IDs are 
// marshalled.
typedef int CATWSTRANSACTIONID;

#define CATWSTRANSACTIONID_NULL -1

class ExportedByCATOmbWarmStart CATWSTRANSACTIONIDSTRUCT {
public:
	CATWSTRANSACTIONID id;
};

#define CATHDICO_Remove
#define CATHDICO_Locate
#define CATHDICO_RemoveAll
#define CATHDICO_ApplyDelete

#include "CATHDICO_Declare.h"

CATHDICO_DECLARE( CATWSTRANSACTIONIDSTRUCT );

// Dictionary CATUnicodeString => CATWSTRANSACTIONIDSTRUCT 
typedef CATHDICO( CATWSTRANSACTIONIDSTRUCT ) CATHDICOTRANSACTIONID;

#endif
