/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1999
//=============================================================================
// BodyFDM :
// It is a kind of CATBody of which elements are CellFDM.
// (see CellForDistanceMin.h)
//=============================================================================
// Usage Notes : used in CATDistanceMinBodyFDM
//=============================================================================
// May. 99  LMH Creation                                                L. Mahe
// 24/10/16 NLD Gestion de configuration
//=============================================================================
#ifndef BodyFDM_h
#define BodyFDM_h

#include "ListPOfCATCell.h"
#include "CATMathDef.h"
//#include "ExportedByCATTopImpl.h"
#include "ExportedByBOOLight.h"
#include "CATCGMVirtual.h"

class CATBody;
class CellFDM;
class CATSoftwareConfiguration;

//-----------------------------------------------------------------------------
class ExportedByBOOLight BodyFDM : public CATCGMVirtual
{
  public :
    //-------------------------------------------------------------------------
    // Constructor/Destructor
    //-------------------------------------------------------------------------
    BodyFDM(CATSoftwareConfiguration* iConfig,
            CATBody                 * iBody  );
    BodyFDM();
    BodyFDM(BodyFDM &iBody);
    virtual ~BodyFDM();     

    //-------------------------------------------------------------------------
    // Data Access
    //-------------------------------------------------------------------------
    CATLONG32  GetNbElems();
    void       BuildElems();
    CATBody  * GetFather();
    CellFDM  * GetElem(CATLONG32 iRank);

    //-------------------------------------------------------------------------
    // Utilities
    //-------------------------------------------------------------------------
    void operator = (BodyFDM &iBody);
    CATBoolean operator == (BodyFDM &iBody);


  private :

    // Private Data
    CATBody                 * _body;
    CATSoftwareConfiguration* _config;
    CATLONG32                 _nb_cell;
    CATLISTP(CATCell)         _list;
    CellFDM                 * _cells;
    short                      show_trace; // while debugging, set this value to 1 and you will see .. heaven
};
#endif
