/* -*-C++-*- */
#ifndef ListPOfCATPrBRep_H
#define ListPOfCATPrBRep_H

#include "CATCGMLISTPP_Declare.h"
#include "AdvOpeInfra.h"

class CATPrBRep;

CATCGMLISTPP_DECLARE(CATPrBRep);

typedef CATLISTP(CATPrBRep) ListPOfCATPrBRep;

//------------------------------------------------------------------------------
class CATCGMOutput;
ExportedByAdvOpeInfra CATCGMOutput& operator<<(CATCGMOutput& iWhereToWrite, const CATLISTP(CATPrBRep)& iToWrite);
//------------------------------------------------------------------------------

#endif
