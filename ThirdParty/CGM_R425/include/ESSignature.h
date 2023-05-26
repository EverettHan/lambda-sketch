/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESSignature_h
#define __ESSignature_h

//ES
#include "ESKernelLib.h"
#include "ESType.h"
#include "ESNativeObject.h"
#include "ESFunctionPtr.h"
#include "ES_internals.h"

//CAT
#include "DSYString.h"

namespace ES {
  
  

  /**
  Class describing a ES signature
  */
  class ESKERNEL_API Signature {

    public:

      /**
      Copy constructor
      */
      Signature(const Signature& iSignature);

      /**
      Destructor
      */
      virtual ~Signature();
      
      /**
      Clears the type
      */
      void Clear();

      /**
      Get the world this value came from
      */
      ES::World* GetWorld() const { return m_World; }

      /**
      Affect operator
      */
      Signature& operator=(const Signature& iSignature);
      
      /**
      Test weather the signature points to a constructed signature implementation. Signature can be seen as Ptr to a signature implementation
      */
      bool IsValued() const;
       
    public:
    
      /**
      INTROSPECTION
      */
      
      /**
      Test wether the signature is a class function
      */
      bool IsMethod() const;

      /**
      Test wether the signature is virtual
      */
      bool IsVirtual() const;
      
      /**
      Test wether the signature is static
      */
      bool IsStatic() const;
      
      /**
      Test wether the signature is an emulated method
      */
      bool IsEmulated() const;
      
      /**
      Tells if this signature forward exceptions to ES
      */
      bool IsThrowable() const;
      
      /**
      Tells if this signature forward CAT exceptions to ES
      */
      bool IsCATThrowable() const;

      /**
      Get the owner type of this signature.
      Returns a valued type if this signature is a class function.
      IE: A::B() with 'A' being a Type.
      */
      Type GetOwnerType() const;
      
      /**
      Get the number of arguments
      */
      unsigned int GetArgumentCount() const;
      
      /**
      Get the Type of an argument
      */
      Type GetArgumentType(unsigned int iPosition) const;
      
      /**
      Get the Name of an argument
      */
      CATUnicodeString GetArgumentName(unsigned int iPosition) const;
    
      /**
      Get the return type
      */
      Type GetReturnType() const;
     
      /**
      Get the signature name
      */
      CATUnicodeString GetName() const;

      /**
      Get the signature complete name
      (includes owner type and arguments)
      */
      CATUnicodeString GetCompleteName() const;

      /**
      */
      FunctionPtr GetFunctionPtr() const; 
            
      /**
      */
      FunctionPtr GetReturnValueDestructor();

      /**
      Get the Key from the signature, to retrieve a user defined description (via a CATCatalogMsg for example)
      Unstable API, may be redefined.
      */
      CATUnicodeString GetNLSKey() const;

    public:
      

      enum EditFlags {
        fNone       = 0,
        fReadOnly   = 1 << 0,
        fDontEnum   = 1 << 1,
        fDontDelete = 1 << 2,
        fPropagateFlags= 1 << 3
      };

      /**
      MODIFICATION
      */
      
      /**
      Tells that this signature is responsible of deleting the return value.
      @param the destructor that will be called on the return valued when it will no more referenced in ES
      */
      bool SetReturnValueDestructor(ES::NativeObject::DestructorCallBack iPointer);

      /**
      Tells that this signature is responsible of deleting the return value.
      @param the destructor that will be called on the return valued when it will no more referenced in ES
      */
      bool SetReturnValueDestructor(const ES::FunctionPtr & iPtr);
      
      /**
      Defines this signature as forwarding exceptions to ES
      */
      bool SetThrowable(bool iThrowable = true);
      
      /**
      Defines this signature as forwarding CAT exceptions to ES
      */
      //bool SetCATThrowable(bool iThrowable = true);

      /**
      Set a Key to a signature, to match a user defined description (via a CATCatalogMsg for example)
      Unstable API, may be redefined.
      */
      void SetNLSKey(const char* iKey);

      void SetEditFlags( unsigned int iFlags);

      unsigned int GetEditFlags();
      
    protected:

      /**
      World as Ptr to prevent destroying a World before destroying ES::Signature
      */
      ES::World* m_World;

      /**
      Key 
      */
      CATUnicodeString m_DescriptionKey;

      /**
      Internal
      */
      ESSIGNATURE_INTERNAL_DEFINITION
  };

}

#endif //__ESSignature_h

