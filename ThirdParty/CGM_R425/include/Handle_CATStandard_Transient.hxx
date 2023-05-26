#ifndef _Handle_CATStandard_Transient_HeaderFile
#define _Handle_CATStandard_Transient_HeaderFile

#ifndef _CATStandard_Macro_HeaderFile
#include "CATStandard_Macro.hxx"
#endif
#ifndef _CATStandard_PrimitiveTypes_HeaderFile
#include "CATStandard_PrimitiveTypes.hxx"
#endif
#ifndef _CATStandard_Transient_proto_HeaderFile
#include "CATStandard_Transient_proto.hxx"
#endif

#ifndef UndefinedHandleAddress 
#ifdef DECOSF1
#define UndefinedHandleAddress ((CATStandard_Transient *) 0xfefdfefdfefd0000)
#else
#define UndefinedHandleAddress ((CATStandard_Transient *) CATINT32ToPtr(0xfefd0000))
#endif
#endif

class CATStandard_Transient;
class Handle_CATStandard_Type;

#include "SysCascade.h"

ExportedBySysCascade  CATStandard_Integer HashCode(const Handle(CATStandard_Transient)& ,const CATStandard_Integer);

class Handle(CATStandard_Transient)
 {
   private:

    CATStandard_Transient *entity;

    ExportedBySysCascade  void RaiseNullObject(const CATStandard_CString S) const;

    void BeginScope() const
      {
       if (entity != UndefinedHandleAddress) entity->count++;
      }    

    void EndScope()
      {
       if (entity != UndefinedHandleAddress) 
         {
          entity->count--;
          if (entity->count == 0) {
	    entity->Delete();
	    entity = UndefinedHandleAddress ;
	  }
	}
      }


   public:

    Handle(CATStandard_Transient)()
      {
       entity = UndefinedHandleAddress ;
      }

    Handle(CATStandard_Transient)(const Handle(CATStandard_Transient)& aTid) 
      {
       entity = aTid.entity;
       BeginScope();
      } 

    Handle(CATStandard_Transient)(const CATStandard_Transient *anItem)
      {
       if (!anItem)
           entity = UndefinedHandleAddress ;
       else {
	 entity = (CATStandard_Transient *)anItem;
	 BeginScope();
       }
      }

    // ExportedBySysCascade  void Dump(CATStandard_OStream& out) const;

    ExportedBySysCascade  ~Handle(CATStandard_Transient)();

    // ExportedBySysCascade  void  ShallowDump(CATStandard_OStream&) const;
     
    CATStandard_Boolean IsImmutable() const {
      return(CATStandard_False);
    };

    void SetImmutable() {};

    int operator==(const Handle(CATStandard_Transient)& right) const
      {
       return entity == right.entity;
      }

    int operator==(const CATStandard_Transient *right) const
      {
       return entity == (CATStandard_Transient *)right;
      }

    friend int operator==(const CATStandard_Transient *left, const Handle(CATStandard_Transient)& right)
      {
       return left == right.entity;
      }

    int operator!=(const Handle(CATStandard_Transient)& right) const
      {
       return entity != right.entity;
      }

    int operator!=(const CATStandard_Transient *right) const
      {
       return entity != right;
      }

    friend int operator!=(const CATStandard_Transient *left, const Handle(CATStandard_Transient)& right)
      {
       return left != right.entity;
      }

    void Nullify()
      {
       EndScope();
       entity =  UndefinedHandleAddress ;
      }

    CATStandard_Boolean IsNull() const
      {
       return entity == UndefinedHandleAddress ;
      } 

   protected:

    CATStandard_Transient* Access() const
      {
       return entity;
      } 

    CATStandard_Transient* ControlAccess() const
      {
//       NullObject_Raise_if(!entity,"");
       return entity;
      } 

    void Assign(const CATStandard_Transient *anItem)
      {
       EndScope();
       if (!anItem)
           entity = UndefinedHandleAddress ;
       else {
	 entity = (CATStandard_Transient *)anItem;
	 BeginScope();
       }
      }


  public:

   operator CATStandard_Transient*()
     {
       return Access();
     }


   ExportedBySysCascade  Handle(CATStandard_Transient)& operator=(const Handle(CATStandard_Transient)& aHandle);
   ExportedBySysCascade  Handle(CATStandard_Transient)& operator=(const CATStandard_Transient* anItem);

   CATStandard_Transient* operator->() 
     {
      return ControlAccess();
     }

   CATStandard_Transient* operator->() const
     {
      return ControlAccess();
     }

   CATStandard_Transient& operator*()
     {
      return *(ControlAccess());
     }

   const CATStandard_Transient& operator*() const
     {
      return *(ControlAccess());
     }

   ExportedBySysCascade  static const Handle(CATStandard_Transient) DownCast(const Handle(CATStandard_Transient)& AnObject);

   //friend void ShallowDump(const Handle_CATStandard_Transient&,CATStandard_OStream&);

 };

class CATStandard_Type;

#endif
