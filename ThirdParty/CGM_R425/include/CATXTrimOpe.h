// COPYRIGHT DASSAULT SYSTEMES 2008, 2009 ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : ZUT
//
// DESCRIPTION  : Trim of skins to build a volume or a skin. BRep Modeling Operator for CATIA Live Shape.
//                
//=============================================================================
// Creation LAP October 2008
//=============================================================================

#ifndef CATXTrimOpe_H
#define CATXTrimOpe_H

#include "AdvTrimOpe.h"
#include "CATXTrimSimplificationMode.h"
#include "CATPersistentOperator.h"

#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"

class CATXTrimImpl;
class CATBody;
class CATString;
class CATMathTransformation;

class ExportedByAdvTrimOpe CATXTrimOpe : public CATPersistentOperator
{
  CATCGMVirtualDeclareClass(CATXTrimOpe);

  public:

  	//-------------------------------------------------
    // Constructor: use the methode CATCreateXTrimOpe
    //-------------------------------------------------
    CATXTrimOpe(CATGeoFactory* iFactory,
                CATTopData*    iTopData,
                CATXTrimImpl*  iImpl);
  	
    //------------------
    // Destructor
    //------------------
	  virtual ~CATXTrimOpe();

    /**
    * Appends a list of faces on referenceBody with their skin image.
    * @param iReferenceFaces.
    * The list of pointers to faces on referenceBody to be replace by Skin.
    * @param iSkinBody.
    * Surfacic Body Rep of local result.
    * @param iExtrapolatedSkinBody
    * Optional already extrapolated skin body
    * @param iNonExtrapolatedEdges
    * Optional non-extrapolated edges in extrapolated skin body (tangent contacts)
    * @param iTransfo
    * Optional transformation applied to iReferenceFaces which leads to iSkinBody
    */
    void AppendSkinToMove(ListPOfCATFace              & iReferenceFaces,
                          CATBody                     & iSkinBody,
                          CATBody                     * iExtrapolatedSkinBody = NULL,
                          ListPOfCATEdge              * iNonExtrapolatedEdges = NULL,
                          const CATMathTransformation * iTransfo = NULL);

    /**
    * Appends skin image and the skin extrapolated.
    * @param iReferenceSkinBody.
    * Surfacic Body Rep to add.
    * @param iExtrapolatedSkinBody.
    * Extrapolated Surfacic Body Rep to add.
    */
    //void AppendSkinToAdd(CATBody& iReferenceSkinBody,
    //                     CATBody* iExtrapolatedSkinBody=NULL);

     /**
    * Appends a list of faces to remove.
    * @param iReferenceFacesToRemove.
    * The list of pointers to faces to remove.
    */
    //void AppendFacesToRemove(ListPOfCATFace& iReferenceFacesToRemove);

    /*
    * Defines the level of simplification of the result body.
    * @param iMode
    * The simplification mode.
    * Default value is CATXTrimSimplificationMode_Default
    */
    void SetSimplificationMode( CATXTrimSimplificationMode iMode );

    // Run
    int RunOperator();

    //------------------
    // CGMReplay methods
    //------------------
    static const CATString *GetDefaultOperatorId();
    const CATString * GetOperatorId();
    CATExtCGMReplay *IsRecordable(short& oLevelOfRuntime, short& oVersionOfStream);
    void WriteInput(CATCGMStream& oStr);
    void ReadInput(CATCGMStream& ioStr, int iVersionOfStream, short iNumReplayVersion = 1);
    void Dump(CATCGMOutput& os);
    void DumpOutput(CATCGMOutput & os);
    void RequireDefinitionOfInputAndOutputObjects();

  protected:
    CATXTrimImpl * GetXTrimImpl();

};

// ----------------------
// CATCreateXTrim
// ----------------------
ExportedByAdvTrimOpe CATXTrimOpe* CATCreateXTrimOpe(CATGeoFactory& iFactory,
                                                    CATTopData&    iTopData,
                                                    CATBody&       iReferenceBody); 

#endif
