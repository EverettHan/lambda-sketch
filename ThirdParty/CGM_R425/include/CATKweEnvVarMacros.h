//===================================================================
//
// CATKweEnvVarMacros.h
// Macros used in CATKweEnvVar.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//  01.12.20 Creation KJD
//===================================================================
#ifndef CATKweEnvVarMacros_H
#define CATKweEnvVarMacros_H

//------------------------------------------------------------------------------
// Macro to declare an environement variable
//------------------------------------------------------------------------------
#define CATKWE_DECLARE_VAR( VarName )                                          \
private :                                                                      \
  static unsigned short _IsSet##VarName;                                       \
  static int _##VarName;                                                       \
public :                                                                       \
  void Set##VarName(const int & iValue) {                                      \
    if (_##VarName == iValue) return;                                          \
    _##VarName      = iValue;                                                  \
    _IsSet##VarName = 1;                                                       \
  };                                                                           \
  const int & Get##VarName() {                                                 \
    return VarName();                                                          \
  };                                                                           \
  static const int &    VarName() {                                            \
    if(!_IsSet##VarName){                                                      \
      char* pString = NULL;                                                    \
      int oValue;                                                              \
      if ( CATLibSuccess == CATGetEnvValue (#VarName, &pString) && pString) {  \
        CATUnicodeString sString (pString); sString.ToLower();                 \
        if (sString.ConvertToNum (&oValue)) {                                  \
          _##VarName = oValue;                                                 \
        }                                                                      \
        if (pString) { free (pString); pString = NULL; }                       \
        _IsSet##VarName=1;                                                     \
      }                                                                        \
    }                                                                          \
    return _##VarName;                                                         \
  };
//------------------------------------------------------------------------------
// Macro to init the variable with default value
//------------------------------------------------------------------------------
#define CATKWE_INIT_VAR( ClassName, VarName, DefaultValue)                     \
  int CATKweEnvVar::_##VarName = DefaultValue;                                 \
  unsigned short CATKweEnvVar::_IsSet##VarName = FALSE;

#endif
