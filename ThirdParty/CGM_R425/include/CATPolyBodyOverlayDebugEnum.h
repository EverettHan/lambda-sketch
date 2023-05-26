// COPYRIGHT DASSAULT SYSTEMES 2021, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyOverlayDebugEnum.h
//
//===================================================================
// Nov 2021 : F1Z : Creation (goal: genericity and clean of overlay dbg)
//===================================================================

#pragma once

namespace Poly
{
  namespace Overlay
  {
    namespace Debug
    {
      enum class OperatorType 
      {
        eUnknown,
        eBoolean,
        eCombine,
        eSplitter,
        eIntersect,
        eJoin,
        eHWO,
        eNaryCombine// add after new operation based on overlay debug infrastructure
      };

      enum class OverlayStage : unsigned int
      {
        /** Substitute overlay contacts (child contacts). */     eSubstituteContacts,
        /** Triangulate the overlay operands. */                 eTriangulate,
        /** Postprocess overlay contacts. */                     ePostprocessContacts,
        /** Build the result of the binary operation. */         eBuildBodyResult,
        /** End of all processing. */                            eEnd
      };

      enum class ContactStage : unsigned int
      {
        /** Compute the BVH for the operands. */                 eBVH,
        /** Compute the intersections between operands. */       eIntersect,
        /** Detecting triangle patches. */                       ePatchDetection,
        /** Overlaying the vertices from the operands. */        eOverlayingVertices,
        /** Overlaying the edges from the operands. */           eOverlayingEdges,
        /** Overlaying the faces from the operands. */           eOverlayingFaces,
        /** Finding the contacts among edges. */                 eFindEdgeEdgeContacts,
        /** Process Contact */                                   eProcessContact,
        /** Applying overlay rules. */                           eApplyRules
      };

      enum class PropagateStage : unsigned int
      {
        /** Propagate a front for overlapping patches. */        ePropagateFront,
        /** Propagate the winding numbers. */                    ePropagateWN,
        /** Find the overlaps between operands. */               ePropagateOverlap
      };

      enum class GeneralStage : unsigned int
      {
        /** Run the bisection of the operands. */                eBisect,
        /** Make the operands conformal by regularization. */    eRegularize,
        /** Remove the small segments from the overlay. */       eFilter,
        /** Collapse small bars from the operand. */             eCollapse
      };

      enum class HWOStage : unsigned int
      {
        /** first contact detection end. */                      eFirstContactDetection,
        /** fill hole contact detection end. */                  eFillHole
      };

      enum class OperationType : unsigned int
      {
        eUnknown,
        eOverlay, // general overlay operations, not specific to an operator
        eContact,
        ePropagate,
        eGeneral,
        eHWO
      };


      template<typename StageType>
      inline OperationType GetOperationType(const StageType iType)
      {
        return OperationType::eUnknown;
      }

      template<typename StageType>
      inline StageType GetStage(unsigned int s)
      {
        return static_cast<StageType>(s);
      }
    }
  }
}

// Specialisation
template<>
inline Poly::Overlay::Debug::OperationType Poly::Overlay::Debug::GetOperationType(const Poly::Overlay::Debug::OverlayStage iType)
{
  return Poly::Overlay::Debug::OperationType::eOverlay;
}

template<>
inline Poly::Overlay::Debug::OperationType Poly::Overlay::Debug::GetOperationType(const Poly::Overlay::Debug::ContactStage iType)
{
  return Poly::Overlay::Debug::OperationType::eContact;
}

template<>
inline Poly::Overlay::Debug::OperationType Poly::Overlay::Debug::GetOperationType(const Poly::Overlay::Debug::PropagateStage iType)
{
  return Poly::Overlay::Debug::OperationType::ePropagate;
}

template<>
inline Poly::Overlay::Debug::OperationType Poly::Overlay::Debug::GetOperationType(const Poly::Overlay::Debug::GeneralStage iType)
{
  return Poly::Overlay::Debug::OperationType::eGeneral;
}

template<>
inline Poly::Overlay::Debug::OperationType Poly::Overlay::Debug::GetOperationType(const Poly::Overlay::Debug::HWOStage iType)
{
  return Poly::Overlay::Debug::OperationType::eHWO;
}
