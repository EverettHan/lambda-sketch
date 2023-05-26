#ifndef CATIAddTypeLibrary_h
#define CATIAddTypeLibrary_h

// COPYRIGHT DASSAULT SYSTEMES 1999



// inherited from
#include "CATBaseUnknown.h"

// Module
#include "CATLifSpecs.h"

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIAddTypeLibrary;
#else
extern "C" const IID IID_CATIAddTypeLibrary;
#endif


/**
 * @nodoc Use CATIAddLibrary instead<br>
 * Interface to implement to add types in the dictionary.
 * <br>
 * Usage:<br>    
 *   If you want to expose your objects to search, knowledge...
 * 
 * <li>Implement this interface on one class that we call XX for example (that
 *      will also implement CATICreateInstance).</li>
 * <li>In the Add method create all the types. </li>
 * <li>Create an Object Modeler dictionary (.dic file) explaining that XX implements
 *     CATICreateInstance and CATIAddTypeLibrary in your shared library</li><br>
 * <br>
 * Those methods will be called by our product at its initialisation <br> 
 * <br>
 * The algorithm to find all types is the following :<br>
 * We scan the Object Modeler Dictionnaries to find all objects implementing CATIAddTypeLibrary and CATICreateInstance :
 * <br> for each object, we create it with CATICreateInstance, then get the
 * CATIAddTypeLibrary interface on it and call the Add Method.<br>
 * In the Add method, you can use the CreateFunction method. <br>
 * Note that the library where you implement this should be as 
 * small as possible in order to avoid long load times and to 
 * keep memory usage as low as possible.<br>  
 * This interface is multi implemented by the different applications.<br> 
 * The Add method is called only once. Thus, you don't need to verify that the types or functions that you're creating already exist.<br>
 * THIS INTERFACE MUST NOT BE USED BY APPLICATIONS TO LOAD THEIR LIBRARIES. USE CATITypeDictionary::LoadLibrary instead.<br>
 * THIS IS REALLY IMPORTANT BECAUSE A CACHE OPTIMIZATION IS PERFORMED IN LoadLibrary AND WE ENSURE THAT THIS METHOD CANNOT BE CALLED TWICE.<br>
 */
class ExportedByCATLifSpecs CATIAddTypeLibrary : public CATBaseUnknown
{
public :

/**
 * @nodoc Implement CATIAddLibrary instead
 */
virtual void Add ()  = 0;

private:

  // to define ClassName
  CATDeclareInterface;


}; 

CATDeclareHandler(CATIAddTypeLibrary,CATBaseUnknown);

#endif


