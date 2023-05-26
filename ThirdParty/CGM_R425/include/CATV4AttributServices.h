
/**
* @level Protected 
* @usage U1
*/

/* -*-c++-*- */

// COPYRIGHT DASSAULT SYSTEMES 2003
//=============================================================================
//
// Service : CATV4AttributService
//
//=============================================================================
// Creation : J. DELAYE March 2003
//=============================================================================

#ifndef CATV4AttributService_H
#define CATV4AttributService_H


#include "CATUnicodeString.h"
#include "CATIAModel.h"
#include "ExportedByCATV4Attributes.h"
#include "CATV4Attributes.h"
#include "CATLISTP_CATV4Attributes.h"
#include "CATReportInformation.h"


extern "C"
{
  /**
    * Define the memory array that will be used by this object as GES+TOLER.
    *
    * @param iGesTolerLength
    *  The number of double of GESTOLER array.
    *  Its number of byte will be iGesTolerLength*sizeof(double)
    * @param iGesTolerArray
    *  The memory array to be used. This array will not be duplicated, and will not be deleted
    *  by CATV4mV4DataStructure object
    *
    * @return
    *  Definition status.
    *  <br><b>Legal values</b>:
    *  <tt>S_OK</tt> if definition is OK
    *  <tt>E_FAIL</tt> if a problem occured. If the iGesTolerLength does'nt correspond to
    *  a standard value. If the GESTOLER is allready defined.
    */
  ExportedByCATV4Attributes CATLISTP(CATV4Attributes)* GetV4Attributes( CATIAEntity* const CatiaEntity, int Partiel ) ;
}

#endif
