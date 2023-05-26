#ifndef CATMMRETURNCODE_H
#define CATMMRETURNCODE_H

#include "CATMMediaCore.h"
#include "CATUnicodeString.h"
//@MMNJNinf @QDesc: Return code manager
//@MMNJNinf @FDesc: Return code manager supporting textual description. 3 values CATMmRC:  OK,False,Failed.

class ExportedByCATMMediaCore CATMmRC
{
public:
  enum ErrorCode { statusFailed=-1,statusFALSE=0,statusOK=1 };

  /** 
   * Default constructor
   */
  inline CATMmRC()                                               :_returnCode(statusOK){};

  /**
   * Copy constructor
   */
  inline CATMmRC(const CATMmRC& iRC)                             :_returnCode(iRC._returnCode),_trace(iRC._trace){};

  /**
   * Constructor from HRESULT
   */
  CATMmRC(HRESULT iHR);

  /**
   * Constructor by specifying ErrorCode and char* for trace.
   */
  inline CATMmRC(CATMmRC::ErrorCode iRC,const char*ipTrace=NULL) :_returnCode(iRC),_trace(ipTrace){
#ifndef CNEXT_CLIENT
                                                                   _trace4dbg=Dump();
#endif
                                                                 };
  /**
   * Constructor by specifying ErrorCode and CATUnicodeString for trace.
   */
  inline CATMmRC(CATMmRC::ErrorCode iRC,const CATUnicodeString &iTrace) :_returnCode(iRC),_trace(iTrace){
#ifndef CNEXT_CLIENT
                                                                   _trace4dbg=Dump();
#endif
                                                                 };

  /**
   * Operator=
   */
  inline CATMmRC& operator=(const CATMmRC&iRC)                   
  { 	  
	  _returnCode=iRC._returnCode; 
	  _trace=iRC._trace;
#ifndef CNEXT_CLIENT
                                                                   _trace4dbg=Dump();
#endif
	  return *this;
  };

  /**
   * Checking if return code is failed
   */
  inline bool                         IsError()                  { return (_returnCode!=statusFALSE && _returnCode!=statusOK); };

  /**
   * Checking if return code is succeeded
   */
  inline bool                         IsValid()                  { return !IsError(); };

  /**
   * OVerload of operator! checking if return code is error.
   */
  inline bool                         operator!()                { return IsError();   };

  /**
   * Returning return code.
   */
  inline ErrorCode                    GetRC()                    { return _returnCode; };

  /**
   * Add traces to current CATMmRC, and set _returnCode with the one from iRC.
   */
  inline CATMmRC&                     Add(const CATMmRC& iRC)    { if(this!=&iRC){ MergesTraces(_trace, iRC._trace); } _returnCode=iRC._returnCode;
#ifndef CNEXT_CLIENT
                                                                   _trace4dbg=Dump();
#endif
                                                                   return *this; };

  /**
   * Add traces from char* to current CATMmRC. Status of return code remains the same.
   */
  inline CATMmRC&                     AddTrace(const char*iTrace){ _trace.Append(iTrace);
#ifndef CNEXT_CLIENT
                                                                   _trace4dbg=Dump();
#endif
                                                                   return *this; };

  /**
   * Add traces from CATUnicodeString to current CATMmRC. Status of return code remains the same.
   */
  inline CATMmRC&                     AddTrace(const CATUnicodeString &iTrace){ _trace.Append(iTrace);
#ifndef CNEXT_CLIENT
                                                                   _trace4dbg=Dump();
#endif
                                                                   return *this; };

  /**
   * Returns traces.
   */
  inline const CATUnicodeString& GetTrace() const           { return _trace; };
  inline const char*                  Dump() const               { return _trace.ConvertToChar(); };
  bool    operator==(const CATMmRC&iRC);
  bool    operator!=(const CATMmRC&iRC);


  static CATUnicodeString InsertLinesBegin(const CATUnicodeString& iString, CATUnicodeString& iStringBeginsLine);
  static CATUnicodeString InsertLinesBegin(const CATUnicodeString& iString, char* ipStringBeginsLine);
private:
  ErrorCode           _returnCode;
  CATUnicodeString    _trace;
//CATUnicodeString    _consumedTrace;
#ifndef CNEXT_CLIENT
  const char*              _trace4dbg;//pointer on char* in order to be able to see traces in MSDEV.
#endif
  static void MergesTraces(CATUnicodeString& iTrace, const CATUnicodeString&iTraceToMergeWith) { if(iTrace.GetLengthInChar()&&iTraceToMergeWith.GetLengthInChar())iTrace.Append("\n"); iTrace.Append(iTraceToMergeWith); };
};

#define CATMmRcOK              CATMmRC(CATMmRC::statusOK)
#define CATMmRcFALSE           CATMmRC(CATMmRC::statusFALSE)
#define CATMmRcFailed          CATMmRC(CATMmRC::statusFailed)
#define CATMmRcFailedMsg(Msg)  CATMmRC(CATMmRC::statusFailed,Msg)

#endif
