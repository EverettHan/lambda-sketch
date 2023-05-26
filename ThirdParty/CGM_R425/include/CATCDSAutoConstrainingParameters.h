// COPYRIGHT DASSAULT SYSTEMES 2013
//=============================================================================
//
// CATCDSAutoConstrainingParameters:
//   Class to engage/disengage autoconstraining in variational operators and
// modify autoconstraining parameters.
//
//=============================================================================
//
// Usage notes:
//
//   To modify autoconstraining parameters, you can use set and get methods in
// in your code. You can also use environnement variables whose description
// follows.
//
//
//   To activate autoconstraining mode in variational operators, you can use
// the environnement variable CDSAutoConstraining.
//
//
//   To select autoconstraining pattern, you can use environnement variables
// in the following list :
// - distance         :  CATCDSACPDistance
// - angle            :  CATCDSACPAngle
// - parallelism      :  CATCDSACPParallelism
// - perpendicularity :  CATCDSACPPerpendicularity
// - coincidence      :  CATCDSACPCoincidence
// - tangency         :  CATCDSACPTangency
// - antiTangency     :  CATCDSACPAntitangency
// - radius           :  CATCDSACPRadius
// - majorRadius      :  CATCDSACPMajorRadius
// - minorRadius      :  CATCDSACPMinorRadius
// - apexAngle        :  CATCDSACPApexAngle
// - concentricity    :  CATCDSACPConcentricity
// - coaxiality       :  CATCDSACPCoaxiality
// - midPoint         :  CATCDSACPMidPoint
// - symmetry         :  CATCDSACPSymmetry
//
//
//   To define the length of propagation in variational model, you can use
// environnement variables in the following list : (values must be integers)
// - default          :  CATCDSACPDefaultPropag
//     /!\ FOR NOW, ONLY DEFAULT IS USED /!\
// - distance         :  CATCDSACPDistancePropag
// - angle            :  CATCDSACPAnglePropag
// - parallelism      :  CATCDSACPParallelismPropag
// - perpendicularity :  CATCDSACPPerpendicularityPropag
// - coincidence      :  CATCDSACPCoincidencePropag
// - tangency         :  CATCDSACPTangencyPropag
// - antiTangency     :  CATCDSACPAntitangencyPropag
// - radius           :  CATCDSACPRadiusPropag
// - majorRadius      :  CATCDSACPMajorRadiusPropag
// - minorRadius      :  CATCDSACPMinorRadiusPropag
// - apexAngle        :  CATCDSACPApexAnglePropag
// - concentricity    :  CATCDSACPConcentricityPropag
// - coaxiality       :  CATCDSACPCoaxialityPropag
// - midPoint         :  CATCDSACPMidPointPropag
// - symmetry         :  CATCDSACPSymmetryPropag
//
//
//=============================================================================
//  Nov 2013  Creation                                Delphine JENNEQUIN (KUB)
//                                              Etienne de SAINT GERMAIN (ZO4)
//=============================================================================

#ifndef CATCDSAutoConstrainingParameters_h
#define CATCDSAutoConstrainingParameters_h


#include "CATCDSUtilities.h"
#include "CATCDSBoolean.h"
#include "CATCDSACEnums.h"


class ExportedByCATCDSUtilities CATCDSAutoConstrainingParameters {

public:
  /** Constructor & destructor */
  CATCDSAutoConstrainingParameters();
  ~CATCDSAutoConstrainingParameters();


  /** Initialize with environnement variables */
  void InitializeWithEnv();


  /** Return TRUE if autoconstraining is engage, FALSE otherwise */
  CATCDSBoolean IsActivated();
  /** To engage/disengage autoconstraining */
  void SetUseAutoContrainingMode(CATCDSBoolean iUseAutoConstrainingMode);


  /**
   * Method to engage/disengage an autoconstraining pattern
   * @param iType
   *   Type of constraint
   * @param iBool
   *   - TRUE if constraint type iType must be searched by autoconstraining
   *   - FALSE otherwise
   */
  void SetConstraint(CATCDSACType iType, CATCDSBoolean iBool);
  /**
   * Method to get if an autoconstraining pattern is used
   * @param iType
   *   Type of constraint
   * @return
   *   - TRUE if the constraint type iType is search by autoconstraining
   *   - FALSE otherwise
   */
  CATCDSBoolean GetConstraint(CATCDSACType iType);


  /**
   * Method to set the weight of a constraint type
   * @param iType
   *   Type of constraint
   * @param iWeight
   *   Weight of the constraint type
   */
  void SetWeight(CATCDSACType iType, double iWeight);
  /**
   * Method to get the weight of a constraint type
   * @param iType
   *   Type of constraint
   * @return
   *   the weight of the constraint type iType
   */
  double GetWeight(CATCDSACType iType);


  /**
   * Method to set the default length of propagation to adjacent elements in variational model.
   * @param iLength
   *   Length of default propagation
   */
  void SetDefaultPropagLength(short iLength);
  /**
   * Method to get the default length of propagation to adjacent elements in variational model.
   */
  short GetDefaultPropagLength();


  /**
   * Method to set the length of propagation to adjacent elements in variational model for a type of constraint.
   * @param iType
   *   Type of constraint
   * @param iLength
   *   Length of default propagation
   */
  void SetPropagLength(CATCDSACType iType, short iLength);
  /**
   * Method to get the length of propagation to adjacent elements in variational model for a type of constraint.
   * @param iType
   *   Type of constraint
   */
  short GetPropagLength(CATCDSACType iType);


private:
  // Boolean used to engage/disengage autoconstraining
  CATCDSBoolean _useAutoConstrainingMode;


  //***************************************************************************
  // Structure used to save which type of constraint is used in autoconstraining
  struct ExportedByCATCDSUtilities UsedConstraintTypes {
    // Constructor
    UsedConstraintTypes();

    // Initialize the types of constraint which are searched by autoconstraint with the values of environment variables
    void InitializeWithEnv();

    // Types of constraint which are searched by autoconstraint
    CATCDSBoolean _distance;
    CATCDSBoolean _angle;
    CATCDSBoolean _parallelism;
    CATCDSBoolean _perpendicularity;
    CATCDSBoolean _coincidence;
    CATCDSBoolean _tangency;
    CATCDSBoolean _antiTangency;
    CATCDSBoolean _radius;
    CATCDSBoolean _majorRadius;
    CATCDSBoolean _minorRadius;
    CATCDSBoolean _apexAngle;
    CATCDSBoolean _concentricity;
    CATCDSBoolean _coaxiality;
    CATCDSBoolean _midPoint;
    CATCDSBoolean _symmetry;
  };

  UsedConstraintTypes _usedConstraintTypes;


  //***************************************************************************
  // Structure used to save weights of constraints
  struct ExportedByCATCDSUtilities ConstraintWeight {
    // Constructor
    ConstraintWeight();

    // Types of constraint which are searched by autoconstraint
    double _distance;
    double _angle;
    double _parallelism;
    double _perpendicularity;
    double _coincidence;
    double _tangency;
    double _antiTangency;
    double _radius;
    double _majorRadius;
    double _minorRadius;
    double _apexAngle;
    double _concentricity;
    double _coaxiality;
    double _midPoint;
    double _symmetry;
  };

  ConstraintWeight _constraintWeight;



  //***************************************************************************
  // Structure used to define the length for propagation in model
  struct ExportedByCATCDSUtilities ACPropagationLength {
    // Constructor
    ACPropagationLength(short iDefaultLenght = 1);

    // Initialize the types of constraint which are searched by autoconstraint with the values of environment variables
    void InitializeWithEnv();

    // Default length of propagation
    short _defaultLength;

    // Length of propagation by constraint
    // NOT USED FOR NOW
    short _distance;
    short _angle;
    short _parallelism;
    short _perpendicularity;
    short _coincidence;
    short _tangency;
    short _antiTangency;
    short _radius;
    short _majorRadius;
    short _minorRadius;
    short _apexAngle;
    short _concentricity;
    short _coaxiality;
    short _midPoint;
    short _symmetry;
  };

  ACPropagationLength _acPropagationLength;
};

/** To get the autoconstraining parameters or change theirs values */
ExportedByCATCDSUtilities CATCDSAutoConstrainingParameters & GetAutoConstrainingParameters();

#endif

