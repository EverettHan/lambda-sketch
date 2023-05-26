#ifndef CATRemoveFaceExt_H
#define CATRemoveFaceExt_H
//---------------------------------------------------------------------
// CATRemoveFaceExt
// 
// Extensible de l'operateur de RemoveFace.
//
//
// COPYRIGHT DASSAULT SYSTEMES  2011
// 
// --------------------------------------------------------------------
//  Jul. 2011                       Creation                      ZUT
//---------------------------------------------------------------------

#include "Thick.h"
#include "CATDRepExtTopOperator.h"
#include "ListPOfCATFace.h"
#include "CATListOfInt.h"

class ExportedByThick CATRemoveFaceExt : public CATDRepExtTopOperator
{
public:
  CATRemoveFaceExt( CATTopOperator * iOperateur = NULL );
  virtual ~CATRemoveFaceExt();

  CATCGMNewClassArrayDeclare; // Pool allocation

  // Runs the operator
  // NOT IMPLEMENTED
  virtual int RunOperator();

  // VoB
  virtual CATBoolean IsVoBSupported();

  // Mode optimise pour les operations locales
  void SetLocalRFMode( short iLocalRFMode );

  // Returns the list of CATFace that couldn't be removed.
  // iFacesToRemoveOnly : Do not include faces that do not belong to the list of faces to be removed
  // iSortDiags : Sort and group tricky faces according to their diagnosis (descending order)
  void GetAllTrickyFaces( CATLISTP(CATFace) & oAllTrickyFaces, CATListOfInt & oAllDiag, short iFacesToRemoveOnly, short iSortDiags=0 );

  /**
  * Get the list of faces for which matter side has been reversed.
  * @param oReverseMatterOutputFaces
  * The list of reversed faces.
  */
  void GetReverseMatterOutputFaces(CATLISTP(CATFace) & oReverseMatterOutputFaces);

  // Defines a maximum extrapolation length for surrounding edges and surfaces
  void SetMaxExtrapolValue(double iMaxExtrapolValue);

  // Permet au client d'indiquer s'il veut calculer la shape Delta à l'issue de RemoveFace
  void  SetDeltaShapeComputation(short iDeltaShapeComputation);

  // Suppression d'une liste de faces avec relimitation par un body objectif
  void AppendUpToBody(const CATLISTP(CATFace) & iFacesToRemove, CATBody * iUpToBody, CATOrientation iOri = CATOrientationPositive);
};

#endif /* CATRemoveFaceExt_H */
