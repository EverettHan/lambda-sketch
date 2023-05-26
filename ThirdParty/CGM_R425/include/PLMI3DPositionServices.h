// COPYRIGHT Dassault Systemes 2009
//===================================================================
// PLMI3DPositionServices.h
// Define the PLMI3DPositionServices interface
//===================================================================
//  April 2009  Creation: Code generated by the LRG wizard
//===================================================================
#ifndef PLMI3DPositionServices_H
#define PLMI3DPositionServices_H

/**
* @level Protected
* @usage U3
*/

#include "CATBaseUnknown.h"
#include "CATPLMModeler3DInterfaces.h"
class CATListPtrCATIPLMComponent;
class CATMathTransformation;
class CATListValCATIPLMComponent_var;

class CATIPLMOccurrence;
class CATIMovable_var;

#ifdef CATIAR424
template<typename T> class CATOmxList;
#endif

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByCATPLMModeler3DInterfaces IID IID_PLMI3DPositionServices;
#else
extern "C" const IID IID_PLMI3DPositionServices ;
#endif

#define PLM3DPositionServices_Component "PLM3DPositionServices"

//------------------------------------------------------------------

/**
* Interface providing services related to 3D positioning for 3D PLM modelers
*
* @example
*  PLMI3DPositionServices *pPLM3DPositionServices = NULL;
*  if (SUCCEEDED(::CATInstantiateComponent(PLM3DPositionServices_Component,IID_PLMI3DPositionServices,(void **)&pPLM3DPositionServices))&&pPLM3DPositionServices)
*  {
*    ...
*  }
*  CATSysReleasePtr(pPLM3DPositionServices);
*/

class ExportedByCATPLMModeler3DInterfaces PLMI3DPositionServices: public CATBaseUnknown
{
  CATDeclareInterface;

public:

  /**
  * Service to compute the cumulated position of an object of a 3D modeler (instance or occurrence) identified
  * by the input description path <tt>iPathTo3DObject</tt>, also taking into account any position overloadings.
  *
  *  @param  iPathTo3DObject
  *      A path of instances describing the 3D object which position will be computed. Size is 1 if the 3D object is a simple instance.<br>
  *      Input Parameter. <br>
  *      This path must not be provided by caller as empty!
  *      This path must be valid in terms of isaninstanceof/isownedby/isaninstanceof/isownedby/... relationships between its items.
  *  @param  oAbsoluteCumulatedPosition
  *      The absolute cumulated position of the 3D object returned. <br>
  *      Output parameter. <br>
  *      This parameter is correctly valuated if method succeeds. Otherwise its value (Identity) is nonsense.
  *  @return
  *      <code>S_OK</code> if the method succeeds. <br>
  *      <code>E_INVALIDARG</code> if <tt>iPathTo3DObject</tt> parameter provided is invalid. <br>
  *      <code>E_FAIL</code> otherwise. <br>
  */
  virtual HRESULT GetPosition(const CATListPtrCATIPLMComponent &iPathTo3DObject,
                              CATMathTransformation &oAbsoluteCumulatedPosition) = 0;

  /**
  * Service to compute the cumulated position of an object of a 3D modeler (CATIMovable component, an occurrence, a 3DVO or a contextual link
  * feature), also taking into account any position overloadings.
  *
  *  @param  ip3DObject
  *      Can be a CATIMovable component, an occurrence, a 3DVO or a contextual link feature. <br>
  *      Input parameter. <br>
  *  @param  oAbsoluteCumulatedPosition
  *      The absolute cumulated position of the 3D object returned. <br>
  *      Output parameter. <br>
  *      This parameter is correctly valuated if method succeeds. Otherwise its value (Identity) is nonsense.
  *  @param  ibUnfoldPointedPublications
  *      Boolean to express whether or not the pointed publications encountered should be recursively
  *      introspected/unfolded to compute the final cumulated position. <br>
  *      Input parameter. Default value is TRUE.<br>
  *  @return
  *      <code>S_OK</code> if the method succeeds. <br>
  *      <code>E_INVALIDARG</code> if <tt> ip3DObject</tt> is NULL or not a 3D Object (not a 3DVO nor a CATIMovable component, nor an
  *      ocurrence nor a PLMIContextualLink).
  *      <code>E_FAIL</code> otherwise. <br>
  */
  virtual HRESULT GetPosition(CATBaseUnknown *ip3DObject,
                              CATMathTransformation &oAbsoluteCumulatedPosition,
                              CATBoolean ibUnfoldPointedPublications = TRUE)=0;

#ifdef CATIAR424
  /**
  * Computes, with fixed context, the longest subPath on which a 3D transformation can be applied, taking into account the repositionable subpaths.
  *
  * - If the full input path can have its position overloaded, it is the result (=> oSize == iPOFI.Size())
  * - If no subPath can be overloaded, the first instance of the path is returned. YOU MAY NEED TO CHECK THAT THE INSTANCE IS NOT FIXED.
  * 
  * @param iPOFI
  *   Path of instances describing the occurrence for which the movable path is computed.
  *   /!\ The consistency of the POFI is not checked !
  *
  * @param oMovableSize
  *  Size of the longest movable path. On success, 1 <= oMovableSize <= iPOFI.Size().
  *  For input I1;I2;I3 : oMovableSize == 3 means I1;I2;I3 is the longest movable path
                          oMovableSize == 2 means I1;I2 is the longest movable path
  *                       oMovableSize == 1 means I1 is the longest movable path
  * @return
  *   <code>S_OK</code> No error occurred.
  *   <code>E_XXX</code> An error occurred. Some possible reasons : invalid input, legacy PMR data found (migration required)...
  */
  virtual HRESULT ComputeMovablePath_FixedContext(CATOmxList<CATBaseUnknown> const & iPOFI, size_t & oSizeOfMovingPath) const = 0;

  /**
  * Computes, with fixed target, the longest subPath on which a 3D transformation can be applied, taking into account the repositionable subpaths.
  *
  * - If the full input path can have its position overloaded, it is the result (=> oSize == iPOFI.Size())
  * - If no subPath can be overloaded, the last instance of the path is returned. YOU MAY NEED TO CHECK THAT THE INSTANCE IS NOT FIXED.
  * 
  * @param iPOFI
  *   Path of instances describing the occurrence for which the movable path is computed.
  *   /!\ The consistency of the POFI is not checked !
  *
  * @param oMovableSize
  *  Size of the longest movable path. On success, 1 <= oMovableSize <= iPOFI.Size().
  *  For input I1;I2;I3 : oMovableSize == 3 means I1;I2;I3 is the longest movable path
                          oMovableSize == 2 means I2;I3 is the longest movable path
  *                       oMovableSize == 1 means I3 is the longest movable path
  * @return
  *   <code>S_OK</code> No error occurred.
  *   <code>E_XXX</code> An error occurred. Some possible reasons : invalid input, legacy PMR data found (migration required)...
  */
  virtual HRESULT ComputeMovablePath_FixedTarget(CATOmxList<CATBaseUnknown> const & iPOFI, size_t & oSizeOfMovingPath) const = 0;

  //Those are exposed for diagnostic only
  /** @nodoc DO NOT USE. Operates on legacy PMR only, if this fails or returns oSizeOfMovingPath > 1, ComputeMovablePath_FixedContext will fail (as opposed to deprecated method ComputeMovingPath which will succeed).*/
  virtual HRESULT ComputeMovablePath_FixedContext_LegacyPMR(CATOmxList<CATBaseUnknown> const & iPOFI, size_t & oSizeOfMovingPath) const = 0;
  /** @nodoc DO NOT USE. Operates on legacy PMR only, if this fails or returns oSizeOfMovingPath > 1, ComputeMovablePath_FixedTarget will fail (as opposed to deprecated method ComputeMovingPath which will succeed).*/
  virtual HRESULT ComputeMovablePath_FixedTarget_LegacyPMR(CATOmxList<CATBaseUnknown> const & iPOFI, size_t & oSizeOfMovingPath) const = 0;
  
  /**
  * Indicates if an occurrence, described by a path of instances, can be repositioned, ie if a position
  * overload can be defined for this occurrence.
  * @param iPOFI
  *   iPOFI.Size() MUST BE >= 2.
  *   Path of instances describing the occurrence for which the movable path is computed.
  *   /!\ The consistency of the POFI is not checked !
  *
  * @param oCanBeRepositioned
  *  Indicates whether the occurrence described by iPOFI can be repositioned.
  * @return
  *   <code>S_OK</code> No error occurred.
  *   <code>E_XXX</code> An error occurred. Some possible reasons : invalid input, legacy PMR data found (migration required)...
  */
  virtual HRESULT CanBeRepositioned(CATOmxList<CATBaseUnknown> const & iPOFI, bool & oCanBeRepositioned) const = 0;
#endif //CATIAR424

  
  /*
  * Search strategy for ComputeMovingPath (cf. below).
  */
  enum RepositionableSearchStrategy
  {
    RSS_FixedContext,
    RSS_FixedTarget,
    RSS_NoSearch,
    NbRepositionableSearchStrategy // Not a strategy ;)
  };

  /**
  * @deprecated R424
  * For a given occurrence path, smartly compute on which object (occurrence/instance) a 3D transformation 
  * can be applied, taking into account the repositionable subpathes and a user strategy (see below).
  *
  * - If the input path position cannot be overloaded, a shorter overloadable occurrence is searched for. 
  *   The search is guided by a user strategy.
  * 
  * - If no occurrence can be overloaded, a first instance is returned.
  * 
  * Remember that the position of the occurrence {i1,i2,i3} can be overloaded (occurrence can be repositionned)
  * if and only if the path {i2,i3} is repositionable.
  * 
  * @param iPOFI
  *   Path of the occurrence to move.
  *   /!\ The consistency of the POFI is not checked !
  *
  * @param iStrategy
  *   FixedContext, FixedTarget or NoSearch.
  *   The strategy is used to capture the user intention. When several objects (repositionable occurrences, 
  *   instances) can be moved it defines which option must prevail.
  *
  *   - FixedContext : the move is performed in the context of the father of the 1st element of the path.
  *     - the repositionable subpaths are searched exclusively in the immediate sub context.
  *     - the longest suitable subpath is used
  *     - if no repositionable is found, the 1st element of the input path is returned.
  *
  *   - FixedTarget : the moved occurrence must target the last element of the path.
  *     - the tested repositionable subpaths always target the last element of the path 
  *     - the longest suitable subpath is used
  *     - if no repositionable is found, the target instance (last of the input path) is returned.
  *
  *   - NoSearch : just checks that the input path is overloadable. Else returns an error.
  *
  * @param ospMovingPath
  *   Occurrence (or first instance) which can actually move. This path is garanteed to be movable 
  *   when used with the SetPosition method below.
  *
  * @return
  *      <code>S_OK</code> The input path position can be overloaded. No further search performed.<br>
  *      <code>S_FALSE</code> A moving path could be computed and is different from the input path.<br>
  *      <code>E_FAIL</code> Otherwise. <br>
  */
  #ifdef CATIAR424
  [[deprecated("Use ComputeMovablePath_FixedContext/ComputeMovablePath_FixedTarget/CanBeRepositioned instead, this allows to get errors on legacy PMR")]]
  #endif
  virtual HRESULT ComputeMovingPath(CATListValCATIPLMComponent_var & iPOFI,
                                    PLMI3DPositionServices::RepositionableSearchStrategy iStrategy,
                                    CATListValCATIPLMComponent_var & ospMovingPath) = 0;

  /**
  * Sets the relative position of an occurrence (overload) or an instance.
  * On a first instance, the method should not fail.
  * Only overloads can be set on occurrences with this method. 

  * Remember that the position of the occurrence {i1,i2,i3} can be overloaded if and only if the path {i2,i3} is repositionable.
  * Use ComputeMovingPath with the "NoSearch" strategy to ensure the position can be set for this path.
  *
  * @param iPOFI
  *   Path of the occurrence to move.
  *   The consistency of the POFI is not checked.
  *
  * @return
  *   <code>S_OK</code> if the position has been overloaded on the occurrence (or set on the instance). <br>
  *   <code>E_INVALIDARG</code> if <tt>iPosition</tt> is invalid or <tt>iPOFI</tt> is not overloadable.<br>
  *   <code>E_FAIL</code> otherwise. <br>
  */
  virtual HRESULT SetPosition(CATMathTransformation & iPosition,
                              CATListValCATIPLMComponent_var & iPOFI) = 0;

  /**
  * @deprecated R424
  * Indicates if an occurrence (in the form of an instances path) can be repositioned, that is if a position
  * overload can be defined for this occurrence.
  * Equivalent to ComputeMovingPath called with NoSearch strategy and an occurrence path (size >= 2),
  * lighter error management (returns FALSE...)
  *
  * @param iPOFI
  *   Path of the occurrence to check. At least 2 elements.
  *   The consistency of the POFI is not checked.
  *
  * @return
  *   <code>TRUE</code> if the occurrence can be repositionned.<br>
  *   <code>FALSE</code> otherwise.<br>
  */
  #ifdef CATIAR424
  [[deprecated("Use HRESULT CanBeRepositioned(CATOmxList<CATBaseUnknown> const &, bool &) instead, better signature and allows to get errors on legacy PMR")]]
  #endif
  virtual CATBoolean CanBeRepositioned(CATListValCATIPLMComponent_var & iPOFI) = 0;

  /**
  * Indicates if an occurrence (in the form of an instances path) is repositioned. 
  * 
  * @param iPOFI
  *   Path of the occurrence to check. At least 2 elements.
  *   The consistency of the POFI is not checked.
  *
  * @param ibCheckOnInputPathOnly
  *   Consider or not the overloads set in subcontexts:
  * 
  *   - If 'ibCheckOnInputPathOnly' is FALSE (default), 'Repositioned' means that the position of the occurrence 
  *     is different from the composition of the instances positions. 
  *     The overload does not need to be defined specifically for this path, but may have been set for a subpath : 
  *     {i1, i2, i3} will be said 'repositioned ' if an overloaded position has been set on {i2, i3}
  *     Hence, IsRepositioned may be TRUE, although CanBeRepositioned is FALSE for the same input path.
  * 
  *   - If 'ibCheckOnInputPathOnly' is TRUE, the method checks a position overload has been specificaly defined for the input path.
  *     In this case IsRepositioned => CanBeRepositioned.
  *
  * @return
  *   <code>TRUE</code> if the occurrence is repositionned.<br>
  *   <code>FALSE</code> otherwise.<br>
  */
  virtual CATBoolean IsRepositioned(CATListValCATIPLMComponent_var & iPOFI, CATBoolean ibCheckOnInputPathOnly = FALSE) = 0;

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------
};

CATDeclareHandler(PLMI3DPositionServices, CATBaseUnknown);

#endif
