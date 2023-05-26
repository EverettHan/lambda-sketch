//
//  Write WhiteBox epxression / factory to a file in the JSON format
//
//  HISTORY : Creation = Q48 July 2019
//=========================================================================
//  01/07/19 Q48  : Creation
//  08/11/19 Q48  : Improvements to handle stream version
//  28/11/19 Q48  : Stream v3: add parent expression tags (for unstream)
//  18/11/19 R1Y  : Added WriteToString()
//  13/01/20 Q48  : Migrated to CATWBx - now uses local JSON classes
//=========================================================================

#ifndef WBxWriteJSON_h
#define WBxWriteJSON_h

// Exported by
#include "WhiteBoxStream.h"

// Utility
#include "CATCDSVirtual.h"

// CDS
#include "CATCDSBoolean.h"
#include "CATCDSString.h"
#include "CATCDSIntArray.h"

// WBx
class CATWBFactory;
class CATWBExpression;

// Debug
#include "CATWBDebug.h"

// ===============================================================================
// Top-level writer class
// ===============================================================================

class ExportedByWhiteBoxStream WBx2JSON
{
public:
  
  // Official constructor
  WBx2JSON(const CATWBFactory & iFactory);

  // Destructor
  virtual ~WBx2JSON();

  int GetVersionOfStream() const;

  void Append(const CATWBExpression * iExpr);
  //void Append(CATWBFactory & iFactory); // not implemented yet

  CATCDSBoolean WriteToFile(const CATCDSString & iFilePath)/* const*/;

  CATCDSBoolean WriteToString(CATCDSString & oString)/* const*/;

protected:

  // Stream versioning
  friend class ODT_StreamJSON;
  void ForceVersionOfStream(const int iForcedLevel);
  static int GetVersionOfStreamDefault();

  // Internal methods
  void AppendProtected(const CATWBExpression * iExpr);

private:

  int _VersionOfStream;

  const CATWBFactory & _Factory;

  CATCDSIntArray _ExprTags;
  CATCDSIntArray _ParentExprTags;
  
  // Debug
  // -----

  WBX_DEBUG_DECLARE;
};
#endif // WBxWriteJSON_h
