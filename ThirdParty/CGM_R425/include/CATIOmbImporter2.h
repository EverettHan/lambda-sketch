#ifndef CATIOmbImporter2_H
#define CATIOmbImporter2_H

/**
 * @level Protected 
 * @usage U3
 */

#include "CATOmbImportExport.h"
#include "CATOmbImportExportParameters.h"


#include "CATUnicodeString.h"
#include "CATILockBytes2.h"
#include "CATOmbLifeCycleRootsBag.h"

extern ExportedByCATOmbImportExport IID IID_CATIOmbImporter2 ;

/**
 * Main Class to implement a component that imports Data.
 * In order to fullfill its contract, it has to implement :
 *  - this interface
 *  - the interface called CATICreateInstance 
 *  - a file that lists all the capabilities of the importer . 
 *    the name of the file is the name of the latype of the object implementing this interface
 *    and the extension is "capa"
 *    This File is  a text file.   
 *    On each line of the file :
 *    From[Extension(,Usage)] On[File/ILB]
 *    Here are some Examples  :
 *    From[cgr,AuthoringVisu] On[File]  
 *    From[cgr] Generates[cgr]  On[ILB]
 *
 *    Formally we have 4 sections :
 *     From[...] : : Here we specify the extension of the stream it imports. Optionaly spearated by a comma, you can have the usage it is used for .
 *                    In this field, it can be the category of the stream descriptor. 
 *     On[...]  : Here you specify if your exporter can work with File IO or CATIA IO. If you are using File , you specify File. in the other case, you define ILB.
 */

class ExportedByCATOmbImportExport CATIOmbImporter2: public CATBaseUnknown
{
  CATDeclareInterface;

  public:
 
    /** 
     * Import Stream into Session
     * @param iStream 
     * The stream from which we want to import.
     * @param iExtension 
     * The identifier of extension you want to import
     * @param iUsage 
     * The  usage
	   * @param oBag
	   * The bag containing all created object
     * @return
     * S_OK if no problems were encoutered, S_FALSE if it is not able to import this Data ( sometimes
	 * the same extension is used for different data) or E_FAIL otherwise
    */
	virtual HRESULT ImportILBOfExtensionAndUsageIntoSession ( CATILockBytes2& iStream, const CATUnicodeString& iExtension, const CATUnicodeString& iUsage, 
                                                            CATOmbImportExportParameters* iParameters, CATOmbLifeCycleRootsBag& oBag) = 0;
    
  /** 
     * Import Stream into Session
     * @param iFilePath 
     * The FilePath from which we want to import.
     * @param iExtension 
     * The identifier of extension you want to import
     * @param iUsage 
     * The  usage
	   * @param oBag
	   * The bag containing all created object
     * @return
     * S_OK if no problems were encoutered, S_FALSE if it is not able to import this Data ( sometimes
	 * the same extension is used for different data) or E_FAIL otherwise
    */
	virtual HRESULT ImportFileOfExtensionAndUsageIntoSession (const CATUnicodeString& iFilePath, const CATUnicodeString& iExtension, const CATUnicodeString& iUsage, 
                                                            CATOmbImportExportParameters* iParameters, CATOmbLifeCycleRootsBag& oBag) = 0;


      
  /** 
  *  The importer says if it knows how to import the input file path  with optional input 
  * extension and usage.
  * @param iFilePath 
  * The FilePath from which we want to import.
  * @param ioExtension 
  * The identifier of  Extension  from which we want to import 
  *  - could be given in input if it's known,
  *  - should be returned  in output if the importer knows how to Import the file
  * @param iUsage 
  * The  usage
  *  - could be given in input if it's known,
  *  - should be returned  in output if the importer knows how to Import the file
  * @return
  * S_OK if it know how to import the file
  */
virtual HRESULT CanImportFileIntoSession (const CATUnicodeString& iFilePath, const CATUnicodeString& ioExtension, const CATUnicodeString& ioUsage)=0;

  /** 
  *  The importer says if it knows how to import the input abstract stream  
  * with optional input extension and usage.
  * @param stream 
  * The stream  we want to import.
  * @param ioExtension 
  * The identifier of  Extension  from which we want to import 
  *  - could be given in input if it's known,
  *  - should be returned  in output if the importer knows how to Import the file
  * @param iUsage 
  * The  usage
  *  - could be given in input if it's known,
  *  - should be returned  in output if the importer knows how to Import the file
  * @return
  * S_OK if it know how to import the file
  */
virtual HRESULT CanImportILBIntoSession (CATILockBytes2& iStream, const CATUnicodeString& ioExtension, const CATUnicodeString& ioUsage)=0;

};


CATDeclareHandler( CATIOmbImporter2, CATBaseUnknown );

#endif
