#ifndef CATRemoveEdge_H
#define CATRemoveEdge_H

// COPYRIGHT DASSAULT SYSTEMES 2008

/**
 * @level Protected
 * @usage U1
 */

#include "CATIACGMLevel.h" // automatic treatment EB_2014_04_16
#include "Thick.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATFace.h"
#include "CATTopOperator.h"
#include "CATTopDefine.h"

class CATBody;
class CATEdge;

/**
 * Class defining the topological operator that removes given Edges on a body.
 */  
class ExportedByThick CATRemoveEdge : public CATTopOperator
{

  CATCGMVirtualDeclareClass(CATRemoveEdge);
public:

  CATRemoveEdge( CATGeoFactory * iFactory,
                 CATTopData    * iTopData,
                 CATBody       * iBody );

  // Destructor (memory is freed and model is cleaned, the resulting body is kept.
  virtual ~CATRemoveEdge();

  /**
  * Appends an edge to remove
  * @param iEdgeToRemove
  * The edge to remove.
  */
  virtual void Append(CATEdge * iEdgeToRemove) = 0;

  /**
  * Appends a list of Edges to remove
  * @param iEdgesToRemove
  * The list of pointers to Edges to remove.
  */
  virtual void Append(const CATLISTP(CATEdge) & iEdgesToRemove) = 0;

  /**
  * Mode de propagation en tangence : 1 = ON, 0 = OFF.
  */
  virtual void SetPropagationMode(short iPropagationMode) = 0;

  /**
  * Defines the state of the resulting body.
  * @param iOnOrOff
  * The state of the resulting body. 
  */
  virtual void SetFreezeMode(CATBodyFreezeMode iOnOrOff) = 0;

  /**
  * @nodoc
  * Appends an edge to remove
  * @param iEdgeToRemove
  * The edge to remove.
  * @param iExtrapolVal
  * An estimation of the required extrapolation value
  */
  virtual void Append(CATEdge *iEdgeToRemove, double iExtrapolVal) = 0;

  /**
  * @nodoc
  * Appends a list of Edges to remove
  * @param iEdgesToRemove
  * The list of pointers to Edges to remove.
  * @param iExtrapolVal
  * An estimation of the required extrapolation value ( the same for all edges )
  */
  virtual void Append(const CATLISTP(CATEdge) & iEdgesToRemove, double iExtrapolVal) = 0;

  /**
  * @nodoc
  * Appends a list of edges to remove
  * @param iEdgesToRemove
  * The list of pointers to edges to remove.
  * @param iExtrapolValList
  * Estimations of required extrapolation values
  */
  virtual void Append(const CATLISTP(CATEdge) &iEdgesToRemove, const CATListOfDouble & iExtrapolValList) = 0;

  /**
  * @nodoc
  * internal RemoveFaceG1G2 option only.
  */
  virtual void SetCouplingMode(short iCouplingMode=1) = 0;

  /**
  * Runs <tt>this</tt> operator.
  */
  virtual int Run() = 0;

  /**
  * Returns the pointer to the resulting body.
  * @return
  * The pointer to the resulting body, <tt>NULL</tt> if the operation failed. 
  * If you do not want to keep the resulting body, 
  * use the @href CATICGMContainer#Remove method to remove it from the 
  * geometric factory, after the operator deletion.
  */
  virtual CATBody* GetResult() = 0;

  /**
  * Returns the list of CATEdge that couldn't be removed.
  */
  virtual void GetAllTrickyEdges(CATLISTP(CATEdge) &oAllTrickyEdges) = 0;

#if defined (CATIACGMR215CAA)
  /**
  * Get the list of faces for which matter side has been reversed.
  * @param oReverseMatterOutputFaces
  * The list of reversed faces.
  */
  virtual void GetReverseMatterOutputFaces(CATLISTP(CATFace) & oReverseMatterOutputFaces) = 0;
#endif

};

ExportedByThick
CATRemoveEdge * CATCreateRemoveEdge( CATGeoFactory * iFactory,
                                     CATTopData    * iTopData,
                                     CATBody       * iBody );

ExportedByThick
CATRemoveEdge * CATCreateRemoveEdge( CATTopData    * iTopData,
                                     CATBody       * iBody );

#endif
