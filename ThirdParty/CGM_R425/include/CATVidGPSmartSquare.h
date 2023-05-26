// COPYRIGHT Dassault Systemes 2007
//===================================================================
#ifndef CATVidGPSmartSquare_H
#define CATVidGPSmartSquare_H

#include <VisuDialog.h>
#include <CATVidGPTexturedWidget.h>
#include <list.h>
#include <CATISYPCollection.h>
#include <CATListOfInt.h>

class CATVidLayGridWeight;
class CAT3DCustomRep;
class CATPickingRender;
class CATVidLayGrid;
class CATVidLayConstraints;
class CATVidLayGridConstraints;

//-----------------------------------------------------------------------
class ExportedByVisuDialog CATVidGPSmartSquare: public CATVidGPTexturedWidget
{
  CATDeclareClass;
public:
  
  /** Constructor */
  CATVidGPSmartSquare ();
  /** Destructor */
  CATVidGPSmartSquare (CATCommand *i_pParent, const CATString & i_pIdentifier, CATBoolean i_useManipulatorFlag = FALSE);
  /** @copydoc CATVidLayGrid#SetGridWeight*/
  void SetGridWeight(const CATVidLayGridWeight& i_gridWeight);
  /** @copydoc CATVidLayGrid#GetGridWeight*/
  const CATVidLayGridWeight& GetGridWeight() const;
  /**
  * @name CATISYPCollection implementation
  */
  /*@{*/ 
  /** @copydoc CATISYPCollection#GetAt */
  virtual CATBaseUnknown_var GetAt( int i_index );
  /** @copydoc CATISYPCollection#GetCount */
  virtual int GetCount();
  /** @copydoc CATISYPCollection#Append */
  virtual void Append( const CATBaseUnknown_var &i_spObject );
  /** @copydoc CATISYPCollection#AppendList */
  virtual void AppendList( const CATSYPConstArray<CATBaseUnknown_var> &i_list );
  /** @copydoc CATISYPCollection#Remove */
  virtual void Remove( const CATBaseUnknown_var &i_spObject );
  /** @copydoc CATISYPCollection#RemoveList */
  virtual void RemoveList( const CATSYPConstArray<CATBaseUnknown_var> &i_list );
  /** @copydoc CATISYPCollection#Clear */
  virtual void Clear();
  /** @copydoc CATISYPCollection#Contains */
  virtual int Contains( const CATBaseUnknown_var &i_spObject );
  /** @copydoc CATISYPCollection#Append */
  virtual void Append( const CATLISTV(CATBaseUnknown_var) &i_list );
  /*@}*/
 /**
  * Adds a spacer into the grid that is used to distributes the texture coords to the smart square representation.
  * The given widget must be a spacer. The given widget will be internally "addref"ed.
  */
  void SetGPConstraints(const CATBaseUnknown_var& i_spChild, const  CATBaseUnknown_var& i_constraints );
  /**
   * @return the constraints associated to a spacer.
   */
   CATBaseUnknown_var GetGPConstraints(const CATBaseUnknown_var& i_spChild ) const;
  /**
   * @return the implicit collection of this widget.
   */
  CATISYPCollection_var GetItems() { return this; };
  void SetConstraints(CATVidWidget *i_pWidget, const CATVidLayConstraints& i_constraints);
protected:
  virtual ~CATVidGPSmartSquare ();
  /** Copy constructor*/
  CATVidGPSmartSquare (CATVidGPSmartSquare &);
  /** operator =*/
  CATVidGPSmartSquare& operator=(CATVidGPSmartSquare&);
private:
  friend class l_CATVidGPSmartSquare;
};

//-----------------------------------------------------------------------

#endif
