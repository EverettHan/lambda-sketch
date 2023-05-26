// COPYRIGHT DASSAULT SYSTEMES 2018, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyOverlayDiagnosis.h
//
//===================================================================
// March 2018 Creation: ndo
//===================================================================
#ifndef CATPolyBodyOverlayDiagnosis_H
#define CATPolyBodyOverlayDiagnosis_H


/**
 * Observer for capture of the various warnings and errors occuring during some overlay operation.
 * Warnings are given when some anomalies are detected but do not prevent completion of the overlay operation.
 * Errors are issued when some failures occur preventing completion of a successful overlay operation.
*/
class CATPolyBodyOverlayDiagnosis
{

public:

  virtual ~CATPolyBodyOverlayDiagnosis () {}

public:

  /**
   * Diagnosis type: error or warning.
   */
  enum Type
  {
    /** No diagnosis. */                                             dNone          = 0x00000000,
    /** Error. */                                                    dError         = 0x00000001,
    /** Warning. */                                                  dWarning       = 0x00000002
  };

  /**
   * Definition of the errors.
   */
  enum Error
  {
    /** Operand error. */                                           eOperand                  = 0x00000100,
    /** Operand not watertight. */                                  eOperandNotWatertight     = 0x00000101,
    /** Detection des contacts: Rules. */                           eDetectionContacts_Rules  = 0x00000200,
    /** Detection des contacts: Conflicting sides. */               eDetectionContacts_Sides  = 0x00000201,
    /** Detection des contacts: Shells (rules). */                  eDetectionContacts_Shells = 0x00000202,
    /** Detection des contacts. */                                  eDetectionContacts_       = 0x00000203,
    /** Triangulation. */                                           eTriangulation            = 0x00000300,
    /** Construction of result. */                                  eResultConstruction       = 0x00000400,
    /** Non-manifold edge. */                                       eResultNonManifoldEdge    = 0x00000401,
    /** Full edge. */                                               eResultFullEdge           = 0x00000402,
    /** Validity of model. */                                       eResultValidity           = 0x00000403
  };

  /**
   * Definition of the warnings.
   */
  enum Warning
  {
    /** Operand warning. */                                          wOperand       = 0x00000001,
    /** Empty result. */                                             wResultEmpty   = 0x00000002
  };

public:

/** @name Logger
    @{ */

  /**
   * Call made to log an error.
   * See enumerator of errors.
   */
  virtual void LogError (Error error) {}

  /**
   * Call made to log a warning.
   * See enumerator of warnings.
   */
  virtual void LogWarning (Warning warning) {}

/** @} */

};

#endif
