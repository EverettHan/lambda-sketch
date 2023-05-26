//-----------------------------------------------------------------------------
// Copyright Dassault Systemes 2020
//-----------------------------------------------------------------------------
#pragma once

#include "IVInterfaces.h"

#include <array>
#include <memory>

#include "CATMathPoint.h"
#include "CATMathTransformation.h"
#include "CATMathVector.h"
#include "IVHandTypes.h"
class IVHandImplItf;
class IVFinger;
class IVHand;

//=============================================================================
/**
 * IVJoint
 *
 * A Joint is the spatial data about a tracked hand joint.
 *
 * Note that an IVJoint kind matches the anatomical hand joint kind, except
 * for:
 *
 * - "Tip" joints that are virtual joints located at the tip of the finger.
 *
 * - Joints that belong to the thumb: we do not respect the anatomical names
 *   for practical purposes (see IVFinger description for more details).
 *
 * @see https://en.wikipedia.org/wiki/Hand#Bones
 */
class ExportedByIVInterfaces IVJoint
{
public:

  /**
   * Property. Joint type.
   */
  IVJointId Kind() const;

  /**
   * Property. Position of the distal extremity of the phalanx
   */
  CATMathPoint Position() const;

  /**
   * Property. Direction of the phalanx (distal extremity to proximal
   * extremity)
   */
  CATMathVector Direction() const;

public:

  /**
   * Hint. Tracking accuracy/confidence.
   *
   * :warning: May/may not be available depending on the tracking
   * source/hardware capabilities.
   *
   * @return 
   *  S_OK if the tracking source/hardware provides a tracking accuracy.
   *  E_XXX otherwise.
   */
  HRESULT TryAccuracy(IVJointAccuracy& oAccuracy) const;

  /**
   * Hint. Distance from the joint position to the surface of the joint
   * (skin).
   *
   * :warning: May/may not be available depending on the tracking
   * source/hardware capabilities.
   *
   * @return 
   *  S_OK if the tracking source/hardware provides a radius. 
   *  E_XXX Otherwise.
   */
  HRESULT TryRadius(double& oRadius) const;

  /**
   * Hint. Direction out of the back of the finger.
   *
   * :warning: May/may not be available depending on the tracking
   * source/hardware capabilities.
   *
   * @return 
   *  S_OK if the tracking source/hardware provides a up direction.
   *  E_FAIL otherwise.
   */
  HRESULT TryUp(CATMathVector& oUp) const;

public:

  /**
   * Navigation. Finger.
   *
   * @return The parent finger. Invalid finger is is this joint is not valid.
   */
   IVFinger Parent() const;

  /**
   * Navigation. Previous/Next joint (from proximal to tip)
   *
   * @return The previous/next joint. Invalid joint if navigation is not
   * possible or if this joint is not valid.
   */
  IVJoint Previous() const;
  IVJoint Next() const;

public:

  /**
   */
  explicit IVJoint() = default; // Invalid

  /**
   * true if the IVJoint is valid.
   */
  explicit operator bool() const;

public:

  /**
   */
  explicit IVJoint(std::shared_ptr<IVHandImplItf> const& iImpl, IVFingerId iFingerId, IVJointId iJointId);

private:

  std::shared_ptr<IVHandImplItf> m_impl;
  IVJointId m_jid{IVJointId::Invalid};
  IVFingerId m_fid{IVFingerId::Invalid};
};


//=============================================================================
/**
 * IVFinger
 *
 * A Finger is an ordered container of joints.
 *
 * Each Finger contains 4 joints.
 *
 * - The Tip joint that is a virtual joint located at the tip of the finger.
 *
 * - The Distal, Intermediate, Proximal joints which match the anatomical
 *   joints of the same name, except for the Thumb
 *
 * - The Thumb joints are:
 *   - Tip         : Virtual joint, same as for other fingers
 *   - Distal      : Anatomical Distal
 *   - Intermediate: Anatomical Proximal
 *   - Proximal    : Anatomical Metacarpal
 *
 * @see https://en.wikipedia.org/wiki/Hand#Bones
 */
class ExportedByIVInterfaces IVFinger
{
public:

  /**
   * Property. Finger type.
   */
  IVFingerId Kind() const;

public:

  /**
   * Navigation. Joint
   *
   * Warning: joint count/joint name may differ from anatomical fingers. See
   * this class's description.
   */
  IVJoint Joint(IVJointId iJointKind) const;

  /**
   * Navigation. Joints
   *
   * Order: proximal, intermediate, distal, tip.
   *
   * :note: joints can be accessed by rank or by id (see IVJointId)
   *
   * Warning: joint count/joint name may differ from anatomical fingers. See
   * this class's description.
   */
  std::array<IVJoint, 4> Joints() const;

  /**
   * Navigation. Hand.
   *
   * @return The parent hand. Invalid hand is is this finger is not valid.
   */
   IVHand Parent() const;

   /**
    * Navigation. Previous/Next finger (from thumb to little)
    *
    * @return The previous/next finger. Invalid finger if navigation
    * is not possible.
    */
   IVFinger Previous() const;
   IVFinger Next() const;

public:

  /**
   * Helper. Position/Direction of the Tip joint.
   */
  CATMathPoint  TipPosition() const;
  CATMathVector TipDirection() const;

  /**
   * Helper. Cumulated length of the phalanxes.
   */
  double Length() const;

public:

  /**
   * Finger posture. Pointing direction of the finger.
   *
   * A finger is considered as pointing only if the finger is fully extended.
   *
   * @param oPos. Position of the tip of the finger.
   *
   * @param oDir. Direction of the finger (proximal to tip). Normalized.
   *
   * @return
   *  S_OK Success.
   *  E_XXX Internal error or the finger is not pointing.
   */
   HRESULT PointingPose(CATMathPoint& oPos, CATMathVector& oDir) const;

public:

  /**
   */
  explicit IVFinger() = default; // Invalid

  /**
   * true if the IVFinger is valid.
   */
  explicit operator bool() const;

public:

  /**
   */
  explicit IVFinger(std::shared_ptr<IVHandImplItf> const& iImpl, IVFingerId iFingerId);

private:

  std::shared_ptr<IVHandImplItf> m_impl;
  IVFingerId m_fid{IVFingerId::Invalid};
};

//=============================================================================
/**
 * IVHand
 *
 * A Hand is a set of Joints organized hierarchically into Fingers
 *
 */
class ExportedByIVInterfaces IVHand
{
public:

  /**
   * Property. Hand type.
   */
  IVHandId Kind() const;

  /**
   * Property. Pose (position and orientation) of the palm.
   *
   * :note: If the tracking source/hardware doesnt provide a palm pose, the
   * latter is approximated according to the hand joint positions.
   *
   * - Y > 0 normal to the palm, oriented from the palm side to the back
   *   side of the hand.
   *
   * - Z > 0 from the palm to the wrist
   */
  CATMathTransformation PalmPose() const;

  /**
   * Property. Position of the wrist.
   */
  CATMathPoint WristPosition() const;

public:

  /**
   * Navigation. Finger
   */
  IVFinger Finger(IVFingerId iKind) const;

  /**
   * Navigation. Fingers
   *
   * Order: thumb, index, middle, ring, little
   * :note: in the array fingers can be accessed by rank or by id (see IVFingerId)
   */
  std::array<IVFinger, 5> Fingers() const;

public:

  /**
   * Hand posture. Position and orientation of the open palm.
   *
   * A palm is considered open when all the fingers of the hand are extended.
   *
   * :warning: there is absolutely no guarantee that a hand that is recognized
   * as open cannot be recognized as performing another posture.
   *
   * @oPose The palm pose. Note that Y>0 is from the palm side to the back
   * side of the hand. @see IVHand::PalmPose
   *
   * @return
   *  S_OK Success.
   *  E_XXX Palm is not open or internal error.
   */
   HRESULT OpenPalmPose(CATMathTransformation& oPose) const;

  /**
   * Hand posture. Pinch strength (Thumb and index).
   *
   * A hand is considered as pinching when (1) the distance (in millimeters)
   * between the thumb tip and the index tip is less than or equal to a given
   * distance while (2) the the little finger tip is away enough from the
   * thumb tip.
   *
   * :warning: there is absolutely no guarantee that a hand that is recognized
   * as pinching cannot be recognized as performing another posture.
   *
   * @param oStrength. Strength [0, 1].
   *  1 is full pinch.
   *
   * @param iMaxOpeningMM. Thumb/index tips distance for which the strength is 1
   *  (millimeters).
   *
   * @return
   *  S_OK Success.
   *  E_XXX The hand is not considered as pinching or internal error.
   */
  HRESULT Pinch2Strength(double& oStrength, double iMaxOpeningMM=40.) const;

  /**
   * Hand posture. Pinch strength (5 fingers).
   *
   * A hand is considered as pinching when (1) all the finger tips are close
   * to each other and then (2) the distance between the thumb and the middle
   * tips is less than a given distance.
   *
   * :warning: there is absolutely no guarantee that a hand that is recognized
   * as pinching cannot be recognized as performing another posture.
   *
   * @param oStrength. Strength [0, 1].
   *  1 is full pinch.
   *
   * @param iMaxOpening. Thumb/middle tips distance for which the strength is
   *  1 (millimeters).
   *
   * @return
   *  S_OK Success.
   *  E_XXX The hand is not considered as pinching or internal error.
   */
  HRESULT Pinch5Strength(double& oStrength, double iMaxOpenMM=60.) const;

  /**
   * Hand posture. Grab strength (fist).
   *
   * :note: A hand is considered as grabbing when the average distance
   * (normalized with finger length) between each finger tip and proximal
   * (thumb excluded) is less than the tolerance.
   *
   * :warning: there is absolutely no guarantee that a hand that is recognized
   * as grabbing cannot be recognized as performing another posture.
   *
   * @param oStrength. Strength [0, 1].
   *  1 is full grab
   *
   * @param iMaxOpening. Hand opening ratio [0, 1]
   * When iMaxOpening is set to 1, the start of a grabbing posture is when the
   * hand is fully open.
   *
   * @return
   *  S_OK Success.
   *  E_XXX The hand is not considered as grabbing or internal error.
   */
  HRESULT GrabStrength(double& oStrength, double iMaxOpening=0.75) const;

  /**
   * Hand posture. Pose of pointing hand index.
   *
   * A hand is considered as pointing when the index is extended while the
   * others fingers are bent. The thumb is not taken into account.
   *
   * :warning: there is absolutely no guarantee that a hand that is recognized
   * as grabbing cannot be recognized as performing another posture.
   *
   * @param oPos. Position of the tip of the index.
   *
   * @param oDir. Direction of the index (proximal to tip). Normalized.
   *
   * @return
   *  S_OK Success.
   *  E_XXX The hand is not considered as pointing or internal error.
   */
   HRESULT PointingPose(CATMathPoint& oPos, CATMathVector& oDir) const;

public:

  /**
   */
  explicit IVHand() = default; // Invalid

  /**
   * true if the IVHand is valid
   */
   explicit operator bool() const;

public:

  /**
   */
  explicit IVHand(std::shared_ptr<IVHandImplItf> const& iImpl);

private:

  std::shared_ptr<IVHandImplItf> m_impl;
};
