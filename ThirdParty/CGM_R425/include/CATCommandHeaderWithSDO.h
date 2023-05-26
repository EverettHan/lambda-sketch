/* -*-c++-*- */
#ifndef CATCommandHeaderWithSDO_H
#define CATCommandHeaderWithSDO_H

// COPYRIGHT DASSAULT SYSTEMES  1997

#include "CATCommandHeader.h"
#include "CATAfrFoundation.h"

class CATCommandHeaderWithSDORep;
class CATListPtrCATBaseUnknown;
class CATListPtrCATCommand;

/**
 * Base class for command headers to represent objects contained in a CATSDO. 
 * <b>Role</b>: This header allows you to see objects of a CATSDO in a toolbar. 
 * This Set of Dialog Objects is filled by a command to visualize objects which 
 * can interact on it during its life.
 * <br>
 * The object's representation is specialized by an interface which must derive 
 * from @href CATIAfrDialog . To be seen in the toolbar objects must implement 
 * this interface (This interface is given in the constructor of the header) .  
 * <br>
 * This class is an abstract class, so used the 
 * derived @href CATCommandHeaderWithSDOForAgent class.
 *
 */
class ExportedByCATAfrFoundation CATCommandHeaderWithSDO : public CATCommandHeader
{
	/** @nodoc */
  CATDeclareClass;
  	/** @nodoc */
  CATDeclareHeaderResources;
  
public:

/**
 * @nodoc 
 * 
 * @param iVisuInterface
 *     Interface deriving from @href CATIAfrDialog.
 */
  void SetVisuIID( const IID & iVisuInterface);

/**
 * @nodoc
 * Constructs the representation associated to the starter.
 * <br>
 * Call @href #BuildSDORep and for the first starter set a callbac to be
 * prevent when the SDO change. @href #ConnectToSDO
 */
  virtual CATCmdRep * CreateToolbarRep( CATCmdStarter *, CATDialog * );

/**
 * @nodoc
 * Deletes the representation associated to the starter.
 * <br><b>Role</b>:
 */
  virtual void        DestroyToolbarRep( CATCmdStarter * );
  
/**
 * @nodoc
 * Empty method.
 */
  virtual CATCmdRep * CreateMenuRep( CATCmdStarter *, CATDialog * );

/**
 * @nodoc
 * Empty method.
 */
  virtual void        DestroyMenuRep( CATCmdStarter * );
  
/**
 * @nodoc
 * Empty method.
 */
  virtual CATCmdRep * CreateCtxMenuRep( CATCmdStarter *, CATDialog * );

/**
 * @nodoc
 * Empty method.
 */
  virtual void        DestroyCtxMenuRep( CATCmdStarter * );


protected:

	
/** 
  * @nodoc
  */

  CATCommandHeaderWithSDO( const CATString &, const IID &);

  virtual ~CATCommandHeaderWithSDO();

/**
 * @nodoc
 * Constructs representations of a set of objects.
 * <br><b>Role</b>Each new object of the SDO must be drawn.
 * <ul>
 * <li>Among the iElems list keep only interesting object</li>
 * <ul>
 * <li>Eventually the good type of object</li>
 * <li>the object wich implements the good interface</li>
 * <li>others criteria ...</li>
 * </ul
 * <li>Call @href CATCommandHeaderWithSDO#AddRep to update all representation of
 * the SDO. If the command header is associated to n starters, the command header
 * has n @href CATCommandHeaderWithSDORep objects </li>
 * </ul>
 * <br>This method is called by the @href #OnSDOChangeCB method
 * @param iElems
 *   List which contains objects to construct 
 */
  virtual void BuildRep( CATListPtrCATBaseUnknown & iElems ) = 0;

/**
 * @nodoc
 * Destroy representations of a set of objects.
 * <br><b>Role</b>Each object removed from the SDO must be erased.
 * <br>
 * Call @href CATCommandHeaderWithSDO#RemoveRep to update all representation of
 * the SDO. If the command header is associated to n starters, the command header
 * has n @href CATCommandHeaderWithSDORep objects.
 * <br>This method is called by the @href #OnSDOChangeCB method
 * @param iElems
 *    List which contains objects to destroy 
 */
  virtual void DestroyRep( CATListPtrCATBaseUnknown & iElems ) = 0;

/**
 * @nodoc
 * Constructs objects'representation in each representation of the command header.
 * <br><b>Role<b>: This method is called to update all representation of 
 * the command header. In each representation we add the representation of
 * each element of iElemList.
 * @param iElemList
 *  list of objects to create representations.
 */
  virtual void AddRep( CATListPtrCATBaseUnknown & iElemList );

/**
 * @nodoc
 * Updates objects'representation in each representation of the command header.
 * <br><b>Role<b>: This method is called to update all representation of 
 * the command header. In each representation we modify the representation of
 * each element of iElemList.
 * @param iElemList
 *  list of objects to update representations.
 */
  virtual void UpdateRep( CATListPtrCATBaseUnknown & iElemList );

/**
 * @nodoc
 * Removes objects'representation in each representation of the command header.
 * <br><b>Role<b>: This method is called to update all representation of 
 * the command header. In each representation we remove the representation of
 * each element of iElemList.
 * @param iElems
 *  list of objects to remove representations.
 */
  virtual void RemoveRep( CATListPtrCATBaseUnknown & iElems );

/**
 * @nodoc
 * Constructs the command header representation for a starter from SDO object. 
 * <br><b>Role</b>:Method called by the @href #CreateToolbarRep method.This
 * method takes all object of the SDO, and called next the @href
 * CATCommandHeaderWithSDORep#AddRep method. If you redefine this method, its
 * en general to filter element of the SDO.
 * @param iRep
 *    The representation of a starter.
 */
  virtual void BuildSDORep( CATCommandHeaderWithSDORep & iRep );

  /* @nodoc */
  CATCommandHeaderWithSDO(CATCommandHeaderWithSDO * header);

  /** @nodoc */
  IID                        _IID;

private:

  /** 
   * @nodoc
   * Copy constructor. Not Implemented.
   */
  CATCommandHeaderWithSDO( const CATCommandHeaderWithSDO & );
  /** 
   * @nodoc
   * Equal operator. Not Implemented.
   */
  CATCommandHeaderWithSDO& operator=( const CATCommandHeaderWithSDO&);

  // Callback when the SDO is modified. 
  // List of removal objects
  //   -> called @href #DestroyRep 
  // List of added objects
  //   ->  called @href #BuildRep 
  //  
  void      OnSDOChangeCB( CATCallbackEvent iPublishedEvent, void * iPublishingObject,
                           CATNotification  * iNotification, CATSubscriberData  iClientData,
                           CATCallback        iCallback );

  // To set the callback OnSDOChangeCB
  // called in the CreateToolbarRep
  void      ConnectToSDO();

  // to remove the callback
  // called in the DestroyToolbarRep
  void      DeconnectFromSDO();



private:

  CATCallback                _cbSDO;

  CATListPtrCATCommand     * _lpHeaderRep;

};

#endif
