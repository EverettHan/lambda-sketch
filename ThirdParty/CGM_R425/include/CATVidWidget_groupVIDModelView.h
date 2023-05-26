/*
 * This header file is not meant to be included by any code.
 *
 * It is only there to be parsed by Doxygen tool to generate the
 * documentation group that aggregates functions used by the VID
 * model view architecture.
 */

#error this file must never be included; doxygen file only.

/**
 * @defgroup groupVidModelView VID Model View architecture
 *
 * The module <b>VID Model View Architecture</b> gathers classes and functions
 * dedicated to manage and display large collection of data items efficiently
 * and easily.
 *
 * @section groupVidModelView_secOverview Overview
 * Model / View architecture provides a way to minimize the degree of dependency
 * between data and how this data is presented to the user. This architecture
 * allows several benefits:
 *   - a greater flexibility to customize the view of displayed items;
 *   - the abstraction between the data sources and the view component by
 *     introducing a new layer called model;
 *   - performance on large collection of data as the view is only built when
 *     needed.
 *
 * This documentation will first focus on the model / view architecture concepts
 * by giving a brief overview of each component separately and then will show
 * how they interact together. Second, the CID model / view components are
 * introduced by highlighting each of their functionalities.
 *
 * @par From Model / View / Controler to Model / View
 * The Model / View architecture is a variant of the well known
 * Model / View / Controler architecture. This architecture divides a program
 * in three main components:
 *   - a model that gathers objects contributing to the application behavior
 *   - a view that is responsible to display a feedback to the user
 *   - a controller that links together the model and the view by reacting to
 *     the user inputs.
 *
 * @par
 * This decoupling targets several goals as:
 *   - increasing flexibility;
 *   - faciliting testing and maintenance.
 *
 * @par
 * On the contrary, the model / view architecture only provides two concepts:
 * on one hand the model and on the other hand the view. The controler is
 * merged into the view component.
 * The major benefit from this architecture is the decoupling between the way
 * that data is stored and the way that data is presented to the user. The
 * user inputs are directly treated by the CID view objects.
 *
 * @par
 * The model is an interface responsible to abstract how the communication
 * between the view and the data is performed. Thus, the model / view
 * architecture can be plug in several different data sources.
 * The view communicates with the model and access through it the data elements
 * it must display. This communication is made using CATVidMdlIndex.
 * A data template describes the way an item of data must be represented on
 * screen.
 *
 * @par
 * Those components communicate with each other using the introspection
 * infrastructure and the events mechanism.
 *
 * @par Model
 * As said above, model is an abstraction on top of the data source to let
 * views being able to extract the data items it needs to display.
 * So, models gathers all classes that inherit from the base interface
 * CATIVidMdl. This interface defines all the member functions useful to
 * the communication between the view and the data source. A model is mainly
 * refered by view classes.
 * This interface doesn't need to hold the data items. It can act like an
 * adaptor to the data source which can be a database, a file, or whatever
 * data structure in memory.
 * One goal of the CATIVidMdl interface is to be able to manage a wide variety
 * of data sources like table based model, list based model and tree based model.
 * The abstraction needed to manage all of this different data sources is
 * encapsulated into the CATVidMdlIndex class.
 *
 * @par
 * CID offers already some implementation of basic models with the
 * CATVidMdlStandardList and CATVidMdlStandardTree (however view classes for
 * tree are not yet available) classes that allow you to build quickly a 
 * simple model of list or tree.
 * To implement your own model, you can directly implement the CATIVidMdl
 * interface (using the CATVidMdlAdapter adapter class) or prefer subclassing
 * either CATVidMdlListAdapter or CATVidMdlTreeAdapter depending on the type
 * of model you want to create. Using those two adapters makes more easily
 * the creation of a model because they already implement some features that
 * belong to those types of model.
 *
 * @par Views
 * Several types of view are offered by CID like list based view with the
 * CATVidCtlListView. The CATVidCtlListView is able to display a simple list
 * of items.
 * In addition of this class, CATVidCtlBasicList is a more simple control
 * than CATVidCtlListView to display data composed of an optional icon and a
 * text entry.
 *
 * @par Data Template
 * Data Templates are a piece of sypstyle that allows you to define how a data
 * item will be rendered on screen. It instructs the view part how to display
 * an item when it must be displayed.
 *
 * @section groupVidModelView_secModel Model
 * This section gathers information about the definition of a model and how
 * it behaves.
 * The model is a layer in the Model / View architecture to abstract the way
 * data sources are read by view components. The base interface for model is
 * called CATIVidMdl.
 * To abstract how the data can be stored inside a data source, this interface
 * assumes that items are stored in a hierarchical data structure with tables
 * of items in each node of the structure.
 * Models emit events to any attached views to warn them about data modification.
 *
 * @par Model indexes
 * Model index is responsible to abstract how a piece of information contained
 * into a model is accessed by a view component whatever the data source is.
 * This concept is implemented by the CATVidMdlIndex class.
 * A model index is generally created by a model because the model is the only
 * component that knows how the data sources is structured. Then using the created
 * model index, a view component can access the data item without knowing anything
 * about the underlying data source.
 *
 * @par
 * CATVidMdlIndex is not intented to be stored for a long time. It rather acts
 * like a temporary reference (like a kind of iterator). In fact, when the
 * structure of a model changes, all the model index that point to a piece of
 * information may be invalidated depending on the nature of the modifications
 * that impact the model.
 *
 * @par
 * A CATVidMdlIndex is composed of three main attributes:
 *   - a row number;
 *   - a column number;
 *   - a pointer on the model on which the data item belongs to.
 *
 * @par
 * The row number and the column number allow to locate a particular data item
 * inside a table based model. Such a representation is very convenient to
 * reference data items stored inside a list (where we are only interested in
 * the row parameter) or a table (where the two parameters row number and column
 * number are used).
 * The parent index enhances the previous representation by allowing a model to
 * be hierarchical and addressed the tree based model. Each item can have a
 * parent item and this relation is described using the parent index attribute.
 * In the most general case, an item can be the parent of a table of items.
 * For example, for a simple tree based model, each item can have a parent item
 * and each item can have a list of child items.
 *
 * @section groupVidModelView_secView View
 * The view components in the Model / View architecture extract data items from
 * the model and display them to the user. The view components manipulate chunks
 * of data from the model using model indexes and build the view of each data item
 * using a data template.
 * View components are also responsible to manage navigation between items and
 * selection of items.
 *
 * A view without being associated to a model can't display useful information on
 * screen. So, the view component becomes useful as soon as it is associated to a
 * model filled with some data items.
 *
 * @par Managing the selection of data items
 * The selection of data items displayed by a view is delegated to a selection
 * model. A selection model is a class that implements the interface
 * CATIVidMdlSelectionModel. CID provides a standard implementation for this
 * interface called CATVidMdlSelectionModel. When a view is instantiated,
 * a selection model is automatically created and associated to this view.
 *
 * @section groupVidModelView_secDataTemplate Data Template
 * Data template is a powerfull concept that allows you to specify how your
 * data item must be rendered on screen when displayed by a view.
 * So, a data template is a piece of sypstyle that defines which CID components
 * will be used to render on screen your data items.
 * A data template is mainly defined by four information:
 *   - its name useful to reference it;
 *   - the name of the sypstyle file in which it is writen;
 *   - the hierarchy of CID components used to define the view of the data item;
 *   - the trigger collection to define some behaviors when properties values change.
 *
 * The hierarchy of CID components inside a data template follows the same
 * rules as for classical Template. Thus, this hierarchy can contain only one root.
 * Moreover, like for any classical Template, the trigger collection is optional.
 *
 * The main particularity between a DataTemplate and a Template is that a
 * DataTemplate does not required to be associated to a target like a classical
 * Template.
 *
 * A data template definition looks like to:
 * 
 * @code
 * <DataTemplate syp:name="MyDataTemplateName">
 *    <!-- Define the hierarchy of CID components used to build the view of your data item -->
 *    <CATVidLayGrid>
 *       <CATVidCtlButton syp:name = "myButton" ...>
 *       ...
 *    </CATVidLayGrid>
 *
 *    <!-- Define the optional triggers collection of your data template -->
 *    <CATSYPTriggerCollection>
 *       <CATSYPTrigger Value = "0" Property = "MyProperty">
 *          <CATSYPSetter Property = "MyOtherProperty" Value = "ATextValue" TargetName = "myButton" />
 *       </CATSYPTrigger>
 *    </CATSYPTriggerCollection>
 * </DataTemplate>
 * @endcode
 *
 * The first line starts the definition of the data template using the DataTemplate
 * keyword and specify its name using the syp:name attribute. This attribute
 * is mandatory.
 * Then, the definition of the hierarchy of CID components follows. This part is
 * mandatory. Finally, a trigger collection is defined.
 *
 * The following example will give you a more concrete view on how a data template
 * is a central part of the model / view architecture. Let's say, you want to
 * display a list of data items that represent an identity card. Thus, your data
 * items are made of
 *    - a text property to specify the name of the person;
 *    - an image to show the person;
 *    - a text property to specify the job of the person;
 *    - a text property to specify the office location of the person;
 *    - a text property to specify the phone number of the person;
 *    - a text property to specify the mail of the person.
 * So each data item contains the information about one person.
 *
 * The C++ class that represents your data item could look like the following:
 *
 * @code
 * class CATVidIdentityCard : public CATBaseUnknown
 * {
 *    CATDeclareClass;
 * public:
 *
 * // For clarity, the accessors for the attributes are not represented
 *
 * private:
 *    CATUnicodeString _name;
 *    CATPixelImage * _pImage;
 *    CATUnicodeString _job;
 *    CATUnicodeString _office;
 *    CATUnicodeString _phoneNumber;
 *    CATUnicodeString _mail;
 *
 *    int _selectedFlag;
 * };
 * @endcode
 *
 * The only prerequisite on this class is that it must be introspectable and
 * it must open to introspection the property you want to display by the data
 * template.
 *
 * To make this class introspectable, you can follow this tutorial:
 * http://codewiki/codewiki/index.php/CID_:_Introspection
 *
 * Finally, the sypintro file associated to the previous C++ class is:
 * @code
 * <?xml version="1.0"?>
 * <Class name="CATVidIdentityCard" visibility="Private">
 *    <Includes Type="List">
 *       <File name="CATBasicBoxing.h"/>
 *       <File name="CATPixelImage.h"/>
 *    </Includes>
 *    <Members Type="List">
 *       <BoxProperty type="CATUnicodeString" name="Name"/>
 *       <BoxProperty type="CATUnicodeString" name="Trigram"/>
 *       <Property type="CATPixelImage" name="Image" />
 *       <BoxProperty type="CATUnicodeString" name="Job"/>
 *       <BoxProperty type="CATUnicodeString" name="Office"/>
 *       <BoxProperty type="CATUnicodeString" name="PhoneNumber"/>
 *       <BoxProperty type="CATUnicodeString" name="Mail"/>
 *       <BoxProperty type="int" name="SelectedFlag"/>
 *    </Members>
 * </Class>
 * @endcode
 * This simple sypintro file defines all the introspectable properties exposed
 * by the IdentityCardItem class. Those properties can be use from the data
 * template to display them values.
 *
 * This defines the model of one data item. Now, you can build the view of this
 * item by defining a DataTemplate. Such a Datatemplate could looks like to:
 * @code
 * <DataTemplate syp:name="IdentityCardItemView">
 *    <CATVidLayGrid CellSpacing="1">
 *      <CATVidLayGrid GridWeight="col1=2" CATVidLayGrid.IndexedConstraints="x=0 y=0 attach=RTLB" CellSpacing="5">
 *        <CATVidGPSquare PixelImage="@Image" CATVidLayGrid.IndexedConstraints="x=0 y=0 xSpan=1 ySpan=2 attach=RTLB" RequestedMinimumDimension="51 64" />
 *        <CATVidGPLabel syp:name="NameLabel" Text="@Name" CATVidLayGrid.IndexedConstraints="x=1 y=0 attach=L" TextHeight="16" TextColor="180 180 180 255" CropPolicy="NoCrop"/>
 *        <CATVidGPLabel syp:name="TrigramLabel" Text="@Trigram" CATVidLayGrid.IndexedConstraints="x=1 y=1 attach=L" TextHeight="16" TextColor="180 180 180 255" CropPolicy="NoCrop"/>
 *      </CATVidLayGrid>
 *      <CATVidLayGrid GridWeight="col1=1" CATVidLayGrid.IndexedConstraints="x=0 y=1 attach=RTLB" CellSpacing="3">
 *        <CATVidGPSquare Texture="building.png" RequestedMinimumDimension="16 16" CATVidLayGrid.IndexedConstraints="x=0 y=1 attach=L" />
 *        <CATVidGPLabel syp:name="OfficeLabel" Text="@Office" CATVidLayGrid.IndexedConstraints="x=1 y=1 attach=L" TextHeight="16" TextColor="180 180 180 255" CropPolicy="NoCrop"/>
 *        <CATVidGPSquare Texture="phone.png" RequestedMinimumDimension="16 16" CATVidLayGrid.IndexedConstraints="x=0 y=2 attach=L" />
 *        <CATVidGPLabel syp:name="PhoneLabel" Text="@PhoneNumber" CATVidLayGrid.IndexedConstraints="x=1 y=2 attach=L" TextHeight="16" TextColor="180 180 180 255" CropPolicy="NoCrop"/>
 *        <CATVidGPSquare Texture="at.png" RequestedMinimumDimension="16 16" CATVidLayGrid.IndexedConstraints="x=0 y=3 attach=L" />
 *        <CATVidGPLabel syp:name="MailLabel" Text="@Mail" CATVidLayGrid.IndexedConstraints="x=1 y=3 attach=L" TextHeight="16" TextColor="180 180 180 255" CropPolicy="NoCrop"/>
 *      </CATVidLayGrid>
 *    </CATVidLayGrid>
 *    <CATSYPTriggerCollection>
 *      <CATSYPTrigger Property="SelectedFlag" Value="1">
 *        <CATSYPSetter TargetName="NameLabel" Property="TextColor" Value="255 255 255 255" />
 *        <CATSYPSetter TargetName="TrigramLabel" Property="TextColor" Value="255 255 255 255" />
 *        <CATSYPSetter TargetName="OfficeLabel" Property="TextColor" Value="255 255 255 255" />
 *        <CATSYPSetter TargetName="PhoneLabel" Property="TextColor" Value="255 255 255 255" />
 *        <CATSYPSetter TargetName="MailLabel" Property="TextColor" Value="255 255 255 255" />
 *      </CATSYPTrigger>
 *      <CATSYPTrigger Property="SelectedFlag" Value="0">
 *        <CATSYPSetter TargetName="NameLabel" Property="TextColor" Value="180 180 180 255" />
 *        <CATSYPSetter TargetName="TrigramLabel" Property="TextColor" Value="180 180 180 255" />
 *        <CATSYPSetter TargetName="OfficeLabel" Property="TextColor" Value="180 180 180 255" />
 *        <CATSYPSetter TargetName="PhoneLabel" Property="TextColor" Value="180 180 180 255" />
 *        <CATSYPSetter TargetName="MailLabel" Property="TextColor" Value="180 180 180 255" />
 *      </CATSYPTrigger>
 *    </CATSYPTriggerCollection>
 *  </DataTemplate>
 * @endcode
 *
 * Let's detail each element of this data template. First we declare a
 * DataTemplate using the DataTemplate keyword and associate this new element
 * to the name "IdentityCardItemView". This name will be used to reference the
 * data template by the view component. Note that this data template is not
 * associated to a given C++ class: it can be applied to every C++ classes
 * that expose to introspection the required properties. Those properties are
 * referenced by @[NameOfTheProperty] in the data template: here, the data
 * template requires that the C++ object to which it is associated exposes the
 * following property: "Image", "Name", "Trigram", "Office", "PhoneNumber",
 * "Mail", "SelectedFlag"). Then, we define a hierarchy of CID controls. This
 * hierarchy is made of one root element: a CATVidLayGrid. This CATVidLayGrid
 * contains two child CATVidLayGrid to organize the data. The first CATVidLayGrid
 * displays the image of the person, its name and its trigram. This is done using
 * a CATVidGPSquare for the image, and two CATVidGPLabel for the name and the
 * trigram. The second CATVidLayGrid displays the office, phone number and mail
 * address of the person. In front of each one, an icon is displayed to indicate
 * the type of information. The name of the icon to use is directly indicated
 * into the data template (here, building.png, phone.png and at.png).
 *
 * The data template only defines how your data must be rendered on screen. It doesn't
 * have to care about internal behavior of the view component like the selection
 * for example. The generated view using your data template will then be embedded
 * inside another view that is in charge to handle all the aspects of selection.
 */
