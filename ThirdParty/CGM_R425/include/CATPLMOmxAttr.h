// COPYRIGHT Dassault Systemes 2009
//===================================================================
//
// CATPLMOmxAttr.h
// Header definition of CATPLMOmxAttr
//
//===================================================================
//
// Usage notes:
//
//===================================================================
// November 2009  Creation: EPB
//===================================================================

/**
 * @level Protected
 * @usage U1
 */

// U1:        Concrete class: use as is only. C++ usage 
// Protected: The header doc is only generated in the PLMInf web. All frameworks authorized to use the framework containing the header can use it.


#ifndef CATPLMOmxAttr_H
#define CATPLMOmxAttr_H

enum CATPLMOmxAttr{
  /* STRING */
  PLMTYPE_OMX_STRING = 0,
  /* INTEGER */
  PLMTYPE_OMX_INTEGER = 1,
  /* BINARY */
  PLMTYPE_OMX_BINARY = 2,
  /* DOUBLE */
  PLMTYPE_OMX_DOUBLE = 3,
  /* DATE */
  PLMTYPE_OMX_DATE = 4,
  /* BOOLEAN */
  PLMTYPE_OMX_BOOLEAN = 5,
  /* Unset */
  PLMTYPE_OMX_UNSET = 6,
  /* CATPLMID */
  PLMTYPE_OMX_PLMID = 7,
  /* CATPLMTypeId */
  PLMTYPE_OMX_PLMTYPEID = 8,
  /* ERROR not recognized type*/
  PLMTYPE_OMX_ERROR = 9,
  /* enum*/
  PLMTYPE_OMX_ENUM=10
};

#endif
