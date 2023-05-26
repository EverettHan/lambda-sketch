#ifndef CATIDLMigrationFlags_h
#define CATIDLMigrationFlags_h

// COPYRIGHT DASSAULT SYSTEMES 2001

//
// These flags must be used to monocode C++ methods in a migration
// meant to correct incompatibilities between DS C++ and Automation.
//
// These flags must be used to monocode C++ methods which have
// been defined in V5 IDL as:
//
// + out CATBSTR or out /*IDLRETVAL*/ CATBSTR parameters
// + out CATVariant or out /*IDLRETVAL*/ CATVariant parameters
// + in CATSafeArrayVariant or inout CATSafeArrayVariant parameters
//
// =========================================================================
//
// For instance, the following IDL method:
// HRESULT m7(out CATBSTR oCATBSTR);
//
// Used to generate the following C++ method:
// virtual HRESULT  __stdcall m7(CATBSTR *& oCATBSTR);
//
// It must be modified as follows.
// #ifdef CATIDLMigration_BSTR // new Automation compatible coding style
//		virtual HRESULT  __stdcall m7(CATBSTR & oCATBSTR);
// #else // CATIDLMigration_BSTR // old Automation incompatible coding style
//		virtual HRESULT  __stdcall m7(CATBSTR *& oCATBSTR);
// #endif // CATIDLMigration_BSTR
//
// =========================================================================
//
// Other example, the following IDL method:
// HRESULT m8(out CATVariant oCATVariant);
//
// Used to generate the following C++ method:
// virtual HRESULT  __stdcall m8(CATVariant *& oCATVariant);
//
// It must be modified as follows.
// #ifdef CATIDLMigration_VARIANT
//		virtual HRESULT  __stdcall m8(CATVariant & oCATVariant);
// #else // CATIDLMigration_VARIANT
//		virtual HRESULT  __stdcall m8(CATVariant *& oCATVariant);
// #endif // CATIDLMigration_VARIANT
//
// =========================================================================
//
// Finally, the following IDL method:
// HRESULT m9(in CATSafeArrayVariant iCATSafeArrayVariant, inout CATSafeArrayVariant ioCATSafeArrayVariant);
//
// Used to generate the following C++ method:
// virtual HRESULT  __stdcall m9(const CATSafeArrayVariant & iCATSafeArrayVariant, CATSafeArrayVariant & ioCATSafeArrayVariant);
//
// It must be modified as follows.
// #ifdef CATIDLMigration_SAFEARRAY
//		virtual HRESULT  __stdcall m9(CATSafeArrayVariant *& iCATSafeArrayVariant, CATSafeArrayVariant * & oCATSafeArrayVariant, CATSafeArrayVariant *& ioCATSafeArrayVariant);
// #else // CATIDLMigration_SAFEARRAY
//		virtual HRESULT  __stdcall m9(const CATSafeArrayVariant & iCATSafeArrayVariant, CATSafeArrayVariant * & oCATSafeArrayVariant, CATSafeArrayVariant & ioCATSafeArrayVariant);
// #endif // CATIDLMigration_SAFEARRAY
//
// =========================================================================
//
// Once all the code has been migrated in this fashion, the build-time flag
// will be activated and the Automation incompatibilities will disappear.
//

#ifndef CATIDLMigration_BSTR
//#define CATIDLMigration_BSTR
#endif // CATIDLMigration_BSTR

#ifndef CATIDLMigration_VARIANT
//#define CATIDLMigration_VARIANT
#endif // CATIDLMigration_VARIANT

#ifndef CATIDLMigration_SAFEARRAY
//#define CATIDLMigration_SAFEARRAY
#endif // CATIDLMigration_SAFEARRAY

#endif // CATIDLMigrationFlags_h
