#ifndef CATLocalOrientationInvert_H
#define CATLocalOrientationInvert_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/*  
=============================================================================

DESCRIPTION  : switches the orientation of an edge or a face with respect to its
               geometric support, accordingly updating the CATSides

               The resulting body is equivalent to the initial one, but has different
               cells wherever specified. This operator helps checking whether other
               operators are local-orientation-sensitive (they should not).
               Handling a journal enables persistent naming if required

               Neither initial body nor final body are "frozen".
               It is advised to do this before and after calling the local orientation
               operator, to enable "undoing" this operation.
*/
#include "Thick.h"
#include "CATTopDef.h"
#include "CATTopData.h"
#include "CATDataType.h" 
#include "CATPGMLocalOrientationInvert.h"
#include "CATMathInline.h"

class CATBody;
class CATFace;
class CATEdge;
class CATCell;
class CATPCurve;
class CATLoop;
class CATTopData;
class CATSmartBodyDuplicator;
class CATCGMJournalList;
class CATGeoFactory;
class CATGeometry;
class CATICGMSmartBodyDuplicator;

class ExportedByThick CATLocalOrientationInvert: public CATPGMLocalOrientationInvert
{
  
public:
  
  // constructor (does nothing but setting the initial body)
  CATLocalOrientationInvert(CATTopData * iTopData, CATBody * iBody);

  // old constructor without CATTopData
  CATLocalOrientationInvert(CATBody * iBody,
                            CATCGMJournalList * iJournal = 0);
  
  // copy constructor and operator = are not implemented (do not call them)
  CATLocalOrientationInvert(const CATLocalOrientationInvert & iShellOrig);
  CATLocalOrientationInvert & operator= (const CATLocalOrientationInvert & iShellRight);

  // destructor (resulting body is not deleted)
  virtual ~CATLocalOrientationInvert();

  // Specifying cells to invert
  // short value returned by AppendCellToInvert = 0 if cell was already in the list, otherwise 1
  // short value returned by RemoveCellToInvert = 1 if cell was already in the list, otherwise 0
  short AppendCellToInvert(CATCell * iCell);
  void AppendListOfCellsToInvert(CATCell ** iCells, CATLONG32 iNumberOfCells);
  short RemoveCellToInvert(CATCell * iCell);
  void RemoveListOfCellsToInvert(CATCell ** iCells, CATLONG32 iNumberOfCells);
  void InvertAllFaces();
  void InvertAllEdges();
  void InvertAllCells();

  // Make local orientations positive or negative (input +1 or -1)
  void SetAllFacesTo(short iOrientation);
  void SetAllEdgesTo(short iOrientation);

  // Set one cell 's orientation, or all cells if cell is ommitted
  void SetOrientation(short iOrientation, CATCell * iCell = 0);

  // Execution 
  void Run();

  // Getting initial and final bodies (final body = null if the operation failed)
  // and get the journal, if it had been giben as input to the constructor
  INLINE CATBody * GetInitialBody() const;
  INLINE CATBody * GetResult() ;
  INLINE CATCGMJournalList * GetJournal() ;

  // Getting internal duplicator
  CATSmartBodyDuplicator * GetDuplicator() const;

  /**
   * Returns the duplicator.
   * @return [out, IUnknown#Release]
   *   The duplicator.
   */
  CATICGMSmartBodyDuplicator * GetIDuplicator() const;

  // internal structures
  struct Wing {
    CATPCurve * _pcrv;
    CATFace *   _fac;
    CATLoop *   _loop;
    CATSide     _sid;
    CATLONG32        _rank;  // rank within loop
    CATLONG32        _looplength;
    short       _ori;   // orientation of edge within loop

    void SmartDuplicate(CATLocalOrientationInvert *iOp, Wing & oDuplicatedWing);
    void Invert();
    friend CATCGMOutput & operator<< (CATCGMOutput& s, const Wing & iObj);
  };

  // internal utility
  void UpdateList(short iDim, CATCell * iBefore, CATCell * iAfter);

private:

  // bodies and factory
  CATBody   * _InitialBody;
  CATBody   * _CurrentBody;
  CATBody   * _ResultBody;
  CATGeoFactory * _Factory;

  // journal
  CATTopData          _FullTopData;
  CATCGMJournalList * _Report;

  // initial cells to be inverted (unset if all faces and or edges must be processed)
  CATLONG32        _NbFaces;
  CATFace  ** _InitFaces;
  CATLONG32        _NbEdges;
  CATEdge  ** _InitEdges;

  short       _AllFaces;
  short       _AllEdges;

  // smart duplicator associated with the initial body
  CATICGMSmartBodyDuplicator * _Duplicator;

  // ---------------
  // private methods

  // Touch cells to be modified (returns number of touched cells)
  CATLONG32 TouchCells(short iOnlyDimension);

  // Faces and Edges inversion
  void InvertFaces();
  void InvertEdges();

  // Utilities
  CATLONG32 LocateCellIndex(CATCell * iCell, short iDim);
  CATLONG32 GetNbCells(short iDim);
  CATCell * GetCell(short iDim, CATLONG32 iIndex);
  void CleanList(short iDim);

  // Scanning cells to be inverted (input null for first, returns null after last)
  CATFace * NextFace(void *& ioIter);
  CATEdge * NextEdge(void *& ioIter);
  short ThereAreCellsToProcess(short iDim);

  // Journal utility
  void JournalizeModification(CATGeometry * iBefore,
                                                         CATGeometry * iAfter);

  // Import into lists _InitFaces & _InitEdges, possibly filtering the orientation
  void ImportAllCells(short iDimension, short iFilterOri=0);
};

// methodes INLINE :
ExportedByThick CATBody * CATLocalOrientationInvert::GetInitialBody() const {
  return _InitialBody; }
ExportedByThick CATBody * CATLocalOrientationInvert::GetResult() {
  return _ResultBody; }
ExportedByThick CATCGMJournalList * CATLocalOrientationInvert::GetJournal()  {
  return _Report; }
#endif

