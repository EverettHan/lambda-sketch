// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyPPPosition.h
//
//===================================================================
//
// Usage notes: Description of a configuration (a position) in a space
// of configurations of type CATPolyPPCartesianProduct in the nD Path
// Planning solver.
//
//===================================================================
//
// 2013-01-04 XXC: Creation
//===================================================================

#ifndef CATPolyPPPosition_HH
#define CATPolyPPPosition_HH

#include "PolyPathPlanning.h"
#include "CATListPV.h"
#include "CATPolyPPCartesianProduct.h"
#include "CATPolyRefCounted.h"
#include "CATBoolean.h"
#include <vector>
#include <cstdio>
#include <string>

//class CATPolyPPTopologicalPoint;
#include "CATPolyPPTopologicalPoint.h"
class CATPolyPPTopologicalSpace;
class CATPolyPPRRTNode;

#ifdef ENABLE_PP_MT
#include <functional>
#endif

/** Class defining a configuration, in other words an object position,
 *  in a space of configurations CATPolyPPCartesianProduct.
 */
class ExportedByPolyPathPlanning CATPolyPPPosition : public CATPolyRefCounted
{
 public:
  /**
   * shared ptr of  CATPolyPPPosition 
   */
  typedef CATCGMSharedPtr<CATPolyPPPosition> SPtr; 
  enum ConfigurationType {
    Basic = 0, /**< Standard configuration with no particular
                  meaning */
    CheckPoint,/**< In the path planning solver, acts as a check
                   point, that is a configuration through which the
                   moving object must pass */
    BlackHole, /**< In the path planning solver, acts as an attractive
                 point to which the moving object is attracted */
    Invalid    /**< An invalid position can be returned by interpolator
               to indicate that the point cannot be interpolate here*/
  };

public:
  /** A position is defined according to a space of configurations,
   *  defining the dimension, the topology, the metric and the range
   *  of values for coordinates in each dimension.
   * @param iSpace
   *        the configurations space where is the constructed configuration.
   * @param iListOfTopoPoints
   *        the list of points in each of the topological spaces defining the configuration space.
   * @param iType
   *        the type of configuration
   */
  CATPolyPPPosition(const CATPolyPPCartesianProduct & iSpace, CATListPV iListOfTopoPoints, ConfigurationType iType = Basic);
  CATPolyPPPosition(const CATPolyPPCartesianProduct & iNewSpace, const CATPolyPPPosition & iPointToCopy );

  /** Copy constructor : copy a configuration in a new one.
   * @param iPoint: the configuration to copy.
   */
  CATPolyPPPosition(const CATPolyPPPosition & iPoint);
  CATPolyPPPosition & operator = (const CATPolyPPPosition & iPoint);



//  /** Returns the distance between this point and iPoint2.
//   */
//  INLINE double operator * (const CATPolyPPPosition & iPoint2) const
//  {
//    return _Space.Distance(*this, iPoint2);
//  }

  /** Direct access to the point coodinate, from 0 to Dimension()-1
   */
  virtual double & operator[](int idx);
  virtual const double & operator[](int idx) const;
  /** Return the configuration space's dimension.
   */
  virtual unsigned int Dimension() const;

  virtual CATBoolean IsInsideLimits() const;

  /** Get the configuration space.
   */
  INLINE const CATPolyPPCartesianProduct & GetSpace() const;

  INLINE void SetType(ConfigurationType iType);
  INLINE ConfigurationType GetType() const;
  INLINE CATPolyPPTopologicalPoint * GetTopoPoint(int index) const;

  /**
   * define the user type id (uint64 ).
   */
  typedef unsigned long long PPUserID;
  /**
   * can be use by caller to identify this position.
   * 0 is default value (must not be used by user )
   * \param[in] iID user id
   *   \warning 0 means undefined
   */
  void SetUserId(PPUserID iID);
  PPUserID GetUserId() const ;


  /**
   * can be use by caller to associate data to this position.
   * any class that derive from  CATPolyRefCounted can be used.
   * nullptr by default
   */
  void SetUserData(CATCGMSharedPtr<CATPolyRefCounted> iUserData);
  CATCGMSharedPtr<CATPolyRefCounted> GetUserData()const ;


  /** Get the associated PP node, if any.
   */
  INLINE const CATPolyPPRRTNode * GetNode() const;
  /** Don't call */
  void SetNode(CATPolyPPRRTNode * iNode);

  // For debug purpose
  INLINE void Print() const;
         std::string toJson() const;
         std::vector<double> toVector() const;

  void SetKinematicData(double time, std::vector<double> dDof, std::vector<double> ddDof);
  void GetKinematicData(double &otime, std::vector<double> & odDof, std::vector<double> & oddDof);

private:
  virtual ~CATPolyPPPosition();

private:

  friend class CATPolyPPCartesianProduct;

  ConfigurationType _Type;

#ifdef ENABLE_PP_MT
  std::reference_wrapper<const CATPolyPPCartesianProduct> _Space;
#else
  const CATPolyPPCartesianProduct & _Space;
#endif

  //CATListPV _TopoPoints;
  std::vector<CATPolyPPTopologicalPoint*> _TopoPoints;
  CATPolyPPRRTNode * m_node;

  //user data
  PPUserID _UserID = 0 ;
  CATCGMSharedPtr<CATPolyRefCounted> _UserData = nullptr;

  double _time;
  std::vector<double> _dDof;
  std::vector<double> _ddDof;
};

INLINE const CATPolyPPCartesianProduct & CATPolyPPPosition::GetSpace() const
{
#ifdef ENABLE_PP_MT
  return _Space.get();
#else
    return _Space;
#endif
}

INLINE void CATPolyPPPosition::SetType(CATPolyPPPosition::ConfigurationType iType)
{
  _Type = iType;
}

INLINE CATPolyPPPosition::ConfigurationType CATPolyPPPosition::GetType() const
{
  return _Type;
}

INLINE const CATPolyPPRRTNode * CATPolyPPPosition::GetNode() const
{
  return m_node;
}
INLINE CATPolyPPTopologicalPoint * CATPolyPPPosition::GetTopoPoint(int index) const
{
  return _TopoPoints[index];
}
INLINE void CATPolyPPPosition::Print() const
{
  unsigned i, dim = this->Dimension();
  printf("(");
  for (i = 0; i < dim; ++i)
  {
    printf("%f", (*this)[i]);
    if (i < dim-1)
      printf(", ");
  }
  printf(")\n");
}




#endif
