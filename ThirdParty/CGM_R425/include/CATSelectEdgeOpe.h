// COPYRIGHT DASSAULT SYSTEMES 2007, ALL RIGHTS RESERVED.
//=============================================================================
//
// RESPONSIBLE  : Q. Freger 
//
// DESCRIPTION  : Create a journal of CATManifold from PerviousBodyList to CurrentBodyList 
//
//=============================================================================
// Creation QF2 Jan 2018
//
//=============================================================================
#ifndef CATSelectEdgeOpe_H
#define CATSelectEdgeOpe_H

#include "TopPersistentLight.h"
#include "CATAdvancedOperator.h"
#include "ListPOfCATEdge.h"
// #include "IUnknown.h" // For HRESULT
#include "CATSelectEdgePropagateMode.h"
#include "CATSelectEdgePrivatePropagateMode.h"

class CATSelectEdgeImpl;
class CATSoftwareConfiguration;
class CATGeoFactory;
class CATTopData;
class CATCGMStream;
class CATCGMOutput;
class CATBody;
class CATCellHashTable;
class CATEdgeHashTable;
class CATFaceHashTable;



/**
* This class is used to select faces with.<br>
**/
class ExportedByTopPersistentLight CATSelectEdgeOpe : public CATAdvancedOperator //CATPersistentOperator
{
  CATCGMVirtualDeclareClass(CATSelectEdgeOpe);

public:

  //==============================================================================
  // destructor 
  //==============================================================================
  /**
  * Standard destructor.<br>
  **/
  // @nocgmitf
  virtual ~CATSelectEdgeOpe();


  // =========================================================
  // Set Methods ( before Run )
  // =========================================================
  /**
  * Set a list of CATEdge pointer to priorise propagation.
  * @param iGuideEdges
  * The pointer list of CATEdge to append.
  */
  void SetGuideEdges(const ListPOfCATEdge &iGuideEdges);
  // @nocgmitf 
  void SetGuideEdges(const CATEdgeHashTable &iGuideEdges);

  /**
  * Set a list of CATEdge pointer to stop propagation.
  * @param iStoppingEdges
  * The pointer list of CATEdge to append.
  */
  void SetStoppingEdges(const ListPOfCATEdge &iStoppingEdges);  
  // @nocgmitf 
  void SetStoppingEdges(const CATEdgeHashTable &iStoppingEdges);  
  
  /**
  * Set an angle value which define the tangency tolerance for edges propagation.
  * @param iRadAngle
  * The angle value in radians.
  */
  void SetTangencyMaxAngle(CATAngle iRadAngle);
    

  /**
  * Choose your own function to run the CATSelectEdge propagation. 
  * This operator must have been created with the mode CSE_CUSTOM_PROPAGATION.
  * 
  * The function will be called on each edge to be propagated. 
  * CSEPropagationFunction is defined in CATSelectEdgePrivatePropagateMode.h,
  *   --> std::function<CATBoolean(CATBody *ipBody, CATVertex *iCurrVertex, CATEdge * iCurrEdge, CATEdge *iCandidateEdge, CATDomain * iDomain)>
  * 
  * Function ordered @parameters
  *   - ipBody         : the operator input body (given at contructor step). 
  *   - iCurrVertex    : the current bounding vertex between iCurrEdge and iCandidateEdge. 
  *   - iCurrEdge      : the current edge to propagate from. 
  *   - iCandidateEdge : the candidate edge to propagate on. 
  *   - iDomain        : the domain owning iCurrEdge and iCandidateEdge. 
  *
  * Function @return
  *   - CATBoolean : if TRUE, propagation from iCurrFace to iNextFace must be accomplished. 
  *                  if FALSE, propagation won't go beyond iNextFace. 
  *
  ** @nocgmitf */
  HRESULT SetCustomPropagation(CSEPropagationFunction     iFunct               /*defined in CATSelectEdgePrivatePropagateMode.h*/,
                               const char               * iFunctionName = NULL /*cgmreplay purpose*/,
                               const char               * iLibName      = NULL /*cgmreplay purpose*/); 


  //==========================================================
  // Get Methods  ( Output after Run )
  // =========================================================
  /** 
  * Retrieve the result of propagation of CATEdge given in input.
  * @param oResultEdgeList
  *   The list filled of pointers on result CATEdge.
  **/
  void GetSelectedResult(ListPOfCATEdge & oResultEdgeList) const;

  /** 
  * Retrieve the result of propagation of CATEdge given in input.
  * @param oResultEdgeList
  *   The hashtable filled by pointers on result selected CATEdge.
  **/
  void GetSelectedResult(CATCellHashTable & oResultEdgeHT) const;

  /** @nocgmitf @nodoc  **/
  void GetSelectedResult(CATEdgeHashTable & oResultEdgeHT) const;



  /** 
  * Get the hash table result from the operator - avoid copy. Note that the hash
  * table will be own by the caller. Think to delete it after usage.
  * This method can only be called once. 
  * @return
  *   The pointer of the hash table that contains pointers on selected edges.
  **/
  CATCellHashTable * GetSelectedResult();


  //==============================================================================
  //
  // CGMREPLAY METHODES
  //
  //==============================================================================
  /** @nodoc @nocgmitf declaration integre au CGMReplay */
  void RequireDefinitionOfInputAndOutputObjects();
  /** @nodoc @nocgmitf */
  CATExtCGMReplay *IsRecordable(short & LevelOfRuntime, short &VersionOfStream);
  /** @nodoc @nocgmitf */
  virtual const CATString * GetOperatorId();
  /** @nodoc @nocgmitf */
  static const CATString * GetDefaultOperatorId();
  /** @nodoc @nocgmitf */
  void DumpOutput(CATCGMOutput& os);
  /** @nodoc @nocgmitf */
  virtual void WriteInput(CATCGMStream  & os);
  /** @nodoc @nocgmitf */
  virtual void ReadInput(CATCGMStream  & ioStream,int VersionOfStream, short iNumReplayVersion=1);
  /** @nodoc @nocgmitf */
  virtual void Dump( CATCGMOutput& os ) ;
  /** @nodoc @nocgmitf */
  virtual int RunOperator();

  /** @nodoc @nocgmitf */
  void DumpOutput(CATCGMStream & Str , CATCGMOutput & os , int VersionNumber);
  /** @nodoc @nocgmitf */
  CATBoolean ReadReferenceOutput(CATCGMStream &Str);
  /** @nodoc @nocgmitf */
  void WriteOutput(CATCGMStream & ioStream);
  /** @nodoc @nocgmitf */
   CATBoolean ValidateTopOutput(CATTopCheckJournal* iEquivalent, CATCGMOutput& os);
  /** @nodoc @nocgmitf */
   CATCGMOperator::CATCheckDiagnostic CheckOutput(CATCGMOutput & os);
  /** @nodoc @nocgmitf */
  CATBoolean ValidateOutput(CATCGMStream & iStr, CATCGMOutput & Os, int VersionNumber=1);

protected:
   /** @nodoc @nocgmitf */
  CATSelectEdgeImpl * GetSelectEdgeImpl() const;

  /** @nodoc @nocgmitf */
  friend ExportedByTopPersistentLight CATSelectEdgeOpe * CATCreateSelectEdgeOpe(  CATTopData                            * ipTopData,
                                                                                  CATBody                               * ipInputBody,
                                                                                  const ListPOfCATEdge                  & iInputEdgeList,
                                                                                  CATSelectEdgePropagateMode              iPropagationMode,
                                                                                  const ListPOfCATEdge                  * iEdgeGuideList,
                                                                                  const ListPOfCATEdge                  * iStoppingEdges);

    /** @nodoc @nocgmitf */
  friend ExportedByTopPersistentLight CATSelectEdgeOpe * CATCreateSelectEdgeOpe(  CATTopData                            * ipTopData,
                                                                                  CATBody                               * ipInputBody,
                                                                                  const CATEdgeHashTable                & iInputEdgeHT,
                                                                                  CATSelectEdgePropagateMode              iPropagationMode,
                                                                                  const CATEdgeHashTable                * iEdgeGuideHT,
                                                                                  const CATEdgeHashTable                * iStoppingEdgeHT);

    /** @nodoc @nocgmitf */
  friend ExportedByTopPersistentLight CATSelectEdgeOpe * CATCreateSelectEdgeOpe(  CATTopData                            * ipTopData,
                                                                                  CATBody                               * ipInputBody,
                                                                                  const CATEdgeHashTable                & iInputEdgeHT,
                                                                                  CATSelectEdgePropagateMode              iPropagationMode,
                                                                                  const CATFaceHashTable                & iSubPropagFaceList);


                                                                                  
  //==============================================================================
  // Protectd Constructor: do not use, use CATCreateExtractCellsOpe
  //==============================================================================
  // @nocgmitf
  CATSelectEdgeOpe(CATGeoFactory                      * iFactory,
                     CATTopData                       * iTopData,
                     CATSelectEdgeImpl                * iImpl);

private :

  //==============================================================================
  // copy constructor
  //==============================================================================
  /**
  * Copy constructor: Not implemented. <br>
  **/
  CATSelectEdgeOpe (const CATSelectEdgeOpe &);


  //==============================================================================
  // Equal operator
  //==============================================================================
  /**
  * Equal operator : Not implemented. <br>
  **/
  CATSelectEdgeOpe& operator=(const CATSelectEdgeOpe &);


  //==============================================================================
  // Data
  //==============================================================================

};


//==============================================================================
// Official Constructor : CATCreateSelectEdgeOpe
//==============================================================================
/**
* Create operator, it call the constructor.<br>
* <b>Legal Values</b>:<br>
*	<ul>
*	  <li> <tt>iTopData</tt> : It represents the information about the configuration and
*								the journal. If iTopData is NULL , the operator create it.<br>
*	  <li> <tt>iBody</tt> : The body of the edge selection<br>
*   <li> <tt>iInputEdgeList</tt> : The list of the first Edges selected<br>
*   <li> <tt>iEdgeGuideList</tt> : The list of pointers on Edges that are first priority during propagation.<br>
*   <li> <tt>iPropagationMode</tt> : The type of propagation :<br>
*     <ul>
*     <li> ChainEdge,<br>
*    </ul>
*   <li> <tt>iStoppingEdges</tt> : It's optional. The list of the edges not to pass through.<br>
*  </ul>
**/  

ExportedByTopPersistentLight CATSelectEdgeOpe * CATCreateSelectEdgeOpe(  CATTopData                            * ipTopData,
                                                                          CATBody                               * ipInputBody,
                                                                          const ListPOfCATEdge                  & iInputEdgeList,
                                                                          CATSelectEdgePropagateMode              iPropagationMode,
                                                                          const ListPOfCATEdge                  * iEdgeGuideList = NULL,
                                                                          const ListPOfCATEdge                  * iStoppingEdges = NULL);

//==============================================================================
// Official Constructor : CATCreateSelectEdgeOpe 2 - with HashTable 
//==============================================================================
/** @nodoc @nocgmitf */
ExportedByTopPersistentLight CATSelectEdgeOpe * CATCreateSelectEdgeOpe( CATTopData                            * ipTopData,
                                                                        CATBody                               * ipInputBody,
                                                                        const CATEdgeHashTable                & iInputEdgeHT,
                                                                        CATSelectEdgePropagateMode              iPropagationMode,
                                                                        const CATEdgeHashTable                * iEdgeGuideHT = NULL,
                                                                        const CATEdgeHashTable                * iStoppingEdgeHT = NULL);

/** @nodoc @nocgmitf */
ExportedByTopPersistentLight CATSelectEdgeOpe * CATCreateSelectEdgeOpe( CATTopData                            * ipTopData,
                                                                        CATBody                               * ipInputBody,
                                                                        const CATEdgeHashTable                & iInputEdgeHT,
                                                                        CATSelectEdgePropagateMode              iPropagationMode,
                                                                        const CATFaceHashTable                & iSubPropagFaceList);



// 
// Export your CSEPropagationFunction 
// example :
//    myfunct (...) {..}
//    CSE_EXPORT_FUNCTION(myfunct)
// 
// -> myfunct function will be named "CSE_myfunct".
// 
#define CSE_EXPORT_FUNCTION(iFunction) \
extern "C" \
{ \
  DSYExport CATBoolean CSE_##iFunction(CATBody *ipBody, CATVertex *iCurrVertex, CATEdge * iCurrEdge, CATEdge *iCandidateEdge) \
  { \
    return iFunction(ipBody, iCurrVertex, iCurrEdge, iCandidateEdge) ; \
  } \
}




#endif

