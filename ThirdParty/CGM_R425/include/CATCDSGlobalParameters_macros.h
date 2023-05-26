#undef DECLARE_BOOL_VARIABLE
#undef DECLARE_INT_VARIABLE
#undef BEGIN_DECLARE_ENUM_VARIABLE
#undef DECLARE_ENUM_VALUE
#undef END_DECLARE_ENUM_VARIABLE
#undef BEGIN_DECLARE_MASK_VARIABLE
#undef DECLARE_MASK_BIT
#undef END_DECLARE_MASK_VARIABLE

#if CATCDSGlobalParameters_Pass == 0
// enum declaration

  #define DECLARE_BOOL_VARIABLE(varname, defvalue, comment)

  #define DECLARE_INT_VARIABLE(varname, defvalue, comment)

  #define BEGIN_DECLARE_ENUM_VARIABLE(varname, defvalue) \
    enum CATCDS##varname {

  #define DECLARE_ENUM_VALUE(varname, valname, comment) \
      varname##_##valname,

  #define END_DECLARE_ENUM_VARIABLE(varname) \
      varname##_##Limit \
    };

  #define BEGIN_DECLARE_MASK_VARIABLE(varname) \
    enum CATCDS##varname {

  #define DECLARE_MASK_BIT(varname, bit, def, valname, comment) \
      varname##_##valname = 1 << bit,

  #define END_DECLARE_MASK_VARIABLE(varname) \
      varname##_##Limit \
    };

#elif CATCDSGlobalParameters_Pass == 1
// variable declaration

  #define DECLARE_BOOL_VARIABLE(varname, defvalue, comment) \
    CATCDSBoolean _##varname;

  #define DECLARE_INT_VARIABLE(varname, defvalue, comment) \
    int _##varname;

  #define BEGIN_DECLARE_ENUM_VARIABLE(varname, defvalue) \
    CATCDS##varname _##varname;

  #define DECLARE_ENUM_VALUE(varname, valname, comment)

  #define END_DECLARE_ENUM_VARIABLE(varname)

  #define BEGIN_DECLARE_MASK_VARIABLE(varname) \
    CATCDS##varname _##varname;

  #define DECLARE_MASK_BIT(varname, bit, def, valname, comment)

  #define END_DECLARE_MASK_VARIABLE(varname)

#elif CATCDSGlobalParameters_Pass == 2
// function declaration

#ifdef CATCDSGlobalParameters_UseSetMembers

  #define DECLARE_BOOL_VARIABLE(varname, defvalue, comment) \
    CATCDSBoolean Is##varname() const; \
    void Set##varname(const CATCDSBoolean iValue);

  #define DECLARE_INT_VARIABLE(varname, defvalue, comment) \
    int Get##varname() const; \
    void Set##varname(const int iValue);

  #define BEGIN_DECLARE_ENUM_VARIABLE(varname, defvalue) \
    CATCDS##varname Get##varname() const; \
    void Set##varname(const CATCDS##varname iValue);

#else

  #define DECLARE_BOOL_VARIABLE(varname, defvalue, comment) \
    CATCDSBoolean Is##varname() const;

  #define DECLARE_INT_VARIABLE(varname, defvalue, comment) \
    int Get##varname() const;

  #define BEGIN_DECLARE_ENUM_VARIABLE(varname, defvalue) \
    CATCDS##varname Get##varname() const;

#endif

  #define DECLARE_ENUM_VALUE(varname, valname, comment)

  #define END_DECLARE_ENUM_VARIABLE(varname)

#ifdef CATCDSGlobalParameters_UseSetMembers

  #define BEGIN_DECLARE_MASK_VARIABLE(varname) \
    CATCDS##varname Get##varname() const; \
    void Set##varname(const CATCDS##varname iValue);

#else

  #define BEGIN_DECLARE_MASK_VARIABLE(varname) \
    CATCDS##varname Get##varname() const;

#endif

  #define DECLARE_MASK_BIT(varname, bit, def, valname, comment)

  #define END_DECLARE_MASK_VARIABLE(varname)

#elif CATCDSGlobalParameters_Pass == 3
// variable initialization

  #define DECLARE_BOOL_VARIABLE(varname, defvalue, comment) \
    _##varname = defvalue;

  #define DECLARE_INT_VARIABLE(varname, defvalue, comment) \
    _##varname = defvalue;

  #define BEGIN_DECLARE_ENUM_VARIABLE(varname, defvalue) \
    _##varname = varname##_##defvalue;

  #define DECLARE_ENUM_VALUE(varname, valname, comment)

  #define END_DECLARE_ENUM_VARIABLE(varname)

  #define BEGIN_DECLARE_MASK_VARIABLE(varname) \
    _##varname = CATCDS##varname(0);

  #define DECLARE_MASK_BIT(varname, bit, def, valname, comment) \
    _##varname = CATCDS##varname(_##varname | def << bit);

  #define END_DECLARE_MASK_VARIABLE(varname)

#elif CATCDSGlobalParameters_Pass == 4
// function implementation

#ifdef CATCDSGlobalParameters_UseSetMembers

  #define DECLARE_BOOL_VARIABLE(varname, defvalue, comment) \
    CATCDSBoolean CATCDSGlobalParameters::Is##varname() const \
    { \
      return _values._##varname; \
    } \
    \
    void CATCDSGlobalParameters::Set##varname(const CATCDSBoolean iValue) \
    { \
      _values._##varname = iValue; \
    }

  #define DECLARE_INT_VARIABLE(varname, defvalue, comment) \
    int CATCDSGlobalParameters::Get##varname() const \
    { \
      return _values._##varname; \
    } \
    \
    void CATCDSGlobalParameters::Set##varname(const int iValue) \
    { \
      _values._##varname = iValue; \
    }

  #define BEGIN_DECLARE_ENUM_VARIABLE(varname, defvalue) \
    CATCDS##varname CATCDSGlobalParameters::Get##varname() const \
    { \
      return _values._##varname; \
    } \
    \
    void CATCDSGlobalParameters::Set##varname(const CATCDS##varname iValue) \
    { \
      _values._##varname = iValue; \
    }

#else

  #define DECLARE_BOOL_VARIABLE(varname, defvalue, comment) \
    CATCDSBoolean CATCDSGlobalParameters::Is##varname() const \
    { \
      return _values._##varname; \
    }

  #define DECLARE_INT_VARIABLE(varname, defvalue, comment) \
    int CATCDSGlobalParameters::Get##varname() const \
    { \
      return _values._##varname; \
    }

  #define BEGIN_DECLARE_ENUM_VARIABLE(varname, defvalue) \
    CATCDS##varname CATCDSGlobalParameters::Get##varname() const \
    { \
      return _values._##varname; \
    }

#endif

  #define DECLARE_ENUM_VALUE(varname, valname, comment)

  #define END_DECLARE_ENUM_VARIABLE(varname)

#ifdef CATCDSGlobalParameters_UseSetMembers

  #define BEGIN_DECLARE_MASK_VARIABLE(varname) \
    CATCDS##varname CATCDSGlobalParameters::Get##varname() const \
    { \
      return _values._##varname; \
    } \
    \
    void CATCDSGlobalParameters::Set##varname(const CATCDS##varname iValue) \
    { \
      _values._##varname = iValue; \
    }

#else

  #define BEGIN_DECLARE_MASK_VARIABLE(varname) \
    CATCDS##varname CATCDSGlobalParameters::Get##varname() const \
    { \
      return _values._##varname; \
    }

#endif

  #define DECLARE_MASK_BIT(varname, bit, def, valname, comment)

  #define END_DECLARE_MASK_VARIABLE(varname)

#elif CATCDSGlobalParameters_Pass == 5
// variable reading

  #define DECLARE_BOOL_VARIABLE(varname, defvalue, comment) \
    var = CATCDSGetEnv("CATCDS" #varname); \
    if (!var.isEmpty()) { \
      if (var == sTRUE) \
        _##varname = TRUE; \
      else if (var == sFALSE) \
        _##varname = FALSE; \
    }

  #define DECLARE_INT_VARIABLE(varname, defvalue, comment) \
    var = CATCDSGetEnv("CATCDS" #varname); \
    if (!var.isEmpty()) { \
      _##varname = atoi(var.str()); \
    }

  #define BEGIN_DECLARE_ENUM_VARIABLE(varname, defvalue) \
    var = CATCDSGetEnv("CATCDS" #varname); \
    if (!var.isEmpty()) {

  #define DECLARE_ENUM_VALUE(varname, valname, comment) \
      if (var == #valname) \
        _##varname = varname##_##valname;

  #define END_DECLARE_ENUM_VARIABLE(varname) \
    }

  #define BEGIN_DECLARE_MASK_VARIABLE(varname) \
    var = CATCDSGetEnv("CATCDS" #varname); \
    if (!var.isEmpty()) { \
      int m = atoi(var.str()); \
      if (0 <= m && m < 2*(varname##_##Limit-1)) \
        _##varname = (CATCDS##varname)m;

  #define DECLARE_MASK_BIT(varname, bit, def, valname, comment)

  #define END_DECLARE_MASK_VARIABLE(varname) \
    }

#endif
