//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES 2002
//=============================================================================
/**
 * @CAA2Level L1
 * @CAA2Usage U3
 */
#ifndef CATIIniSearchContext_H
#define CATIIniSearchContext_H

#include "UIModelInterfaces.h"
#include "IUnknown.h"
#include "CATUnicodeString.h"
class CATPathElement;

// Global Unique IDentifier defined in .cpp 
extern ExportedByUIModelInterfaces IID IID_CATIIniSearchContext;

/** 
 * Class to define in which context the objects will be looked for.
 * <b>Role</b>: A Search context defines the granularity with which
 * objects will be looked for. Refer to the @href #Scope enumeration
 * for further details.
 * <br>A context applies to a @href CATIIniSearchCriterion, since it defines
 * the set of objects (usually represented in the specification tree) that 
 * will be confronted with the criterion.
 * <br>Refer to the "Search Overview" technical article for further details.
 */
class ExportedByUIModelInterfaces CATIIniSearchContext : public CATBaseUnknown
{
  CATDeclareInterface;

public:
	/**
   * Contexts value for a Search procedure.
   * <br>The following contexts are allowed:
   * @param Everywhere
   *    To look for objects located anywhere in the document.
   * @param InUIActiveObject
   *    To look for objects located between the current UIActive object (called current
   *    top object) and the next UIActivable objects located below this top object
   *    (called current bottom objects). Those objects are also included in the Search process.
   *    <br>In a Part document, in a Part Design context, this
   *    context will consider all the objects from the top of the specification
   *    tree, to the sketches (included). But it would not take into account
   *    the elements of each sketch.
   * @param FromUIActiveObjectToBottom
   *    To look for objects located from the current top object (included in the Search
   *    process), to the very bottom of the specification tree for the current top object's branch.
   *    <br>In a Product document, in a Part Design context, this
   *    context will consider all the objects from the current Part object to 
   *    its constitutive sketches, and all their elements.
   * @param FromSelection
   *    To look for objects located in the current set of objects of the editor ( @href CATCSO ), 
   *    as well as other objects located underneath in the specification tree.
   *    <br>For example, let us consider a Part document where a hole object 
   *    and a pad object are selected. The Search process will confront the hole,
   *    the pad, their sketches, and constitutive elements to the criterion.
   * @param OnSameLevel
   *    To look for objects located on the same specification tree level as a 
   *    reference object.
   *    <br>This reference object is excluded from the search result.
   *    <br>It is only possible to define this scope through the @href #SetScope method.
   *    When doing so, the second argument of the method must be provided.
   *    <br>In addition, there is no possible print out of this scope's NLS or 
   *    TransFormat value.
   * @param VisibleOnScreen
   *    To look for objects visible (fully or not) in the current active window.
   *    <br>This context won’t take into account elements not activated, not represented
   *    (features used to build other features that appear in the specification tree but
   *    not in 3D), not in the current active filter, not in the current mask... and when
   *    the 2D mode will be activated elements not in the active plane will be excluded from
   *    the search result too.
   *    <br>Caution: do not use this scope in a batch, the result would be unpredictable.
   * <br><br>The default scope, i.e. if no setup is made, is <tt>InUIActiveObject</tt>
   * <br><br>Using any scope in batch mode could lead to unpredictable result. Search engine mainly
   * relies on visualization interfaces, which could be not used in batch mode.
   */
  enum Scope{Everywhere,
             InUIActiveObject,
             FromUIActiveObjectToBottom,
             FromSelection,
             OnSameLevel,
             VisibleOnScreen};

  /** Sets the scope from the dedicated enumeration.
   * <br><b>Role</b>: This methods sets the scope through 
   * an enumeration value.
   * <br><br>
   * @param iScope
   *    The scope value.
   * @param iReferenceObjectPath
   *    <li>If the chosen scope is <tt>OnSameLevel</tt>, this argument is <b>mandatory</b>. 
   *    <br>It defines the reference object for the scope: on the same level as this reference object.</li>
   *    <li>If the chosen scope is <tt>InUIActiveObject</tt>, or <tt>FromUIActiveObjectToBottom</tt>,
   *    this argument is optional.
   *    <br>It enables the user to define an object implementing the @href CATIUIActivate,
   *    from which the search will start. It is especially useful when the search should
   *    start from an UIActivable object that is not the current UIActiveObject.</li>
   *    <li>In all the other case, this argument <b>must</b> be omitted.</li> 
   * @return
   *    S_OK if the scope has successfully been set up.
   *    E_FAIL otherwise
   */
  virtual HRESULT SetScope(CATIIniSearchContext::Scope iScope, 
                           CATPathElement* iReferenceObjectPath=NULL) = 0;

  /** Sets the scope from a string.
   * <br><b>Role</b>: This method sets the scope through a CATUnicodeString
   * refering to either an NLS or a TransFormat context.
   * <br><br>
   * @param iStringScope
   *    The scope under an NLS or TransFormat format.
   *    <li>
   *    Here are different complete NLS queries that can be obtained 
   *    through the Edit/Search user interface, with an English session. 
   *    Those pieces of information are session's language dependent. 
   *    Here under the matching between enumeration and string-format
   *    context is explained:
   *    <ul><li><tt>Everywhere</tt>: in <tt>Name=Johnny,all</tt> the context is <b>all</b>.</li>
   *    <li><tt>InUIActiveObject</tt>: in <tt>Name=Johnny,in</tt> the context is <b>in</b>.
   *    In the <tt>Name=Johnny</tt> query, there is no context. So the default one is assumed 
   *    to be here.</li>
   *    <li><tt>FromUIActiveObjectToBottom</tt>: in <tt>Name=Johnny,from</tt> the context is <b>from</b>.</li>
   *    <li><tt>FromSelection</tt>: in <tt>Name=Johnny,sel</tt> the context is <b>sel</b>.</li></ul></li>
   *    <li>Here under the matching between enumeration and 
   *    Transformat context is explained:
   *    <ul><li><tt>Everywhere</tt>: the Transformat context is <b>all</b>.</li>
   *    <li><tt>InUIActiveObject</tt>: the Transformat context is <b>in</b>.</li>
   *    <li><tt>FromUIActiveObjectToBottom</tt>: : the Transformat context is <b>from</b>.</li>
   *    <li><tt>FromSelection</tt>: : the Transformat context is <b>sel</b>.</li></ul>
   *    </li>
   * @return
   *    <ul><li>S_OK if the scope has successfully been set up.</li>
   *    <li>E_FAIL otherwise.</li></ul>
   */
  virtual HRESULT SetScopeFromString(const CATUnicodeString& iStringScope) = 0;

  /** Retrieves the scope in the NLS format.
   * <br><b>Role</b>: This methods retrieves the scope under an NLS format string,
   *  whatever the way it has been set up.
   * <br><br>
   * @param oNLSScope
   *    The returned scope under an NLS format.
   * @return
   *    S_OK if the scope has successfully been set up.
   *    E_FAIL otherwise
   */
  virtual HRESULT GetNLSScope(CATUnicodeString& oNLSScope) = 0;

  /** Retrieves the scope in the TransFormat format.
   * <br><b>Role</b>: This method retrieves the scope under a TransFormat format string,
   * whatever the way it has been set up.
   * <br><br>
   * @param oTFScope
   *    The returned scope under an TransFormat format.
   * @return
   *    S_OK if the scope has successfully been set up.
   *    E_FAIL otherwise
   */
  virtual HRESULT GetTransFormatScope(CATUnicodeString& oTFScope) = 0;

  /** Retrieves the enumeration value scope.
   * <br><b>Role</b>: This method retrieves the enumeration corresponding
   *  to the scope, whatever the way it has been set up.
   * <br><br>
   * @param oScope
   *    The returned scope under the enumeration format.
   * @return
   *    S_OK if the scope has successfully been set up.
   *    E_FAIL otherwise
   */
  virtual HRESULT GetScope(CATIIniSearchContext::Scope &oScope) = 0;

  /** Retrieves the reference object.
   * <br><b>Role</b>: This method retrieves the path of the reference object
   * used when the scope has been set up through the 2-argument @href #SetScope
   * method.
   * <br><br>
   * @param oReferenceObjectPath
   *    The path of the reference object. (The value cannot be null)
   * @return
   *    S_OK if the scope has successfully been set up.
   *    E_FAIL otherwise
   */
  virtual HRESULT GetReferenceObjectPath(CATPathElement *&oReferenceObjectPath) = 0;
}; 
#endif
