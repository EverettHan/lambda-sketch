#ifndef CSIExecutionGraphBuilderType_H
#define CSIExecutionGraphBuilderType_H

#include "CSICommandBinderModule.h"

#include <string>

namespace JSON
{
  class JOStream;
}

namespace CSI
{
  namespace ExecutionGraph
  {
    namespace Builder
    {
      class Optional;
      class OptionalImpl;
      class TypeImpl;

      class ExportedByCSIBinderModule Type
      {
      public:
        Type();
        Type(const Type&);
        Type& operator=(const Type&);
        Type(Type&&) noexcept;
        Type& operator=(Type&&) noexcept;
        ~Type();

        enum EBasicType
        {
          eUndefined = -1,
          eBoolean = 0,
          eInt8,
          eUint8,
          eInt16,
          eUint16,
          eInt32,
          eUint32,
          eInt64,
          eUint64,
          eFloat,
          eDouble,
          eString,
          eBuffer,
        };

        class ExportedByCSIBinderModule Optional
        {
        public:
          Optional(bool isOptional);
          Optional(const char* defaultValue);
          Optional(JSON::JOStream& defaultValue);
          Optional(std::string defaultValue);

          Optional(const Optional&);
          Optional& operator=(const Optional&);
          Optional(Optional&&) noexcept;
          Optional& operator=(Optional&&) noexcept;
          ~Optional();

        private:
          friend OptionalImpl& getImpl(const Optional&);
          OptionalImpl* impl_;
        };

        Type& AddBasicProperty(std::string name, EBasicType basicType, std::string desc, Optional optional = Optional(false));
        Type& AddBasicArrayProperty(std::string name, EBasicType basicType, std::string desc, Optional optional = Optional(false));

        Type& AddTypeProperty(std::string name, std::string registeredType, std::string desc, Optional optional = Optional(false));
        Type& AddTypeArrayProperty(std::string name, std::string registeredType, std::string desc, Optional optional = Optional(false));

        Type& AddParametersProperty(std::string name, Type inlineType, std::string desc, Optional optional = Optional(false));
        Type& AddParametersArrayProperty(std::string name, Type inlineType, std::string desc, Optional optional = Optional(false));

      private:
        friend TypeImpl& getImpl(const Type&);
        TypeImpl* impl_;
      };
    }
  }
}

#endif
