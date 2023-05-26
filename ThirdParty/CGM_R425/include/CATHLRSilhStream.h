/* -*-C++-*-*/
#ifndef CATHLRSilhStream_H
#define CATHLRSilhStream_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2008
//
//
// DESCRIPTION :
//
// CATHLRSilhStream : class to write CATHLRSilhouetteComputer results in a file
//                          to compare file contains with another one
//
// Main Methods :
//  
//=============================================================================
// Abstract Class     : No
//=============================================================================
//
// History
//
// Dec. 08   Dominique Prevost (dps)    Creation            
//
//=============================================================================

//  derivation
#include "CATHLRStream.h"

// For Windows NT
#include "HLREngine.h"
#include "CATDataType.h"
#include "CATErrorDef.h"

#include <stdio.h>

class CATHLRSilhouetteComputer;
class CATCGMOutput;
class CATUnicodeString;


class ExportedByHLREngine CATHLRSilhStream : public CATHLRStream
{

public:

  //=============================================================================
  // CONSTRUCTORS AND DESTRUCTOR
  //=============================================================================
  /**
  * Default Constructor
  */
  CATHLRSilhStream(CATHLRSilhouetteComputer &iSilhOp);

  //=============================================================================
  /**
  * Destructor
  */
  virtual ~CATHLRSilhStream();


  //=============================================================================
  // METHODS
  //=============================================================================


  //=============================================================================
  // Stream
  virtual HRESULT WriteToFile(CATUnicodeString &iFilePath, int iVerbose);


  //=============================================================================
  // Dump 
  virtual HRESULT Dump(CATCGMOutput & s, int iVerbose);

    
  //=============================================================================
  // Comparison
  // oDiffSeverity : output value between 0 (no difference) and 10 (stronger difference)
  virtual HRESULT CompareToFile(CATUnicodeString &iRefFilePath, CATCGMOutput & s, int &oDiffSeverity);


  //=============================================================================
  // INTERNAL DATAS
  //=============================================================================
private:

  CATHLRSilhouetteComputer & _SilhOp;

};

#endif
