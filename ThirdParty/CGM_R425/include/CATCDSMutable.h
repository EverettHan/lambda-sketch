#ifndef CATCDSMutable_h
#define CATCDSMutable_h

#ifdef _SUNOS_SOURCE
#define CATCDSMutable
#define MUTABLE_CAST(Type, Obj) const_cast<Type>(Obj)
#else
#define CATCDSMutable mutable
#define MUTABLE_CAST(Type, Obj) Obj
#endif

#endif
