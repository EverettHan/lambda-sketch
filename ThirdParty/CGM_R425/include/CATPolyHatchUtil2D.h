/* -*-c++-*- */
#ifndef CATPolyHatchUtil2D_h
#define CATPolyHatchUtil2D_h
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2012
//-------------------------------------------------------------------------------------------------
// CATPGMHatchFaceOperator replay
//-------------------------------------------------------------------------------------------------
 
#include "PolygonalHatching.h"          // ExportedBy

#include "CATListOfInt.h"
#include "CATListOfDouble.h"

#include "CATDataType.h"
#include "CATErrorDef.h"
#include <stdio.h>

#include <iostream.h>

class CATUnicodeString;

class CATPolyHatchResult2D;
class CATPolyHatchPattern2D;
class CATTolerance;

/**
* Interface to manage persistency with CATMathStream/CACGMStream infrastructure
*/
class ExportedByPolygonalHatching CATPolyHatchUtil2D
{ 

public:

  
  //=============================================================================
  // Stream
  static HRESULT WriteResultToFile(CATPolyHatchResult2D & iResult, CATUnicodeString &iFilePath, int iVerbose=0);
  static HRESULT WritePatternToFile(CATPolyHatchPattern2D & iPattern, CATUnicodeString &iFilePath, int iVerbose=0);


  //=============================================================================
  // Unstream
  static CATPolyHatchPattern2D * UnstreamHatchPatternFromFile(CATUnicodeString &iFilePath);


  //=============================================================================
  // Dump 
  static HRESULT DumpResult(CATPolyHatchResult2D & iResult, ostream      & s, int iVerbose);
  static HRESULT DumpPattern(CATPolyHatchPattern2D & iPattern, ostream      & s, int iVerbose);

    
  //=============================================================================
  // Comparison
  static HRESULT CompareResultToRef(CATPolyHatchResult2D & iResult, CATUnicodeString &iRefFilePath, ostream & s, 
                                    const CATTolerance &iTol);


protected:

  static int GetNbWordsOnLine(const char * iFile);
  static HRESULT GoToNextWord(char * &ioFile, int iDoNotSkipLine=0);
  static HRESULT SkipBlanksAndComments(char * &ioFile);
  static HRESULT SkipBlanks(char * &ioFile, int iDoNotSkipLine=0);
  static HRESULT SkipLine(char * &ioFile);


private :

  //------------------------------------------------------------------------
  // Forbidden (Declared, Not Defined) : Constructor by copy  et   operator =
  //------------------------------------------------------------------------
  CATPolyHatchUtil2D(const CATPolyHatchUtil2D &iCopy);
  CATPolyHatchUtil2D& operator=(const CATPolyHatchUtil2D &iCopy);
};

#endif



