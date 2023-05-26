#ifndef CATIntegrationDumper_H
#define CATIntegrationDumper_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2007

/**
 * @level Private
 * @usage U1
 */
#include "CATtraproto.h"
#include "CATOmbXmlTraces.h"
#include "CATPLMIntegrationBase.h"
#include "CATPLMTypeId.h"
#include "CATPLMID.h"
#include "CATBoolean.h"
#include "CATRelationId.h"
#include "CATOmxSR.h"

/** Collection of macros for dumping various objects for debug purpose. */
/** Dump of a CATPLMID */
#define DUMP_PID( iTag, iMsg, iPID ) ItgDumpMessages::DumpPLMID( iTag, iMsg, iPID )
/** Dump of a ComponentId */
#define DUMP_CID( iTag, iMsg, iCID ) ItgDumpMessages::DumpCompId( iTag, iMsg, iCID )
/** Dump of a CATIPLMRecordRead */
#define DUMP_RECORDREAD( iTag, iMsg, iRecord ) ItgDumpMessages::DumpRecordRead( iTag, iMsg, iRecord )
/** Dump of a CATPLMTypeId */
#define DUMP_TYPEID( iTag, iMsg, iTypeId, iSpace ) ItgDumpMessages::DumpPLMTypeId( iTag, iMsg, iTypeId, iSpace )
/** Dump of a CATPLMType */
#define DUMP_TYPE( iTag, iMsg, iType, iSpace ) ItgDumpMessages::DumpPLMType( iTag, iMsg, iType, iSpace )
/** Dump of a CATPLMType */
#define DUMP_TYPEH( iTag, iMsg, iType, iSpace ) ItgDumpMessages::DumpPLMTypeH( iTag, iMsg, iType, iSpace )
/** Dump of a char */
#define DUMP_VALUE( iTag, iMsg, iValue ) ItgDumpMessages::DumpValue( iTag, iMsg, iValue )
#define DUMP_ERROR_VALUE( iTag, iMsg, iValue ) ItgDumpMessages::DumpValue( iTag, iMsg, iValue, TRUE )
/** Dump of a integer */
#define DUMP_INTVALUE( iTag, iMsg, iValue ) ItgDumpMessages::DumpIntValue( iTag, iMsg, iValue )
/** Dump of a double */
#define DUMP_DOUBLEVALUE( iTag, iMsg, iValue ) ItgDumpMessages::DumpDoubleValue( iTag, iMsg, iValue )
/** Dump of a time */
#define DUMP_DATEVALUE( iTag, iMsg, iValue ) ItgDumpMessages::DumpDateValue( iTag, iMsg, iValue )
/** Dump of a URL */
#define DUMP_URL( iTag, iMsg, iValue ) ItgDumpMessages::DumpUrl( iTag, iMsg, iValue )
/** Dump of a message */
#define DUMP_MESSAGE( iTag, iMsg, iSpace ) ItgDumpMessages::DumpMessage( iTag, iMsg, iSpace )
/** Dump of a message */
#define DUMP_ERROR_MESSAGE( iTag, iMsg, iSpace ) ItgDumpMessages::DumpMessage( iTag, iMsg, iSpace, TRUE )
/** Dump of a CEStamp */
#define DUMP_CESTAMP( iTag, iMsg, iComponent, iCEStamp ) ItgDumpMessages::DumpCEStamp( iTag, iMsg, iComponent, iCEStamp )
/** Dump of a space */
#define DUMP_SPACE( iTag, iMsg, iSpace ) ItgDumpMessages::DumpSpace( iTag, iMsg, iSpace )
/** Dump of a space */
#define DUMP_ERROR( iTag, iMsg, iCatalog, iKey, iPID, iIsError ) ItgDumpMessages::DumpError( iTag, iMsg, iCatalog, iKey, iPID, iIsError )
/** Dump of a space */
#define DUMP_RELATION( iTag, iMsg, iRelation ) ItgDumpMessages::DumpRelation( iTag, iMsg, iRelation )


/**
* Services for dumping various types. For flexibility, please use the
* corresponding macros instead of directly calling these methods.
*/
class CATTime;
class CATVVSUrl;
class CATPLMCEStamp;
class CATProxySpace;
class CATComponentId;
class CATIPLMRecordRead;
class CATPLMType;
class CATProxySpace;
class CATPLMID;
class CATPLMTypeH;
class CATRelationId;
class ExportedByCATPLMIntegrationBase ItgDumpMessages
{
public:
  static void DumpMessage( const char* iTag, const char * iMsg, int iSpace, CATBoolean iError=FALSE );
  static void DumpValue(const char* iTag, const char * iMsg, const char * iValue, CATBoolean iError=FALSE );
  static void DumpIntValue(const char* iTag, const char * iMsg, int iValue );
  static void DumpDoubleValue(const char* iTag, const char * iMsg, double iValue );
  static void DumpDateValue(const char* iTag, const char * iMsg, const CATTime & iTime );
  static void DumpUrl(const char* iTag, const char * iMsg, const CATVVSUrl & iValue );
  static void DumpCEStamp(const char* iTag, const char * iMsg, const CATComponentId & iComponent, const CATPLMCEStamp & iCEStamp );
  static void DumpSpace(const char* iTag, const char * iMsg, const CATProxySpace & iSpace );
  static void DumpPLMTypeId( const char* iTag, const char * iMsg, const CATPLMTypeId & iTypeId, int iSpace );
  static void DumpPLMType(const char* iTag, const char * iMsg, CATPLMType & iType, int iSpace );
  static void DumpPLMTypeH(const char* iTag, const char * iMsg, const CATPLMTypeH & iType, int iSpace );
  static void DumpRecordRead( const char* iTag, const char * iMsg, CATIPLMRecordRead * iRecord );
  static void DumpCompId( const char* iTag, const char * iMsg, const CATComponentId & iCID );
  static void DumpPLMID( const char* iTag, const char * iMsg, const CATPLMID & iPID );
  static void DumpError( const char* iTag, const char * iMsg, const char * iErrorCatalog, const char * iErrorKey, const CATPLMID & iPID, CATBoolean iIsError );
  static void DumpRelation( const char* iTag, const char * iMsg, const CATRelationId & iRID );

private:
  static void PrintPLMID(const char * iMessage, const CATPLMID & iPLMID);
};


/**
* Class for dumping a PLMID.
*/
class ExportedByCATPLMIntegrationBase CATPLMIDMessage : public TraceMessage
{
public :
  CATPLMIDMessage(const CATPLMID& iPlmid); 
  virtual void Dump() const;
private : 
  const CATPLMID _Plmid;  
  void DumpPlmId(const CATPLMID& iPlmid) const;
  mutable CATString _typename,_physicalid,_logicalid, _majorid;
};

inline CATOmxSR<CATOmbXmlElement> operator << (const CATOmxSR<CATOmbXmlElement>& stream, const CATPLMID& iDatum)
{
  CATPLMIDMessage msg(iDatum);
  return stream << msg;
}

ExportedByCATPLMIntegrationBase CATOmxSR<CATOmbXmlElement> operator<<(const CATOmxSR<CATOmbXmlElement>& stream, CATIPLMRecordRead* iRecordRead);

ExportedByCATPLMIntegrationBase CATOmxSR<CATOmbXmlElement> operator<<(const CATOmxSR<CATOmbXmlElement>& stream, const CATComponentId& iCID);

ExportedByCATPLMIntegrationBase CATOmxSR<CATOmbXmlElement> operator<<(const CATOmxSR<CATOmbXmlElement>& trace, CATPLMType * iPLMType);

ExportedByCATPLMIntegrationBase CATOmxSR<CATOmbXmlElement> operator<<(const CATOmxSR<CATOmbXmlElement>& trace, const CATPLMCEStamp & iCEStamp);

#endif
