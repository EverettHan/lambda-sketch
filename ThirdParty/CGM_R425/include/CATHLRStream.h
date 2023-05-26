/* -*-C++-*-*/
#ifndef CATHLRStream_H
#define CATHLRStream_H

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

// For Windows NT
#include "HLREngine.h"
#include "CATDataType.h"
#include "CATErrorDef.h"

#include <stdio.h>

class CATCGMOutput;
class CATUnicodeString;


class ExportedByHLREngine CATHLRStream
{

public:

  //=============================================================================
  /**
  * Default constructor
  */
  CATHLRStream();
  /**
  * Destructor
  */
  virtual ~CATHLRStream();


  //=============================================================================
  // METHODS
  //=============================================================================


  //=============================================================================
  // Stream
  virtual HRESULT WriteToFile(CATUnicodeString &iFilePath, int iVerbose)=0;


  //=============================================================================
  // Dump 
  virtual HRESULT Dump(CATCGMOutput & s, int iVerbose)=0;

    
  //=============================================================================
  // Comparison
  // oDiffSeverity : output value between 0 (no difference) and 10 (stronger difference)
  virtual HRESULT CompareToFile(CATUnicodeString &iRefFilePath, CATCGMOutput & s, int &oDiffSeverity)=0;


  //=============================================================================
  static HRESULT GoToNextWord(char * &ioFile);
  static HRESULT SkipBlanksAndComments(char * &ioFile);
  static HRESULT SkipBlanks(char * &ioFile);
  static HRESULT SkipInt(char * &ioFile);
  static HRESULT SkipLine(char * &ioFile);
  static HRESULT SkipBlanksThenSpecificString(char * &ioFile, char * iString, int iStringLength);


};

#endif
