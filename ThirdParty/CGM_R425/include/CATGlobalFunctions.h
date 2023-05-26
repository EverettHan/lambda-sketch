#ifndef CATGlobalFunctions_h
#define CATGlobalFunctions_h

// COPYRIGHT DASSAULT SYSTEMES 2000


/** 
* @CAA2Level L1
* @CAA2Usage U1 
*/


#include "CATLifSpecs.h"

#include "CATUnicodeString.h"
#include "CATIForwardsDecl.h"


class CATICkeObject_var;

/** 
 * Pointer on function to instantiate an object from its Knowledge type.
 * Internal Use.	 
 * @param iOwner The object that will aggregate the object to create
 * @param iKey The name of the object to create
 * @param oInstanciated The object instanciated.
 * @return classic HRESULT
 */
typedef HRESULT (*CATInstanciationFunction) ( const CATICkeObject_var & iOwner, const CATUnicodeString& iKey, CATICkeObject_var& oInstanciated);
											 
/**   
 * Class dedicated to the acquisition of the Knowledge dictionary.
 * <b>Role</b>: This class is used to get a handler on the Knowledge dictionary.<br>
 * @see CATIType, CATITypeDictionary
   */
#include "CATITypeDictionary.h"
class CATIFunctionDictionary_var;

class ExportedByCATLifSpecs CATGlobalFunctions {
public:

  /**
   * Returns the Knowledge dictionary of types.<br> 
   */
	static CATITypeDictionary_var GetTypeDictionary();

  /**
   * @nodoc
   * Returns the Knowledge dictionary of functions.<br> 
   */
	static CATIFunctionDictionary_var GetFunctionDictionary();

  /**
   * Frees the dictionary (Necessary for MLK clean-up). DO NOT USE.
   */
  static void FreeDictionary();

  /** Returns the name of a function that can be used in the definition of a Knowledge type, for precising how to instantiate an object of this type.
   *  This one declares that the instanciation of the type will be done by instanciating a feature startup of the same name.
   */
  static CATUnicodeString InstanciatorFromStartup (); 

  /** Returns the name of a function that can be used in the definition of a Knowledge type, for precising how to instantiate an object of this type.
   *  This one declares that the instanciation of the type will be done by using CATIInstanciation on the container.  
   */
  static CATUnicodeString InstanciatorFromContainer (); 

  /** Returns the name of a function that can be used in the definition of a Knowledge type, for precising how to instantiate an object of this type.
   *  This one declares that the instanciation of the type will be done by using CATIInstanciation on the father.
   */
  static CATUnicodeString InstanciatorFromFather (); 

private:
	static CATITypeDictionary_var theGlobalDico;
	friend class CATCkeDictionary;
};

#endif 
