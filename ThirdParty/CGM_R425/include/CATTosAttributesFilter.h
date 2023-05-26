#ifndef CATTosAttributesFilter_H
#define CATTosAttributesFilter_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005

/**
 * @level Private
 * @usage U3
 */

 /**
 * Definition of the possible filters.
 * <tt> Possible values:</tt>
 * <dl>
 * @param <tt>CATTosAttributesFilter_ReadOnly</tt>      <dd>ReadOnly.
 * @param <tt>CATTosAttributesFilter_ReadWrite</tt>     <dd>ReadWrite.
 * </dl>
 */
#if ! defined ( CATTosAttributesFilter_definition )
#define CATTosAttributesFilter_definition
typedef unsigned int CATTosAttributesFilter;
#endif

#define CATTosAttributesFilter_ALL                        0x00000000

#define CATTosAttributesFilter_ReadOnly                   0x00000001 
#define CATTosAttributesFilter_ReadWrite                  0x00000002 

#endif



