#ifndef CheckSkin_H
#define CheckSkin_H
//=============================================================================
// Copyright Dassault Systemes 2002-2015, all rights reserved
//=============================================================================
//
// CheckSkin.h
//
//=============================================================================
// Usage notes:
//=============================================================================
// Jan.  02 ASE Creation                                                  ASE
// 11/05/15 HLN Ajout methode CheckTwistedSkin(CATCellHashTable*, ...)
// 01/12/15 HLN Ajout arg. iCheckInsideFace
// 09/07/19 NLD Ajout argument iConfig CheckMaxGapOnShell() pour ComputeMaxGapOnBody()
//=============================================================================
#include "CATBoolean.h"
#include "ListPOfCATBody.h"
#include "CATDynValidShell.h"
#include "ListPOfCATFace.h"
#include "ListPOfCATEdge.h"
#include "ListPOfCATCell.h"// Added By : SUH : 2003:6:3
#include "CATTopTools.h"
#include "RibbonLight.h"

class CATGeoFactory;
class CATSoftwareConfiguration;
class CATShell;
class CATBody;
class CATFace;
class CATTopOpInError;
class CATCGMJournalList;
class CATCGMDiagnosis;
class CATTopData;
class CATCellHashTable;

//------------------------------------------------------------------------------
// Check if a skin or a hash table of faces is twisted and return the first
// twisted face
//
// Please note:
// If a pointer on the optional output list of twisted faces is provided, the
// method will first search all faces of the shell or hash table, and not stop
// on the first detected twist. All twisted faces are then contained in the
// list and first face is returned by the method directly
//------------------------------------------------------------------------------
ExportedByRibbonLight CATFace *CheckTwistedSkin(CATShell                 *iShellToCheck,
                                                CATSoftwareConfiguration *iConfig,
                                                CATLISTP(CATFace)        *oTwistedFaces = NULL,
                                          CATBoolean                iCheckInsideFace = FALSE);

ExportedByRibbonLight CATFace *CheckTwistedSkin(CATCellHashTable         *ihtShellToCheck,
                                                CATSoftwareConfiguration *iConfig,
                                                CATLISTP(CATFace)        *oTwistedFaces = NULL,
                                                CATBoolean                iCheckInsideFace = FALSE);

//------------------------------------------------------------------------------
// Generate a twist error with corresponding data
//------------------------------------------------------------------------------
ExportedByRibbonLight CATTopOpInError *MakeTwistError(CATShell          *iSkin,
                                                      CATLISTP(CATFace) &iTwistedFaces,
                                                      CATGeoFactory     *iFactory);

//------------------------------------------------------------------------------
// Generate a collision error with corresponding data
//------------------------------------------------------------------------------
ExportedByRibbonLight CATTopOpInError *MakeCollisionError(CATShell          *iSkin,
                                                     CATLISTP(CATBody) &iCollisionBodies,
                                                     CATGeoFactory     *iFactory,
                                                     CATBoolean         iForceBlendVertexError = FALSE);

//------------------------------------------------------------------------------
// The methode checks whether iFace is twisted (and returns TRUE if it is)
//------------------------------------------------------------------------------
ExportedByRibbonLight CATBoolean IsTwistedFace(CATFace                  *iFace,
                                               CATBoolean                iDoNewTest = FALSE,
                                               CATSoftwareConfiguration *iConfig    = NULL,
                                               CATBoolean                iCheckInsideFace = FALSE);

//------------------------------------------------------------------------------
// The methode checks face is offsetable
//------------------------------------------------------------------------------
ExportedByRibbonLight CATBoolean IsFaceOffsetable(CATFace                  *iFace,
                                                  CATSoftwareConfiguration *iConfig,
                                                  double                    iOffsetValue);

//------------------------------------------------------------------------------
// Check if a skin is hermetic and return true if it is not
//------------------------------------------------------------------------------
ExportedByRibbonLight CATBoolean CheckUnhermeticSkin(CATSoftwareConfiguration *iConfig,
                                                     CATBody                  *iBodyToCheck,
                                                     CATShell                 *iShellToCheck,
                                                     CATBody                 **oResultBody = NULL);

//------------------------------------------------------------------------------
// donne le nombre de domaine par dimension
//------------------------------------------------------------------------------
ExportedByRibbonLight void GetNbDomainsPerDimension(CATBody *iBody,
                                                    int     &oNbLumps,
                                                    int     &oNbShells,
                                                    int     &oNbWires,
                                                    int     &oNbVertex);

//------------------------------------------------------------------------------
// Check if a skin is topologically valid
//------------------------------------------------------------------------------
ExportedByRibbonLight CATDynValidShellType CheckValidSkin (CATSoftwareConfiguration *iConfig,
                                                           CATGeoFactory            *iFactory,
                                                           CATBody                  *iBodyToCheck,
                                                           CATLISTP(CATBody)        &oListBody);

// Added By : SUH : 2003:6:3
//--------------------------------------------------------------------------------------
// Prefer using the other overload, MakeDiagError(const char        *iMsgId, ....
//
// Generate - if possible - a CATTopOpInError of type iNumberError with diagnosis (error
// bodies). One should make an entry for string identifier associated with iNumberError, 
// if not already there. This string identifier is the same which appears in NLS file.
//
// iListOfCellToShow : The list of cells to be sent with error as the location of error
//--------------------------------------------------------------------------------------
ExportedByRibbonLight CATTopOpInError * MakeDiagError(const int          iNumberError,
                                                      CATGeoFactory     *iFactory,
                                                      const ListPOfCATCell & iListOfCellToShow);

//--------------------------------------------------------------------------------------
// Generate - if possible - a CATTopOpInError with identifier iMsgId (same as appears in
// NLS file) with diagnosis (error bodies)
//
// iListOfCellToShow : The list of cells to be sent with error as the location of error
//--------------------------------------------------------------------------------------
ExportedByRibbonLight CATTopOpInError * MakeDiagError(const char        *iMsgId,
                                                      CATGeoFactory     *iFactory,
                                                  const ListPOfCATCell & iListOfCellToShow);

//------------------------------------------------------------------------------
// Update a list of faces with respect to given body
//------------------------------------------------------------------------------
ExportedByRibbonLight void UpdateListOfSkinFaces(ListPOfCATFace           &iFaces,
                                                 CATListOfInt             &iOrientations,
                                                 CATBody                  *iBody,
                                                 CATCGMJournalList        *iJournal);

//------------------------------------------------------------------------------
// Check maximum G0 or tangency gap on a shell in a body
//------------------------------------------------------------------------------ old
ExportedByRibbonLight CATBoolean CheckMaxGapOnShell
(CATBody                    *iBody,
 CATShell                   *iShell,
 CATCGMDiagnosis           *&oMaxGapOnResultDiagnosis,
 CATTopTools::GapCheckMode   iGapCheckMode = CATTopTools::G0GapCheckMode,
 ListPOfCATEdge             *oGapEdges = NULL);

//------------------------------------------------------------------------------
// Check maximum G0 or tangency gap on a shell in a body
//------------------------------------------------------------------------------new
ExportedByRibbonLight CATBoolean CheckMaxGapOnShell
(CATBody                    *iBody,
 CATShell                   *iShell,
 CATCGMDiagnosis           *&oMaxGapOnResultDiagnosis,
 CATTopTools::GapCheckMode   iGapCheckMode,
 ListPOfCATEdge             *oGapEdges,
 const ListPOfCATEdge       &iListPOfEdgeToCheck,
 CATSoftwareConfiguration   *iConfig    = NULL);


//------------------------------------------------------------------------------
ExportedByRibbonLight CATBoolean CheckBodyShellConnexity(CATSoftwareConfiguration *iConfig,
                                                         CATGeoFactory            *iFactory,
                                                         CATBody                  *iBodyToCheck);

//------------------------------------------------------------------------------
// Check face
//------------------------------------------------------------------------------
ExportedByRibbonLight CATBoolean CheckFace
(CATBody                    *iBody,
 CATFace                    *iFace,
 ListPOfCATEdge             *oListOfEdgeOfNullLength = NULL);

#endif
