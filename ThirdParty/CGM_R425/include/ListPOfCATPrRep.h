/* -*-C++-*- */
#ifndef ListPOfCATPrRep_H
#define ListPOfCATPrRep_H

#include "CATCGMLISTPP_Declare.h"

class CATPrRep;

CATCGMLISTPP_DECLARE(CATPrRep);

typedef CATLISTP(CATPrRep) ListPOfCATPrRep;

//------------------------------------------------------------------------------
class CATCGMOutput;
CATCGMOutput& operator<<(CATCGMOutput& iWhereToWrite, const CATLISTP(CATPrRep)& iToWrite);
//------------------------------------------------------------------------------

#endif
