// COPYRIGHT DASSAULT SYSTEMES 2006

#ifndef CATCVMGeoConstraintProvider_H
#define CATCVMGeoConstraintProvider_H

// COPYRIGHT DASSAULT SYSTEMES 2006

//===================================================================
//===================================================================
//
// CATCVMGeoConstraintProvider
//
//===================================================================
//
//Provide constraints on given geometries
//
//===================================================================
// Oct. 2006    Creation                         AAD
//===================================================================

#include "CATCVMGeoOperators.h"
#include "CATCVMGeoOperator.h"
#include "ListPOfCATCVMGeometry.h"
#include "CATListOfInt.h"
#include "CATCVMDouble.h"
#include "CATCVMGeoConstraint.h"

class CATCVMGeoContainer;
class CATGeoFactory;
class CATTopData;

class ExportedByCATCVMGeoOperators CATCVMGeoConstraintProvider : public CATCVMGeoOperator
{
  public:
  //------------------------------------------------------------------------------
  // Create a ConstraintProvider operator
  //------------------------------------------------------------------------------
    static CATCVMGeoConstraintProvider * Create(CATCVMGeoContainer *iCVMGeoContainer,
                                     CATTopData         *iTopData);

  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  protected:
    CATCVMGeoConstraintProvider(CATCVMGeoContainer   *iCVMGeoContainer,
                     CATTopData           *iTopData,
                     CATCVMGeoOperatorExt *iExtensible);
  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  public:
  virtual ~CATCVMGeoConstraintProvider();

/**
 *To be called before Run
 *iListGeometries: the geometries on which constraints will be provided
 */
  public:
    virtual void SetGeometries(ListPOfCATCVMGeometry & iListGeometries);


/**
 *To be called after Run
 *Return: number of proposed constraints 
 */
  public:
    virtual int GetNbProposedConstraints();

/**
 *To be called after Run
 *iIndex: index of the constraint. 0 < iIndex <= GetNbProposedConstraints()
 *oValue: current value of the constraint. Meaningful only if the returned type is a subtype of 
 *  CATCVMGeoDimConstraint. 
 *oRoles: list of roles for the geometries and for oValue. Same order as iListGeometries, with
 *  oValue role at the end.
 *oPossibility:
 *  CATCVMConstraintActual: the constraint is satisfied with the current position of the geometries
 *  CATCVMConstraintPossible: the constraint is not satisfied with the current position of the geometries
 *Return: the type of the proposed constraint. 
 */
  public:
    virtual CATCVMObjectType GetProposedConstraint(int iIndex, double & oValue,
        CATListOfInt & oRoles, CATBoolean & oIsSatisfied);

/**
 *To be called after Run
 *iIndex: index of the constraint. 0 < iIndex <= GetNbProposedConstraints()
 *Return: proposed constraint with proper atoms and located in the right component. 
 */
  public:
    virtual CATCVMGeoConstraint * CreateConstraint(int iIndex);


  //------------------------------------------------------------------------------
	// CGM Internal Use
	//------------------------------------------------------------------------------
  private:
    //virtual int RunOperator();
    
  public:
    static const CATString *GetDefaultOperatorId();
};
#endif

