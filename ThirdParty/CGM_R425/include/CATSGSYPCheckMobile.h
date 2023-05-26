#ifndef CATSGSYPCheckMobile_H
#define CATSGSYPCheckMobile_H



#include <CATSGSYPCheck.h>

/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * An assertion that always fails.
 * Note that is not not exactly an assertion since it does not check a condition.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#FAILURE.2A_Macros for details
 */
#define SG_FAILURE(iDiagnostic) SG_CheckFailure__(iDiagnostic, __FILE__, __LINE__, NULL)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * An assertion that always fails with a message.
 * Note that is not not exactly an assertion since it does not check a condition.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#FAILURE.2A_Macros for details
 */
#define SG_FAILURE_MSG(iDiagnostic, iMessage) SG_CheckFailure__(iDiagnostic, __FILE__, __LINE__, NULL)

/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a boolean condition (i.e. an int that is considered TRUE if != 0, FALSE if 0) is TRUE.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iBoolean the boolean to test (i.e. an int)
 */
#define SG_CHECK_TRUE(iBoolean) do { if (!(iBoolean)) SG_Check_TRUE_Failed__(#iBoolean, __FILE__, __LINE__, NULL); } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a boolean condition (i.e. an int that is considered TRUE if != 0, FALSE if 0) is TRUE and add a message.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iBoolean the boolean to test (i.e. an int)
 * @param iMessage the message to add to the diagnostic (a const char*).
 */
#define SG_CHECK_TRUE_MSG(iBoolean, iMessage) do { if (!(iBoolean)) SG_Check_TRUE_Failed__(#iBoolean, __FILE__, __LINE__, NULL); } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a boolean condition (i.e. an int that is considered TRUE if != 0, FALSE if 0) is TRUE,
 * and exit the function by calling "return" if the condition is FALSE.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iBoolean the boolean to test (i.e. an int)
 */
#define SG_CHECK_TRUE_RET(iBoolean) do { if(!(iBoolean)) { SG_Check_TRUE_Failed__(#iBoolean, __FILE__, __LINE__, NULL); return; } } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a boolean condition (i.e. an int that is considered TRUE if != 0, FALSE if 0) is TRUE,
 * and exit the function by calling "return" if the condition is FALSE. It adds a message.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iBoolean the boolean to test (i.e. an int)
 * @param iMessage the message to add to the diagnostic (a const char*).
 */
#define SG_CHECK_TRUE_RET_MSG(iBoolean, iMessage) do { if(!(iBoolean)) { SG_Check_TRUE_Failed__(#iBoolean, __FILE__, __LINE__, NULL); return; } } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a boolean condition (i.e. an int that is considered TRUE if != 0, FALSE if 0) is TRUE,
 * and exit the function by calling "return" with the specified value if the condition is FALSE.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iBoolean the boolean to test (i.e. an int)
 * @param iVal the value to return (must be of a type compatible with the return type of
 * the function where this macro is used)
 */
#define SG_CHECK_TRUE_RETV(iBoolean, iVal) do { if(!(iBoolean)) { SG_Check_TRUE_Failed__(#iBoolean, __FILE__, __LINE__, NULL); return iVal; } } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a boolean condition (i.e. an int that is considered TRUE if != 0, FALSE if 0) is TRUE,
 * and exit the function by calling "return" with the specified value if the condition is FALSE. It adds a message.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iBoolean the boolean to test (i.e. an int)
 * @param iVal the value to return (must be of a type compatible with the return type of
 * the function where this macro is used)
 * @param iMessage the message to add to the diagnostic (a const char*).
 */
#define SG_CHECK_TRUE_RETV_MSG(iBoolean, iVal, iMessage) do { if(!(iBoolean)) { SG_Check_TRUE_Failed__(#iBoolean, __FILE__, __LINE__, NULL); return iVal; } } while(0)

/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a pointer is NOT NULL.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iPointer the pointer to test
 */
#define SG_CHECK_POINTER(iPointer) do { const void *pointer = iPointer; if (pointer == NULL) SG_Check_Pointer_Failed__(#iPointer, __FILE__, __LINE__, NULL); } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a pointer is NOT NULL and add a message.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iPointer the pointer to test
 * @param iMessage the message to add to the diagnostic (a const char*).
 */
#define SG_CHECK_POINTER_MSG(iPointer, iMessage) do { const void *pointer = iPointer; if (pointer == NULL) SG_Check_Pointer_Failed__(#iPointer, __FILE__, __LINE__, NULL); } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a pointer is NOT NULL, and exit the function by calling "return" if the condition is FALSE.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iPointer the pointer to test
 */
#define SG_CHECK_POINTER_RET(iPointer) do { const void *pointer = iPointer; if (pointer == NULL) { SG_Check_Pointer_Failed__(#iPointer, __FILE__, __LINE__, NULL); return;} } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a pointer is NOT NULL, and exit the function by calling "return" if the condition is FALSE. 
 * It adds a message.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iPointer the pointer to test
 * @param iMessage the message to add to the diagnostic (a const char*).
 */
#define SG_CHECK_POINTER_RET_MSG(iPointer, iMessage) do { const void *pointer = iPointer; if (pointer == NULL) { SG_Check_Pointer_Failed__(#iPointer, __FILE__, __LINE__, NULL); return; } } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a pointer is NOT NULL, and exit the function by calling "return" with the specified 
 * value if the condition is FALSE.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iPointer the pointer to test
 * @param iVal the value to return (must be of a type compatible with the return type of
 * the function where this macro is used)
 */
#define SG_CHECK_POINTER_RETV(iPointer, iVal) do { const void *pointer = iPointer; if (pointer == NULL) { SG_Check_Pointer_Failed__(#iPointer, __FILE__, __LINE__, NULL); return iVal; } } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a pointer is NOT NULL, and exit the function by calling "return" with the specified 
 * value if the condition is FALSE. It adds a message.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iPointer the pointer to test
 * @param iVal the value to return (must be of a type compatible with the return type of
 * the function where this macro is used)
 * @param iMessage the message to add to the diagnostic (a const char*).
 */
#define SG_CHECK_POINTER_RETV_MSG(iPointer, iVal, iMessage) do { const void *pointer = iPointer; if (pointer == NULL) { SG_Check_Pointer_Failed__(#iPointer, __FILE__, __LINE__, NULL); return iVal;} } while(0)

/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a handler is NOT NULL_var.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iHandler the handler to test
 */
#define SG_CHECK_HANDLER(iHandler) do { const CATBaseUnknown *pointer = iHandler; if (pointer == NULL_var) SG_Check_Handler_Failed__(#iHandler, __FILE__, __LINE__, NULL); } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a handler is NOT NULL_var and add a message.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iHandler the handler to test
 * @param iMessage the message to add to the diagnostic (a const char*).
 */
#define SG_CHECK_HANDLER_MSG(iHandler, iMessage) do { const CATBaseUnknown *pointer = iHandler; if (pointer == NULL_var) SG_Check_Handler_Failed__(#iHandler, __FILE__, __LINE__, NULL); } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a handler is NOT NULL_var, and exit the function by calling "return" if the condition is FALSE.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iHandler the handler to test
 */
#define SG_CHECK_HANDLER_RET(iHandler) do { const CATBaseUnknown *pointer = iHandler; if (pointer == NULL_var) { SG_Check_Handler_Failed__(#iHandler, __FILE__, __LINE__, NULL); return;} } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a handler is NOT NULL_var, and exit the function by calling "return" if the condition is FALSE. 
 * It adds a message.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iHandler the handler to test
 * @param iMessage the message to add to the diagnostic (a const char*).
 */
#define SG_CHECK_HANDLER_RET_MSG(iHandler, iMessage) do { const CATBaseUnknown *pointer = iHandler; if (pointer == NULL_var) { SG_Check_Handler_Failed__(#iHandler, __FILE__, __LINE__, NULL); return; } } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a handler is NOT NULL_var, and exit the function by calling "return" with the specified 
 * value if the condition is FALSE.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iHandler the handler to test
 * @param iVal the value to return (must be of a type compatible with the return type of
 * the function where this macro is used)
 */
#define SG_CHECK_HANDLER_RETV(iHandler, iVal) do { const CATBaseUnknown *pointer = iHandler; if (pointer == NULL_var) { SG_Check_Handler_Failed__(#iHandler, __FILE__, __LINE__, NULL); return iVal; } } while(0)
/**
 * @nodoc
 * @ingroup groupUIVCoreToolsAssertions
 * Check a handler is NOT NULL_var, and exit the function by calling "return" with the specified 
 * value if the condition is FALSE. It adds a message.
 * See http://codewiki/codewiki/index.php/VID_:_Assertions_Macros#CHECK.2A_Macros for details.
 * @param iHandler the handler to test
 * @param iVal the value to return (must be of a type compatible with the return type of
 * the function where this macro is used)
 * @param iMessage the message to add to the diagnostic (a const char*).
 */
#define SG_CHECK_HANDLER_RETV_MSG(iHandler, iVal, iMessage) do { const CATBaseUnknown *pointer = iHandler; if (pointer == NULL_var) { SG_Check_Handler_Failed__(#iHandler, __FILE__, __LINE__, NULL); return iVal;} } while(0)

#endif // CATSGSYPCheckMobile_H
