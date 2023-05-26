//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2005
//=============================================================================
/**
 * @level Private
 * @usage U3
 */
#ifndef _VPMDicSEMANTICS_h
#define _VPMDicSEMANTICS_h

/**
 * enum VPMDicSEMANTICS describes Relationship,
 * and supersedes the VPMDicAGGREGATION enum
 *
 *<p> VPMDicUNKNOWN     : Life cycle is not defined
 *<p> VPMDicREFERENCE   : Association Relationship
 *                        Pointed object have separate life cycle
 *<p> VPMDicCOMPOSITION : Pointed objects have the same life cycle as the pointing object
 *<p>
 * <br>
 */
enum VPMDicSEMANTICS
{
  VPMDicUNKNOWN=1
 ,VPMDicREFERENCE=2
 ,VPMDicCOMPOSITIO=4 //car VPMDicCOMPOSITION est defini dans VPMDicAGGREGATION
}
;
#endif
