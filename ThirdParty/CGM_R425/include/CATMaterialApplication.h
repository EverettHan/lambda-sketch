//===================================================================
// CATMaterialApplication.h
// Header definition of class CATMaterialApplication
// COPYRIGHT DASSAULT SYSTEMES 2014
//===================================================================

#ifndef CATMaterialApplication_H
#define CATMaterialApplication_H

#include "SGInfra.h"
#include "CATDataType.h"
#include "IUnknown.h"

class CATGraphicMaterial;
class CATStreamer;
class CATMaterialApplicationImpl;
class VisMaterialApplication;
class CATMappingOperator;

/**
* @CAA2Level L1
* @CAA2Usage U1
*/

/** Number max for a CATULONG32 layer */
#define LAYER_MAX             0xFFFFFFFF
/** Number max minus one for a CATULONG32 layer */
#define	LAYER_MAX_MINUS_ONE   0xFFFFFFFE

/** @nodoc */
enum CATMatAppStreamSettings
{
  STREAM_NONE           =  0x00,  // 0000 0000 0000
  STREAM_MATERIAL       =  0x01,  // 0000 0000 0001
  STREAM_INHERIT_INT    =  0x02,  // 0000 0000 0010
  STREAM_INHERIT_UINT   =  0x04,  // 0000 0000 0100
  STREAM_INHERIT_ULONG  =  0x08,  // 0000 0000 1000
  STREAM_LAYER_INT      =  0x10,  // 0000 0001 0000
  STREAM_LAYER_UINT     =  0x20,  // 0000 0010 0000
  STREAM_LAYER_ULONG    =  0x40,  // 0000 0100 0000
  STREAM_UVTRANSFO      =  0x80,  // 0000 1000 0000
  STREAM_MAPPING_INFO   = 0x100,  // 0001 0000 0000
  STREAM_LIGHTMAP       = 0x200,  // 0010 0000 0000
  STREAM_ALL_INT        = STREAM_MATERIAL|STREAM_INHERIT_INT  |STREAM_LAYER_INT  |STREAM_UVTRANSFO|STREAM_MAPPING_INFO|STREAM_LIGHTMAP,   
  STREAM_ALL_UINT       = STREAM_MATERIAL|STREAM_INHERIT_UINT |STREAM_LAYER_UINT |STREAM_UVTRANSFO|STREAM_MAPPING_INFO|STREAM_LIGHTMAP,   
  STREAM_ALL_ULONG      = STREAM_MATERIAL|STREAM_INHERIT_ULONG|STREAM_LAYER_ULONG|STREAM_UVTRANSFO|STREAM_MAPPING_INFO|STREAM_LIGHTMAP
};

//-----------------------------------------------------------------------

//=======================================================================
// Abstract 
// --------
//  This class manages a CATGraphicMaterial, defines how it is applied to a geometry and how it will be inherited in the SceneGraph.
//
//=======================================================================
// Usage
// -----
//  The implementation is delegated to a CATMaterialApplicationImpl thanks to a letter-envelope design pattern.
//  The implementation contains :
//    > a pointer to CATGraphicMaterial
//    > a layer that defines the material context application
//    > an inheritance number that defines how the material will be inherited through the SceneGraph
//
//  <> NEW INHERITANCE RULE <>
//  (mat1,layer1,inherit1) VS (mat2,layer2,inherit2)
//  if ( layer1 < layer2 ) then mat1 wins
//  if ( layer1 > layer2 ) then mat2 wins
//  if ( layer1 = layer2 ) then compare inherit1 and inherit2
//=======================================================================

/** CATMaterialApplication Class Definition.
* This class manages a @href CATGraphicMaterial, defines how it is applied to a geometry and how it will be inherited in the SceneGraph.
*/
class ExportedBySGInfra CATMaterialApplication
{
public:
	
	/** Constructor of an empty CATMaterialApplication */
	CATMaterialApplication();
	/** Constructor of a CATMaterialApplication, with material, inheritance and layer initialization */
	CATMaterialApplication( CATGraphicMaterial* pMat, CATULONG32 inherit = 1, CATULONG32 layer = LAYER_MAX_MINUS_ONE );
  /** Copy constructor */
  CATMaterialApplication( const CATMaterialApplication& matApp );
  /** Equal operator */
  CATMaterialApplication& operator=( const CATMaterialApplication& matApp );
	/** Destructor */
	virtual ~CATMaterialApplication();

	// MATERIAL MANAGEMENT //

	/** Sets the CATGraphicMaterial */
	void SetGraphicMaterial( CATGraphicMaterial* pMat );
	/** Gets the CATGraphicMaterial */
	CATGraphicMaterial * GetGraphicMaterial() const;

	// INHERITANCE MANAGEMENT //

	/** Sets the inheritance number */
	void SetMaterialInheritance( CATULONG32 inherit );
	/** Gets the inheritance number */
	CATULONG32 GetMaterialInheritance() const;

	// LAYER MANAGEMENT //

	/** Sets the layer number */
	void SetLayer( CATULONG32 layer );
	/** Gets the layer number */
	CATULONG32 GetLayer() const;

  // UV TRANSFORMATION API //

  /** Sets the UV translation in both U and V directions */
  void SetUVTranslation( float translate_u, float translate_v );
  /** Gets the UV translation in both U and V directions */
  void GetUVTranslation( float& translate_u, float& translate_v ) const;

  /** Sets the UV rotation angle, which has to be in radian */
  void SetUVRotation( float angle );
  /** Gets the UV rotation angle, which is in radian */
  void GetUVRotation( float& angle ) const;

  /** Sets the uniform UV scale, which has to be positive */
  void SetUVScale( float scale );
  /** Gets the uniform UV scale, which is positive */
  void GetUVScale( float& scale ) const;

  // TEXTURE COORDINATE MAPPING API //

  /** Returns the mapping operator associated to the graphic material. */
  CATMappingOperator * GetMappingOperator() const;

  /** Sets the mapping operator associated to the graphic material.
  * @param iOperator
  * Mapping operator used to calculate texture coordinates.
  */
  void SetMappingOperator(CATMappingOperator *iOperator);

  // STREAMING API //

  /** @nodoc */
  void Stream( CATStreamer& str, CATMatAppStreamSettings iSettings = STREAM_ALL_ULONG );
  /** @nodoc */
  void Unstream( CATStreamer& str, CATMatAppStreamSettings iSettings = STREAM_ALL_ULONG );

  // LETTER - ENVELOPE PATTERN

  /** @nodoc */
  inline CATMaterialApplicationImpl* GetImpl() const { return nullptr; }

  /** @nodoc */
  inline VisMaterialApplication* GetVisuImpl() const { return _pMatAppImpl; }


private:

  VisMaterialApplication* _pMatAppImpl;
};

//-----------------------------------------------------------------------

#endif
