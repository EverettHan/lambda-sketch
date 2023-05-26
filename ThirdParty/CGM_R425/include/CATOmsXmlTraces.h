/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2007

/**
 * @level Private
 * @usage U1
 */


#ifndef CATOmsXmlTraces_H
#define CATOmsXmlTraces_H

#include "CATOMY.h"//ExportedBy

#include "CATBaseUnknown.h"

#include "CATUnicodeString.h"
#include "CATListOfCATUnicodeString.h"
#include "CATCollec.h"
#include "CATLib.h"
#include "CATThreads.h"
#include "CATOmxSR.h"
#include "CATTime.h"
#include "CATError.h"
#include "CATOmxTextStream.h"
#include "CATOmxSharable.h"
#include "CATOmxArray.h"
#include "CATOmxOMap.h"
#include "CATOmxKernelUtilities.h"
#include "CATIAV5Level.h"

class CATIXMLPPOutputSource_var;
class CATIXMLPPWriter_var;
class CATXMLPPMemoryBuffer;
class CATILockBytes2;

#ifdef _WINDOWS_SOURCE
#pragma warning (push)
#pragma warning (disable : 4099)
#pragma warning (disable : 4251)
#endif

class CATBaseUnknown;
class CATVVSURLConnection;

/**
 * A basic xml trace node and utility classes..
 *
 * The node is opened in the constructor and closed when Close() is called or when the element is destroyed.
 * To get a valid one, you must use the various CATOmsXmlTraces::GetOmsXmlTracer, CATOmsXmlTraces::BlockXmlTracer
 * or CATOmsXmlTraces::ArgumentXmlTracer methods.
 */
class CATOmbXmlElementAttrib
{
  CATUnicodeString key, value;
public:
  inline CATOmbXmlElementAttrib() {}
  inline CATOmbXmlElementAttrib(const CATUnicodeString & iKey, const CATUnicodeString & iValue) :key(iKey), value(iValue) {}
  inline CATOmbXmlElementAttrib(const CATUnicodeString & iKey, int iValue) : key(iKey) { value.BuildFromNum(iValue); }
  inline CATOmbXmlElementAttrib(const CATUnicodeString & iKey, CATULONG64 iValue) : key(iKey) { value.BuildFromNum(iValue); }
  inline CATOmbXmlElementAttrib(const CATUnicodeString & iKey, CATULONG32 iValue) : key(iKey) { value.BuildFromNum(iValue); }
  inline CATOmbXmlElementAttrib(const CATUnicodeString & iKey, const CATTime & iValue) : key(iKey) { value = iValue.ConvertToString("%H:%M:%S"); }
  inline const CATUnicodeString & Key() const { return key; }
  inline const CATUnicodeString & Value() const { return value; }
  ExportedByCATOMY void Stream(CATOmxTextStream &iTraceFileStream) const;
  ExportedByCATOMY static CATOmxCollecManager& Manager();
  ExportedByCATOMY static int Compare(const CATOmbXmlElementAttrib&a, const CATOmbXmlElementAttrib&b);
};

typedef CATOmxArray<CATOmbXmlElementAttrib, CATOmbXmlElementAttrib::Manager> CATOmbXmlElementAttribListBase;
class CATOmbXmlElementAttribList : public CATOmbXmlElementAttribListBase
{
public:
  using CATOmbXmlElementAttribListBase::Append;
  template <typename T>
  inline void Append(const CATUnicodeString & iKey, const T & iValue)
  {
    Append(CATOmbXmlElementAttrib(iKey, iValue));
  }

  inline void Sort()
  {
    CATOmxArray<CATOmbXmlElementAttrib, CATOmbXmlElementAttrib::Manager>::Sort(CATOmbXmlElementAttrib::Compare);
  }

  void Stream(CATOmxTextStream &iTraceFileStream) const;
};

class ExportedByCATOMY CATOmbXmlElement : public CATOmxSharable
{
  // Constructors are restricted to CATOmsXmlTraces
  friend class CATOmsXmlTraces;
  friend class CATOmbXmlElementStack;
  CATOmbXmlElement(
    CATOmxTextStream &iTraceFileStream,
    const CATUnicodeString& iTag
  );

  CATOmbXmlElement(
    CATOmxTextStream &iTraceFileStream,
    const CATUnicodeString& iTag,
    const CATOmbXmlElementAttribList& iAttribs
  );

  void CloseStartTagForAddChild();

public:
  virtual ~CATOmbXmlElement();
  const CATUnicodeString & GetTag() { return _tag; }

  /**
   * Adds a sub node to the current one.
   */
  CATOmxSR<CATOmbXmlElement> AddChild(const CATUnicodeString& iTag);
  CATOmxSR<CATOmbXmlElement> AddChild(const CATUnicodeString& iTag,
    const CATOmbXmlElementAttribList& iAttribs);

  /**
   * Writes the text in the current node.
   */
  void WriteCharacters(const CATUnicodeString & iContent);

  /**
   * Close the current node. If AddChild is called, the new
   * node will be instanciated under the parent node.
   */
  CATOmxSR<CATOmbXmlElement> Close();

private:
  CATOmxTextStream &_traceFileStream;
  CATUnicodeString _tag;
  CATBoolean _hasChild, _hasText, _isClosed;
  CATOmxSR<CATOmbXmlElement> _parent;
};

/**
 * Methods to dump various types.
 *
 * <code>
 * int IntValue=42;
 * if(CATOmsXmlTraces::IsActive()) CATOmsXmlTraces::GetOmsXmlTracer("PLMQuery","Info",InfoMessage(),0,"ITG")<<"MyInt " <<IntValue;
 * </code>
 */
 //ExportedByCATOMY const CATOmxSR<CATOmbXmlElement>& operator<<(const CATOmxSR<CATOmbXmlElement>& trace, char* message);
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> operator<<(const CATOmxSR<CATOmbXmlElement>& trace, const CATUnicodeString& message);
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> operator<<(const CATOmxSR<CATOmbXmlElement>& trace, const CATUnicodeString* message); //WTF ?
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> operator<<(const CATOmxSR<CATOmbXmlElement>& trace, const CATString* message);        //WTF ?
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> operator<<(const CATOmxSR<CATOmbXmlElement>& trace, CATINT32 message);
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> operator<<(const CATOmxSR<CATOmbXmlElement>& trace, CATUINT32 message);
#if !defined(PLATEFORME_DS64)
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> operator<<(const CATOmxSR<CATOmbXmlElement>& trace, CATLONG32 message);
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> operator<<(const CATOmxSR<CATOmbXmlElement>& trace, CATULONG32 message);
#elif !defined(_WINDOWS_SOURCE)
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> operator<<(const CATOmxSR<CATOmbXmlElement>& trace, CATINTPTR message);
#endif
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> operator<<(const CATOmxSR<CATOmbXmlElement>& trace, CATLONG64 message);
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> operator<<(const CATOmxSR<CATOmbXmlElement>& trace, CATULONG64 message);
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> operator<<(const CATOmxSR<CATOmbXmlElement>& trace, double message);
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> operator<<(const CATOmxSR<CATOmbXmlElement>& trace, const CATTime & iTime);
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> operator<<(const CATOmxSR<CATOmbXmlElement>& trace, const CATError& iError);

/**
 * All those methods close the current xml element and return it enclosing one.
 * Thanks to  CATOmxSR<CATOmbXmlElement>(*iMethod)(CATOmxSR<CATOmbXmlElement>),
 * those methods can be called this way :
 * if(CATOmsXmlTraces::IsActive()) CATOmsXmlTraces::GetOmsXmlTracer("PLMQuery","Info",InfoMessage(),0,"ITG")
 *   <<"MyInt " << IntValue << EndXmlInfoMessage;
 *
 * Note that all opened element will be automatically closed when the CATOmbXmlElement is deleted.
 * In many cases, using those methods is not useful.
 */
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> EndXmlInfoMessage(CATOmxSR<CATOmbXmlElement> trace);
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> EndXmlMessage(CATOmxSR<CATOmbXmlElement> trace);
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> EndXmlPerfoMessage(CATOmxSR<CATOmbXmlElement> trace);
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> operator << (CATOmxSR<CATOmbXmlElement> trace, CATOmxSR<CATOmbXmlElement>(*iMethod)(CATOmxSR<CATOmbXmlElement>));

/**
 * Base class to customized the traces for your own types.
 *
 * To avoid unnecessary copy of objects, the TraceMessage is passed as a reference to the << operator.
 * To ease the usage of this protocole, it is recommanded to also overload the << operator for your own types.
 *
 * Note that there can be a better startegy :)
 *
 * <code>
 * class MY_TRACE_MESSAGE : public TraceMessage
 * {
 *   //...
 * }
 *
 * const CATOmxSR<CATOmbXmlElement>& operator<<(const CATOmxSR<CATOmbXmlElement>& trace, const MY_TYPE & iMyObj)
 * {
 *   if(trace)
 *   {
 *     MY_TRACE_MESSAGE msg(iMyObj);
 *     trace << msg;
 *   }
 *   return trace;
 * }
 * </code>
 */
class ExportedByCATOMY TraceMessage
{
  const CATUnicodeString _Tag;
  CATOmbXmlElementAttribList _Attribs;
protected:
  mutable CATUnicodeString _Text; //grgrgrgr
  void SetAttribute(const CATUnicodeString& iAttrib, const CATUnicodeString &iValue) const;
  void SetAttribute(const CATOmbXmlElementAttrib& iAttrib) const;
public:
  TraceMessage(const CATUnicodeString &iTag);
  virtual ~TraceMessage();

  /**
   * Method to overload. It should fill the various attributes wanted in the xml node
   * through the SetAttribute, as well as filling the _Text member that will be the
   * content of the node.
   */
  virtual void Dump() const = 0;

  const CATUnicodeString& GetTag() const { return _Tag; }
  const CATUnicodeString& GetText() const { return _Text; }
  const CATOmbXmlElementAttribList & GetAttribs() const { return _Attribs; }
};
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> operator<<(const CATOmxSR<CATOmbXmlElement>& trace, const TraceMessage& iTraceMessage);


/**
 * Open <Args> node and <Arg name="..."> subnode.
 * Useful in combination with a block tracer to track a method.
 *
 * In this case, using EndArgs is recommended, even if the Args node will be closed
 * when loosing the current scope : if you leave it opened, all created submethods
 * will be traced in the Args node which is pretty ugly.
 *
 * <code>
 * if(CATOmsXmlTraces::IsActive()) CATOmsXmlTraces::BlockXmlTracer("MyMethod",,0,"ITG")<<Args
 *  <<Arg("Arg1")<<ArgValue1
 *  <<Arg("Arg2")<<ArgValue2<<EndArgs;
 * </code>
 */
struct CATOmbXmlArgName
{
  static const CATUnicodeString &ArgTag();
  CATOmbXmlArgName(const CATUnicodeString & iName) :Name(iName) {}
  CATUnicodeString Name;
};
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> StartArgs(CATOmxSR<CATOmbXmlElement> trace);
ExportedByCATOMY CATOmbXmlArgName AddArg(const CATUnicodeString & iName);
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> operator<<(const CATOmxSR<CATOmbXmlElement>& trace, const CATOmbXmlArgName & iArgName);
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> EndArgs(CATOmxSR<CATOmbXmlElement> trace);

/**
 * Open <Results> node and <Result name="..."> subnode.
 * Useful in combination with a block tracer to track the result of a method.
 *
 * In this case, using EndResults is optionnal, as the Results node will be closed
 * when loosing the current scope, but be careful, if you leave it opened, all created
 * submethods will be traced in the Args node which is pretty ugly.
 *
 * <code>
 * if(CATOmsXmlTraces::IsActive()) CATOmsXmlTraces::ResultsXmlTracer()
 *  <<Result("Result1")<<ResultValue1
 *  <<Result("Result2")<<ResultValue2<<EndResults;
 * </code>
 */

struct CATOmbXmlResultName
{
  static const CATUnicodeString &ResultTag();
  CATOmbXmlResultName(const CATUnicodeString & iName) :Name(iName) {}
  CATUnicodeString Name;
};
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> Results(CATOmxSR<CATOmbXmlElement> trace);
ExportedByCATOMY CATOmbXmlResultName Result(const CATUnicodeString & iName);
ExportedByCATOMY CATOmbXmlResultName AddResult(const CATUnicodeString & iName);
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> operator<<(const CATOmxSR<CATOmbXmlElement>& trace, const CATOmbXmlResultName & iArgName);
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> EndResults(CATOmxSR<CATOmbXmlElement> trace);

/**
* Dump a generic message
*/
class ExportedByCATOMY InfoMessage : public TraceMessage
{

public:
  static const CATUnicodeString& InfoTag();
  InfoMessage();
  ~InfoMessage();
  virtual void Dump() const;
};
ExportedByCATOMY CATOmxSR<CATOmbXmlElement> operator<<(const CATOmxSR<CATOmbXmlElement>& trace, const InfoMessage& iTraceMessage);

class ExportedByCATOMY CATOmsXmlStructure : public CATBaseUnknown
{
public:
  CATOmsXmlStructure(CATUnicodeString Tag, CATULONG32 cpuTime, CATULONG32 elaTime);
  virtual ~CATOmsXmlStructure();

  CATUnicodeString GetTag() { return _Tag; }
  CATUnicodeString _Tag;
  CATULONG32 _cpuTime;
  CATULONG32 _elaTime;
};


/**
* @collection CATListOfCATOmsXmlStructure
* Collection class for pointers to @href CATOmsXmlStructure.
* Only the following methods of pointer collection classes are available:
* <ul>
* <li><tt>Append</tt></li>
* </ul>
* Refer to the articles dealing with collections in the encyclopedia.
*/

class CATOmsXmlStructure;
#include "CATLISTP_Clean.h"
#define CATLISTP_Append
#define CATLISTP_RemovePosition
#include "CATLISTP_Declare.h"
#include "CATOmxSR.h"
#include "CATSysMacros.h" //Indirect prereq ! ie. needed for compilation of other fws...
CATLISTP_DECLARE(CATOmsXmlStructure)


class ExportedByCATOMY CATOmsXmlTraces
{

public:

  /*
  * Get tracers
  * GetOmsErrorXmlTracer will generate a "Message" trace with error type.
  * GetOmsWarningXmlTracer will generate a "Message" trace with warning type.
  * GetOmsInfoXmlTracer will generate a "Message" trace with info type.
  *
  * To use, GetOmsXXXXTracer(tag,owner) << "Some message " << 1 << PLMIDMessage(plmid) << "otherText";
  *
  * Tag is an identifier (not to be mistaken with an XML tag), like a "class" in xml. You can concatenate text and other "native" (like CATTime) supported types with <<. This will be dumped under an "Info" tag in the XML.
  * When you concatenate some type deriving from TraceMessage, it creates a new tag in the XML file, and will close the Info tag if necessary.
  * For instance, in the sample case you will have an <Info> tag with "Some message 1" </Info>, then a <PLMID></PLMID>, then another Info tag with "other text".
  */
  static CATOmxSR<CATOmbXmlElement> GetOmsErrorXmlTracer(const CATUnicodeString& iMessageTag, const CATUnicodeString& iOwner);
  static CATOmxSR<CATOmbXmlElement> GetOmsWarningXmlTracer(const CATUnicodeString& iMessageTag, const CATUnicodeString& iOwner);
  static CATOmxSR<CATOmbXmlElement> GetOmsInfoXmlTracer(const CATUnicodeString& iMessageTag, const CATUnicodeString& iOwner);

  //BlockXmlTracer will generate a "Block" trace. While the CATOmbXmlElement is alive, every other traces will be generated under this block.

  static CATOmxSR<CATOmbXmlElement> BlockXmlTracer(const CATUnicodeString& iFunctionTag, const CATUnicodeString& iFunctionName, const CATUnicodeString& iOwner);

  // Use these to dump block argument, or block results of the block.
  static CATOmxSR<CATOmbXmlElement> ArgumentXmlTracer();
  static CATOmxSR<CATOmbXmlElement> ResultsXmlTracer();


private:
  static CATULONG32 _CurrentTraceId;
  static CATOmxOMap<CATUnicodeString, unsigned int> _TagsIds;
  static CATListOfCATUnicodeString _StackRequest;
  static CATUnicodeString _SessionDir;
  static CATUnicodeString _StackDir;
  static CATUnicodeString _RelStackDir;
  static CATUnicodeString _TrsDir;
  static CATUnicodeString _ErrorStackDir;
  static CATUnicodeString _RelErrorStackDir;
  static CATUnicodeString _CurrentTag;
  static CATBoolean       _IsActive;
  static CATTimerId _Timer;
  static CATListPtrCATOmsXmlStructure _TransactionsPerfoList;
  static int _nbStartTrace;

  enum eMessageSeverity
  {
    Undef = 0,
    Info = 1,
    Warning = 2,
    Error = 3,
    Stack = 4,
    NbElem
  };
  static const CATUnicodeString& EnumToString(CATOmsXmlTraces::eMessageSeverity iSeverity);

#ifdef _WINDOWS_SOURCE
#pragma warning(push)
#pragma warning( disable: 4251 )
#endif
  static CATOmxTextStream _traceFileStream;
  static CATOmxSR<CATOmbXmlElement> _head;
#ifdef _WINDOWS_SOURCE
#pragma warning(pop)
#endif
  static CATOmxSR<CATOmbXmlElement> WriteNode(const CATUnicodeString& iMessageTag, const CATUnicodeString& iOwner, CATOmsXmlTraces::eMessageSeverity iSeverity);
protected:
  static CATUnicodeString _RelTrsDir;
  static CATUnicodeString _Slash;
public:
  static void flush();

  CATOmsXmlTraces();
  virtual ~CATOmsXmlTraces();

  static CATListOfCATUnicodeString _AliasRequest;
  static CATUnicodeString _Directory;
  static boolean _EasyCompare;

  static inline CATUnicodeString returnTrsModifDirectoryPath() { return _TrsDir; }


  static const CATBoolean& IsActive();
  static int GetVerboseMode();
  static CATBoolean IsVerboseActive();

  /**
  * Creates and inits an XML File those FilePath (Directory) is given by CATGetEnvValue("OMB_XML_TRACE")
  */
  static  HRESULT StartTrace();

  /**
  * Finalizes and closes the XML File currently edited
  */
  static HRESULT StopTrace();


  static void StartTransactionXmlTracer(const  CATUnicodeString&  iMessageTag, const  CATUnicodeString&  iMessageType, const  TraceMessage&  Message = InfoMessage(), int  iLevel = 0, const  CATUnicodeString&  iOwner = "Perfo");
  static void StartTransactionXmlTracer(int  increment, const  CATUnicodeString&  iMessageTag, const  CATUnicodeString&  iMessageType, const  TraceMessage&  Message = InfoMessage(), int  iLevel = 0, const  CATUnicodeString&  iOwner = "Perfo");

  static CATOmxSR<CATOmbXmlElement> StopTransactionXmlTracer(const  CATUnicodeString&  iMessageTag, const  CATUnicodeString&  iMessageType, const  TraceMessage&  Message = InfoMessage(), int  iLevel = 0, const  CATUnicodeString&  iOwner = "Perfo");
  static CATOmxSR<CATOmbXmlElement> StopTransactionXmlTracer(int  increment, const  CATUnicodeString&  iMessageTag, const  CATUnicodeString&  iMessageType, const  TraceMessage&  Message = InfoMessage(), int  iLevel = 0, const  CATUnicodeString&  iOwner = "Perfo");

  /**
  * DEPRECATED
  */

  static CATOmxSR<CATOmbXmlElement> GetOmsXmlTracer(const CATUnicodeString& iMessageTag, const CATUnicodeString& iMessageType, const TraceMessage& Message, int iLevel, const CATUnicodeString& iOwner);

  /**
  * Convert a HRESULT to an understanble NLS message
  */
  static CATUnicodeString ConvertHR(HRESULT iHR); //buggue, il manque un LocalFree !

  static CATUnicodeString RemoveInvalidChar(const CATUnicodeString& oMsg);

  /**
  * Dumps the header bytes structure of a loaded stream.
  * Dump request is to be specified by the specific keyword STREAM_HEADER into the .conf file
  * iMessageTag : the message tag referencing the traces associated to the dump into the resulting trace file
  * ipILBStream : The CATILockBytes2 object handling the binary stream to be partially dumped
  * oFileName   : Path and Name of the generated dump file, for eventuel completion with other relative data
  */
  static HRESULT DumpStreamHeader(const CATUnicodeString& iMessageTag, CATILockBytes2 * ipILBStream, CATUnicodeString &oDumpFile);

  /**
  * Dumps the content of a given Error.
  * Dumps ErrorKey, ErrorCatalog and Error single or composite NLS message into
  * - A file given as input if iFileDesc valuated
  * - The default error trace file:  $OMB_XML_TRACE\<Session_OMB_date_exe_pid>\ErrorStacks\
  * iError : Error to be dumped
  * iFileDesc : Eventual FileDescriptor of the dump file, previously opened using CATFOpen
  * oErrorLabel : "key | catalog" referenced by this input iError
  */
  static HRESULT ErrorToFile(CATError& iError, unsigned int iFileDesc, CATUnicodeString& oErrorLabel);

  /**
  * Write stack that matches each (TAG;TAGId) into a unique file
  */
  static HRESULT DumpStack(CATUnicodeString &oFilePath, int iFrom = -1);

  /**
  * Writes a given dump content into the OMB session trace directory: $OMB_XML_TRACE\<Session_OMB_date_exe_pid>\OmbDebugDir\iFileName
  */
  static HRESULT DumpToOmbFile(const CATUnicodeString& iFileName, const CATUnicodeString& iFileContent);

private:
  /**
  * Read TAG;TAGId and Alias parametre from a configuration File
  */
  static HRESULT ReadConfigurationFile(const CATUnicodeString &iFilePath);

  /**
  * Computes File absolute path and name for Document Dump in OSM format
  * iOsmDirName : dump Directory name  (example Rollin)
  * iOsmFileName : dump file name  (ex. DocN.CATPart.osm)
  * increment : used to differentiate several occurences of Dump for the same doc in same context (ex: AutoSave every N minutes)
  * ioDumpDirPath : absolute path for the Dump directory, computed if not set as entry, and created when it doesn't already exist
  * It is computed as follows  $OMB_XML_TRACE\<eventual unique sub-dir>\iOsmDirName0Increment_PIDxxx_dxxx_hxxmyyszz
  * (example $OMB_XML_TRACE\<..>\Rollin02_PID5312_d100_h15m36s36)
  * oDumpFilePath : absolute path for the Dump file (example $OMB_XML_TRACE\<..>\Rollin02_PID5312_d100_h15m36s36\DocN.CATPart.osm)
  */
  static HRESULT GetOsmDumpFilePath(CATUnicodeString iOsmDirName, CATUnicodeString iOsmFileName, int Increment,
    CATUnicodeString & ioDumpDirPath, CATUnicodeString & oDumpFilePath);


  static HRESULT CopyRessourceFile(const CATUnicodeString& iFileName, const CATUnicodeString& iDirectory);
  static unsigned int GetNextTagId(const CATUnicodeString & iTag);

};

#ifdef _WINDOWS_SOURCE
#pragma warning(pop)
#endif

#endif
