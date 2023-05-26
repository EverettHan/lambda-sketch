/* -*-C++-*-*/
#ifndef CATHLRResultStream_H
#define CATHLRResultStream_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 2011
//
//
// DESCRIPTION :
//
// CATHLRStream : class to write CATHLRxxxComputer results in a file
//                to compare file contains with another one
//
// Main Methods :
//  
//=============================================================================
// Abstract Class     : No
//=============================================================================
//
// History
//
// May. 2011   Dominique Prevost (dps)    Creation            
//
//=============================================================================

//  derivation
#include "CATHLRStream.h"

// For Windows NT
#include "HLREngine.h"
#include "CATDataType.h"
#include "CATErrorDef.h"

#include <stdio.h>

class CATHLRResultBrowser;
class CATCGMOutput;
class CATUnicodeString;

class ExportedByHLREngine CATHLRResultStream : public CATHLRStream
{

public:

  //=============================================================================
  // CONSTRUCTORS AND DESTRUCTOR
  //=============================================================================
  /**
  * Default Constructor
  */
  CATHLRResultStream(CATHLRResultBrowser &iHLRResult);

  //=============================================================================
  /**
  * Destructor
  */
  virtual ~CATHLRResultStream();


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

  CATHLRResultBrowser & _HLRResult;

};

#endif
