#ifndef IVISTEXTUREPTR_H_
#define IVISTEXTUREPTR_H_

#include "vWeakPtr.h"
#include "SGInfra.h"
#include "IVisTexture.h"
#include "VisTextureFactory.h" //Should be removed as an include but will impact applications....

// Unfortunately CATSupport.h forward declares IVisTexturePtr as class (PublicInterfaces)
// So we cannot do: using IVisTexturePtr = VKL::vSmartPtr<IVisTexture>;
using IVisTextureWeakPtr = VKL::vWeakPtr<IVisTexture>;
class ExportedBySGInfra IVisTexturePtr
{
  friend class VisTextureFactoryImpl;
  friend class vRETextureFactory;
  friend class VisTextureFactory;
 
  friend class CATGraphicMaterial;            // To remove after migration

  using Base = VKL::vSmartPtr<IVisTexture>;

public:

  IVisTexturePtr();

  IVisTexturePtr(const IVisTexture* iObjPtr);
  IVisTexturePtr(const IVisTexturePtr & iCopy);
  IVisTexturePtr & operator = (const IVisTexturePtr& rhs);
  IVisTexturePtr(IVisTexturePtr && iMove);
  IVisTexturePtr & operator = (IVisTexturePtr&& iRhs);
  IVisTexturePtr(const Base& iCopy);
  IVisTexturePtr& operator = (const Base& rhs);
  IVisTexturePtr(Base&& iMove);
  IVisTexturePtr& operator = (Base&& iRhs);
  ~IVisTexturePtr();
  explicit operator bool() const;
  operator IVisTexture *() const;
  IVisTexturePtr& operator = (IVisTexture* iPtr);
  
  bool operator == (const IVisTexturePtr& rhs) const;
  bool operator == (const Base& rhs) const;
  bool operator == (std::nullptr_t iPtr) const;
  inline bool operator != (const IVisTexturePtr& rhs) const { return !(*this == rhs); }
  inline bool operator != (const Base& rhs) const { return !(*this == rhs); }
  inline bool operator != (std::nullptr_t rhs) const { return !(*this == rhs); }

  inline IVisTexture* Get() const
  {
    return impl.Ptr();
  }

  template <typename Ty>
  inline static Ty* CastTo(IVisTexturePtr& iPtr)
  {
    return static_cast<Ty*>(iPtr.Get());
  }

  template <typename Ty>
  inline static const Ty* CastTo(const IVisTexturePtr& iPtr)
  {
    return static_cast<const Ty*>(iPtr.Get());
  }
  inline const IVisTexture* operator->() const { return Get(); }
  inline IVisTexture* operator->() { return Get(); }
  inline IVisTexture const& operator*() const { return *Get(); }
  inline IVisTexture& operator*() { return *Get(); }

  const static IVisTexturePtr kNullPtr;
private:
  // Hide impl because Linux will have link issues when it tries to link with VisREKernel
  VKL::vSmartPtr<IVisTexture> impl;
};





#endif //IVISTEXTUREPTR_VAR_H_
