#ifndef CATVidData_H
#define CATVidData_H

#include "VisuDialog.h"
#include "CATBoolean.h"
#include "CATBaseUnknown.h"
#include "CATUnicodeString.h"
#include "CATMathPoint2Df.h"

class CATUnicodeString;
class CATPixelImage;
class CATVidMimeData;
class CATSYPDataBlock;
class CATSYPDataBlockFactory;

/** @ingroup groupVidDnD
 *
 * Base class to store and translate data. 
 */
class ExportedByVisuDialog CATVidData: public CATBaseUnknown
{
  CATDeclareClass;

  /**
   * Adds a read-only property of type @c int to a data block factory.
   *
   * @param i_pFactory the factory in which the property must be added.
   * @param i_name name of the property to add.
   * @param i_val the value to associate to the property.
   *
   * @see CATSYPDataBlockFactory#AddProperty
   */
  static void AddIntToFactory(CATSYPDataBlockFactory * i_pFactory, const CATUnicodeString & i_name, int i_val);
  /**
   * Adds a read-only property of type @c CATUnicodeString to a data block factory.
   *
   * @param i_pFactory the factory in which the property must be added.
   * @param i_name name of the property to add.
   * @param i_val the value to associate to the property.
   *
   * @see CATSYPDataBlockFactory#AddProperty
   */
  static void AddTextToFactory(CATSYPDataBlockFactory * i_pFactory, const CATUnicodeString & i_name, const CATUnicodeString & i_val);
  /**
   * Adds a read-only property of type @c CATMathPoint2Df to a data block factory.
   *
   * @param i_pFactory the factory in which the property must be added.
   * @param i_name name of the property to add.
   * @param i_val the value to associate to the property.
   *
   * @see CATSYPDataBlockFactory#AddProperty
   */
  static void AddDimensionToFactory(CATSYPDataBlockFactory * i_pFactory, const CATUnicodeString & i_name, const CATMathPoint2Df & i_val);
  /**
   * Adds a read-only value-type property to a data block factory.
   *
   * @param i_pFactory the factory in which the property must be added.
   * @param i_name name of the property to add.
   * @param i_type type of the property (eg. <tt>"float"</tt>, <tt>"CATBoolean"</tt>, ...).
   * @param i_val the boxed value to associate to the property. 
   *
   * @see CATSYPDataBlockFactory#AddProperty
   */
  static void AddBoxedValueToFactory(CATSYPDataBlockFactory * i_pFactory, const CATUnicodeString & i_name, const CATUnicodeString & i_Type, CATBaseUnknown_var i_spVal);
  /**
   * Adds a read-only property to a data block factory.
   *
   * @param i_pFactory the factory in which the property must be added.
   * @param i_name name of the property to add.
   * @param i_type type of the property (eg. <tt>"CATPixelImage"</tt>, <tt>"CATVidCtl"</tt>, ...).
   * @param i_val the value to associate to the property.
   *
   * @see CATSYPDataBlockFactory#AddProperty
   */
  static void AddPropertyToFactory(CATSYPDataBlockFactory * i_pFactory, const CATUnicodeString & i_name, const CATUnicodeString & i_Type, CATBaseUnknown_var i_spVal);
  /**
   * Retreives a property of type @c CATUnicodeString from a data block.
   *
   * @param i_pDataBlock said data block.
   * @param i_name the name of the property to retreive.
   *
   * @return the unboxed property
   *
   * @see CATSYPDataBlock#GetProperty
   */
  static CATUnicodeString GetTextFromDataBlock(CATSYPDataBlock * i_pDataBlock, const CATUnicodeString & i_name); 
  /**
   * Retreives a property of type @c CATMathPoint2Df from a data block.
   *
   * @param i_pDataBlock said data block.
   * @param i_name the name of the property to retreive.
   *
   * @return the unboxed property
   *
   * @see CATSYPDataBlock#GetProperty
   */
  static CATMathPoint2Df GetDimensionFromDataBlock(CATSYPDataBlock * i_pDataBlock, const CATUnicodeString & i_name); 
  /**
   * Retreives a property of type @c int from a data block.
   *
   * @param i_pDataBlock said data block.
   * @param i_name the name of the property to retreive.
   *
   * @return the unboxed property
   *
   * @see CATSYPDataBlock#GetProperty
   */
  static int GetIntFromDataBlock(CATSYPDataBlock * i_pDataBlock, const CATUnicodeString & i_name);

public:
  /** Default constructor. */
  CATVidData();
  /**
   * Constructor. 
   *
   * @param i_pDataBlock the data block exported for drag-and-drop. Will be
   * @c AddRefed. @c CATSYPDataBlock#BeginUpdateTransaction will be called on
   * the data block, to make it read-only. Cannot be @c NULL.
   */
  CATVidData(CATSYPDataBlock * i_pDataBlock);
  /**
   * Constructor. 
   *
   * @param i_pDataBlock the data block exported for drag-and-drop. Will be
   * @c AddRefed. @c CATSYPDataBlock#BeginUpdateTransaction will be called on
   * the data block, to make it read-only. May be @c NULL.
   *
   * @param i_pExternalData the external data exported for drag-and-drop. Cannot
   * be @c NULL.
   */
  CATVidData(void * i_pExternalData, CATSYPDataBlock * i_pDataBlock);
  /** 
   * Destructor. 
   */
  virtual ~CATVidData();
  /** 
   * @return the data-block exported for drag-and-drop, if any. 
   */
  CATSYPDataBlock * GetDataBlock() const;

  /** 
   * @Sets the data-block exported for drag-and-drop, if any. 
   */
  void SetDataBlock( CATSYPDataBlock* ipDataBlock );
  /**
   * @return the external data exported for drag-and-drop, if any has been
   * set.
   */
  void * GetExternalData() const;
  /**
   * Sets the data as an external data type, not recognized by VID 
   * infrastructure, but possibly recognized by the target of the drop. 
   * The data will be fed to the @c CATInteractiveApplication on the
   * call to CATInteractiveApplication::StartDrag:
   * @code
   * @c pApplication->StartDrag(pData->GetExternalData(), dropeffect);
   * @endcode
   *
   * @par
   * On Windows, @c i_data must be a @ref IDataObject 
   * (cf @c CATInteractiveApplication::StartDrag).
   *
   * @param i_data the external data -- a @ref IDataObject on Windows.
   */
  void SetExternalData(void * i_data);

private:
  /** Copy constructor. */
  CATVidData (CATVidData &);
  /** Equal operator. */
  CATVidData& operator=(CATVidData&);

private:
  /** @see #GetExternalData */
  void * _pExternalData;
  /** @see #GetDataBlock */
  CATSYPDataBlock * _pDataBlock;
};

//-----------------------------------------------------------------------------

#endif
