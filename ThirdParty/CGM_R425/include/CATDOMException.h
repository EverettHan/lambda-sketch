// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

#ifndef CATDOMException_h
#define CATDOMException_h

#include "CATInternalError.h"
#include "CatXmlItfExt.h"

/**
 * DOM operations only raise exceptions in "exceptional" circumstances, i.e., 
 * when an operation is impossible to perform (either for logical reasons, 
 * because data is lost, or because the implementation has become unstable). 
 * In general, DOM methods return specific error values in ordinary 
 * processing situations, such as out-of-bound errors when using 
 * @href CATIDOMNodeList 
 * <p>Implementations should raise other exceptions under other circumstances. 
 * For example, implementations should raise an implementation-dependent 
 * exception if a <tt>NULL_var</tt> argument is passed. 
 * <p>Some languages and object systems do not support the concept of 
 * exceptions. For such systems, error conditions may be indicated using 
 * native error reporting mechanisms. For some bindings, for example, 
 * methods may return error codes similar to those listed in the 
 * corresponding method descriptions.
 * <p>See also the <a href='http://www.w3.org/TR/2000/REC-DOM-Level-2-Core-20001113'>Document Object Model (DOM) Level 2 Core Specification</a>.
 */
class ExportedByCatXmlItfExt CATDOMException: public CATInternalError  {
	CATDeclareError(CATDOMException, CATInternalError)
	public:

		/**
		 * Exception codes.
		 *
		 * @param INDEX_SIZE_ERR
	     * If index or size is negative, or greater than the allowed value
		 * @param DOMSTRING_SIZE_ERR
	     * If it would return more characters than supported by the underlying implementation
		 * @param HIERARCHY_REQUEST_ERR
	     * If any node is inserted somewhere it doesn't belong
		 * @param WRONG_DOCUMENT_ERR
		 * If a node is used in a different document than the one that created it 
		 * (that doesn't support it)
		 * @param INVALID_CHARACTER_ERR
		 * If an invalid or illegal character is specified, such as in a name. See 
		 * production 2 in the XML specification for the definition of a legal 
		 * character, and production 5 for the definition of a legal name 
		 * character.
		 * @param NO_DATA_ALLOWED_ERR
		 * If data is specified for a node which does not support data
 		 * @param NO_MODIFICATION_ALLOWED_ERR
		 * If an attempt is made to modify an object where modifications are not 
		 * allowed
		 * @param NOT_FOUND_ERR
		 * If an attempt is made to reference a node in a context where it does 
		 * not exist
		 * @param NOT_SUPPORTED_ERR
		 * If the implementation does not support the requested type of object or 
		 * operation.
 		 * @param INUSE_ATTRIBUTE_ERR
		 * If an attempt is made to add an attribute that is already in use 
		 * elsewhere
		 * @param INVALID_STATE_ERR
		 * If an attempt is made to use an object that is not, or is no longer, 
		 * usable.
		 * @param SYNTAX_ERR
	     * If an invalid or illegal string is specified.
		 * @param INVALID_MODIFICATION_ERR
	     * If an attempt is made to modify the type of the underlying object.
		 * @param NAMESPACE_ERR
		 * If an attempt is made to create or change an object in a way which is 
		 * incorrect with regard to namespaces.
		 * @param INVALID_ACCESS_ERR
		 * If a parameter or an operation is not supported by the underlying 
		 * object.
		 */
		 enum ExceptionCode {
			INDEX_SIZE_ERR       = 1,
            DOMSTRING_SIZE_ERR   = 2,
            HIERARCHY_REQUEST_ERR = 3,
            WRONG_DOCUMENT_ERR   = 4,
            INVALID_CHARACTER_ERR = 5,
            NO_DATA_ALLOWED_ERR  = 6,
            NO_MODIFICATION_ALLOWED_ERR = 7,
			NOT_FOUND_ERR        = 8,
            NOT_SUPPORTED_ERR    = 9,
            INUSE_ATTRIBUTE_ERR  = 10,
			INVALID_STATE_ERR		= 11,
			SYNTAX_ERR                     = 12,
			INVALID_MODIFICATION_ERR       = 13,
			NAMESPACE_ERR                  = 14,
			INVALID_ACCESS_ERR             = 15 
		};
		
		/**
		 * Factory method.
		 *
		 * @param iRequest
		 * specifies the operation which was being performed at the time the error occurred.
		 * @param iMessage
		 * specifies the message describing the error details.
		 * @param oError
		 * the error created by the factory method.
		 */
		static HRESULT CreateError(
			const CATUnicodeString& iRequest, 
			const CATUnicodeString& iMessage,
			const ExceptionCode iCode,
			CATDOMException*& oError);

		/**
		 * Retrieves the error code associated with the object.
		 * @return
		 * the error code associated with the object
		 */
		ExceptionCode GetCode(); 

		/**
		 * Returns the message describing the error details.
		 * To get a complete description of the error, you can call
		 * @href CATError#GetNLSMessage
		 * @returns
		 * The message describing the error details
		 */
		CATUnicodeString GetMessage();


	private:
		CATUnicodeString _message;
		ExceptionCode _code;
};

#endif // CATDOMException_h

