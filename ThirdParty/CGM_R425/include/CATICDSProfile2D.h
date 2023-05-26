#ifndef CATICDSProfile2D_H
#define CATICDSProfile2D_H

// COPYRIGHT DASSAULT SYSTEMES  2012

/**
 * @CAA2Level L0
 * @CAA2Usage U1
 */

#include "CATCDS.h"

#include "CATICDSCurve2D.h"
#include "CATICDSPoint2D.h"
#include "CATICDSCoincidence.h"

class CATICDSFactory;
class CATICDSOffsetConstraint;
class CATCDSString;

#if defined(_EMSCRIPTEN_SOURCE)

#include <string>

class CATICDSProfile2D;

class CATICDSProfileIterator
{
public:
  /**
   * @SKIP
   */
  CATICDSProfileIterator(CATICDSProfile2D* ipProfile) : _pProfile(ipProfile), _state(0) {}

  /**
   * @CHECKRESULT TRUE
   */
  CATCDSBoolean next(CATICDSMonoParametric2D *& opEdge, double & oStart, double & oEnd, int & oOrientation, CATICDSPoint2D *& opStartVertex, CATICDSPoint2D *& opEndVertex, CATCDSBoolean & oHidden, double& oLocalStart);

private:
  CATICDSProfile2D * const _pProfile;
  int _state;
};

class CATICDSProfileLoopIterator
{
public:

  /**
   * @SKIP
   */
  CATICDSProfileLoopIterator(CATICDSProfile2D* ipProfile, int iLoop) : _pProfile(ipProfile), _loop(iLoop), _state(0) {}

  /**
   * @CHECKRESULT TRUE
   */
  CATCDSBoolean next(CATICDSMonoParametric2D *& opSubElement, double & oStart, double & oEnd, int & oOrientation, CATICDSPoint2D *& opStartVertex, CATICDSPoint2D *& opEndVertex);

private:
  CATICDSProfile2D * const _pProfile;
  int const _loop;
  int _state;
};

#endif

/**
 * Profile.
 */
class ExportedBySolverInterface CATICDSProfile2D : public CATICDSCurve2D
{
public:

  /**
   * @SKIP
   */
  struct ProfileSegment
  {
    /**
    * @SKIP
    */
    ProfileSegment(): 
      _SubElement(-1), _StartParameter(0.), _Delta(0.), _IsHidden(TRUE) {}
    /**
    * @SKIP
    */
    ProfileSegment(int iSubElement, double iStartParameter, double iDelta, CATCDSBoolean iIsHidden): 
      _SubElement(iSubElement), _StartParameter(iStartParameter), _Delta(iDelta), _IsHidden(iIsHidden) {}

    int _SubElement;
    double _StartParameter;
    double _Delta;
    CATCDSBoolean _IsHidden;
  };

  /**
   * Modify the behavior of a self-intersected CATCSProfile2D, the mode can take any of the following values
   * - simNOTCHECKED : self intersections are allowed
   * - simAUTOTRIM : unwanted portions are removed on offset profiles
   * @param iMode new mode (simNOTCHECKED is the default value set upon construction)
   */
  virtual void SetSelfIntersectionMode(CATCDSSelfIntersectionMode iMode) = 0;

  /**
   * Read the self-intersection mode
   */
  virtual CATCDSSelfIntersectionMode GetSelfIntersectionMode() const = 0;

  /**
   * Get all subelements 
   * @param oNb number of monoparametric sub-elements (lines, curves, conics)
   * @param oaSubElements list of sub-elements, ordered parameter-wise
   *
   * @SIZE oaSubElements oNb
   */
  virtual void GetSubElements(int &oNb, CATICDSMonoParametric2D **&oaSubElements) const = 0;

    /**
   * Get all subelements and orientations
   * @param oNb number of monoparametric sub-elements (lines, curves, conics)
   * @param oaSubElements list of sub-elements, ordered parameter-wise
   * @param ioaOrientations list of orientations, ordered parameter-wise 
   *
   * @SIZE oaSubElements oNb
   * @SIZE oaOrientations oNb
   * @SKIP
   */
  virtual void GetSubElements(int &oNb, CATICDSMonoParametric2D **&oaSubElements, int* &oaOrientations) const = 0;

  /**
   * Get all vertices
   * @param oNb number of vertices ( = number of sub-elements if the profile is closed) 
   * @param oaVertices list of vertices, ordered parameter-wise
   *
   * @SIZE oaVertices oNb
   */
  virtual void GetVertices(int &oNb, CATICDSPoint2D **&oaVertices) const = 0;

  /**
   * Get all coincidences
   * @param oNb number of coincidences
   * @param oaCoincidences list of coincidences, ordered parameter-wise
   *
   * @SIZE oaCoincidences oNb
   */
  virtual void GetCoincidences(int &oNb, CATICDSCoincidence **&oaCoincidences) const = 0;

  /**
   * Read the number of topological loops. Note that an open profile has only one 'open' loop. A closed profile may have several loops, considering only non-hidden parts of its sub-elements
   * @return number of loops
   */
  virtual int GetNumberOfLoops() const = 0;

  /**
   * Topological iterator: returns FALSE when a loop has been entirely visited
   * This method iterates on "segments" which are subsets of the profile sub-elements. If a sub-element is trimmed, there may be several segments lying on it
   * @param  iLoopIndex index of the current loop between 0 and the number of loops-1 
   * @param  ioIter  internal use: must be =0 when starting a new loop, and then passed without being modified between iterations 
   * @param  opSubElement current monoparametric sub-element (note that the same monoparametric may appear several times in the same loop or in different loops if it has been trimmed)
   * @param  oStart local parameter on opSubElement associated with the start point of the current segment wrt the profile orientation (will be > oEnd if the sub-element is run with a negative orientation)
   * @param  oEnd local parameter on opSubElement associated with the end point of the current segment wrt the profile orientation (will be < oStart if the sub-element is run with a negative orientation)
   * @param  oOrientation  +1 if the sub-element is run positively (profile parameter and local parameter have same orientation), otherwise -1
   * @param  opStartVertex vertex located at the start of the current segment wrt the profile orientation (vertex corresponding to oStart parameter value). May be null if the sub-element is trimmed and if no vertex exists at this point
   * @param  opEndVertex vertex located at the end of the current segment wrt the profile orientation (vertex corresponding to oEnd parameter value). May be null if the sub-element is trimmed and if no vertex exists at this point
   * @return TRUE while the loop is not completely visited
   *
   * @SKIP
   */
  virtual CATCDSBoolean GetNextInLoop(int iLoopIndex, int & ioIter, CATICDSMonoParametric2D *& opSubElement, double & oStart, double & oEnd, int & oOrientation, CATICDSPoint2D *& opStartVertex, CATICDSPoint2D *& opEndVertex) const = 0;

#if defined(_EMSCRIPTEN_SOURCE)
  virtual CATICDSProfileLoopIterator GetLoopIterator(int iLoop) = 0;
#endif

  /**
   * Parameter conversion from profile to sub-element (curve / line / conic)
   * The profile parameterization is defined by shifting the sub-elements parameterizations into adjacent intervals 
   * @param  iProfileParam  profile (global) parameter
   * @param  opSubElement  involved sub-element
   * @param  oLocalParam  local parameter on opSubElement
   * @return TRUE if the method succeeded, FALSE if iProfileParam is not a valid parameter on the profile
   *
   * @CHECKRESULT TRUE
   */
  virtual CATCDSBoolean GlobalToLocal(double iProfileParam, CATICDSMonoParametric2D *& opSubElement, double & oLocalParam) const = 0;

  /**
   * Parametric iterator: returns FALSE when the profile has been entirely visited
   * This method iterates on "segments" which are subsets of the profile sub-elements. If a sub-element is trimmed, there may be several segments lying on it
   * Unlike GetNextInLoop(), this method visits hidden parts of sub-elements, and does not consider the existence of loops
   * @param  ioIter  internal use: must be =0 when starting to iterate, and then passed without being modified between iterations 
   * @param  oProfileEdge current monoparametric sub-element (note that the same monoparametric may appear several times if it has been trimmed)
   * @param  oStart profile-parameter associated with the start point of the current segment wrt the profile orientation 
   * @param  oEnd profile-parameter associated with the end point of the current segment wrt the profile orientation 
   *         Note that oStart is always <= oEnd but they may be equal if the current segment is hidden, hence not taken into account in the profile parameterization
   * @param  oOrientation  +1 if the sub-element is run positively (profile parameter and local parameter have same orientation), otherwise -1
   * @param  opStartVertex vertex located at the start of the current segment wrt the profile orientation (vertex corresponding to oStart parameter value). May be null if the sub-element is trimmed and if no vertex exists at this point
   * @param  opEndVertex vertex located at the end of the current segment wrt the profile orientation (vertex corresponding to oEnd parameter value). May be null if the sub-element is trimmed and if no vertex exists at this point
   * @param  oHidden TRUE if the current segment is hidden and not taken into account in the profile parameterization, otherwise FALSE
   * @param oLocalStart local parameter at the start (WRT profile) of the current segment
   * @return TRUE while the profile is not completely visited
   *
   * @SKIP
   */
  virtual CATCDSBoolean GetNextInProfile(int & ioIter, CATICDSMonoParametric2D *& oProfileEdge, double & oStart, double & oEnd, int & oOrientation, CATICDSPoint2D *& opStartVertex, CATICDSPoint2D *& opEndVertex, CATCDSBoolean & oHidden) const = 0;
  
  /**
   * @SKIP
   */
  virtual CATCDSBoolean GetNextInProfile(int & ioIter, CATICDSMonoParametric2D *& oProfileEdge, double & oStart, double & oEnd, int & oOrientation, CATICDSPoint2D *& opStartVertex, CATICDSPoint2D *& opEndVertex, CATCDSBoolean & oHidden, double& oLocalStart) const = 0;



#if defined(_EMSCRIPTEN_SOURCE)
  virtual CATICDSProfileIterator GetProfileIterator() = 0;
#endif

  /**
   * Create a zero value offset profile from a given profile
   * This method also creates offset variables, offset sub-elements and vertices, coincidence constraints that bind together the sub-elements of the offset profile.
   * Note that sub-elements of the base profile may require an extrapolation when the offset variables are changed to non-zero values; if such is the case, the extrapolation
   * should be done before creating the zero offset profile.
   * @param  ipFactory  Creation factory
   * @param  opOffsetConstraint Offset constraint between profiles, automatically created by CreateOffsetableProfile()
   * @param  iOneVariablePerElement (optional) if this parameter is TRUE, then CreateOffsetableProfile() creates as many offset variables as there are sub-elements
   *                                           if this parameter is FALSE, then only one offset variable is created and shared by all sub-elements
   * @return Offset profile created, with zero offset, that is, coincident with the base profile until the offset variable(s) is (are) modified
   *
   * @RETURNNAME profile
   */
  virtual CATICDSProfile2D* CreateOffsetableProfile(CATICDSFactory* ipFactory, CATICDSOffsetConstraint *&opOffsetConstraint, CATCDSBoolean iOneVariablePerElement=FALSE) const = 0;

  /**
   * Check if there are any intersections between sub-elements, or self-intersection in a sub-element
   * Note that this method can process any kind of profile, not necessarily an offset profile
   * @return TRUE if there is at least one self-intersection point, otherwise FALSE
   */
  virtual CATCDSBoolean IsSelfIntersected() = 0;

  /**
   * Get the trimming and parameterization information currently associated with a profile (how sub-elements are cut into visible and hidden segments)
   * This information is coded into a CATCDSString, and may be later used to reset the profile exactly as it is when the information was retrieved
   * Note that the list of sub-elements and vertices is not included in the output string, only the way they are trimmed is inside.
   * @param  oTrimmingInfo String containing all information defining the current state of the profile: how sub-elements are trimmed, and how the profile is parameterized
   * @return TRUE if the method succeeded, FALSE if the profile is invalid or not initialized    
   */
#if !defined(_EMSCRIPTEN_SOURCE)
  virtual CATCDSBoolean GetTrimmingInfo(CATCDSString & oTrimmingInfo) = 0;
#else
  /**
   * @CHECKRESULT TRUE
   */
  virtual CATCDSBoolean GetTrimmingInfo(std::string &oTrimmingInfo) = 0;
#endif
  
  /**
  * Get the trimming and parameterization information currently associated with a profile (how sub-elements are cut into visible and hidden segments)
  * This information is coded into a struct ProfileSegment, and may be later used to reset the profile exactly as it is when the information was retrieved
  * Note that the list of sub-elements and vertices is not included in the output string, only the way they are trimmed is inside.
  * @param  oTrimmingInfo String containing all information defining the current state of the profile: how sub-elements are trimmed, and how the profile is parameterized
  * @return TRUE if the method succeeded, FALSE if the profile is invalid or not initialized    
  *
  * @SKIP
  */
  virtual CATCDSBoolean GetTrimmingInfo(int& oNbSegments, ProfileSegment*& oaProfileSegments) = 0;

  /**
  * Set the trimming and parameterization information onto an existing profile, in order to reset it at the same state as when the information was retrieved.
   * The profile must already contain the right sub-elements and vertices, the method will otherwise fail
   * This method is much faster than recomputing all trimming points by running the constraint solver, if the resulting profile had already been computed
   * The input string must be identical to the one retrieved by GetTrimmingInfo() method
   * @param  oTrimmingInfo String containing all information defining the current state of the profile: how sub-elements are trimmed, and how the profile is parameterized
   * @return TRUE if the method succeeded, FALSE if the profile does not match the information coded in the input string
   */
#if !defined(_EMSCRIPTEN_SOURCE)
  virtual CATCDSBoolean SetTrimmingInfo(CATCDSString const & iTrimmingInfo) = 0;
#else
  virtual CATCDSBoolean SetTrimmingInfo(std::string const & iTrimmingInfo) = 0;
#endif

  /**
   * Set the trimming and parameterization information onto an existing profile, in order to reset it at the same state as when the information was retrieved.
   * The profile must already contain the right sub-elements and vertices, the method will otherwise fail
   * This method is much faster than recomputing all trimming points by running the constraint solver, if the resulting profile had already been computed
   * The input string must be identical to the one retrieved by GetTrimmingInfo() method
   * @param  iNbSegments number of segments
   * @param iaProfileSegments array of struct ProfileSegment containing all information defining the current state of the profile: how sub-elements are trimmed, and how the profile is parameterized
   * @return TRUE if the method succeeded, FALSE if the profile does not match the information coded in the input string
   *
   * @SKIP
   */
  virtual const CATCDSBoolean SetTrimmingInfo(int iNbSegments, ProfileSegment*& iaProfileSegments) = 0;

  /**
   * Compute the size of the profile and return TRUE if the global size is null. With the reroot of vertices it allows to detect when an offset profile is hidden
   * @return TRUE if the size is null
   **/
  virtual CATCDSBoolean IsReversedProfile() = 0;

  /**
   * Static method used to create a profile from its sub-elements
   * Note that all coincidence constraints required to keep the profile connected must have been created before
   * The constraint solver must be run after the profile is created, in order to complete its initialization.
   * @param  ipFactory  Creation factory
   * @param  inSubElements Number of sub-elements
   * @param  iapSubElements Ordered list of sub-elements
   * @param  iapVertices Ordered list of vertices
   * @param  iaOrientations Ordered list of orientations, each value may only be -1 or +1 according to the parametric orientation of the corresponding sub-element with respect to the profile global orientation
   * @param  iClosed TRUE if the profile is closed (same start and end vertices), otherwise FALSE
   * @return Profile created
   *
   * @SIZE iapSubElements inSubElements
   * @SIZE iapVertices (inSubElements+(iClosed?0:1))
   * @SIZE iaOrientations inSubElements
   */
  static CATICDSProfile2D* Create(CATICDSFactory* ipFactory,
    int inSubElements, CATICDSMonoParametric2D **iapSubElements,
    CATICDSPoint2D **iapVertices, int *iaOrientations, CATCDSBoolean iClosed);

  virtual ~CATICDSProfile2D() {}
};

#endif
