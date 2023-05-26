 // COPYRIGHT DASSAULT SYSTEMES 1998
//==========================================================================
//
// CATFrFConvertCCVToWire:
// Interface class of transformation from CCV to WIRE
//
//
//==========================================================================
//
// Usage notes:
//========================================================================== 
// MAY 98    Creation                   JBX
// 10/02/00 NLD argument iFreezeBody dans constructeur, _FreezeBody
// 21/11/00 NLD constructeur avec CATTopData
// 10/01/01 NLD - argument iMaxGapInDomain pour creation body multidomaines
//              - _MaxGapInDomain
// 21/05/02 NLD argument optionnel iRefBody, et variable _RefBody
//              pour gestion d'un body de reference decrivant la topologie
// 22/09/05 NLD Suppression du constructeur sans TopData
//========================================================================== 

#ifndef CATFrFConvertCCVToWire_H
#define CATFrFConvertCCVToWire_H

#include <AdvTopoUtil.h>
#include <CATFrFCompositeCurve.h>
#include <CATTopData.h>
#include "CATCGMVirtual.h"

class CATWire;
class CATBody;
class CATGeoFactory;


//-----------------------------------------------------------------------------
class ExportedByAdvTopoUtil CATFrFConvertCCVToWire: public CATCGMVirtual
{
  CATCGMVirtualDeclareClass(CATFrFConvertCCVToWire);
  public :
    
    // Basic Methods
    // there are to ways to make a body with several domains:
    // iMaxGapInDomain : if positive, a new domain is generated when 
    // gap between consecutive curves is superior to iMaxGapInDomain
    // iRefBody : if  exists, describes topology to be obtained
    // (output wire will have same number of domains and same number
    // of cells in each domain)
    CATFrFConvertCCVToWire(CATGeoFactory * iFactory,
                           CATTopData * iTopData,
                           CATFrFCompositeCurve * iCCV,
                           CATBoolean iFreezeMode=CATBoolean(1),
                           double     iMaxGapInDomain=-1.,
                           CATBody*   iRefBody=NULL);

/*TO BE DELETED*/   /*NLD220905 CATFrFConvertCCVToWire(CATGeoFactory * iFactory,
                           CATFrFCompositeCurve * iCCV,
                           CATBoolean iFreezeMode=CATBoolean(1));
*/
    virtual ~CATFrFConvertCCVToWire();

    void Run();

    //  Getting the Wire result  
    CATWire *GetWire() const;

    //  Getting the Body result  
    CATBody *GetBody() const;


 private:
    CATTopData             _TopData;
    CATWire              * _ResultWire;
    CATBody              * _ResultBody;
    CATBody              * _RefBody;
    CATGeoFactory        * _Factory;
    CATFrFCompositeCurve * _MyCCV;
    CATBoolean             _FreezeBody;  
    double                 _MaxGapInDomain ;
};

#endif
