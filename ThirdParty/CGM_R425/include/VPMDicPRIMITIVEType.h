//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef VPMDicPRIMITIVEType_h
#define VPMDicPRIMITIVEType_h

/**
 * ENOVIA primitive types.
 * @param VPMDicUNDEFINED
 *   The ENOVIA primitive is of an undefined type
 * @param VPMDicBOOLEAN
 *   The ENOVIA primitive is a boolean
 * @param VPMDicINTEGER
 *   The ENOVIA primitive is an integer
 * @param VPMDicDOUBLE
 *   The ENOVIA primitive is a double
 * @param VPMDicSTRING
 *   The ENOVIA primitive is a character string
 * @param VPMDicBINARY
 *   The ENOVIA primitive is a queryable binary
 * @param VPMDiCLOB
 *   The ENOVIA primitive is a binary large object
 * @param VPMDicDATE
 *   The ENOVIA primitive is a date
 * @param VPMDicLOGICAL
 *   The ENOVIA primitive is a logical
 * @param VPMDicURL
 *   The ENOVIA primitive is a URL
 * @param VPMDicANYOBJECT
 *   The ENOVIA primitive is a any object
 * @param VPMDicENUUM
 *   The ENOVIA primitive is a Enum
 */

enum VPMDicPRIMITIVEType
{
      VPMDicUNDEFINED   = 0
    , VPMDicBOOLEAN     = 1
    , VPMDicINTEGER     = 2
    , VPMDicDOUBLE      = 3
    , VPMDicSTRING      = 4
    , VPMDicBINARY      = 5
    , VPMDicDATE        = 6
    , VPMDicLOGICAL     = 7
    , VPMDicURL         = 8
    , VPMDicANYOBJECT   = 9
    , VPMDicENUMERATION = 10
    , VPMDicCLOB        = 11
    , VPMDicIDENTIFIER  = 12
};

/**
 * Number of valid ENOVIA primitive types.
 * <b>Role:</b>It is the number of valid  primitive types, i.e. the size of the @href VPMDicPRIMITIVEType variable.
 * This constant can be used for instance:
 * <ul>
 * <li>to check the range of a VPMDicPRIMITIVEType variable </li>
 * <li>to define the condition section of a "for" loop, when scanning all the available @href VPMDicPRIMITIVEType </li>
 * </ul>
 */
#define _VPMDicPRIMITIVETypeNumber  12

#endif /*VPMDicPRIMITIVEType_h*/
