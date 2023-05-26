//-----------------------------------------------------------------------------
// Copyright Dassault Systemes 2020
//-----------------------------------------------------------------------------
#pragma once

//=============================================================================
/**
 * IVHandId
 */
enum class IVHandId : unsigned char {
  Left    = 0,
  Right   = 1,
  Invalid = 0xFF
};

//=============================================================================
/**
 * IVFingerId
 */
enum class IVFingerId : unsigned char {
  Thumb     = 0,
  Index     = 1,
  Middle    = 2,
  Ring      = 3,
  Little    = 4,
  Invalid = 0xFF
};

//=============================================================================
/**
 * IVJointId
 *
 * :Note:
 *
 *   - "Tip" joints are virtual joints
 *   - Thumb joints:
 *       - "Intermediate" is the anatomical Proximal
 *       - "Proximal"     is the anatomical Metacarpal
 */
enum class IVJointId : unsigned char {
  Proximal     = 0,
  Intermediate = 1,
  Distal       = 2,
  Tip          = 3,
  Invalid      = 0xFF
};

//=============================================================================
/**
 * IVJointAccuracy
 *
 * How confident we are about the spatial tracking of a joint.
 */
enum class IVJointAccuracy : unsigned char {
  Accurate    = 0,
  Approximate = 1,
  Invalid     = 0xFF
};
