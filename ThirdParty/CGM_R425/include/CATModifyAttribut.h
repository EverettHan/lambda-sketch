#ifndef CATModifyAttribut_h
#define CATModifyAttribut_h
/** @CAA2Required */
/**********************************************************************/
/* DON T DIRECTLY INCLUDE THIS HEADER IN YOUR APPLICATION CODE. IT IS */
/* REQUIRED TO BUILD CAA APPLICATIONS BUT IT MAY DISAPEAR AT ANY TIME */
/**********************************************************************/

// COPYRIGHT DASSAULT SYSTEMES 1999
/**
 *  @quickReview CDT 02:09:13
 */


#include "CATVisItf.h"
#include "CATModify.h"
#include "CATBaseUnknown.h"
#include "CATBaseUnknown_var.h"
#include "CATPathElement.h"


/**
 * Graphical attribute modification type.
 * @param globalAttribut
 * All graphical attributes are to be modified, that is color, thickness, pick, show,..
 *
 * @param interactiveAttribut
 * Only the pick/nopick attribute is to be changed. 
 *
 * @param Redraw
 * Use to trigger a draw when materials is changed.
 *
 * @param RebuildTC
 *  Only the texture coordinates are changed.
 *
 * @param showAttribut
 * Only the show/noshow attribute is to be changed.
 * @see CATModifyAttribut
 */
enum CATAttributKind { globalAttribut, interactiveAttribut,Redraw,RebuildTC,showAttribut };



/**
  * Basic class of visualization event concerning any type of modification of the
  * graphical attributes of one object.
  * 
  * <br><b>Do not used this class</b>: See @href CATModifyVisProperties 
  * <br><br>
  * <b>Role</b>: 
  * When any type of graphical attributes of one object is to be changed, you
  * need to warn all of its  graphical representations. To achieve this goal, you have to 
  * send a <tt>CATModifyAttribut</tt> event. This class holds all
  * the information needed to modify the graphical attributes of the representations as well 
  * as the recorded properties of one object.
  * <br>Refer to the @href CATIModelEvents interface to have details about the management 
  * of the visualization events and their mechanism.
  *
  * @see CATIVisu, CATExtIVisu, CATModifyVisProperties
  */
class ExportedByCATVisItf CATModifyAttribut : public CATModify
{
  /** @nodoc */
  CATDeclareClass;

  public:

  /**
   * Constructs the class from a given set of graphical attributes to apply onto a given object and for a specific 
   * interface of graphical properties.
   *
   * @param iObject
   * the object you want to modify.
   *
   * @param iAttr
   * a smart pointer to a set of graphical attributes.
   *
   * @param iIid
   * the interface of graphical properties to modify.
   *
   * @param iKind
   * the type of modification.
   *
   * @param iPath
   * a path of objects which hold more informations about the user selection, that is what is the path of objects 
   * we are working on.
   *
   */
    CATModifyAttribut(CATBaseUnknown *iObject, 
                      CATBaseUnknown_var iAttr,
                      const IID & iIid = CATBaseUnknown::ClassId(), 
                      CATAttributKind iKind = globalAttribut,
                      CATPathElement iPath = CATPathElement() );
  
    virtual ~CATModifyAttribut();

  /**
   * Returns the set of graphical attributes.
   */
    CATBaseUnknown_var GetAttribut() const;
  
  /**
   * Returns the type of graphical modification.
   */
  CATAttributKind GetAttributKind() const;

  /**
   * Return the path of objects.
   */
  CATPathElement GetPathElement() const;

  /**
   * Returns a pointer to a new  CATModifyAttribut event which is the clone of the current one.
   */
  virtual CATModelNotification* Clone ();


  protected:
  /** @nodoc 
   * smart pointer to the set of graphical attributes. */
  CATBaseUnknown_var _att;

  /** @nodoc 
  * the type of graphical modification. */
  CATAttributKind _attKind;

  /** @nodoc the path of objects. */
  CATPathElement _path;
};

#endif
