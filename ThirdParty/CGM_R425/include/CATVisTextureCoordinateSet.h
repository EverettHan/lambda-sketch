// COPYRIGHT DASSAULT SYSTEMES 2007

#ifndef CATVisTextureCoordinateSet_H
#define CATVisTextureCoordinateSet_H

#include "SGInfra.h"

#include "IUnknown.h"
#include "CATUnicodeString.h"

#define LEGACY_UV_SET     ::CATVisTextureCoordinateSet::s_LegacyUVSet
#define DEFAULT_TC_SET    ::CATVisTextureCoordinateSet::s_DefaultTCSet
#define EXTERNAL_TC_SET_0 ::CATVisTextureCoordinateSet::s_ExternalTCSet0
#define EXTERNAL_TC_SET_1 ::CATVisTextureCoordinateSet::s_ExternalTCSet1
#define EXTERNAL_TC_SET_2 ::CATVisTextureCoordinateSet::s_ExternalTCSet2

/**
 * @nodoc
 * Defines the way to supply an array of coordinates.
 * COPY : values are copied from the input array to the member one, ownership doesn't change
 * SET : input pointer is set as is, but the class doens't own the lifecycle
 * SET_AND_DELEGATE : input pointer is set as is, and the lifecycle is delegated to the class
 */
enum TCLifecycleManagement { COPY, SET, SET_AND_DELEGATE };

/**
 * @nodoc
 * Class to manage a set of texture coordinates.
 * It is defined by a number of vertices, a dimension (1D,2D,3D) and the corresponding array of float coordinates.
 * The set can be identified in order to be retrieved in the host VertexBuffer.
 * The streamability can also be switch on/off.
 * NOTE : only sets with 'authorized' ids can be streamed ( see upper #define ).
 * 
*/
class ExportedBySGInfra CATVisTextureCoordinateSet
{
 
public:

  static CATUnicodeString const s_LegacyUVSet;
  static CATUnicodeString const s_DefaultTCSet;
  static CATUnicodeString const s_ExternalTCSet0;
  static CATUnicodeString const s_ExternalTCSet1;
  static CATUnicodeString const s_ExternalTCSet2;
  
 /** 
  * @nodoc
  * Creates an empty TexCoordSet that can be allocated using the Allocate method
  * @param identifier : TextCoordSet identification
  * NOTE : DEFAULT_TC_SET is the identifier dedicated to the default set stored in the VertexBuffer
  */
  CATVisTextureCoordinateSet( const CATUnicodeString& identifier = s_DefaultTCSet );

  /** 
  * @nodoc
  * Creates a TexCoordSet
  * @param iNbVertices : number of vertices
  * @param iCoordsDim : input coordinates dimension (1,2,3)
  * @param ipCoordinates : array of float coordinates
  * NOTE : Coordinates will be allocated the same dimension as the input one
  * NOTE : The TexCoordSet will make a copy of the input texture coordinates array
  */
  static CATVisTextureCoordinateSet* Build(const unsigned int iNbVertices, const unsigned int iCoordsDim, float const* ipCoordinates = NULL);

  /** 
  * @nodoc
  * Creates a TexCoordSet
  * @param iNbVertices : number of vertices
  * @param iInputCoordsDim : input coordinates dimension (1,2,3)
  * @param iAllocatedCoordsDim : allocated coordinates dimension requested (1,2,3)
  * @param ipCoordinates : array of float coordinates
  * @param lifecycle : lifecycle delegation
  */
  static CATVisTextureCoordinateSet* Build(const unsigned int iNbVertices, const unsigned int iInputCoordsDim, const unsigned int iAllocatedCoordsDim, float const* ipCoordinates = NULL, TCLifecycleManagement lifecycle = COPY);

  /** @nodoc */
  ~CATVisTextureCoordinateSet();   

  /** @nodoc */
  HRESULT Allocate(const unsigned int iNbVertices, const unsigned int iDimension, int init = 0);

  /** @nodoc */
  HRESULT Empty( bool resetId = false );

  /** @nodoc */
  const unsigned int GetDimension() const;

  /** @nodoc */
  const unsigned int GetNumberOfVertices() const;

  /** @nodoc */  
  float* GetCoordinates();

  /** @nodoc */  
  float const* GetCoordinates() const;
  
  /** @nodoc */  
  HRESULT NormalizeCoordinates();

  /** @nodoc */
  HRESULT EnsureCapacity(const unsigned int iNbVertices, const unsigned int iAllocatedCoordsDim);

  /** @nodoc */
  HRESULT SupplyCoordinates( const unsigned int iNbVertices, const unsigned int iCoordsDim, float const* ipCoordinates, TCLifecycleManagement lifecycle );

  /** @nodoc */
  void SetIdentifier( const CATUnicodeString& identifier );

  /** @nodoc */
  inline CATUnicodeString const& GetIdentifier() const { return _identifier; }

  /** @nodoc */
  inline bool HasCoordinates() const { return _pCoordinates ? TRUE : FALSE; }

  /** @nodoc */
  void SetStreamable( const CATBoolean doStream );

  /** @nodoc */
  inline CATBoolean GetStreamable() const { return _streamable; }

  /** @nodoc */
  void SetStorageID(unsigned int iStorageID) const;

  /** @nodoc */
  unsigned int GetStorageID() const;

  /** @nodoc */
  inline unsigned int StorageIDisValid();

private:

 /** 
  * @nodoc 
  * Copy not allowed
  */  
  CATVisTextureCoordinateSet (const CATVisTextureCoordinateSet &);
  CATVisTextureCoordinateSet & operator=(const CATVisTextureCoordinateSet &);
 
  /** @nodoc Number of vertices */
  unsigned int _nbVertices : 29;
  /** @nodoc Dimension of the texture coordinates of the set (e.g. 1D, 2D, 3D) */
  unsigned int _dimension : 2;
  /** @nodoc Coordinates array lifecycle ownership */
  unsigned int _ownTCs : 1;

  /** @nodoc */
  mutable unsigned int _StorageID;
  
  /** @nodoc The array of texture coordinates */
  float* _pCoordinates;

  /** @nodoc Identifier */
  CATUnicodeString _identifier;

  /** @nodoc */
  CATBoolean _streamable;

};

inline unsigned int CATVisTextureCoordinateSet::StorageIDisValid()
{
  if (_StorageID==0 || _StorageID==0x7fFFFFFF)
    return 0;
  else
    return 1;
}

#endif
