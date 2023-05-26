/* Generated from CATHybErrors.msg on Fri Nov  6 17:16:58 1998
 */
#ifndef _CATHYBERRORS_INCLUDE
#define _CATHYBERRORS_INCLUDE

// COPYRIGHT DASSAULT SYSTEMES 1999

typedef enum {

      HybIntTopologyContourError = 0x00020001u,
        HybIntUnexpectedGeometry = 0x00020002u,
          HybIntEdgeMergingError = 0x00020003u,
          HybIntCuttingWireError = 0x00020004u,
          HybIntProjectWireError = 0x00020005u,
         HybIntExtrapolWireError = 0x00020006u,
         HybIntExtrapolEdgeError = 0x00020007u,
        HybIntDuplicateWireError = 0x00020008u,
          HybIntInvalidWireError = 0x00020009u,
         HybIntInvalidShellError = 0x0002000au,
      HybIntOrientationWireError = 0x0002000bu,

      HybInputUnexpectedGeometry = 0x00020001u,
 HybInputUnexpectedOperatorInput = 0x00020002u,
 HybInputClosedWireOperatorInput = 0x00020003u,
 HybInputInvalidKindOfProjection = 0x00020004u,
HybInputSuperimposedElementsInput = 0x00020005u,
HybInputNoIntersectionBetweenElements = 0x00020006u,
  HybInputOptionModeInconsistent = 0x00020007u,
    HybInputInvalidRunManagement = 0x00020008u,
HybInputInvalidGetResultManagement = 0x00020009u

} HybTopologicalOperatorsErrors;

#endif
