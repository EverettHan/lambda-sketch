/* -*-C++-*- */

#ifndef CATTopRemoveFaceG1G2OpeBridge_H
#define CATTopRemoveFaceG1G2OpeBridge_H

// COPYRIGHT DASSAULT SYSTEMES 2003

// Class and functions are @nodoc and will soon be destroyed : Do not use

//=============================================================================
//=============================================================================
//
// CATTopRemoveFaceG1G2OpeBridge : Pile "Topo" du Pont logiciel
//                                 permettant l'utilisation du VarOffset
//                                 dans le fw Topo.
//
// Classe abstraite qui permet d'appeler les fonctions de VarOffset
// via le pont
// + definition de la fonction de chargement dynamique de la librairie
//
//=============================================================================

//=============================================================================
// April  2008  Creation                                        L. Marini
//=============================================================================
//=============================================================================

// Pour le ExportedByThick
#include "Thick.h"

// Includes 
#include "CATCGMVirtual.h"
#include "CATBodyFreezeMode.h"
#include "ListPOfCATFace.h"
#include "ListPOfListPOfCATEdge.h"   // todo : a supprimer
#include "CATCGMJournal.h"
#include "CATTopDefine.h"
#include "CATBoolean.h"
#include "CATCGMInterruptDef.h"
#include "CATRemoveFaceG1G2ContactType.h"
#include "ListPOfCATPersistentBodies.h"
#include "IUnknown.h"

class CATTopRemoveFaceG1G2OpeBridge;
class CATGeoFactory;
class CATTopData;
class CATBody;
class CATTopOperator;
class CATCGMProgressBar;
class CATPersistentCellInfra;
class CATPersistentBody;
class CATTopJournalSpy;
class CATlsoPersistentContext;
class CATPGMDRepBehavior;

typedef CATTopRemoveFaceG1G2OpeBridge*  (*CATRemoveFaceG1G2OpeBridgeCreator)  
                                  (CATGeoFactory        & iFactory,
                                   CATTopData           & iTopData,
                                   CATBody              & iBody,
                                   const ListPOfCATFace & iFacesToRemove);

typedef CATTopRemoveFaceG1G2OpeBridge*  (*CATRemoveFaceG1G2OpeBridgeCreator2)  
                                  (CATGeoFactory          & iFactory,
                                   CATTopData             & iTopData,
                                   CATPersistentBody      & iPBody,
                                   const ListPOfCATFace   & iFacesToRemove,
                                   CATPersistentCellInfra & iPersistentCellInfra);

class ExportedByThick CATTopRemoveFaceG1G2OpeBridge : public CATCGMVirtual
{

public :

  //------------------------------------------------------------------------------
  // Destructeur
  //------------------------------------------------------------------------------
  virtual ~CATTopRemoveFaceG1G2OpeBridge() {};

  /**
  * Appends a list of faces to remove
  * @param iFacesToRemove
  * The list of pointers to faces to remove.
  */
  virtual void Append(const CATLISTP(CATFace) &iFacesToRemove)=0; 

  /**
  * Appends a list of faces allowed to be removed
  * @param iFacesToRemove
  * The list of pointers to faces to potentially remove.
  */
  virtual void AppendCandidate(const CATLISTP(CATFace) &iFacesToRemove)=0;

  /**
  * Defines the state of the resulting body.
  * @param iOnOrOff
  * The state of the resulting body. 
  */
  virtual void SetFreezeMode(CATBodyFreezeMode iOnOrOff)=0;

  /**
  * permet au client d'indiquer si l'on va ajouter (iMatterDirection = 1)
  * ou supprimer (iMatterDirection = -1) de la matiere pour obtenir
  * le resultat du RemoveFace.
  */
  virtual void SetMatterDirection(short iMatterDirection)=0;

  /**
  * option spécifique pour AutoDraft. 
  * essaie d'enlever les paquets de faces connexes séparément si sortie en 
  * erreur avec toutes les faces.
  */
  virtual void SetPartialRemoveFaceAllowed(short iPartialRemoveFaceAllowed)=0;

  virtual void GetTrickyFaces(CATLISTP(CATFace) &oTrickyFaces)=0;

  virtual void AppendG1G1Zone(CATLISTP(CATEdge)            &  iListOfG1Edges1,
                              CATLISTP(CATEdge)            &  iListOfG1Edges2,
                              CATOrientation                  iEdgesListOrientations[2],
                              double                          iExtrapolValues[2],
                              CATRemoveFaceG1G2ContactType    iContactTypes[2],
                              CATLISTP(CATFace)               iCapFaces[2])=0;

  virtual void AppendG1G2Zone(CATLISTP(CATEdge)            &  iListOfG1Edges,
                              CATLISTP(CATEdge)            &  iListOfG2Edges,
                              CATOrientation                  iEdgesListOrientations[2],
                              double                          iExtrapolValues[2],
                              CATRemoveFaceG1G2ContactType    iContactType,
                              CATLISTP(CATFace)               iCapFaces[2])=0;

  virtual void AppendG2G2Zone(CATLISTP(CATEdge) &  iListOfG2Edges1,
                              CATLISTP(CATEdge) &  iListOfG2Edges2,
                              CATOrientation       iEdgesListOrientations[2],
                              CATBody           *  iLimitingBodies[2],
                              CATLISTP(CATFace)    iCapFaces[2])=0;

  virtual void AppendTriTangentZone(CATLISTP(CATEdge) & iListOfEdgesSide1,
                                    CATLISTP(CATEdge) & iListOfEdgesSide2,
                                    CATOrientation      iEdgesListOrientations[2],
                                    short               iExtrapolationType[2],
                                    CATLISTP(CATFace) & iListOfFacesToRemove)=0;


  //-------------------------------------------------------------
  //GET Methods
  //------------------------------------------------------------- 

  /**
  * Returns the pointer to the resulting body.
  * @return
  * The pointer to the resulting body, <tt>NULL</tt> if the operation failed. 
  * If you do not want to keep the resulting body, 
  * use the @href CATICGMContainer#Remove method to remove it from the 
  * geometric factory, after the operator deletion.
  */
  virtual CATBody * GetResult() const = 0;
  virtual CATBody * GetLiveResult() const = 0;

  virtual CATCGMJournalList * GetJournal() = 0;

  //-------------------------------------------------------------
  //  Gestion des interruptions
  //------------------------------------------------------------- 

  /**
  * Method to provide the "progress bar display and interrupt query" function
  * (Creates automatically the current progress bar if undefined)
  */
  virtual void SetProgressBarFunction ( CATCGMInterruptFunction ipInterruptFunction ) = 0;

  /**
  * Set the "parent progress bar" to progress bar of this operator
  * (Creates automatically the current progress bar if undefined)
  * iParentProgressBar : Parent progress bar
  * iStartPercentage, iEndPercentage : Start and End percentages of the current progress bar inside parent progress bar range
  * Sample : If the current operator will go from 20% to 80% of the total range of the parent operator,
  *          set iStartPercentage = 20.0 and iEndPercentage = 80.0
  */
  virtual void SetParentProgressBar ( CATCGMProgressBar * iParentProgressBar, 
                                      const double iStartPercentage = 0.0, const double iEndPercentage = 100.0 ) = 0;

  virtual CATCGMProgressBar * GetProgressBar() = 0;

  //-------------------------------------------------------------
  //  Gestion du DRepBehaviour
  //------------------------------------------------------------- 

  virtual void SetDRepBehavior ( CATPGMDRepBehavior * iDRepBehavior ) = 0;

  //-------------------------------------------------------------
  // RUN Method
  //------------------------------------------------------------- 
  virtual int Run()=0;

  virtual HRESULT RunByPersistentInfra( CATPersistentCellInfra     *  iInfra,
                                        ListPOfCATPersistentBodies  & iInputBodies,
                                        CATPersistentBody          *& oOutputBody,
                                        CATlsoPersistentContext    *  iFatherContext,
                                        CATTopJournalSpy           *  iJournalSpy,
                                        CATBoolean                    iGetTypeFromJournal,
                                        CATBoolean                    iCreateManifolds = FALSE ) = 0;


private:
  //===========================================================================================================

};

//------------------------------------------------------------------------------
// Creation d'un objet cree comme un CATTopRemoveFaceG1G2OpeBridge 
//                     & vu comme un CATRemoveFaceG1G2Ope
//------------------------------------------------------------------------------
ExportedByThick CATTopRemoveFaceG1G2OpeBridge * CATCreateTopRemoveFaceG1G2OpeBridge(CATGeoFactory        & iFactory,
                                                                                          CATTopData           & iTopData,
                                                                                          CATBody              & iBody,
                                                                                          const ListPOfCATFace & iFacesToRemove);

ExportedByThick CATTopRemoveFaceG1G2OpeBridge * CATCreateTopRemoveFaceG1G2OpeBridge(CATGeoFactory        & iFactory,
                                                                                          CATTopData           & iTopData,
                                                                                          CATPersistentBody    & iPBody,
                                                                                          const ListPOfCATFace & iFacesToRemove,
                                                                                          CATPersistentCellInfra & iPersistentCellInfra);
#endif

