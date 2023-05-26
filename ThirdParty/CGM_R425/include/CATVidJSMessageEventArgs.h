//===================================================================
// COPYRIGHT Dassault Systemes 2014-04-11
//===================================================================
// Header definition of class CATVidJSMessageEventArgs
//===================================================================
//  2014-04-11 Creation: D6K
//===================================================================

#ifndef CATVidJSMessageEventArgs_H
#define CATVidJSMessageEventArgs_H

// VisuImmersiveDialog
#include <VisuDialog.h>
#include <CATSYPEventArgs.h>
// UIVCoreTools
#include <CATSYPArray.h>
// SystemTS
#include <DSYString.h>

class CATSYPEvent;

/**
 * Dispatching arguments for JS messages processed by a web browser.
 * Used for calls to the Console API (like console.log()) and dscef.sendString().
 */
class ExportedByVisuDialog CATVidJSMessageEventArgs : public CATSYPEventArgs
{
  CATDeclareClass;

public:
  CATVidJSMessageEventArgs(CATSYPEvent*, const CATSYPConstArray<CATUnicodeString>&, const CATUnicodeString&, const int, const int);
  ~CATVidJSMessageEventArgs();

  /**
   * Returns the message content.
   * If there are multiple messages, it only returns the first one.
   */
  const CATUnicodeString& GetMessage() const;
  /**
   * Returns all the messages.
   */
  const CATSYPConstArray<CATUnicodeString>& GetMessages() const;
  /**
   * Returns the address of the document where this message originated.
   * Returns "<anonymous>" if the call was made in the console or if the info could not be retrieved.
   */
  const CATUnicodeString& GetOrigin() const;
  /**
   * Returns the line number from the document where this message originated.
   * Returns 1 if the info could not be retrieved.
   */
  int GetOriginLine() const;
  /**
   * Returns the column number from the document where this message originated.
   * Always returns 1 for the Console API or if the info could not be retrieved.
   */
  int GetOriginColumn() const;

private:
  CATVidJSMessageEventArgs();
  CATVidJSMessageEventArgs(const CATVidJSMessageEventArgs&);
  CATVidJSMessageEventArgs& operator=(const CATVidJSMessageEventArgs&);

  const CATSYPConstArray<CATUnicodeString> _messages;
  const CATUnicodeString                   _originURL;
  const int                                _originLine;
  const int                                _originColumn;
};

#endif
