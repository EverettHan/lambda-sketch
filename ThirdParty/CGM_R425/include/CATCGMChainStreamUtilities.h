// COPYRIGHT DASSAULT SYSTEMES 2006
#ifndef CATCGMChainStreamUtilities_H
#define CATCGMChainStreamUtilities_H

//#include "CATCVMGeoObjects.h"
#include "ExportedByBONEWOPE.h"
#include "CATBoolean.h"
//#include "CATCGMTopoChain.h"

class CATTopData;
class CATCGMStream;
class CATCGMChain;
class CATGeoFactory;


/*

#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ostream;
#endif
*/


class ExportedByBONEWOPE CATCGMChainStreamUtilities
{
  public:
    static CATBoolean Save(CATCGMChain * iChain, char* iFileName);
    static CATBoolean Open(CATCGMChain *& ioChain, CATGeoFactory *& oFactory, char* iFileName);

	   
  public:
    static CATBoolean WriteCGMChainFile(CATCGMChain * iChain, char* iFileName);
    static CATBoolean WriteCGMChainFile(CATCGMChain * iChain, CATCGMStream * iStream);

    static CATBoolean ReadCGMChainFile(CATCGMChain * &oChain, CATGeoFactory *& oFactory, char* iFileName);
    static CATBoolean ReadCGMChainFile(CATCGMChain * &oChain, CATCGMStream * iStream);

	




};

extern "C" ExportedByBONEWOPE CATBoolean CATWriteCGMChainRecord (CATCGMChain * iChain, char* iFileName);
#endif


