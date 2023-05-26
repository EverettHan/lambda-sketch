#ifndef CATIAddLibrary_h
#define CATIAddLibrary_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/** 
 * @CAA2Level L1
 * @CAA2Usage U5 
 */



// inherited from
#include <CATBaseUnknown.h>

// Module
#include "CATLifSpecs.h"

// OLE iid
#ifndef LOCAL_DEFINITION_FOR_IID
extern IID ExportedByCATLifSpecs IID_CATIAddLibrary;
#else
extern "C" const IID IID_CATIAddLibrary;
#endif


/**   
 * Interface to implement to add Knowledge libraries.<br>
 * <b>Role</b>: This interface helps us to find your specific Knowledge functions or Knowledge types that you would like to add to our language.
 * <br><br>
 * Usage:<br>    
 * If you want to customise the Knowledge tools (by adding functions, knowledge types ,etc...)<br>
 * <li>Implement this interface on one class that we call XX for example (that
 * will also implement CATICreateInstance).</li>
 * <li>In the Add method create all the functions, , etc... and add them to CATITypeDictionary.</li>
 * <li>Create an Object Modeler dictionary (.dico file) explaining that XX implements CATICreateInstance and CATIAddLibrary in your shared library.</li><br>
 * <br>Those methods will be called by our product when necessary. <br> 
 * <br>For example, you may want to create a max(double,double) function that could then be used in formulas, checks or programs.<br>
 * <br>
 * The algorithm to find all functions is the following :<br>
 * We scan the Object Modeler Dictionnaries to find all objects implementing CATIAddLibrary and CATICreateInstance.
 * <br> For each object, we create it with CATICreateInstance, then get the
 * CATIAddLibrary interface on it and call the Add Method.<br>
 * In the Add method, you can use the CreateFunction method. <br>
 * <br> This interface is multi implemented by the different applications.<br> 
 * The Add method is called only once. Thus, you don't need to verify that the types or functions that you're creating already exist.<br>
 * THIS INTERFACE MUST NOT BE USED BY APPLICATIONS TO LOAD THEIR LIBRARIES. USE CATITypeDictionary::LoadLibrary instead.<br>
 * THIS IS REALLY IMPORTANT BECAUSE A CACHE OPTIMIZATION IS PERFORMED IN LoadLibrary AND WE ENSURE THAT THIS METHOD CANNOT BE CALLED TWICE.<br>
 * @see CATICkeSignature, CATICkeArg
 */
class ExportedByCATLifSpecs CATIAddLibrary : public CATBaseUnknown
{
public :

/**
 * Add your own Knowledge functions or Knowledge types here.
 */
virtual void Add ()  = 0;

private:

  // to define ClassName
  CATDeclareInterface;


}; 

CATDeclareHandler(CATIAddLibrary,CATBaseUnknown);

#endif


