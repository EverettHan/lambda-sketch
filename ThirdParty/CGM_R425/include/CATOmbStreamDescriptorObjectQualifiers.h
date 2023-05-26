// COPYRIGHT Dassault Systemes 2005
//===================================================================
//  Apr 2005  Creation: Code generated by the CAA wizard  PHB
//===================================================================
#ifndef CATOmbStreamDescriptorObjectQualifiers_H
#define CATOmbStreamDescriptorObjectQualifiers_H

/**
 * @level  Private
 * @usage   U1
 */

#include "CATOmbSelectiveLoadingForInfraOnly.h"
#include "CATVVSUrl.h"
#include "CATUnicodeString.h"

//-----------------------------------------------------------------------
/**
 * Set of qualifiers for a stream descriptor object.
 */
class ExportedByCATOmbSelectiveLoading CATOmbStreamDescriptorObjectQualifiers
{
public:
  /**
   * Constructs a unset set of qualifiers.
   */
  CATOmbStreamDescriptorObjectQualifiers();

  /**
   * Constructs a Set of Qualifiers for a Stream Descriptor Object.
   * @param iURL
   *   URL of the stream to be handled by the SD
   * @param iWatermarkStamp
   *   WatermarkStamp of the stream descriptor: indicates the last Save state of the SD
   * @param iSynchroStamp
   *   SynchroStamp of the stream descriptor: indicates Secondary SD synchro towards its main authoring SD
   * @param iPersistencyType
   *   The format in which the stream has been generated (binary, xml, ... ) 
   * @param iPersistencyName
   *   The name of the stream
   */
  CATOmbStreamDescriptorObjectQualifiers(const CATVVSUrl &iURL, int iWatermarkStamp, int iSynchroStamp, const CATUnicodeString& iPersistencyType, const CATUnicodeString& iPersistencyName);

  /**
  * Constructs a Set of Qualifiers for a Stream Descriptor Object.
  * @param iURL
  *   URL of the stream to be handled by the SD
  * @param iWatermarkStamp
  *   WatermarkStamp of the stream descriptor: indicates the last Save state of the SD
  * @param iSynchroStamp
  *   SynchroStamp of the stream descriptor: indicates Secondary SD synchro towards its main authoring SD
  * @param iPersistencyType
  *   The format in which the stream has been generated (binary, xml, ... )
  * @param iPersistencyName
  *   The name of the stream
  * @param iWatermarkStampMD5
  *   WatermarkStamp of the stream descriptor: indicates the last Save state of the SD as an MD5
  * @param iStreamSize
  *   Size of the stream in bytes. Value -1 should be used if this is unknown
  */
  CATOmbStreamDescriptorObjectQualifiers(const CATVVSUrl &iURL, int iWatermarkStamp, int iSynchroStamp, const CATUnicodeString& iPersistencyType, const CATUnicodeString& iPersistencyName, const CATUnicodeString& iWatermarkStampMD5, const CATLONG64 iStreamSize);

  /**
   * Destroys a Set of Qualifiers for Stream Descriptor Object.
   */
  ~CATOmbStreamDescriptorObjectQualifiers();

  //-----------------------------------------------------------------------
  // ACCESSORS
  // =========
  /**
   * Returns the URL of the Stream Descriptor.
   */
  const CATVVSUrl &GetURL() const    { return _URL; }

  /**
   * Returns the watermark stamp.
   * @return
   *   The stamp.
   */
  int GetWatermarkStamp() const { return _WatermarkStamp; }

  /**
   * Returns the reference to the watermark stamp.
   * @return
   *   The reference to the watermark stamp. It avoids changing CATIOmbStreamDescriptor#GetWatermarkStamp for the moment (@R201).
   */
  const int &GetWatermarkStampRef() const { return _WatermarkStamp; }

  /**
  * Returns the watermark stamp.
  * @return
  *   The MD5 stamp.
  */
  const CATUnicodeString& GetWatermarkStampMD5() const { return _WatermarkStampMD5; }

  
  /** 
  * Returns the Persistency Type   
  * @return
  *   Returns the persistency type
  *
  */
  const CATUnicodeString &GetPersistencyType() const {return _PersistencyType;}

  /** 
  * Returns the Persistency Name 
  * @return
  *   Returns the persistency name
  *
  */
  const CATUnicodeString &GetPersistencyName() const {return _PersistencyName;}

   /**
   * Returns the SynchroStamp of the Stream Descriptor.
   */
  int GetSynchroStamp() const { return _SynchroStamp; }

  /**
  * Returns the stream size of the Stream Descriptor. (-1 if unknown)
  */
  CATLONG64 GetStreamSize() const { return _StreamSize; }

  //-----------------------------------------------------------------------
  // MODIFIERS
  // =========
  /**
   * Sets the URL of the Stream Descriptor (if it exists).
   * @param iURL
   *   The new URL.
   */
  void SetURL    ( const CATVVSUrl &iURL );

  /**
   * Sets the WatermarkStamp of the Stream Descriptor.
   * @param iWatermarkStamp
   *   The new watermark stamp.
   */
  void SetWatermarkStamp ( int iWatermarkStamp );
 
  /**
  * Sets the WatermarkStamp as MD5 of the Stream Descriptor.
  * @param iWatermarkStamp
  *   The new MD5 watermark stamp.
  */
  void SetWatermarkStampMD5(const CATUnicodeString& iWatermarkStampMD5);

  /**
   * Sets the PersistencyType of the Stream Descriptor.
   * @param iPersistencyType
   *   The new persistency type.
   */
  void SetPersistencyType(const CATUnicodeString& iPersistencyType );

   /**
   * Sets the PersistencyName of the Stream Descriptor.
   * @param iPersistencyName
   *   The new persistency name.
   */
  void SetPersistencyName(const CATUnicodeString& iPersistencyName );

   /**
   * Sets the SynchroStamp of the Stream Descriptor.
   * @param iSynchroStamp
   *   The new synchronization stamp.
   */
  void SetSynchroStamp( int iSynchroStamp );

  /**
  * Sets the streamSize of the Stream Descriptor.
  * @param iStreamSize
  *   The new stream size (-1 if unknown).
  */
  void SetStreamSize(CATLONG64 iStreamSize);

private:

  int operator==( const CATOmbStreamDescriptorObjectQualifiers& iOpD ) const;
  int operator!=( const CATOmbStreamDescriptorObjectQualifiers& iOpD ) const;
  int operator<( const CATOmbStreamDescriptorObjectQualifiers& iOpD ) const;
  int operator>( const CATOmbStreamDescriptorObjectQualifiers& iOpD ) const;
  //-----------------------------------------------------------------------
  // Data members
  // ============
  CATVVSUrl _URL;
  int _WatermarkStamp;
  int _SynchroStamp;
  CATUnicodeString _PersistencyType;
  CATUnicodeString _PersistencyName;
  CATUnicodeString _WatermarkStampMD5;
  CATLONG64 _StreamSize;

};

//-----------------------------------------------------------------------

#endif