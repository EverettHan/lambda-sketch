#ifndef __CATA5Parser_h__
#define __CATA5Parser_h__ 1

#include "CATA5ParserExport.h"

#include "CATSysMacroPtr.h"
#include "CATAssert.h"

#include "CATOmxSharable.h"
#include "CATOmxArray.h"
#include "CATOmxUTF8String.h"
#include "CATOmxSR.h"
#include "CATOmxList.h"
#include "CATOmxTextStream.h"

#include "CATA5CsvContext.h"
#include "CATA5CsvRow.h"
#include "CATA5TclNode.h"
#include "CATA5ParserListener.h"
#include "CATA5Enums.h"

// FIXME hard to remove may hang (need a PutNoWait)
#define CATA5Parser_NO_WAIT 10000000

namespace CATA5
{
  const int ROW_IS_SEEN = 0x1;

  struct ErrorInfo
  {
    ParseStatus status; // state of parser
    int line;  // number of processed line
    int count; // number of processed row
    CATOmxUTF8String info; // optional error info

    CATUnicodeString GetLine() const
    {
      CATUnicodeString strLine;
      strLine.BuildFromNum(line);
      return strLine;
    }
  };

  /*
  * Abstract parser.
  * It can be implemented to support different returned formats:
  *   - TCL     -> CATA5TclParser (CATA5TclParserContext)
  *   - JSON    -> CATA5JsonParser
  */
  class ExportedByCATA5Parser Parser : public CATOmxSharable
  {
  public:
    Parser();
    ~Parser();

    /**
    * Bootstraps the subsystem.
    * Should be run in the main thread.
    */
    static void Init();

    /*
    * Resets parser's context.
    * Then parser can be reused to parse a new answer.
    *
    * /!\ if you override this, do not forget to call parent's implementation /!\
    */
    virtual HRESULT ResetContext();

    /**
    * Prepares the Parser for request processing, with the given definition list.
    */
    virtual HRESULT Configure(CATOmxList<CsvRowDefinition>& iDefinitions);

    /**
    * Parses a chunk of data.
    * @param iData the UTF8 encoded data chunk
    * @param iLen the data chunk length
    * @param iLast notify the last chunk
    */
    virtual HRESULT ScanChunk(const char *iData, CATLONG64 iLength, bool iLastChunk) = 0;

    /**
    * Aborts the parse if not already done.
    */
    virtual HRESULT Abort() = 0;

    /**
    * Returns the parser' status.
    */
    virtual ParseStatus GetStatus() = 0;

    /**
    * Returns detailed status. ErrorInfo contains the parsing error info: line in error and error message.
    */
    virtual ParseStatus GetErrorInfo(ErrorInfo& oErrorInfo) = 0;

    /*
    * Returns true if there is a global error returned by the server.
    * This kind of error is different of parsing error.
    */
    virtual bool HasServerGlobalError() = 0;

    /*
    * Returns the global error returned by the server. Empty string means there is no global error.
    * This kind of error is different of parsing error.
    */
    virtual CATOmxUTF8String GetServerGlobalError() = 0;

    /*
    * Dumps parser's definitions
    */
    virtual void DumpPrototypes(CATOmxTextStream &iStream, CATBoolean iAddSurroundingBracket = TRUE) const;

    /**
    * Returns true if the output queue contains data do not block.
    */
    bool DataAreAvailable() const;

    /**
    * Gets and wait for a new chunk.
    * @return NULL [#delete] if no data cannot be any more available
    */
    CsvRowChunk* GetNextChunk();

    /**
    * Gets and do not wait for a new chunk.
    * @return NULL [#delete] if no data is not yet available
    */
    CsvRowChunk* GetNextChunkNoWait();

    /*
    * Adds a parser listener.
    * It will be notified on different parser states.
    * The given listener is addrefed.
    */
    void AddParserListener(CATA5ParserListener* ipListener);

    virtual void PostError(const CATUnicodeString& iError) = 0;
  protected:
    // Methods
    void _HandleParsingStarted();
    void _HandleParsingFinished(CATLONG64 iElapseMs, CATLONG64 iRowParsedCount, int iNbofProcessedChunck);
    void _HandleParsingStartedChunck();
    void _HandleParsingFinishedChunk();
    // Attributes
    bool _ResultCsvRowLastGet;
    CATA5::CsvRowQueue _CsvRowChunksBlockingQueue;

    CATA5::CsvContext _CsvContext;
    CATOmxList<CATA5ParserListener> _ParserListeners;
  };
}
#endif
