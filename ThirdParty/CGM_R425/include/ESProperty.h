/**
@file

@COPYRIGHT

@author Damien Gleizes
@author Julien Vouillaume
@author Francois Dujardin
*/


#ifndef __ESProperty_h
#define __ESProperty_h

//ES
#include "ESKernelLib.h"
#include "ESType.h"
#include "ESSignature.h"
#include "ES_internals.h"

namespace ES {

	/**
	Class describing a ES Property
	*/
	class ESKERNEL_API Property {

		public:

			/**
			Copy constructor
			*/
			Property(const Property& iProperty);

			/**
			Destructor
			*/
			virtual ~Property();
			
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
			Property& operator=(const Property& iProperty);
			
			/**
			Test weather the property points to a constructed property implementation. Property can be seen as Ptr to a property implementation
			*/
			bool IsValued() const;

		public:
		
			/**
			INTROSPECTION
			*/
			
			/**
			Get the type from which the property comes
			*/
			ES::Type GetOwnerType() const;
			
			/**
			Get the property type
			*/
			ES::Type GetType() const;
			
			/**
			Get the property name
			*/
			CATUnicodeString GetName() const;
		
			/**
			Get the getter signature
			*/
			Signature GetGetter() const;
		
			/**
			Get the setter signature
			*/
			Signature GetSetter() const;

			CATUnicodeString GetNLSKey() const;

		public:
			
			/**
			MODIFICATION
			*/
			
			void SetNLSKey(const char* iKey);


			void SetEditFlags( unsigned int iFlags);

			unsigned int GetEditFlags();

		protected:

			/**
			*/
			ES::World* m_World;

			/**
			Internal
			*/
			ESPROPERTY_INTERNAL_DEFINITION
	};

}

#endif //__ESProperty_h
