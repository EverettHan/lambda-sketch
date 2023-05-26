#ifndef CATSYPFactoryResult_H
#define CATSYPFactoryResult_H
//'identifier1' has C-linkage specified, but returns UDT 'identifier2' 
// which is incompatible with C.
// This is legal as we are in C++ language.(cf msdn)
#pragma warning(disable:4190)

#include <IntroInfra.h>
#include <CATSYPMacros.h>
#include <CATBaseUnknown_var.h>
#include <CATSYPErrorMgt.h>
#include <CATUnicodeString.h>

class CATSYPErrorReport;

/**
 * Describes the result of a call to a property factory.
 * @see CATSYPStream
 */
class ExportedByIntroInfra CATSYPFactoryResult
{
public:
  /**
   * Describes the type of error that append during the 
   * construction of the property.
   */
  enum ErrorCode{
    /** No error occured*/
    NoError, 
    /** The factory has not been found in a CATFactory dictionnary, 
     * or it can't be build from the found library.
     */
    FactoryNotFound,
    /**
     * The enum factory has not been found
     */
    EnumFactoryNotFound,
    /**
     * The parsing of the CATUnicodeString failed
     */
    ParsingError,
    /**
     * The input CATUnicodeString is empty (not always a case of error)
     */
    EmptyValueString,
    /**
    * The input JSON object is empty (not always a case of error)
    */
    EmptyValueJSON,
    /**
     * The requested property type is empty
     */
    EmptyPropertyString,
    /**
     * The input string has not the good number of attributes, once parsed
     */
    BadNumberOfAttributes,
    /**
     * The input string can not be parsed into correct attributes
     */
    InvalidAttributes,
    /**
     * The enum value is not valid
     */
    InvalidEnumValue,
    /**
     * The bitfield value is not valid
     */
    InvalidBitFieldValue,
    /**
     * The resource file to use is not found
     */
    ResourceFileNotFound,
    /**
     * Error in the internal XML Builder
     */
    XMLBuilderInternalError
  };
  /** 
   * Constructor that takes the result object of the factory when succeded.
   * Will assert if i_spObject is a NULL_var. In case of NULL_var, the other 
   * constructor must be called.
   */
  explicit CATSYPFactoryResult(const CATBaseUnknown_var& i_spObject);
  /**
   * @deprecated use other constructors
   * Constructor to use in case of error. The character offset were is located the error
   * must be given as an entry.
   */
  explicit CATSYPFactoryResult(int i_errorCharacterOffset,
                               CATSYPFactoryResult::ErrorCode i_errorCode);
  /**
   * Constructor to use in case of error. The character offset were is located the error
   * must be given as an entry.
   * @param i_pErrorReport error report, that will be cloned
   */
  explicit CATSYPFactoryResult(int i_errorCharacterOffset,
                               CATSYPFactoryResult::ErrorCode i_errorCode,
                               const CATSYPErrorReport* i_pErrorReport);
  /** 
   * A constructor to use in case of error.
   * An error report will be built internally.
   * @param i_pError this error will be added to the internal error report, retrieve it with GetErrorReport()
   */
  explicit CATSYPFactoryResult(int i_errorCharacterOffset,
                               CATSYPFactoryResult::ErrorCode i_errorCode,
                               const CATUnicodeString& i_pError);
  /** Destructor */
  ~CATSYPFactoryResult();
  /** Copy Constructor */
  CATSYPFactoryResult(const CATSYPFactoryResult& i_toCopy);
  /**  operator = */
  CATSYPFactoryResult& operator =(const CATSYPFactoryResult& i_toCopy);
  /**
   * @return the return code indicating if the factory failed or succeeded. 
   */
  CATSYPFactoryResult::ErrorCode GetErrorCode() const;
  /**
   * @return the offset in the factory string were an error occured.
   */
  int GetErrorCharacterOffset() const;
  /**
   * @return the built object if no error occured.
   */
  const CATBaseUnknown_var& GetObject() const;
  /**
   * @return the error report
   */
  const CATSYPErrorReport* GetErrorReport() const;
  /**
   * Add an error to the embedded error report
   */
  virtual void AddError(const CATUnicodeString& i_message,
                        CATSYPErrorMgt::Severity i_errorType = CATSYPErrorMgt::Error);

  /** Gets the origin of the resource if exists else return empty string*/
  void GetResourceAbsolutePath(CATUnicodeString& o_resourceAbsolutePath) const;
  /** Sets the origin of the resource*/
  void SetResourceAbsolutePath(const CATUnicodeString& i_resourceAbsolutePath);

private:
  CATSYPFactoryResult();
  FORCE_STACK_ALLOCATION();
private:
  ErrorCode _errorCode;
  int _errorCharacterOffset;
  CATBaseUnknown_var _spObject;
  CATSYPErrorReport* _pErrorReport;
  CATUnicodeString _resourceAbsolutePath;
};
#endif
