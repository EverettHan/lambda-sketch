#ifndef CATCkeTypeQualification_h
#define CATCkeTypeQualification_h

// COPYRIGHT Dassault Systemes 2009

#include "CATLifSpecs.h" 

// This namespace contains the informations that are used to qualify a type

// We differentiate two typing system
// - V1=Former typing. Objects were created with a a custo type or with a modeler type directly
// - V2=Unified typing. Objects are created with specialized customer types, or applicative type. Objects can be extended with customer extensions, or deployment extensions


class ExportedByCATLifSpecs CATCkeTypeQualification
{
public:

  // Nature of the type
  //	-PLM types are proposing the 4 different natures
  //	-Rep types are proposing only Primary and Secondary
  enum Nature { Primary,       // Type given at creation, cannot be changed (default value of a type)
			    Secondary,     // Type that has been added afterwards (corresponds to an extension type)
				Custo,		   // Type that corresponds to the deployment axis (V1 custo type)
				Deployment };  // Type that corresponds to the deployment axis (V2 deployment extensions)

  // Origin of the type
  //	-PLM types are proposing the 4 different natures
  //	-Rep types are proposing only Modeler, Root and Customer
  enum Origin { Modeler,       // Type defined by a modeler (can be nature=primary or secondary). Default value
	            Discipline,    // Type defined by a modeler as a discipline (can be nature=primary or secondary)
				Customer,      // Type defined by the customer (can be nature = primary, secondary, or custo, or Deployment): 
				Root };        // Type defined as an abstraction that is derived by modelers (can be nature=primary or secondary)


  // Location of the type
  enum Location { PLM,					// Type defined for a PLM object, saved in the database, available on 3D Live client, Blue and server
	              Representation,		// Type defined for an object inside a representation, available on Blue layer (authoring only)
				  Occurrence,			// Type for an object that only exist in a session and that corresponds to an occurrence
				  Index,				// Type used for indexes, stored in Index server
				  Contract,				// Type that is a pure contract: can be shared between different objects
				  Transcient,			// Type that is transcient
				  TranscientServerOnly,	// Type that is transcient but only on the server
  				  UserFeature   };		// Type that is defined by a user feature...


};


#endif // CATCkeTypeQualification_h

