
#ifndef DSYStringHelperEx_H
#define DSYStringHelperEx_H

#include "NS0S3STR.h"
#include "CATCollec.h"

class CATSysTSVectorOfUnicodeString;

namespace DSY
{
    ExportedByNS0S3STR void Copy(CATSysTSVectorOfUnicodeString &oCUSTSVect, CATListOfCATUnicodeString &iCUSVect);
    ExportedByNS0S3STR void Copy(CATListOfCATUnicodeString &oCUSVect, CATSysTSVectorOfUnicodeString &iCUSTSVect);
    
    /**
     * Externalized algorithms.
     */
    ExportedByNS0S3STR void Split(const CATUnicodeString &iStr, 
        const CATUnicodeString &iPattern, CATListOfCATUnicodeString &ovStrings);
}

#endif  // DSYStringHelperEx_H
