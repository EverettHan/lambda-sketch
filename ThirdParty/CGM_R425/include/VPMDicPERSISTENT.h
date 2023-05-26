//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMDicPERSISTENT_h
#define _VPMDicPERSISTENT_h

/**
 * ENOVIA package persistency types.
 * @param VPMDicLIB
 *   Explodes the lib result of the EXPRESS compilation.
 *   VPMDicLIB can only be used in read mode, that is, you can't save using VPMDicLIB
 * @param VPMDicFILE
 *   Save is done in a file.
 *   The file location is retrieved from the environment variable <code>ENOVDicPath</code>
 * @param VPMDicDATABASE
 *   Save is done in the database
 * @param VPMDicEXPRESS
 *   Generates an Express schema for the package
 */
enum VPMDicPERSISTENT
{
  VPMDicLIB=1
, VPMDicFILE=2
, VPMDicDATABASE=3
, VPMDicEXPRESS=4
}
;

#endif
