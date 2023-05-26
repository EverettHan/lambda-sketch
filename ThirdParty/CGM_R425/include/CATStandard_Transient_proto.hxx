// AMR le 09/11/01 : pour la migration compilateur Aix CXR8
// PMG le 05/11/10 : pour la migration compilateur MacOSX 4.2.1
// PMG le 14/08/17 : jeton inconsitent dll

#ifndef _CATStandard_Transient_proto_HeaderFile
#define _CATStandard_Transient_proto_HeaderFile

#ifndef _CATStandard_Macro_HeaderFile
# include <CATStandard_Macro.hxx>
#endif  // _CATStandard_Macro_HeaderFile

#if     !defined No_Exception && !defined No_CATStandard_NullObject
#define NullObject_Raise_if(COND,MSG) if(COND) RaiseNullObject(MSG)
#else
#define NullObject_Raise_if(COND,MSG)
#endif  

class Handle_CATStandard_Transient;
class CATStandard_Type;
class Handle_CATStandard_Type;
class CATStandard_Type;
#if defined(_AIX_SOURCE) || defined(_LINUX_SOURCE) || defined (_DARWIN_SOURCE) || defined (_MOBILE_SOURCE)
  extern ExportedBySysCascade  Handle_CATStandard_Type& CATStandard_Transient_Type_();
#endif

#include "SysCascade.h"

class ExportedBySysCascade CATStandard_Transient
{
  //---- uses the friend CATStandard_Transient class
  friend ExportedBySysCascade  Handle_CATStandard_Type& CATStandard_Transient_Type_();
  friend class Handle(CATStandard_Transient);

 public:

 /* ExportedBySysCascade*/  virtual Handle_CATStandard_Transient This() const;
//  virtual void FieldIterator(CATStandard_FieldIterator&) const;
  /*ExportedBySysCascade */ virtual void Delete() const;
  /*ExportedBySysCascade */ virtual ~CATStandard_Transient();

         /* ExportedBySysCascade */ CATStandard_Transient& operator= (const CATStandard_Transient&);
          CATStandard_Transient() : count(0) {};
          CATStandard_Transient(const CATStandard_Transient&){};
 /* ExportedBySysCascade*/  virtual const Handle_CATStandard_Type& DynamicType() const;
  /*ExportedBySysCascade*/  virtual CATStandard_Boolean IsKind(const Handle_CATStandard_Type&)const;
        /*  ExportedBySysCascade*/  CATStandard_Boolean IsInstance(const Handle_CATStandard_Type&)const;  
  /*ExportedBySysCascade */ virtual CATStandard_Integer HashCode(const CATStandard_Integer Upper) const;
  //ExportedBySysCascade  virtual void ShallowDump(CATStandard_OStream& ) const;

 private:

  /*ExportedBySysCascade */ virtual void Initialize();

 private:

  CATStandard_Integer count;
};


#endif 


