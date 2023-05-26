//=============================================================================
// COPYRIGHT Dassault Systemes 2022
//=============================================================================
//
// CATPolyBVHTreeFilterHidden.h
//
//=============================================================================
// 2009-05-12   GH7
//      * New
//=============================================================================
#ifndef CATPPVisuRepTreeSelectorOper_H
#define CATPPVisuRepTreeSelectorOper_H




#include "CATPolyRefCounted.h"
#include "CATCGMSharedPtr.h"
#include "CATMathTransformation.h"
#include "DSYExport.h"
#include "CATPolyLittleTimer.h"




class CATRep;
class CAT3DBagRep;


//------------------------------------------------------------------

/**
 * This operator duplicate a rep tree by keeping only some rep selected by a user filter.
 * It can be used to reduce the data send to a CATBVHTree
 */
class DSYExport CATPPVisuRepTreeSelectorOper : public CATPolyRefCounted
{
public:

  CATPPVisuRepTreeSelectorOper();
  virtual ~CATPPVisuRepTreeSelectorOper();


  
  /**
   *  operator that must clone a rep 
   *  default implement only create a new bag rep a more complete implementation should use 
   * 
   *  CATVisGeomServices::CATDuplicateRep
   * 
   * */
  class DSYExport CloneOper 
  {
    public: 
      virtual CAT3DBagRep * Clone(CAT3DBagRep & iToClone ) const;

  };



  /**
   *  brief base class to override to select a node default accept all (rep,tranformation) couple
   * */
  class DSYExport Filter : public CATPolyRefCounted
  {
    public:
      /**
       * smart pointer type
       * */
      typedef CATCGMSharedPtr<Filter> SPtr;
    /**
     * @brief must return true if the iRep at the iT position must be selected
     * @param[in] iRep the rep to analyse
     * @param[in] iT the current matrix of transformation of iRep
     * */
    virtual bool Select(const CATRep & iRep, const CATMathTransformation  & iT);
  };

  /**
   * Set the filter to use
   * */
  void SetFilter(Filter::SPtr & iFilter);
  Filter::SPtr GetFilter() const;

  /**
   * apply the operator on this root node with the filter set with SetFilter
   * @param[in] iRoot original node
   * @param[in] iParentTransformation matrix of position where we do the computation (ID by default)
   * @param[in] iCloneOper operator of cloning
   * @return a new rep tree with only the rep selected by the filter , should be release by caller
   * */
  CATRep * Run(CATRep & iRoot , const CATMathTransformation & iParentTransformation  = CATMathTransformation(), const CloneOper & iCloneOper=CloneOper() );

  /**
   * can be call after Run to get min, max sag of the selected return tree.
   * */
  void GetMinMaxSag(double & oMinSag, double & oMaxSag);

  protected:

  Filter::SPtr _Filter = nullptr;  
  CATPolyLittleTimer _DuplicateTimer; 
  double _MinSag;
  double _MaxSag;
   

};




//_________________________________________________________________
// Usefull filter


//_____________________________________________
// Composition of Filter with boolean operation

/**
 * Compose 2 filter with And
 * */
class DSYExport CATPPVisuRepTreeSelectorOper_FilterAnd : public CATPPVisuRepTreeSelectorOper::Filter
{
    public:  
    typedef CATCGMSharedPtr<CATPPVisuRepTreeSelectorOper_FilterAnd> SPtr;
        CATPPVisuRepTreeSelectorOper_FilterAnd(
            CATPPVisuRepTreeSelectorOper::Filter::SPtr & A,
            CATPPVisuRepTreeSelectorOper::Filter::SPtr & B);
        bool Select(const CATRep & iRep, const CATMathTransformation  & iT);
    protected:
    CATPPVisuRepTreeSelectorOper::Filter::SPtr _A;
    CATPPVisuRepTreeSelectorOper::Filter::SPtr _B;
};

/**
 * Compose 2 filter with Or
 * */
class DSYExport CATPPVisuRepTreeSelectorOper_FilterOr : public CATPPVisuRepTreeSelectorOper::Filter
{
    public:  
    typedef CATCGMSharedPtr<CATPPVisuRepTreeSelectorOper_FilterOr> SPtr;
        CATPPVisuRepTreeSelectorOper_FilterOr(
            CATPPVisuRepTreeSelectorOper::Filter::SPtr & A,
            CATPPVisuRepTreeSelectorOper::Filter::SPtr & B);
        bool Select(const CATRep & iRep, const CATMathTransformation  & iT);
    protected:
    CATPPVisuRepTreeSelectorOper::Filter::SPtr _A;
    CATPPVisuRepTreeSelectorOper::Filter::SPtr _B;
};

/**
 * Inverse filter (apply boolean not )
 * */
class DSYExport CATPPVisuRepTreeSelectorOper_FilterNot : public CATPPVisuRepTreeSelectorOper::Filter
{
    public:  
    typedef CATCGMSharedPtr<CATPPVisuRepTreeSelectorOper_FilterNot> SPtr;
        CATPPVisuRepTreeSelectorOper_FilterNot(
            CATPPVisuRepTreeSelectorOper::Filter::SPtr & A );
        bool Select(const CATRep & iRep, const CATMathTransformation  & iT);
    protected:
    CATPPVisuRepTreeSelectorOper::Filter::SPtr _A;    
};

//_____________________________________________
// Filter Wrapping visufilter
#include "CATPolyBVHTreeVisualizationFilter.h"

class DSYExport CATPPVisuRepTreeSelectorOper_FilterVisu : public CATPPVisuRepTreeSelectorOper::Filter
{
  public:  
   typedef CATCGMSharedPtr<CATPPVisuRepTreeSelectorOper_FilterVisu> SPtr;
    CATPPVisuRepTreeSelectorOper_FilterVisu(CATPolyBVHTreeVisualizationFilter * iVisuFilter):
      _VisuFilter(iVisuFilter,true)
      {

      };
    
   
    bool Select(const CATRep & iRep, const CATMathTransformation  & iT)
    {
      if (_VisuFilter)
      {
        if (_VisuFilter->Filter((CATRep*)&iRep)==TRUE)
          return false;
      }
      return true;
    };
  protected:
  CATCGMSharedPtr<CATPolyBVHTreeVisualizationFilter> _VisuFilter;
};


//_____________________________________________
// Filter base on position 


//this include are only for the next filter (todo separate into multiple file)
#include <map>
#include <vector>
#include "CATPolyOBB.h"



/**
 * filter duplicate Rep that have same rep ptr at same position matrix
 * */
class DSYExport CATPPVisuRepTreeSelectorOper_FilterDuplicate : public CATPPVisuRepTreeSelectorOper::Filter
{
  public:  
  typedef CATCGMSharedPtr<CATPPVisuRepTreeSelectorOper_FilterDuplicate> SPtr;
    bool Select(const CATRep & iRep, const CATMathTransformation  & iT);
    ~CATPPVisuRepTreeSelectorOper_FilterDuplicate();
  protected:
  std::map<const CATRep*, std::vector<CATMathTransformation>> _AlreadyInTree;
  CATPolyLittleTimer Timer;
};


class CAT3DBoundingBoxRender;
class CATSupport;

/**
 * exclude rep that are fully out of a bounding box
 * */
class DSYExport CATPPVisuRepTreeSelectorOper_FilterOBB : public CATPPVisuRepTreeSelectorOper::Filter
{
  public:  
    typedef CATCGMSharedPtr<CATPPVisuRepTreeSelectorOper_FilterOBB> SPtr;
    CATPPVisuRepTreeSelectorOper_FilterOBB(const CATPolyOBB & iLimits);
    ~CATPPVisuRepTreeSelectorOper_FilterOBB();
    bool Select(const CATRep & iRep, const CATMathTransformation  & iT);
    
  protected:
    CATPolyOBB _Limits;
    CATPolyLittleTimer Timer;
    CATPolyLittleTimer _SupportTimer;
    CATPolyLittleTimer _bboxTimer;
    
    CAT3DBoundingBoxRender *_bbRender;
    CATSupport * _Support;
    
};

#endif // !CATPPVisuRepTreeSelectorOper
