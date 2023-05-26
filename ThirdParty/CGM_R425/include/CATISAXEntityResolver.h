// COPYRIGHT DASSAULT SYSTEMES 2002

/**
 * @CAA2Level L1
 * @CAA2Usage U5
 */

#ifndef CATISAXEntityResolver_h
#define CATISAXEntityResolver_h

// System framework
#include "CATBaseUnknown.h"
class CATUnicodeString;

// XMLParser framework
#include "CatXmlItfBase.h"
class CATISAXInputSource_var;

#ifndef LOCAL_DEFINITION_FOR_IID
	extern ExportedByCatXmlItfBase IID IID_CATISAXEntityResolver;
#else // LOCAL_DEFINITION_FOR_IID
	extern "C" const IID IID_CATISAXEntityResolver ;
#endif // LOCAL_DEFINITION_FOR_IID

/**
 * Interface for resolving entities.
 *
 * <p>If a SAX application needs to implement customized handling
 * for external entities, it must implement this interface and
 * register an instance with the SAX parser using 
 * the parser @href CATISAXXMLReader#SetEntityResolver method @href .</p>
 *
 * <p>The parser will then allow the application to intercept any
 * external entities (including the external DTD subset and external
 * parameter entities, if any) before including them.</p>
 *
 * <p>Many SAX applications will not need to implement this interface,
 * but it will be especially useful for applications that build
 * XML documents from databases or other specialised input sources,
 * or for applications that use URI types other than URLs.</p>
 *
 * <p>The following resolver would provide the application
 * with a special character stream for the entity with the system
 * identifier "http://www.myhost.com/today":</p>
 *
 *<pre>
 *
 * #include "CATISAXEntityResolver.h"
 * #include "CATISAXInputSource.h"
 *	
 * class MyResolver : public CATBaseUnknown {
 *     public:
 *         HRESULT ResolveEntity (
 *             const CATUnicodeString & iPublicId, 
 *             const CATUnicodeString & iSystemId, 
 *             CATISAXInputSource *& oInputSource);
 *         ...
 * };
 * 
 * // Declaration of the class as a CNext implementation class.
 * CATImplementClass( MyResolver, Implementation, CATBaseUnknown, CATnull );
 * 
 * // Implement the CATISAXEntityResolver interface.
 * #include "TIE_CATISAXEntityResolver.h"
 * TIE_CATISAXEntityResolver( MyResolver );
 * 
 * 
 * HRESULT MyResolver::ResolveEntity (
 *     const CATUnicodeString & iPublicId, 
 *     const CATUnicodeString & iSystemId, 
 *     CATISAXInputSource *& oInputSource) {
 * 
 *     HRESULT hr = E_FAIL;
 *     oInputSource = NULL;
 *     if (iSystemId == "http://www.myhost.com/today") {
 *         hr = CATISAXInputSourceFactory::CreateURLInputSource(iSystemId, oInputSource);
 *     }
 *     return hr;
 * }
 *
 *</pre>
 *
 * <p>The application can also use this interface to redirect system
 * identifiers to local URIs or to look up replacements in a catalog
 * (possibly by using the public identifier).</p>
 *
 * <p>The @href CATSAXDefaultHandler class implements the default behaviour for
 * this interface, which is simply always to return <tt>NULL</tt> (to request
 * that the parser use the default system identifier).</p>
 *
 * @see CATISAXInputSource, CATSAXDefaultHandler, CATISAXXMLReader#SetEntityResolver
 */
class ExportedByCatXmlItfBase CATISAXEntityResolver: public CATBaseUnknown {
	CATDeclareInterface;
	
	public:
		
		/**
		 * Allows the application to resolve external entities.
		 *
		 * <p>The @href CATISAXXMLReader will call this method before opening any external
		 * entity except the top-level document entity (including the
		 * external DTD subset, external entities referenced within the
		 * DTD, and external entities referenced within the document
		 * element): the application may request that the parser resolve
		 * the entity itself, that it use an alternative URI, or that it
		 * use an entirely different input source.</p>
		 *
		 * <p>Application writers can use this method to redirect external
		 * system identifiers to secure and/or local URIs, to look up
		 * public identifiers in a catalogue, or to read an entity from a
		 * database or other input source (including, for example, a dialog
		 * box).</p>
		 *
		 * <p>If the system identifier is a URL, the SAX parser must
		 * resolve it fully before reporting it to the application.</p>
		 *
		 * @param iPublicId 
		 * The public identifier of the external entity being referenced 
		 * (can be an empty @href CATUnicodeString if no public identifier was given).
		 * @param iSystemId 
		 * The system identifier of the external entity being referenced.
		 * @param oInputSource
		 * An InputSource object describing the new input source,
		 *         or <tt>NULL</tt> to request that the parser open a regular
		 *         URI connection to the system identifier.
		 *
		 * </dl>
		 * <dt><b>Errors Returned</b>:</dt>
		 * <dd>
		 *   <table class="errtab">
		 *     <tr>
		 *       <th class="errth">Error Class</th>
		 *       <th class="errth">Error Id</th>
		 *       <th class="errth">Description</th>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXException </td>
		 *        <td class="errtd">XMLParserERR_2000</td>
		 *        <td class="errtd">The method can raise a CATSAXException</td>
		 *     </tr>
		 *     <tr>
		 *        <td class="errtd">@href CATSAXIOException </td>
		 *        <td class="errtd">XMLParserERR_2001</td>
		 *        <td class="errtd">If an I/O error occurs, possibly the result of creating a new @href CATISAXInputSource
		 * the method can raise this error.</td>
		 *     </tr>
		 *   </table>
		 * </dd>
		 *
		 * @see CATISAXInputSource
		 */
		virtual HRESULT ResolveEntity(
			const CATUnicodeString & iPublicId, 
			const CATUnicodeString & iSystemId, 
			CATISAXInputSource_var& oInputSource) = 0;
	
};
CATDeclareHandler(CATISAXEntityResolver, CATBaseUnknown);


#endif // CATISAXEntityResolver_h
