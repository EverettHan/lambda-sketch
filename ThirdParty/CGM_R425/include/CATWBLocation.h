// ============================================================================
// COPYRIGHT Dassault Systemes 2011
// ============================================================================
//
// CATWBLocation
// Bison-compatible location tracker
//
// ============================================================================
// 2011-10-03 BPG
// ============================================================================
#ifndef CATWBLocation_H
#define CATWBLocation_H

#include "WhiteBoxModel.h"
#include "CATCDSString.h"
#include "CATCDSListP.h"



class ExportedByWhiteBoxModel CATWBLocation
{
  /** @name Constructors and destructors
      @{ */
public:
  CATWBLocation();
  CATWBLocation(const CATWBLocation &l);
  ~CATWBLocation();
  /** @} */

  /** @name Accessors
      @{ */
public:
  void GetLocation(int & oFirstLine,int & oFirstColumn,int & oLastLine, int & oLastColumn) const;
  int GetFirstLine() const;
  int GetFirstColumn() const;
  int GetLastLine() const;
  int GetLastColumn() const;

  void SetLocation(int iFirstLine,int iFirstColumn,int iLastLine, int iLastColumn);
  void SetFirstLine(int l);
  void SetFirstColumn(int c);
  void SetLastLine(int l);
  void SetLastColumn(int c);
  
  CATCDSBoolean Compare(const CATWBLocation & iLocationtoCompare) const;

//name Steppers
public:
  void IncrementLastColumn(int n);

  void NextLine();

  void Reset();

  void Step();

 CATCDSString  Write() const ;

  /** @name Members
      @{ */
private:
  int _FirstLine;
  int _FirstColumn;

  int _LastLine;
  int _LastColumn;
  /** @} */
};

CATCDSLISTP_DECLARE_EXPORTED(CATWBLocation, ExportedByWhiteBoxModel);

#endif // !CATWBLocation_H
