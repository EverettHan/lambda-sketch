// COPYRIGHT Dassault Systemes 2011
//=============================================================================
//
// CATWBParser.h
// Header definition of CATWBParser
//
//=============================================================================
//
// Usage notes: A class for parsing White Boxes equations
//
//=============================================================================
//
//   /02/11     Creation( Benoit PERROT)
// 25/11/19 Q48 Add common utility
//=============================================================================

#ifndef CATWBParser_H
#define CATWBParser_H

// Std
#include <stdio.h>

// CDS
#include "CATCDSListP.h"

// Parser
#include "WhiteBoxParser.h"

// WBx
#include "CATWBBlackBox.h"

// CDS
class CATCDSIntArray;

// WBx
class CATWBFactory;
class CATWBModel;
class CATWBExpression;

// Parser
class CATWBParserMessenger;
class YYLTYPE;

/**
* @brief The CATWBParser class manages the parsing of the formal expressions
*/
class CATWBParser
{
public:
  //WARNING :It is left to the caller to delete the BlackBox created during the parsing !!!!
  static ExportedByWhiteBoxParser int Parse(const char                       * is,
                                                  CATWBModel                 & oModel,
                                                  CATCDSIntArray             & oListId,
                                                  CATWBParserMessenger       & Messenger,
                                                  CATCDSLISTP(CATWBBlackBox) * pBBxList = NULL);

  static ExportedByWhiteBoxParser int Parse(FILE                       * iFile,
                                            CATWBModel                 & oModel,
                                            CATCDSIntArray             & oListId,
                                            CATWBParserMessenger       & Messenger,
                                            CATCDSLISTP(CATWBBlackBox) * pBBxList = NULL);

  static ExportedByWhiteBoxParser CATWBExpression* ReadCATWBExpression(const char                       * iData,
                                                                             CATWBFactory               & ioFactory,
                                                                             CATCDSLISTP(CATWBBlackBox) & oListBBx);
};

#endif
