/* -*-C++-*- */
#ifndef CATComplFace_H
#define CATComplFace_H
// COPYRIGHT DASSAULT SYSTEMES 1998
//-----------------------------------------------------------------------------
// 26/03/98    Creation                                       Francois Dujardin
// 21/12/98    Gestion UseCount                               Remy Rorato
// 31/07/00    Integration LoopExtension                      Pascal Rossignol
//
//             Responsable                                    Pascal Rossignol
//-----------------------------------------------------------------------------
//#include "ExportedByCATFDGImpl.h"
#include "ExportedByRIBLight.h"
#include "CATMathDef.h"
#include "CATTopDef.h"
#include "CATTopRibDef.h"
#include "CATListPV.h"
#include "CATCGMVirtual.h"
#include "CATMathInline.h"

class CATLoop;
class CATFace;
class CATVertex;
class CATCell;
class CATBody;
class CATTopRibNuplet;
class CATLoopExtension;
class CATSoftwareConfiguration;

//-----------------------------------------------------------------------------
//
// CATComplFace
// Classe "complementaire de face"
//
// contient : - une face
//            - son complementaire (ayant le meme side)
//            - la loop ayant servit a complementariser la face
//-----------------------------------------------------------------------------
class ExportedByRIBLight CATComplFace : public CATCGMVirtual
{
public :

  //CATComplFace(CATBody* iCreationBody, CATFace* iInitialFace, CATLoop* iInitialLoop, CATSoftwareConfiguration* iConfig); 
  CATComplFace(CATBody*                  iCreationBody,
               CATFace*                  iInitialFace,
               CATLoop*                  iInitialLoop,
               CATSoftwareConfiguration* iConfig,
               CATFace*                  iComplementaryFace,
               CATLoop*                  iCreatedLoop,
               CATBoolean                iLinkIsOnBorder = TRUE);
  CATComplFace(); // Makes an empty CATComplFace
  ~CATComplFace() ;

  // Set this CATComplFace to Empty.
  // Raise exception whenever this is still referenced to.
  // Remove ComplementaryFace is it has not been exported.
  void Reset() ; 
  
  // The ComplementaryFace will not be removed by Reset or Set.
  CATFace*  ExportComplementaryFace() ;

  // The ComplementaryFace will be removed by Reset or Set.
  CATFace*  UnExportComplementaryFace() ;

  // Find out whether the complementary face has been exported
  CATBoolean HasComplementaryFaceBeenExported();

  // Copy the loop of iFace on the ComplementaryFace
  void CopyFace(CATFace* iFace, CATBoolean iReverseLocation);

  // Data access
  INLINE CATBody* GetCreationBody() const ;
  INLINE CATFace* GetInitialFace() const ;
  INLINE CATFace* GetComplementaryFace() const ;
  INLINE CATLoop* GetInitialLoop() const ;
  INLINE CATLoop* GetCreatedLoop() const ;
  INLINE CATLoopExtension* GetLoopExtension() const ;
  INLINE void SetLoopExtension(CATLoopExtension *iLoopExtension) ;
  INLINE CATBoolean IsLinkOnBorder();
  // Utility
  static void CopyLoop(CATLoop &iLoop, CATFace &iFace, CATLoop &oLoop, CATFace &Face, const CATBoolean iSwithLocation);

  // Find out if a given cell is in _Link (the method
  // returns _Link if this is true and NULL otherwise)
  CATLoop * IsCellOnLink(CATCell    * iLinkCell       ,
                         CATBoolean   iManageLyingOn=0);

  // Store the nuplets lying on the complementary face
  void AppendNuplet(CATTopRibNuplet * iNuplet         ,
                    int               iNumSupp        ,
                    int             * ioNumList  =NULL,
                    int             * ioPosInList=NULL,
                    CATOrientation  * ioOrient   =NULL);

  // Remove unnecessary extrapolation ribbon 
  void RemoveUnnecessaryExtrRib();

  // special cas de confusion (HFV)
  void       SetSpcConfused();
  CATBoolean GetSpcConfused();
  CATLoop*   GetSpcIniLoop();


private :

  /* Copy constructor. Not implemented */
  CATComplFace(CATComplFace &iComplFace);

  /* Affectation operator. Not implemented */
  CATComplFace& operator=(const CATComplFace &iComplFace);

  // Return the end vertex of a nuplet list 
  CATVertex * GetEndVertex(int iNumList, CATTopRibSign iDirection);

  // Concat the lists of nuplets who share the same end vertex
  void ConcatNupletList();
  
  //-----------------------------------------------------------------------------
  // Data
  //-----------------------------------------------------------------------------
  CATFace            *_Ini ;
  CATFace            *_Compl ;
  CATLoop            *_Link ;
  CATLoop            *_LinkConf;
  CATLoop            *_CreatedLoop ;
  CATLoopExtension   *_LoopExtension;
  CATBoolean          _ComplFaceHasBeenExported ;
  CATBoolean          _SpcConfused ;
  CATListPV          *_ListPOfNupletLists;
  CATListPV          *_ListPOfOrientLists;
  CATListPV          *_ListPOfPositionLists;
  CATBody            *_CreationBody ;
  CATBoolean          _LinkIsOnBorder;
  CATSoftwareConfiguration* _SoftwareConfiguration;
};

INLINE CATBody* CATComplFace::GetCreationBody() const       { return _CreationBody  ; } ;
INLINE CATFace* CATComplFace::GetInitialFace() const        { return _Ini           ; } ;
INLINE CATFace* CATComplFace::GetComplementaryFace() const  { return _Compl         ; } ;
INLINE CATLoop* CATComplFace::GetInitialLoop() const        { return _Link          ; } ;
INLINE CATLoop* CATComplFace::GetCreatedLoop() const        { return _CreatedLoop   ; } ;
INLINE CATLoopExtension* CATComplFace::GetLoopExtension() const      { return _LoopExtension ; } ;
INLINE void CATComplFace::SetLoopExtension(CATLoopExtension *iLoopExtension) {
  _LoopExtension = iLoopExtension; } ;
INLINE CATBoolean CATComplFace::IsLinkOnBorder() {
  return _LinkIsOnBorder; } ;
#endif
