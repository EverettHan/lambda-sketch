#ifndef CATExtIVisu_H
#define CATExtIVisu_H

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U2
 */

#include "SceneGraphManager.h"
#include "CATBaseUnknown.h"
#include "list.h"
#include "CATModifyVisProperties.h"
#include "CATIVisProperties.h"


class CATRep;
class CATPickPath;
class CATRepPath;
class CATPathElement;
class CATNotification;
class CATGraphicAttributeSet;
class CATVisRepContext;
class CATGraphicMaterial;


/**
  * Adapter for specialized CATIVisu interface .
 *
 * <b>Role</b>: This class provides a default implementation for any extension of interface deriving
 * from @href CATIVisu, which is the super-class of any Visualization interface.
 * That means one should derive from this class to implement an extension of a Visualization interface.
 */

class ExportedBySceneGraphManager CATExtIVisu: public CATBaseUnknown
{
  CATDeclareClass;

  /** @nodoc */
  enum  CATVisBuildingState  {CATVisGO, CATVisSTOP};

private :   
  /** @nodoc */
  enum  CATVisBuiltState {CATVisShowState, CATVisNoshowState, CATVisShowAndNoshowState, CATVisNoneState};

public:
    
  
   /**
    * Constructs the class.
	*/
	CATExtIVisu (void) ;
	
	/** @nodoc */
	CATExtIVisu(const IID &iid);
	
	virtual ~CATExtIVisu (void) ;

  /**
   * Builds the graphical representation of the object.
   * <br><b>Role</b> :
   * It is the general method that applications have to implement to built 
   * their geometry from modeling information. The @href #_rep data member must be valuated.
   * Calling BuildRep on already built rep may lead to leaks or other issues. To retrieve the built rep, GiveRep method must be used.  
   */
    virtual CATRep *BuildRep () = 0 ;

   /**
    * Returns the graphical representation of the object.
    */
      virtual CATRep * GiveRep() ;

  /**
   * Modifies the geometry or the graphical attributes of the object.
   * <br><b>Role</b>: It is the general method called by the Visu Manager ( @href CATVisManager )
   * for processing all the notifications concerning 
   * visual changes for one object (eg geometrical change, color/show/pick attribute change, ...).
   * Generic notifications treated by this default implementation are of
   * type @href CATModifyVisProperties.
   * <br>If a specific model supports other specific notifications, which are related to any 
   * model modification, it may also
   * define specific processing for those specialized @href CATModify event. To achieve this goal, 
   * one has to override the <tt>ModifyRep</tt> method and do some job only for those 
   * specific notifications. But caution, if you overwrite this method, at the end of it, the default
   * method should be called so as to profit by generic processing.
   *
   * @return the status of the notification's processing.
   * <br><b> Legal values</b>: the status is either
   * <ol><li> 0 when the input notification has not been processed. Then the Visu Manager takes hand and the 
   * default processing is applied </li>
   *<li> 1 when the input notification has been processed. </li>
   * </ol>
   *
   * @param iNotif
   * the input notification holding all the information we need in order to process it.
   */
     virtual int ModifyRep ( const CATNotification &iNotif ) ;


  /**
   * Sets the reference to the graphical representation to null. 
   *<br><b>Role</b>:
   * It is automatically called within the deletion mechanism of a graphical representation thanks to
   * its model identifier. Remind that the deletion mechanism of a graphical representation has to be 
   * performed by the Visu Manager : either one sends a @href CATDelete event or one destroys
   * a whole tree of graphical representations by the invocation of the 
   * @href CATVisManager#DetachFrom method. Do not delete a graphical representation outside the scope of the 
   * the Visu Manager.
   * <br>If you overwrite this method, at this end of it, the default
   * method should be called .
   */
     virtual void UnreferenceRep ();


  /**
   * Builds step by step a path of graphical representations from a path of objects.
   * 
   * <br><b>Role</b>:
   *Adds the current graphical representation into the output path of graphical representations <tt>ioPathRep</tt>. 
   * The default behavior is to add in turn the graphical representations to 
   * the output by going through the input <tt>iPathElt</tt> from top to leaf. 
   * One extension can take hand and change the default behavior
   * and manipulate the input to get further information (eg what is under the current object of the input ?). It's up
   * to the implementation to decide what are the graphical representations associated to the sub-elements
   * enclosed inside the input path <tt>iPathElt</tt>.
   * 
   * @param iPathElt
   * input path of objects enclosing the current object.
   * @param ioPathRep
   * output path of graphical representations to fill in.
   * @return an HRESULT value.
   * <br><b> Legal values</b>:
   * <ol><li>S_OK if the operation succeeds </li>
   * <li>E_FAIL otherwise</li>
   *</ol>
   */
     virtual HRESULT BuildRepPath(const CATPathElement &iPathElt, CATRepPath &ioPathRep ) ;



  /**
   * Builds step by step a path of graphical representations from a path of objects for (pre)highlight purposes.
   * 
   * <br><b>Role</b>: 
   * The same as @href #BuildRepPath but it is for (pre)highlight purposes only.
   *
   * @param iPathElt
   * input path of objects enclosing the current object.
   * @param ioPathRep
   * output path of graphical representations to fill in.
   * @return an HRESULT value.
   * <br><b> Legal values</b>:
   * <ol><li>S_OK</tt> if the operation succeeds </li>
   * <li>E_FAIL otherwise</li>
   *</ol>
   */
     virtual HRESULT BuildHighlightLook(const CATPathElement &iPathElt, CATRepPath &ioPathRep ) ;




  /**
   * Builds step by step a path of objects from a path of graphical representations.
   * <br><b>Role</b>: 
   * Add the current object to <tt>ioPathElt</tt>.  The default behavior is to add in turn objects to the output
   * by going through the input path of graphical representations from top to leaf. 
   * One extension can take hand and change the default behavior
   * and manipulate the input to get further information (eg what is under the current graphical representation
   * of the input ?). This method should be implemented to decode another object than itself ; for instance if 
   * one object wants to decode sub-elements of itself through its own access services.
   *
   * @param iPickPath
   * input path of graphical representations.
   * @param ioPathElt
   * output path of model to fill in.
   * @return an HRESULT value.
   * <br><b> Legal values</b>:
   * <ol><li>S_OK</tt> if the operation succeeds </li>
   * <li>E_FAIL</tt> otherwise</li>
   * </ol>
   */
     virtual HRESULT DecodeGraphic ( const CATPickPath &iPickPath, CATPathElement &ioPathElt) ;    
    
  /**
   * Sets the main graphic attributes onto the graphical representation.
   * <br> They are read from the model through
   * the interface managing graphical properties.
   */
     virtual void SetGraphicAttribut();


  /**
   * Sets the material attribute onto the graphical representation. 
   * <br><b>Role</b>: 
   * It is read from the model through the interface managing material.
   */
     virtual void SetGraphicMaterial();

  /**
   * @nodoc
   * Builds and returns the graphical representation of the object. 
   * <br><b> role</b> :
   * <br><b>Deprecated</b> <br>
   * If the graphical representation doesn't exist, it is built with the
   * invocation of the @href #BuildRep method.
   * Calling GetRep on already built rep may lead to leaks or other issues. To retrieve the built rep, GiveRep method must be used.
   * Representation with 'not uptodate' state will be rebuilt but its children will not be destroyed. Application should take care of children.
   */
     virtual CATRep * GetRep() ;
  /**
   * Returns a pointer to the list of children of the current object.
   *
   * <br><b>Role</b>: 
   * The default implementation is based on graphical representations.
   * That means the returned list is based on the graphical children'list of the current graphical representation.
   * Then we get back the model from the graphical representations through their model identifier.
   * Nevertheless this implementation is often the wrong way to get back the children'list (because it is not pertinent)
   * and one had better call a service provided by the CATIAV5 model design. In that case one has to overrride this method.
   * 
   */
     virtual list<CATBaseUnknown> * GetChildrenList();

   /** 
    * @nodoc 
    *
    * This method is called when an object is logically dead.
	  * We therefore destroy its associated representation whenever it is possible.
    */
     virtual HRESULT ChangeComponentState( ComponentState iFromState, 
                                           ComponentState iToState, 
                                            const CATSysChangeComponentStateContext * iContext);
     
   /**
    * Method used to test if the elements of a CATPathElement are valid for highlight.
    * <br><b>Role</b>: in the default implementation, finds the first element that implements @href CATIVisu.
    * It then calls recursively method IsHighlightValid until one of the element has redefined this method or 
    * until the grahical representation @href #_rep is NULL.
    * @param iPathElt
    * input path of components of which we want to determine if they are highlightable..
    * @return 
    * an HRESULT value.
    * <br><b>Legal values</b>:
    * <ul>
    * <li>S_OK if none of the graphical representation @href #_rep data member of the elements of iPathElt is NULL  </li>
    * <li>E_FAIL if a graphical representation @href #_rep data member of one of the elements of iPathElt is NULL</li>.
    * </ul>
    */
     
     virtual HRESULT IsHighlightValid(CATPathElement & iPathElt);
     
    /**
     * @nodoc
     * internal method used to get the graphical representation even though it is in an invalid state.
     */
     virtual HRESULT GiveContextualRep( CATVisRepContext & iContext, CATRep *& oRep );
     
    /**
     * @nodoc
     */
     virtual HRESULT SetVisuRep(CATRep * iRep);
     
    /**
     *  Sets the graphical representation of this object to an not uptodate state.
     * <br><b>Role</b>: 
     * Sets the the graphical representation @href #_rep data member to an invalid state.
     * The return to a valid state can only be reached when the representation is built again.
     * Method GiveRep will return NULL if the @href #_rep data member is invalid.
     */
     virtual void SetRepNotUpToDate();
     
    /**
     * Tests whether or not the graphical representation of the current component is uptodate.
     * @return 
     * <ol>
     * <li>1 if the graphical representation @href #_rep data member of the component is uptodate</li>
     * <li>0 if the graphical representation @href #_rep data member of the component is not uptodate</li>
     * </ol>
     * 
     */
     virtual int IsRepUpToDate();



protected :
 
  /**
   * A pointer to the geometry associated to the current model. This pointer is set by the <tt>GetRep()</tt>
   * method and it is unreferenced through either the dedicated <tt>UnreferenceRep()</tt> method or 
   * the destructor.
   */
     CATRep *_rep;


  /**
   * IID of the interface that object implements by deriving  CATExtIVisu.
   */
   const IID  & _iid;

	/** @nodoc */
   //pour notre usage personnel, declare que la rep ne doit plus etre utilisee.
  unsigned int _isInvalid : 1;
  //indique que la rep doit etre remis a jour.
  /** @nodoc */
  unsigned int _isUpToDate :1;

protected :
   /**
    * @nodoc
    *
    */
    virtual CATVisBuildingState PreProcess();

    /**
    * @nodoc
    * Tests whether or not the graphical representation of the current component is uptodate
    * and returns a pointer to it or NULL.
    * <br><b>Role</b>: this method is used by the @href GetRep() and @href GiveRep() methods.
    * @return 
    * <ol>
    * <li>a pointer to the graphical representation of the component if it is uptodate</li>
    * <li>NULL otherwise</li>
    * </ol>
    *
    */
    virtual CATRep * IsRepOK();

  //  internal use for attribute propagation for object which
  //  deleguate their representation build to another one
  /** @nodoc */
  virtual int PropagateAttribut (CATBaseUnknown_var &att, const IID &attIID);


  /** @nodoc */
  int  OldModifyAttribut  (CATModifyAttribut       & modify);

  /** @nodoc */
  virtual int  ModifyAttribute  (CATModifyVisProperties & modify);
 
/**
* Sets mesh graphic attributes on the rep.
* @param iRep
* rep on which mesh graphic attributes are set.
* @param iPropertyType
* type of property to put on the rep.
* <br><b> Legal values</b>:
*  <ol>
*   <li>CATVPColor : color of the mesh</li>
*   <li>CATVPOpacity : opacity of the mesh</li>
*   <li>CATVPAllPropertyType : all types are put on the mesh</li>
* </ol>
* @param iPropertyValue
* Token which contains mesh graphic attributes to put on the rep.
*/
  virtual void SetMeshGraphicAttribute (CATRep                 * iRep,
    CATVisPropertyType       iPropertyType,
    CATVisPropertiesValues & iPropertyValue);


/**
* Sets point graphic attributes on the rep.
* @param iRep
* rep on which point graphic attributes are set.
* @param iPropertyType
* type of property to put on the rep.
* <br><b> Legal values</b>:
*  <ol>
*   <li>CATVPColor : color of the point</li>
*   <li>CATTVPSymbol : symbol of the point</li>
*   <li>CATVPAllPropertyType : all types are put on the point</li>
* </ol>
* @param iPropertyValue
* Token which contains point graphic attributes to put on the rep.
*/
  virtual void SetPointGraphicAttribute (CATRep                 * iRep,
                                CATVisPropertyType       iPropertyType,
                                CATVisPropertiesValues & iPropertyValue);

/**
* Sets line graphic attributes on the rep.
* @param iRep
* rep on which line graphic attributes are set.
* @param iPropertyType
* type of property to put on the rep.
* <br><b> Legal values</b>:
*  <ol>
*   <li>CATVPColor : color of the line</li>
*   <li>CATTVPLineType : type of the line</li>
*   <li>CATVPWidth : width of the line</li>
*   <li>CATVPAllPropertyType : all types are put on the line</li>
* </ol>
* @param iPropertyValue
* Token which contains point graphic attributes to put on the rep.
*/
  virtual void SetLineGraphicAttribute (CATRep                 * iRep,
                                CATVisPropertyType       iPropertyType,
                                CATVisPropertiesValues & iPropertyValue);

/**
* Sets edge graphic attributes on the rep.
* @param iRep
* rep on which edge graphic attributes are set.
* @param iPropertyType
* type of property to put on the rep.
* <br><b> Legal values</b>:
*  <ol>
*   <li>CATVPColor : color of the edge</li>
*   <li>CATTVPLineType : type of the edge</li>
*   <li>CATVPWidth : width of the edge</li>
*   <li>CATVPAllPropertyType : all types are put on the edge</li>
* </ol>
* @param iPropertyValue
* Token which contains point graphic attributes to put on the rep.
*/
  virtual void SetEdgeGraphicAttribute (CATRep                 * iRep,
                                CATVisPropertyType       iPropertyType,
                                CATVisPropertiesValues & iPropertyValue);
/**
* Sets asm graphic attributes on the rep.
* @param iRep
* rep on which asm graphic attributes are set.
* @param iPropertyType
* type of property to put on the rep.
* <br><b> Legal values</b>:
*  <ol>
*   <li>CATVPColor : color of the asm object</li>
*   <li>CATVPOpacity : opacity of the asm object</li>
*   <li>CATTVPSymbol : symbol of the asm object</li>
*   <li>CATTVPLineType : LineType of the asm object</li>
*   <li>CATVPWidth : width of the asm object</li>
*   <li>CATVPInheritance : inheritance of the asm object</li>
*   <li>CATVPAllPropertyType : all types are put on the asm object</li>
* </ol>
* @param iPropertyValue
* Token which contains asm graphic attributes to put on the rep.
*/
  virtual void SetAsmGraphicAttribute (CATRep                 * iRep,
                                CATVisPropertyType       iPropertyType,
                                CATVisPropertiesValues & iPropertyValue);

/** @nodoc */
  virtual void SetGlobalGraphicAttribute (CATRep                 * iRep,
                                CATVisPropertyType       iPropertyType,
                                CATVisPropertiesValues & iPropertyValue);

/** @nodoc */
  virtual void SetShowGraphicAttribute (CATRep                 * iRep,
                                CATVisPropertiesValues & iPropertyValue);

/** @nodoc */
  virtual void SetLayerGraphicAttribute (CATRep                 * iRep,
                                CATVisPropertiesValues & iPropertyValue);

/** @nodoc */
  virtual void SetPickGraphicAttribute (CATRep                 * iRep,
                                CATVisPropertiesValues & iPropertyValue);

 /** @nodoc */
  virtual void SetLowIntGraphicAttribute(CATRep                 * iRep,
                                CATVisPropertiesValues & iPropertyValue);

  /** @nodoc */
  virtual void SetRenderingGraphicAttribute(CATRep                 * iRep,
                                CATVisPropertiesValues & iPropertyValue);

/**
* Sets other graphic attributes (different from point, edge, line, mesh and asm)
* on the rep.
* <br><b>role</b>:
* If new graphic attributes (different from mesh, point, edge, line, asm)
* have been created, this function must be overhide to set on a rep
* these new graphic attributes.
* @param iRep
* rep on which <i>iGeomType</i> graphic attributes are set.
* @param iGeomType
* Type of graphic attributes to put on the rep.
* @param iPropertyType
* type of property to put on the rep.
* <br><b> Legal values</b>:
*  <ol>
*   <li>CATVPColor : color of the <i>iGeomType</i></li>
*   <li>CATVPOpacity : opacity of the <i>iGeomType</i></li>
*   <li>CATTVPSymbol : symbol of the <i>iGeomType</i></li>
*   <li>CATTVPLineType : LineType of the <i>iGeomType</i></li>
*   <li>CATVPWidth : width of the <i>iGeomType</i></li>
*   <li>CATVPInheritance : inheritance of the <i>iGeomType</i></li>
*   <li>CATVPAllPropertyType : all types are put on the asm <i>iGeomType</i></li>
* </ol>
* @param iPropertyValue
* Token which contains graphic attributes to put on the rep.
*/
  virtual void SetOtherGeomTypeGraphicAttribute(CATRep              *    iRep,
                                CATVisGeomType           iGeomType, 
                                CATVisPropertyType       iPropertyType,
                                CATVisPropertiesValues&  iPropertyValue);

/** @nodoc */
  virtual void SetMeshGraphicAttribute (CATIVisProperties * iPtrToVP);

/** @nodoc */
  virtual void SetPointGraphicAttribute (CATIVisProperties * iPtrToVP);

/** @nodoc */
  virtual void SetLineGraphicAttribute (CATIVisProperties * iPtrToVP);

/** @nodoc */
  virtual void SetEdgeGraphicAttribute (CATIVisProperties * iPtrToVP);

/** @nodoc */
  virtual void SetAsmGraphicAttribute (CATIVisProperties * iPtrToVP);

/** @nodoc */
  virtual void SetOtherGeomTypeGraphicAttribute(CATIVisProperties * iPtrToVP);

/** @nodoc */
  virtual void SetGlobalGraphicAttribute(CATIVisProperties * iPtrToVP);


/** @nodoc */
  virtual void GetMeshGraphicAttribute (CATIVisProperties * iPtrToVP, CATVisPropertiesValues & ioPropertyValue);

/** @nodoc */
  virtual void GetPointGraphicAttribute (CATIVisProperties * iPtrToVP,CATVisPropertiesValues & ioPropertyValue);

/** @nodoc */
  virtual void GetLineGraphicAttribute (CATIVisProperties * iPtrToVP,CATVisPropertiesValues & ioPropertyValue);

/** @nodoc */
  virtual void GetEdgeGraphicAttribute (CATIVisProperties * iPtrToVP,CATVisPropertiesValues & ioPropertyValue);

/** @nodoc */
  virtual void GetAsmGraphicAttribute (CATIVisProperties * iPtrToVP,CATVisPropertiesValues & ioPropertyValue);

 /** @nodoc */
   virtual void GetGlobalGraphicAttribute (CATIVisProperties * iPtrToVP,CATVisPropertiesValues & ioPropertyValue);

 /**
* Transfer some data from a CATVisPropertiesValues in a CATGraphicAttributeSet.
* @param oAtt
* CATGraphicAttributeSet which is set.
* @param iPropertyType
* type of property to transfer from iPropertyValue on oAtt.
* <br><b> Legal values</b>:
*  <ol>
*   <li>CATVPColor : color</li>
*   <li>CATVPOpacity : opacity</li>
*   <li>CATTVPLineType : LineType</li>
*   <li>CATVPWidth : width</li>
* </ol>
* @param iPropertyValue
* Token which contains graphic attributes to put on oAtt.
*/
  void SetGraphicAttributeSet (CATGraphicAttributeSet  * oAtt,
    CATVisPropertyType        iPropertyType, 
    CATVisPropertiesValues  & iPropertyValue);

  
/** @nodoc */
  void IsAppliMigrated();

/** @nodoc */
  void SetAppliMigrated();

private :

/** @nodoc */
  void SetShowGraphicAttributeAndNotif (CATRep                 * iRep,
                                CATVisPropertiesValues & iPropertyValue);
                                

    
 /** @nodoc */
  void SetGraphicAttribute (CATRep              *    iRep,
                                   CATVisGeomType           iGeomType, 
                                   CATVisPropertyType       iPropertyType,
                                   CATVisPropertiesValues&  iPropertyValue);

  /** @nodoc */

  CATExtIVisu& operator=(CATExtIVisu& iRef);

  // Copy constructor, not implemented
  // Set as private to prevent from compiler automatic creation as public.
  CATExtIVisu(const CATExtIVisu &iObjectToCopy);
  

private:

/** @nodoc */
  //CATVisBuiltState _State;
 unsigned int _State:2;//pour les perfos

/** @nodoc */
  unsigned int _isAppliMigrated:2;


};


#endif
