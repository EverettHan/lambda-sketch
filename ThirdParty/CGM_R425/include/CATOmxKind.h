
#ifndef __CATOmxKind_h__
#define __CATOmxKind_h__

#include "CATOmxKernel.h"

/**
 * @level Protected
 * @usage U1
 */

// Mapping type of a value to an integer.
// These values are used in the stream in order to know what kind
// of attribute we are reading/writing.

/**
 * The grand unified kind: TCKind, 
 * 
 * Application domain
 * <ul>
 * <li>ALL : universal</li>
 * <li>PROPERTY : applicable on property and OSML</li>
 * <li>FMLATE : applicable for late feature and OSML</li>
 * <li>FMEARLY : applicable for early feature legacy and OSML</li>
 * <li>LITERAL : applicable for literal feature value and OSML</li>
 * <li>OMXANY : applicable only for OMXANY</li>
 * <li>OMXANY/ExtendedKind : applicable only for OMXANY as an extended kind (no optimisation)</li>
 * <li>OMXANY/Boxing : applicable only for OMXANY as an IUnknown extended kind (no optimisation)</li>
 * <li>FMOSML : applicable only for OSML langage</li>
 * </ul>
 * 
 */

enum CATOmxKind {
  //* BEWARE: do not change first ten values which are used for early/any persistency
  /** int32 type  (ALL) */
  omx_int =	0x0000, omx_int32=omx_int,
  /** double type (ALL) */
  omx_double = 0x0001,
  /** octet type (ALL) */
  omx_octet = 0x0002,
  /** boolean (ALL) */
  omx_boolean = 0x0003,
  /** unicode string (ALL) */
  omx_string = 0x0004,
  /** feature reference (FMLATE and FMEARLY) */
  omx_specobject = 0x0005,
  /** feature reference (FMLATE and FMEARLY) */
  omx_component = 0x0006, 
  /** general purpose intercontainer reference (FMLATE and FMEARLY) */
  omx_external = 0x0007, 
  
  /** represent any type (ALL) */
  omx_any = 0x8, 

  /** attribute reference (FMLATE) */  
  omx_attribute = 0x9 , 
  /** technological link (FMLATE) */  
  omx_techno = 0xa ,
  /** empty kind (ALL) */
  omx_void,
  /** (ALL) */

  //* BEWARE: do not change first ten values which are used for early/any persistency

  omx_IUnknown,
  /** void * (ALL) */
  omx_pointer , 
  /** CATINT64 (OMXANY) */
  omx_int64 , 
  /** CATError reference (caution : unmanaged life cycle) (FMLATE) */
  omx_error ,
  /** CATUuid type (OMXANY and OSML) */
  omx_uuid , 
  /** time_t type (OMXANY). */
  omx_time ,
  
  /** magnitude type for (LITERAL) */
  omx_alias , 
  /** fake initial type for (LITERAL) */
  omx_principal ,
  /** enum type for (LITERAL) */
  omx_enum ,
  /** CORBAAny::tk_binary (PROPERTY) */ 
  omx_binary ,
  /** CORBAAny::tk_short (PROPERTY) */
  omx_short , omx_int16 = omx_short,

  /** identifier not a string (OSML) */
  omx_identifier ,
  /** exception type (OSML) */
  omx_exception , 
  /** reference type (OSML) */
  omx_reference ,
  /** map type (OSML) */
  omx_map ,
  /** deprecated */
  omx_facet = omx_map ,
  /** class type (OSML) */
  omx_class ,
  /** class instance type (OSML) */
  omx_instance ,
  /** CATIFeatPlug reference (OSML) */
  omx_container,
  /** CATDocument reference (OSML) */
  omx_document,
  /** CATILinkableObject reference (OSML) */
  omx_linkable,
  /** CATOmbLink (OSML) */
  omx_omblink,
  /** module type (OSML) */
  omx_module,
  /** definition bytecode type (OSML) */
  omx_def,
  /** unsigned 16 bits int (OMXANY/ExtendedKind). */ 
  omx_ushort, omx_uint16 = omx_ushort,
  /** unsigned 32 bits int (OMXANY/ExtendedKind). */ 
  omx_uint,  omx_uint32= omx_uint,
  /** unsigned 64 bits int (OMXANY/ExtendedKind). */ 
  omx_uint64,
  /** float marker (OMXANY/ExtendedKind). */ 
  omx_float,
  /** v6 only object id (OMXANY/Boxing) */
  omx_plmid,
  /** v6 only type (OMXANY/Boxing) */
  omx_plmtype,
  /** InternalUs */
  omx_utf8string,

  /** @nodoc DO NOT REMOVE this used to initialize internal table */
  omx_LASTKIND 
};
namespace CATOmx {
  /**
   * Return the label associated to the iKind. 
   * Approximatively it report the omx_xx as "xx".
   * @return NULL if invalid kind.
   */
  ExportedByCATOmxKernel const char *GetKindLabel(CATOmxKind iKind) ;
}


#endif // __CATOmxKind_h__
