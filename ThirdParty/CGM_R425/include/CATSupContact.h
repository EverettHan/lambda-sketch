/* -*-C++-*- */

#ifndef CATSupContact_H
#define CATSupContact_H

// COPYRIGHT DASSAULT SYSTEMES 1997

//===================================================================
//===================================================================
//
// CATSupContact
// Classe servant a stocker les infos permettant de determiner les 
// prochains supports d'un support 
//
//===================================================================


//===================================================================
// Usage notes:
//
//===================================================================

//===================================================================
// June. 97 JGD Creation                                 J-M.Guillard
// 20/02/20 NLD Ajout Init()
//===================================================================
//===================================================================

#include "RibbonLight.h"   
#include "CATTopRibObject.h"
#include "CATMathDef.h" 
#include "CATMathInline.h"
#include "CATTopDef.h"
#include "CATTopRibDef.h"
#include "CATCell.h"
#include "CATVertex.h"
#include "CATEdge.h"
#include "CATFace.h"

class CATSoftwareConfiguration;
class CATBody;
class CATBody;
class CATCrvParam;
class CATSurParam;
class CATTopRibNuplet;
class CATMathVector;

class CATTopRibMacroTool;

#include "CATCGMNewArray.h"   // Pool allocation

//#define dbg_supcontact
// PRL: a decommenter pour tracker les MLKs apparus suite a la 
// protection des donnees de CATSupContact avec AddRef/Release/IsNull
// NB:  les MLKs CATSupContact, meme alloues par pool, ne sont pas vus par
//      codes 77 car ils sont alloues en tableau. 
//      Ex : CATSupContact *InExContact = new CATSupContact[NbSupp];
#ifdef  dbg_supcontact
#include "CATCGMOutput.h"
#endif

#include "CATSafe.h"
CATSafeDefine(CATSupContact);

class ExportedByRibbonLight CATSupContact : public CATTopRibObject
{
 public: 

#ifdef  dbg_supcontact
   //static CATListPV Dbg_Contacts;
#endif

  //------------------------------------------------------------------------------
  // Constructors
  //------------------------------------------------------------------------------
  CATCGMNewClassArrayDeclare; // Pool allocation

  CATSupContact              (CATVertex* iEndVertex) ;
  CATSupContact              (CATVertex* iEndVertex, CATCell* iBaseCell) ;
  CATSupContact              (CATVertex* iEndVertex, CATCell* iLinkCell, CATCell* iTrack,
                              CATCell* iBaseCell, const int iTypeContact                ) ;
  CATSupContact              (const CATSupContact & iContactToCopy);
  CATSupContact & operator = (const CATSupContact & iContact);
  CATSupContact              (CATTopRibNuplet* iNuplet, const int iNumSupp, const double iRatioOnTrack); 
  CATSupContact              ();

  void Clear();
  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  virtual ~CATSupContact();

  //------------------------------------------------------------------------------
  // Data Access (Set/Get)
  //------------------------------------------------------------------------------
  INLINE CATVertex* GetEndVertex      () const { /* ThrowIfIsNull(_EndVertex, NULL, NULL, NULL);*/  return _EndVertex         ; };
  INLINE CATCell*   GetLinkCell       () const { /* ThrowIfIsNull(NULL,  _LinkCell, NULL, NULL);*/  return _LinkCell          ; };
  INLINE CATCell*   GetBaseCell       () const { /* ThrowIfIsNull(NULL,  NULL, NULL, _BaseCell);*/  return _BaseCell          ; };
  INLINE CATCell*   GetTrackCell      () const { /* ThrowIfIsNull(NULL, NULL, _TrackCell, NULL);*/  return _TrackCell         ; };
  INLINE int        GetContactType    () const {                                                    return _TypeContact       ; };
  INLINE CATCell*   GetUpperLinkCell  () const {                                                    return _UpperLinkCell     ; }; 
  INLINE CATBoolean IsConfusedLinkCell() const {                                                    return _LinkCellIsConfused; };

  void         SetEndVertex         (CATVertex* iVertex      ) ;
  void         SetLinkCell          (CATCell*   iCell        ) ;
  void         SetBaseCell          (CATCell*   iCell        ) ;
  void         SetTrackCell         (CATCell*   iCell        ) ;
  INLINE void  SetContactType       (const int  iContactType ) { _TypeContact = iContactType; };
  void         SetUpperLinkCell     (CATCell*   iCell     ) ;
  void         SetLinkCellAsConfused();
  void         Set                  (CATVertex* iEndVertex, CATCell* iLinkCell, CATCell* iTrackCell, CATCell* iBaseCell,
                                     const int iContactType,
                                     const CATBoolean iLinkCellAsConfused) ;

  //------------------------------------------------------------------------------
  // Replaces EndVertex, LinkCell and/or TrackCell by iNewVertex 
  // whenever equal to iOldVertex.
  //------------------------------------------------------------------------------
  void       SwapCell(CATVertex* iOldVertex, CATVertex* iNewVertex);

  //------------------------------------------------------------------------------
  // Returns position of this contact with regards to the support of a face or an edge.
  // Throws an exception whenever no topological link is found.
  //------------------------------------------------------------------------------
  void GetCrvParam(CATEdge* iEdge, CATCrvParam & oCrvParam) const ;
  void GetSurParam(CATSoftwareConfiguration * iConfig, CATFace* iFace, CATSurParam & oSurParam) const ;

  //------------------------------------------------------------------------------
  // Returns LinkCell Side with regards to BaseCell.
  //------------------------------------------------------------------------------
  CATSide GetLinkCellSideVsBaseCell() const ;

  //------------------------------------------------------------------------------
  // Evalue (si valeur de retour = TRUE ) la sharpness globale sur la linkcell
  // (Edge seulement)
  //------------------------------------------------------------------------------
  CATBoolean EvalGlobalSharpnessOfLink(CATTopRibMacroTool *iMacroTool, CATTopRibSharpness &oGlobalSharpness) const;

  //------------------------------------------------------------------------------
  // Evaluate Existing Gap on Support (at least Resolution)
  //------------------------------------------------------------------------------
  CATPositiveLength EvalGapOnLink(CATSoftwareConfiguration* iConfig) const;

  //------------------------------------------------------------------------------
  // Evalue (si valeur de retour = TRUE ) la sharpness sur la linkcell
  // (Edge seulement) et retourne la valeur de l'angle
  //------------------------------------------------------------------------------
  CATBoolean EvalSharpnessOnLink (CATTopRibMacroTool *iMacroTool, CATTopRibSharpness &oSharpness, double & oAngleOfSharpness) const;

  //------------------------------------------------------------------------------
  // Evalue (si valeur de retour = TRUE ) l'angle (entre 0 et PI/2) entre
  // la trace (Edge seulement) et la LinkCell (Edge seulement).
  // Modified By : AJD : 2004:4:12
  // IncidenceVector = TrackEdgeDirection ^ LinkEdgeDirection
  //------------------------------------------------------------------------------
  CATBoolean EvalAngleOfIncidence(double & oAngleOfIncidence, CATMathVector *oIncidenceVector = 0) const;

  //------------------------------------------------------------------------------
  // To use to protect the cutting links of the end vertex 
  //------------------------------------------------------------------------------
  void AddRefOnEndVertex(CATTopRibMacroTool *iMacroTool, CATBoolean iSetCutting=FALSE);

  // A terme, il faudra le stocker a la creation du CATSupContact pour lever les ambiguites
  // private :
  // CATSide                     _LinkEdgeSideOnBaseFace ;

  //------------------------------------------------------------------------------
  // Destroy the Vertex
  //------------------------------------------------------------------------------
  void DestroyVertex();

  //------------------------------------------------------------------------------
  // Unset cutting of _EdgeForEV 
  //------------------------------------------------------------------------------
  void UnsetCuttingOnEdgeForEV();

  //------------------------------------------------------------------------------
  // Data Protection
  //------------------------------------------------------------------------------
  void AddRef       (CATVertex* iEndVertex, CATCell* iLinkCell, CATCell* iTrack, CATCell*   iBaseCell);
  void Release      (CATVertex* iEndVertex, CATCell* iLinkCell, CATCell* iTrack, CATCell*   iBaseCell);
  void ThrowIfIsNull(CATVertex* iEndVertex, CATCell* iLinkCell, CATCell* iTrack, CATCell*   iBaseCell) const;

  //------------------------------------------------------------------------------
  // Dump internal data
  //------------------------------------------------------------------------------
  void Dump( CATCGMOutput& ioOS );

  //------------------------------------------------------------------------------
  // Display 
  //------------------------------------------------------------------------------
  void Display(const int iR=7, const int iG=7, const int iB=7, CATLISTP(CATGeometry) * iCreatedObject=NULL);

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------
  private :

  // 
  void        Init    ();

  // Internal data member modification
  void        SetCell ( CATCell * iCell, CATCell *& ioRefCell ); 

  CATVertex                  * _EndVertex;
  CATCell                    * _LinkCell;
  CATCell                    * _TrackCell;
  CATCell                    * _BaseCell;
  int                          _TypeContact;
  CATBoolean                   _LinkCellIsConfused;  
  CATBoolean                   _EdgeForEVwasSetCutting;
  CATEdge                    * _EdgeForEV;
  CATCell                    * _UpperLinkCell;
  CATBody                    * _CreationBody;
  CATSoftwareConfiguration   * _SoftwareConfiguration;
};

#endif 


