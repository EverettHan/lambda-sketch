#ifndef CATRemoveEdgeExt_H
#define CATRemoveEdgeExt_H
//---------------------------------------------------------------------
// CATRemoveEdgeExt
// 
// Extensible de l'operateur de RemoveEdge.
//
//
// COPYRIGHT DASSAULT SYSTEMES  2011
// 
// --------------------------------------------------------------------
//  Jul. 2011                       Creation                      ZUT
//---------------------------------------------------------------------

#include "Thick.h"
#include "CATDRepExtTopOperator.h"

class ExportedByThick CATRemoveEdgeExt : public CATDRepExtTopOperator
{
public:
  CATRemoveEdgeExt( CATTopOperator * iOperateur = NULL );
  virtual ~CATRemoveEdgeExt();

  CATCGMNewClassArrayDeclare; // Pool allocation

  // Runs the operator
  // NOT IMPLEMENTED
  virtual int RunOperator();

  /**
  * @nocgmitf
  * Defines a maximum extrapolation length for surrounding edges and surfaces
  */
  void SetMaxExtrapolValue(double iMaxExtrapolValue);

  /**
  * @nodoc
  * @nocgmitf
  * Try Local mode
  */
  void SetLocalMode(short iLocalMode);

  //-------------------------------------------------------------------------
  // Set KeepBorderEdges option value
  // 0 : OFF
  // 1 : ON
  //-------------------------------------------------------------------------
  void SetKeepBorderEdges(short iKeepBorderEdges);

  //-------------------------------------------------------------------------
  // Set JournalCreationMode option value
  // 0 : Modification
  // 1 : Creation
  //-------------------------------------------------------------------------
  void SetJournalCreationMode(short iJournalCreationMode);

};

#endif /* CATRemoveEdgeExt_H */
