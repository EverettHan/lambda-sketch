// COPYRIGHT DASSAULT SYSTEMES 2008, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : LAP
//
// DESCRIPTION  : 
//                
//=============================================================================
// Creation LAP January 2009
//=============================================================================

#ifndef CATGMMultiBodyMergerOpe_H
#define CATGMMultiBodyMergerOpe_H

#include "AdvTrimOpe.h"
#include "CATPersistentOperator.h"

#include "ListPOfCATBody.h"
#include "ListPOfCATPersistentBodies.h"
#include "CATSurLimits.h"
#include "CATTopDefine.h"

class CATGMMultiBodyMergerImpl;
class CATBody;
class CATString;
class CATBody;
class CATFace;
class CATEdge;
class CATVertex;
class CATEdgeCurve;
class CATMathPoint;
class CATSurface;
class CATPersistentCellInfra;

class ExportedByAdvTrimOpe CATGMMultiBodyMergerOpe : public CATPersistentOperator
{
  CATCGMVirtualDeclareClass(CATGMMultiBodyMergerOpe);

  public:

  	//-------------------------------------------------
    // Constructor: use the method CATCreateGMMultiBodyMergerOpe
    //-------------------------------------------------
    CATGMMultiBodyMergerOpe(CATGeoFactory            * iFactory,
                            CATTopData               * iTopData,
                            CATGMMultiBodyMergerImpl * iImpl);
  	
    //------------------
    // Destructor
    //------------------
	  virtual ~CATGMMultiBodyMergerOpe();

    //void SetFromNonManilodLump(CATBody & iBody);

    // Default value : simplification = FALSE
    void SetSimplificationBetweenVolums(CATBoolean iSimplificationBetweenVolums);
    void SetDontCreateVolumesForClosedShells(CATBoolean iDontCreateVolume=TRUE);
    //void SetSimplificationBetweenSkins(CATBoolean iSimplificationBetweenSkins); // To do if needed
    //void SetSimplificationBetweenVolumAndSkin(CATBoolean iSimplificationBetweenVolumAndSkin); // To do if needed
    void SetSolveInvalidMultiShellBody (CATBoolean iSolveInvalidMultiShellBody);

    //Defaut Value : FailWhenCompatibleFails : FALSE
    //void SetFailWhenCompatibleFails(CATBoolean iFailWhenCompatibleFails);

    // Run
    int RunOperator();

    //------------------
    // CGMReplay methods
    //------------------
    static const CATString *GetDefaultOperatorId();
    const CATString * GetOperatorId();
    CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
    void WriteInput(CATCGMStream  & Str);
    void ReadInput(CATCGMStream  & ioStr, int VersionOfStream, short iNumReplayVersion = 1);
    void Dump( CATCGMOutput& os );
    void RequireDefinitionOfInputAndOutputObjects();
    void AddBodyCoupleToUnify(CATBody *iBody1,CATBody *iBody2);
    void AllowBodyCoupleForCompatible(CATBody *iBody1,CATBody *iBody2);
    void AddBodyCoupleToUnify(CATPersistentBody *iBody1,CATPersistentBody *iBody2);
    void AllowBodyCoupleForCompatible(CATPersistentBody *iBody1,CATPersistentBody *iBody2);

  protected:

    CATGMMultiBodyMergerImpl * GetMBMergerImpl();

};

// ---------------------------
// CATCreateMultiBodyMergerOpe
// ---------------------------
ExportedByAdvTrimOpe CATGMMultiBodyMergerOpe * CATCreateGMMultiBodyMergerOpe(CATGeoFactory          & iFactory,
                                                                              CATTopData            & iTopData,
                                                                              const ListPOfCATBody  & iInputBodyList); 

ExportedByAdvTrimOpe CATGMMultiBodyMergerOpe * CATCreateGMMultiBodyMergerOpe(CATGeoFactory                      & iFactory,
                                                                              CATTopData                        & iTopData,
                                                                              const ListPOfCATPersistentBodies  & iInputPersistentBodyList,
                                                                              CATPersistentCellInfra            & iPCellInfra);

ExportedByAdvTrimOpe CATGMMultiBodyMergerOpe* CATCreateGMMultiBodyMergerOpeForXTrim(CATGeoFactory&  iFactory,
                                                                                    CATTopData&     iTopData,
                                                                                    ListPOfCATBody& iInputBodyList);

ExportedByAdvTrimOpe CATGMMultiBodyMergerOpe* CATCreateGMMultiBodyMergerOpeForXTrim(CATGeoFactory&              iFactory,
                                                                                    CATTopData&                 iTopData,
                                                                                    ListPOfCATPersistentBodies& iInputPersistentBodyList,
                                                                                    CATPersistentCellInfra&     iPCellInfra);



#endif
