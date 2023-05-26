/* -*-C++-*- */

#ifndef CATRibAdvTopOp_H
#define CATRibAdvTopOp_H

// COPYRIGHT DASSAULT SYSTEMES 2008

//------------------------------------------------------------------------------
//
// CATRibAdvTopOp: Base class for Ribbon operators which needs relimitaion 
//
//
//------------------------------------------------------------------------------
// Jun. 08    Creation                                                   SOU
//            All methods previously in CATRibTopOp - Archi purpose
//
//            Responsable                                                PRL
//------------------------------------------------------------------------------

#include "Fillet.h"
#include "CATRibTopOp.h"
#include "CATMathDef.h"
#include "CATTopRibDef.h"
#include "CATCGMNewArray.h"
#include "ListPOfCATBody.h"

class CATBody;
class CATShell;
class CATCGMJournalList;
class CATSoftwareConfiguration;
class CATGeoFactory;
class CATBlendRlm;
class CATIntRibNuplet;
class CATDynTrimSew;

#include "CATSafe.h"
CATSafeDefine(CATRibAdvTopOp);

class ExportedByFillet CATRibAdvTopOp : public CATRibTopOp
{
public:
//===========================================================================================================

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  CATRibAdvTopOp(CATSoftwareConfiguration * iConfig,
                CATCGMJournalList        * iJournal, 
                CATBody                  * iCreationBody);
  CATCGMNewClassArrayDeclare; // Pool allocation

  //------------------------------------------------------------------------------
  // Constructor with CATTopData
  //------------------------------------------------------------------------------
  CATRibAdvTopOp(CATTopData * iTopData,
                CATBody    * iCreationBody);

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  virtual ~CATRibAdvTopOp();

  //------------------------------------------------------------------------------
  // RecalculateTouch on initial faces of unused LoopExtensions
  //------------------------------------------------------------------------------
  void TouchOnUsedLoopExtensions(int           iNbBlendRlm,
                                 CATBlendRlm **iBlendRlm);

  void NeedExtrSurf(CATIntRibNuplet *iNuplet);

  //------------------------------------------------------------------------------
  // Methode de cast 
  //------------------------------------------------------------------------------    
  CATRibAdvTopOp* GetAsRibAdvTopOp() {return this;};


protected:
//===========================================================================================================

  //------------------------------------------------------------------------------
  // Update the Skin with Parting Information
  //------------------------------------------------------------------------------
  virtual void UpdateSkinToSew(CATShell *iSkinToSew, CATBlendRlm ** iBlendRlm, int iNbBlendRlm,
                               CATCGMJournalList  * iJournal=NULL);

  //------------------------------------------------------------------------------
  // Couture avancee
  //------------------------------------------------------------------------------
  void AdvSewing(   CATShell        *iSkinToSew,
                    CATShell        *iInitialShell,
                    ListPOfCATFace  *iDrftInitFaces,
                    CATTopRibSign    iSewingOrientation);
  void AdvSewing_2 (CATShell        *iSkinToSew,
                    CATShell        *iInitialShell,
                    ListPOfCATFace  *iDrftInitFaces,
                    CATTopRibSign    iSewingOrientation);

  //------------------------------------------------------------------------------
  // Check relimitation quality and emit warnings if necessary
  //------------------------------------------------------------------------------
  CATBoolean CheckRelimQuality(int                 iNbBlendRlm,
                               CATBlendRlm       **iBlendRlm);

  //------------------------------------------------------------------------------
  // Generate error bodies from relimitation ribbons
  //------------------------------------------------------------------------------
  int GenerateRelimitationAnalysisBodies(int                 iNbBlendRlm,
                                         CATBlendRlm       **iBlendRlm,
                                         CATBoolean          iShowSkin,
                                         CATBoolean          iDisconnectOrSewingFailure,
                                         CATBoolean          iErrorMode,
                                         CATBoolean          iAddResultBodyToDiag,
                                         CATLISTP(CATBody)  &ioListBodies,
                                         CATLISTP(CATBody)  &ioListContext);

  //------------------------------------------------------------------------------
  // Generate - if possible - a relimitation-type error with
  // diagnostics (error bodies)
  //
  // Please note: 1) the method MUST NOT BE CALLED BEFORE the Run() method
  //              2) the method may return NULL
  //------------------------------------------------------------------------------
  CATTopOpInError *MakeRelimError(CATError     *iOldError,
                                  int           iNbBlendRlm,
                                  CATBlendRlm **iBlendRlm,
                                  CATBoolean    iShowSkin = TRUE,
                                  CATBoolean    iDisconnectOrSewingFailure = FALSE,
                                  CATBoolean    iAddResultBodyToDiag = FALSE);  

  //------------------------------------------------------------------------------
  // Generate - if possible - a relimitation-type error with
  // diagnostics (error bodies)
  //
  // iListOfCellToShow : Liste d'éléments de relimitation ou d'initialisation
  // non encore stockés dans des BlendRlm mais utiles pour analyser la sortie
  // en erreur
  //------------------------------------------------------------------------------
 /* public:
  static CATTopOpInError *MakeRelimError(int            iNumberError,
                                         CATGeoFactory *iFactory,
                                         ListPOfCATCell iListOfCellToShow);*/


  //------------------------------------------------------------------------------
  // Detection de collisions internes de la skin (entre faces non connexes)
  //------------------------------------------------------------------------------
  CATBoolean IntersectSkinFaces(CATShell          *iSkinShell,
                                CATLISTP(CATBody) *oCollisonBodies = NULL);


private:
//===========================================================================================================

  //------------------------------------------------------------------------------
  // Get the indices of the used LoopExtensions
  //------------------------------------------------------------------------------
  void GetIndicesOfUsedLoopExtensions(CATTopRib    *iRib,
                                      CATListOfInt &ioUsedLoopExtIndex,
                                      int          &ioDepthCounter);


protected :
//===========================================================================================================
  
  CATCGMJournalList*               _PrivateJournal;    // Journal de travail
  CATTopData*                      _PrivateTopData;    // Data de travail

  // Pour TrimSew
  CATDynTrimSew*                   _TrimSew;
  CATBoolean                       _ResTSew; // Vrai = resultat du TrimSew est bon
  CATBody*                         _BdyTSew; // Resultat TSew
  ListPOfCATFace                   _SkiFacs;
  ListPOfCATEdge                   _IntEdgs; // Internes
  ListPOfCATEdge                   _BrdEdgs; // Bords
  ListPOfCATEdge                   _BrJEdgs; // a suivre
  ListPOfCATEdge                   _NtrEdgs; // liees au neutre
  ListPOfCATEdge                   _LayEdgs; // bords a poser


};
#endif
