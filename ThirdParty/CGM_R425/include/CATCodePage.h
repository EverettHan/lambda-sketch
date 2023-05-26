/* -*-C++-*- */
// COPYRIGHT DASSAULT SYSTEMES 1996
//================================================================================================
//
// CATCodePage :
// Class for code page management
//
//================================================================================================
//
// Considerations of usage:
//   This class provides services to convert strings: 
//       - from a standard code page to Unicode 10646
//       - from Unicode 10646 to a standard code page
//       - from Unicode 10646 to UTF-8
//       - from UTF-8 to Unicode 10646
//
//================================================================================================
//
// February 96   Creation                                        O Fresse
//
//================================================================================================

#ifndef CATCodePage_H
#define CATCodePage_H
#include "NS0S3STR.h"
#include "CATStrlen32.h"
#ifndef _WINDOWS_SOURCE
#ifndef _ANDROID_SOURCE
#include <iconv.h>
#else
#include "DSYiconv.h"
#endif
#endif
#include <string.h>
#include "CATI18NTypes.h"
#include "CATString.h"
#include "CATBoolean.h"
#include "IUnknown.h"
#include "CATUnicodeChar.h"

class DSYSysCodePage;

/**
 * Code page class.
 * <b>Role</b>: processing a code page.</br>
 * A character is associated to a Unicode code (see @href CATUnicodeString ). A code page contains a set of rules that
 * establish a character set, and it contains and the relationship between the characters of the set and their coded
 * representation. A code page also contains a table of (bytes of the code,character) couples.
 * <p><b>Example</b>: The ISO 8859-1 is a code page for which the coded representation of each character of the character
 * set takes one byte. Here is the ISO 8859-1 code page,
 * <ul>
 * <li>the coded representation is shown in hexadecimal</li>
 * <li>the character appears through its Unicode character name</li>
 * </ul>
 * <table>
 * <tr><td>00</td><td>NULL</td></tr>
 * <tr><td>01</td><td>START OF HEADING</td></tr>
 * <tr><td>02</td><td>START OF TEXT</td><td>82</td><td>BREAK PERMITTED HERE</td></tr>
 * <tr><td>03</td><td>END OF TEXT</td><td>83</td><td>NO BREAK HERE</td></tr>
 * <tr><td>04</td><td>END OF TRANSMISSION</td></tr>
 * <tr><td>05</td><td>ENQUIRY</td><td>85</td><td>NEXT LINE</td></tr>
 * <tr><td>06</td><td>ACKNOWLEDGE</td><td>86</td><td>START OF SELECTED AREA</td></tr>
 * <tr><td>07</td><td>BELL</td><td>87</td><td>END OF SELECTED AREA</td></tr>
 * <tr><td>08</td><td>BACKSPACE</td><td>88</td><td>CHARACTER TABULATION SET</td></tr>
 * <tr><td>09</td><td>CHARACTER TABULATION</td><td>89</td><td>CHARACTER TABULATION WITH JUSTIFICATION</td></tr>
 * <tr><td>0A</td><td>LINE FEED</td><td>8A</td><td>LINE TABULATION SET</td></tr>
 * <tr><td>0B</td><td>LINE TABULATION</td><td>8B</td><td>PARTIAL LINE FORWARD</td></tr>
 * <tr><td>0C</td><td>FORM FEED</td><td>8C</td><td>PARTIAL LINE BACKWARD</td></tr>
 * <tr><td>0D</td><td>CARRIAGE RETURN</td><td>8D</td><td>REVERSE LINE FEED</td></tr>
 * <tr><td>0E</td><td>SHIFT OUT</td><td>8E</td><td>SINGLE SHIFT TWO</td></tr>
 * <tr><td>0F</td><td>SHIFT IN</td><td>8F</td><td>SINGLE SHIFT THREE</td></tr>
 * <tr><td>10</td><td>DATA LINK ESCAPE</td><td>90</td><td>DEVICE CONTROL STRING</td></tr>
 * <tr><td>11</td><td>DEVICE CONTROL ONE</td><td>91</td><td>PRIVATE USE ONE</td></tr>
 * <tr><td>12</td><td>DEVICE CONTROL TWO</td><td>92</td><td>PRIVATE USE TWO</td></tr>
 * <tr><td>13</td><td>DEVICE CONTROL THREE</td><td>93</td><td>SET TRANSMIT STATE</td></tr>
 * <tr><td>14</td><td>DEVICE CONTROL FOUR</td><td>94</td><td>CANCEL CHARACTER</td></tr>
 * <tr><td>15</td><td>NEGATIVE ACKNOWLEDGE</td><td>95</td><td>MESSAGE WAITING</td></tr>
 * <tr><td>16</td><td>SYNCHRONOUS IDLE</td><td>96</td><td>START OF GUARDED AREA</td></tr>
 * <tr><td>17</td><td>END OF TRANSMISSION BLOCK</td><td>97</td><td>END OF GUARDED AREA</td></tr>
 * <tr><td>18</td><td>CANCEL</td><td>98</td><td>START OF STRING</td></tr>
 * <tr><td>19</td><td>END OF MEDIUM</td></tr>
 * <tr><td>1A</td><td>SUBSTITUTE</td><td>9A</td><td>SINGLE CHARACTER INTRODUCER</td></tr>
 * <tr><td>1B</td><td>ESCAPE</td><td>9B</td><td>CONTROL SEQUENCE INTRODUCER</td></tr>
 * <tr><td>1C</td><td>INFORMATION SEPARATOR FOUR</td><td>9C</td><td>STRING TERMINATOR</td></tr>
 * <tr><td>1D</td><td>INFORMATION SEPARATOR THREE</td><td>9D</td><td>OPERATING SYSTEM COMMAND</td></tr>
 * <tr><td>1E</td><td>INFORMATION SEPARATOR TWO</td><td>9E</td><td>PRIVACY MESSAGE</td></tr>
 * <tr><td>1F</td><td>INFORMATION SEPARATOR ONE</td><td>9F</td><td>APPLICATION PROGRAM COMMAND</td></tr>
 * <tr><td>20</td><td>SPACE</td><td>A0</td><td>NO-BREAK SPACE</td></tr>
 * <tr><td>21</td><td>EXCLAMATION MARK</td><td>A1</td><td>INVERTED EXCLAMATION MARK</td></tr>
 * <tr><td>22</td><td>QUOTATION MARK</td><td>A2</td><td>CENT SIGN</td></tr>
 * <tr><td>23</td><td>NUMBER SIGN</td><td>A3</td><td>POUND SIGN</td></tr>
 * <tr><td>24</td><td>DOLLAR SIGN</td><td>A4</td><td>CURRENCY SIGN</td></tr>
 * <tr><td>25</td><td>PERCENT SIGN</td><td>A5</td><td>YEN SIGN</td></tr>
 * <tr><td>26</td><td>AMPERSAND</td><td>A6</td><td>BROKEN BAR</td></tr>
 * <tr><td>27</td><td>APOSTROPHE</td><td>A7</td><td>SECTION SIGN</td></tr>
 * <tr><td>28</td><td>LEFT PARENTHESIS</td><td>A8</td><td>DIAERESIS</td></tr>
 * <tr><td>29</td><td>RIGHT PARENTHESIS</td><td>A9</td><td>COPYRIGHT SIGN</td></tr>
 * <tr><td>2A</td><td>ASTERIX</td><td>AA</td><td>FEMININE ORDINAL INDICATOR</td></tr>
 * <tr><td>2B</td><td>PLUS SIGN</td><td>AB</td><td>LEFT-POINTING DOUBLE ANGLE QUOTAT. MARK</td></tr>
 * <tr><td>2C</td><td>COMMA</td><td>AC</td><td>NOT SIGN</td></tr>
 * <tr><td>2D</td><td>HYPHEN-MINUS</td><td>AD</td><td>SOFT HYPHEN</td></tr>
 * <tr><td>2E</td><td>FULL STOP</td><td>AE</td><td>REGISTERED SIGN</td></tr>
 * <tr><td>2F</td><td>SOLIDUS</td><td>AF</td><td>MACRON</td></tr>
 * <tr><td>30</td><td>DIGIT ZERO</td><td>B0</td><td>DEGREE SIGN</td></tr>
 * <tr><td>31</td><td>DIGIT ONE</td><td>B1</td><td>PLUS-MINUS SIGN</td></tr>
 * <tr><td>32</td><td>DIGIT TWO</td><td>B2</td><td>SUPERSCRIPT TWO</td></tr>
 * <tr><td>33</td><td>DIGIT THREE</td><td>B3</td><td>SUPERSCRIPT THREE</td></tr>
 * <tr><td>34</td><td>DIGIT FOUR</td><td>B4</td><td>ACUTE ACCENT</td></tr>
 * <tr><td>35</td><td>DIGIT FIVE</td><td>B5</td><td>MICRO SIGN</td></tr>
 * <tr><td>36</td><td>DIGIT SIX</td><td>B6</td><td>PILCROW SIGN</td></tr>
 * <tr><td>37</td><td>DIGIT SEVEN</td><td>B7</td><td>MIDDLE DOT</td></tr>
 * <tr><td>38</td><td>DIGIT EIGHT</td><td>B8</td><td>CEDILLA</td></tr>
 * <tr><td>39</td><td>DIGIT NINE</td><td>B9</td><td>SUPERSCRIPT ONE</td></tr>
 * <tr><td>3A</td><td>COLON</td><td>BA</td><td>MASCULINE ORDINAL INDICATOR</td></tr>
 * <tr><td>3B</td><td>SEMICOLON</td><td>BB</td><td>RIGHT-POINTING DOUBLE ANGLE QUOTAT. MARK</td></tr>
 * <tr><td>3C</td><td>LESS-THAN SIGN</td><td>BC</td><td>VULGAR FRACTION ONE QUARTER</td></tr>
 * <tr><td>3D</td><td>EQUALS SIGN</td><td>BD</td><td>VULGAR FRACTION ONE HALF</td></tr>
 * <tr><td>3E</td><td>GREATER-THAN SIGN</td><td>BE</td><td>VULGAR FRACTION THREE QUARTERS</td></tr>
 * <tr><td>3F</td><td>QUESTION MARK</td><td>BF</td><td>INVERTED QUESTION MARK</td></tr>
 * <tr><td>40</td><td>COMMERCIAL AT</td><td>C0</td><td>LATIN CAPITAL LETTER A WITH GRAVE</td></tr>
 * <tr><td>41</td><td>LATIN CAPITAL LETTER A</td><td>C1</td><td>LATIN CAPITAL LETTER A WITH ACUTE</td></tr>
 * <tr><td>42</td><td>LATIN CAPITAL LETTER B</td><td>C2</td><td>LATIN CAPITAL LETTER A WITH CIRCUMFLEX</td></tr>
 * <tr><td>43</td><td>LATIN CAPITAL LETTER C</td><td>C3</td><td>LATIN CAPITAL LETTER A WITH TILDE</td></tr>
 * <tr><td>44</td><td>LATIN CAPITAL LETTER D</td><td>C4</td><td>LATIN CAPITAL LETTER A WITH DIAERESIS</td></tr>
 * <tr><td>45</td><td>LATIN CAPITAL LETTER E</td><td>C5</td><td>LATIN CAPITAL LETTER A WITH RING ABOVE</td></tr>
 * <tr><td>46</td><td>LATIN CAPITAL LETTER F</td><td>C6</td><td>LATIN CAPITAL LIGATURE AE</td></tr>
 * <tr><td>47</td><td>LATIN CAPITAL LETTER G</td><td>C7</td><td>LATIN CAPITAL LETTER C WITH CEDILLA</td></tr>
 * <tr><td>48</td><td>LATIN CAPITAL LETTER H</td><td>C8</td><td>LATIN CAPITAL LETTER E WITH GRAVE</td></tr>
 * <tr><td>49</td><td>LATIN CAPITAL LETTER I</td><td>C9</td><td>LATIN CAPITAL LETTER E WITH ACUTE</td></tr>
 * <tr><td>4A</td><td>LATIN CAPITAL LETTER J</td><td>CA</td><td>LATIN CAPITAL LETTER E WITH CIRCUMFLEX</td></tr>
 * <tr><td>4B</td><td>LATIN CAPITAL LETTER K</td><td>CB</td><td>LATIN CAPITAL LETTER E WITH DIAERESIS</td></tr>
 * <tr><td>4C</td><td>LATIN CAPITAL LETTER L</td><td>CC</td><td>LATIN CAPITAL LETTER I WITH GRAVE</td></tr>
 * <tr><td>4D</td><td>LATIN CAPITAL LETTER M</td><td>CD</td><td>LATIN CAPITAL LETTER I WITH ACUTE</td></tr>
 * <tr><td>4E</td><td>LATIN CAPITAL LETTER N</td><td>CE</td><td>LATIN CAPITAL LETTER I WITH CIRCUMFLEX</td></tr>
 * <tr><td>4F</td><td>LATIN CAPITAL LETTER O</td><td>CF</td><td>LATIN CAPITAL LETTER I WITH DIAERESIS</td></tr>
 * <tr><td>50</td><td>LATIN CAPITAL LETTER P</td><td>D0</td><td>LATIN CAPITAL LETTER ETH (Icelandic)</td></tr>
 * <tr><td>51</td><td>LATIN CAPITAL LETTER Q</td><td>D1</td><td>LATIN CAPITAL LETTER N WITH TILDE</td></tr>
 * <tr><td>52</td><td>LATIN CAPITAL LETTER R</td><td>D2</td><td>LATIN CAPITAL LETTER O WITH GRAVE</td></tr>
 * <tr><td>53</td><td>LATIN CAPITAL LETTER S</td><td>D3</td><td>LATIN CAPITAL LETTER O WITH ACUTE</td></tr>
 * <tr><td>54</td><td>LATIN CAPITAL LETTER T</td><td>D4</td><td>LATIN CAPITAL LETTER O WITH CIRCUMFLEX</td></tr>
 * <tr><td>55</td><td>LATIN CAPITAL LETTER U</td><td>D5</td><td>LATIN CAPITAL LETTER O WITH TILDE</td></tr>
 * <tr><td>56</td><td>LATIN CAPITAL LETTER V</td><td>D6</td><td>LATIN CAPITAL LETTER O WITH DIAERESIS</td></tr>
 * <tr><td>57</td><td>LATIN CAPITAL LETTER W</td><td>D7</td><td>MULTIPLICATION SIGN</td></tr>
 * <tr><td>58</td><td>LATIN CAPITAL LETTER X</td><td>D8</td><td>LATIN CAPITAL LETTER O WITH STROKE</td></tr>
 * <tr><td>59</td><td>LATIN CAPITAL LETTER Y</td><td>D9</td><td>LATIN CAPITAL LETTER U WITH GRAVE</td></tr>
 * <tr><td>5A</td><td>LATIN CAPITAL LETTER Z</td><td>DA</td><td>LATIN CAPITAL LETTER U WITH ACUTE</td></tr>
 * <tr><td>5B</td><td>LEFT SQUARE BRACKET</td><td>DB</td><td>LATIN CAPITAL LETTER U WITH CIRCUMFLEX</td></tr>
 * <tr><td>5C</td><td>REVERSE SOLIDUS</td><td>DC</td><td>LATIN CAPITAL LETTER U WITH DIAERESIS</td></tr>
 * <tr><td>5D</td><td>RIGHT SQUARE BRACKET</td><td>DD</td><td>LATIN CAPITAL LETTER Y WITH ACUTE</td></tr>
 * <tr><td>5E</td><td>CIRCUMFLEX ACCENT</td><td>DE</td><td>LATIN CAPITAL LETTER THORN (Icelandic)</td></tr>
 * <tr><td>5F</td><td>LOW LINE</td><td>DF</td><td>LATIN SMALL LETTER SHARP S</td></tr>
 * <tr><td>60</td><td>GRAVE ACCENT</td><td>E0</td><td>LATIN SMALL LETTER A WITH GRAVE</td></tr>
 * <tr><td>61</td><td>LATIN SMALL LETTER A</td><td>E1</td><td>LATIN SMALL LETTER A WITH ACUTE</td></tr>
 * <tr><td>62</td><td>LATIN SMALL LETTER B</td><td>E2</td><td>LATIN SMALL LETTER A WITH CIRCUMFLEX</td></tr>
 * <tr><td>63</td><td>LATIN SMALL LETTER C</td><td>E3</td><td>LATIN SMALL LETTER A WITH TILDE</td></tr>
 * <tr><td>64</td><td>LATIN SMALL LETTER D</td><td>E4</td><td>LATIN SMALL LETTER A WITH DIAERESIS</td></tr>
 * <tr><td>65</td><td>LATIN SMALL LETTER E</td><td>E5</td><td>LATIN SMALL LETTER A WITH RING ABOVE</td></tr>
 * <tr><td>66</td><td>LATIN SMALL LETTER F</td><td>E6</td><td>LATIN SMALL LIGATURE AE</td></tr>
 * <tr><td>67</td><td>LATIN SMALL LETTER G</td><td>E7</td><td>LATIN SMALL LETTER C WITH CEDILLA</td></tr>
 * <tr><td>68</td><td>LATIN SMALL LETTER H</td><td>E8</td><td>LATIN SMALL LETTER E WITH GRAVE</td></tr>
 * <tr><td>69</td><td>LATIN SMALL LETTER I</td><td>E9</td><td>LATIN SMALL LETTER E WITH ACUTE</td></tr>
 * <tr><td>6A</td><td>LATIN SMALL LETTER J</td><td>EA</td><td>LATIN SMALL LETTER E WITH CIRCUMFLEX</td></tr>
 * <tr><td>6B</td><td>LATIN SMALL LETTER K</td><td>EB</td><td>LATIN SMALL LETTER E WITH DIAERESIS</td></tr>
 * <tr><td>6C</td><td>LATIN SMALL LETTER L</td><td>EC</td><td>LATIN SMALL LETTER I WITH GRAVE</td></tr>
 * <tr><td>6D</td><td>LATIN SMALL LETTER M</td><td>ED</td><td>LATIN SMALL LETTER I WITH ACUTE</td></tr>
 * <tr><td>6E</td><td>LATIN SMALL LETTER N</td><td>EE</td><td>LATIN SMALL LETTER I WITH CIRCUMFLEX</td></tr>
 * <tr><td>6F</td><td>LATIN SMALL LETTER O</td><td>EF</td><td>LATIN SMALL LETTER I WITH DIAERESIS</td></tr>
 * <tr><td>70</td><td>LATIN SMALL LETTER P</td><td>F0</td><td>LATIN SMALL LETTER ETH (Icelandic)</td></tr>
 * <tr><td>71</td><td>LATIN SMALL LETTER Q</td><td>F1</td><td>LATIN SMALL LETTER N WITH TILDE</td></tr>
 * <tr><td>72</td><td>LATIN SMALL LETTER R</td><td>F2</td><td>LATIN SMALL LETTER O WITH GRAVE</td></tr>
 * <tr><td>73</td><td>LATIN SMALL LETTER S</td><td>F3</td><td>LATIN SMALL LETTER O WITH ACUTE</td></tr>
 * <tr><td>74</td><td>LATIN SMALL LETTER T</td><td>F4</td><td>LATIN SMALL LETTER O WITH CIRCUMFLEX</td></tr>
 * <tr><td>75</td><td>LATIN SMALL LETTER U</td><td>F5</td><td>LATIN SMALL LETTER O WITH TILDE</td></tr>
 * <tr><td>76</td><td>LATIN SMALL LETTER V</td><td>F6</td><td>LATIN SMALL LETTER O WITH DIAERESIS</td></tr>
 * <tr><td>77</td><td>LATIN SMALL LETTER W</td><td>F7</td><td>DIVISION SIGN</td></tr>
 * <tr><td>78</td><td>LATIN SMALL LETTER X</td><td>F8</td><td>LATIN SMALL LETTER O WITH STROKE</td></tr>
 * <tr><td>79</td><td>LATIN SMALL LETTER Y</td><td>F9</td><td>LATIN SMALL LETTER U WITH GRAVE</td></tr>
 * <tr><td>7A</td><td>LATIN SMALL LETTER Z</td><td>FA</td><td>LATIN SMALL LETTER U WITH ACUTE</td></tr>
 * <tr><td>7B</td><td>LEFT CURLY BRACKET</td><td>FB</td><td>LATIN SMALL LETTER U WITH CIRCUMFLEX</td></tr>
 * <tr><td>7C</td><td>VERTICAL LINE</td><td>FC</td><td>LATIN SMALL LETTER U WITH DIAERESIS</td></tr>
 * <tr><td>7D</td><td>RIGHT CURLY BRACKET</td><td>FD</td><td>LATIN SMALL LETTER Y WITH ACUTE</td></tr>
 * <tr><td>7E</td><td>TILDE</td><td>FE</td><td>LATIN SMALL LETTER THORN (Icelandic)</td></tr>
 * <tr><td>7F</td><td>DELETE</td><td>FF</td><td>LATIN SMALL LETTER Y WITH DIAERESIS</td></tr>
 * </table>
 * <p>Since:
 * <ul>
 * <li>most CATIA persistent strings are encoded in UTF-8</li>
 * <li>most CATIA internalized strings are encoded in Unicode</li>
 * <li>the rare conversions that CATIA does between Unicode and the thread code page i.e. :
 * <ul>
 * <li>the display and interactive input of message strings on Unix</li>
 * <li>accessing strings in databases</li>
 * <li>output traces</li>
 * </ul>
 * are usually made through calls to @href CATUnicodeString#ConvertToChar and the CATUnicodeString constructor from 
 * a char*</li>
 * </ul>
 * this class should rarely be used, except regarding the use of the @href CATCodePage#ConvertToBase64 and
 * @href CATCodePage#ConvertFromBase64 methods.
 */

class ExportedByNS0S3STR  CATCodePage {

public:

/**
 * Constructor from the thread locale code page.
 * <br><b>Role</b>: Constructs a code page from the thread locale code page.
 */          
    CATCodePage();

/**
 * Constructor from a given code page name.
 * <br><b>Role</b>: Constructs a code page from a given code page name.
 * @param iCodePageName
 *   Name of the code page. For a given language, the default code page can be retrieved in a OS-independent 
 *   manner with GetCodePageByLanguage (DSYSysNLSCore.h).
 * <br>@deprecated input values:
 * <br>On Windows, possible values are:
 * <pre>
 *   1252     : ISO 8859-1 code page 
 *   1250     : ISO 8859-2 code page 
 *   1251     : ISO 8859-5 code page 
 *   932      : IBM 943 code page 
 *   949      : EUC KR code page 
 *   950      : EUC TW code page 
 *   936      : EUC CN code page 
 * </pre>
 * On Unix, possible values are:
 * <pre>
 *   ISO8859-1: ISO 8859-1 code page 
 *   ISO8859-2: ISO 8859-2 code page 
 *   ISO8859-5: ISO 8859-5 code page 
 *   IBM-932  : IBM 943 code page 
 *   EUC-KR   : EUC KR code page 
 *   EUC-TW   : EUC TW code page 
 *   EUC-CN   : EUC CN code page 
 * </pre>
 */
    CATCodePage( const char *iCodePageName );
    
  // Destructor :
  // ============
    virtual ~CATCodePage();
    
/**
 * Converts a string from the instance code page to a Unicode string.
 * <br><b>Role</b>: Converts a string from the instance code page to a Unicode string.
 * <p><b>Note</b>: If a character of the input string character does not exist in the thread locale code page, the
 * character will be replaced, in the returned Unicode string, by the "QUESTION MARK" (003F) character.
 * <br><b>CAUTION</b>: This method supposes that, when it is called, the code page of the thread locale is 
 * the same as the code page of the current instance, see the comments of the @href CATCodePage#ConvertStrToUcs 
 * method, overloading version without the input string length. 
 * @param iCodePageString
 *   String described in the coded representation of the code page of the current instance.
 * @param iStringLength
 *   Length of the string to be converted, in bytes (without taking into account the possible ending NULL byte).
 * @param oUnicodeString
 *   Pointer to the resulting Unicode string. This string has no string-terminating character.
 *   <br><b>Lifecycle rules deviation</b>: The caller must allocate the buffer.
 * @param oUnicodeSize
 *   Number of Unicode characters in oUnicodeString.
 */
    void ConvertStrToUcs( const char* iCodePageString, int iStringLength, CATUC2Bytes *oUnicodeString, int *oUnicodeSize );


/**
 * Converts a string from the instance code page to a Unicode string, version without the input string length.
 * <br><b>Role</b>: Converts a string from the instance code page to a Unicode string. This overloading version
 * does not require to precise the string length.
 * <p><b>Note</b>: If a character of the input string character does not exist in the thread locale code page, the
 * character will be replaced, in the returned Unicode string, by the "QUESTION MARK" (003F) character.
 * @param iCodePageString
 *   String described in the coded representation of the code page of the current instance (ending with a NULL byte).
 * @param oUnicodeString
 *   Pointer to the resulting Unicode string. This string has no string-terminating character.
 *   <br><b>Lifecycle rules deviation</b>: The caller must allocate the buffer.
 * @param oUnicodeSize
 *   Number of Unicode characters in oUnicodeString.
 */
    void ConvertStrToUcs( const char* iCodePageString, CATUC2Bytes *oUnicodeString, int *oUnicodeSize )
      { ConvertStrToUcs( iCodePageString, CATStrlen32(iCodePageString), oUnicodeString, oUnicodeSize ); }


/**
 * Converts a Unicode string to a string in the instance code page. 
 * <br><b>Role</b>: Converts a Unicode string to a string in the instance code page.
 * <p><b>Note</b>: If a character of the input string does not exist in the thread locale code page, the character will
 * be replaced, in the returned string in the instance code page, by the following coded representation:
 * <pre>
 * +-------------------------+------------+------------+------------+------------+------------+
 * ! thread locale code page !  Windows   !     AIX    !    HP-UX   !    IRIX    !    SunOS   !
 * +-------------------------+------------+------------+------------+------------+------------+
 * +-------------------------+------------+------------+------------+------------+------------+
 * !        ISO 8859-1       !     3F     !     1A     !     1A     !     3F     !     3F     !
 * +-------------------------+------------+------------+------------+------------+------------+
 * !        ISO 8859-2       !     3F     !     1A     !     1A     !     3F     !     3F     !
 * +-------------------------+------------+------------+------------+------------+------------+
 * !        ISO 8859-5       !     3F     !     1A     !     1A     !     3F     !     3F     !
 * +-------------------------+------------+------------+------------+------------+------------+
 * !        IBM 943          !     3F     ! 7F or FCFC !     FCFC   !     3F     !     3F     !
 * +-------------------------+------------+------------+------------+------------+------------+
 * !        EUC KR           !     3F     ! 1A or AFFE !     FFFF   !     3F     !    3F3F    !
 * +-------------------------+------------+------------+------------+------------+------------+
 * !        EUC TW           !     3F     ! 1A or FDFE !     FEFE   !     3F     !    3F3F    !
 * +-------------------------+------------+------------+------------+------------+------------+
 * !        EUC CN           !     3F     ! 1A or A1A1 !     FFFF   !     3F     !    3F3F    !
 * +-------------------------+------------+------------+------------+------------+------------+
 * </pre>
 * <b>CAUTION</b>: This method supposes that, when it is called, the code page of the thread locale is 
 * the same as the code page of the current instance, see the comments of the @href CATCodePage#ConvertStrToUcs 
 * method, overloading version without the input string length. 
 * @param iUnicodeString
 *   String described in Unicode.
 * @param iUnicodeSize
 *   Length of the string to be converted, in characters.
 * @param oCodePageString
 *   Pointer to the resulting string in the coded representation of the code page of the current instance (ending with
 *   a NULL byte).
 *   <br><b>Lifecycle rules deviation</b>: The caller must allocate the buffer.
 * @param oStringLength
 *   Length of the resulting string, in bytes (without taking into account the ending NULL byte).
 */
    void ConvertUcsToStr( CATUC2Bytes* iUnicodeString, int iUnicodeSize, char *oCodePageString, int *oStringLength = NULL );


/**
 * Converts a Unicode string (UCS-2) to a UTF-8 string.
 * <br><b>Role</b>: Converts a Unicode string (UCS-2) to a UTF-8 string. About UTF-8, see @href CATUnicodeString .
 * @param iUnicodeString
 *   Pointer to the string to be converted.
 * @param iUnicodeSize
 *   Number of Unicode characters to be converted.
 * @param oUTF8String
 *   Pointer to the resulting UTF-8 string.
 * @param oUTF8Size
 *   Number of bytes in the UTF-8 string.
 */
    static int  ConvertUCS2ToUTF8( CATUC2Bytes *iUnicodeString, int iUnicodeSize, 
				   char *oUTF8String, size_t *oUTF8Size );

/**
 * Converts a UTF-8 string to a Unicode string (UCS-2).
 * <br><b>Role</b>: Converts a UTF-8 string to a Unicode string (UCS-2). About UTF-8, see @href CATUnicodeString .
 * @param iUTF8String
 *   Pointer to the UTF-8 string to be converted.
 * @param iUTF8Size
 *   Number of bytes in the input string.
 * @param oUnicodeString
 *   Pointer to the resulting Unicode string.
 * @param iUnicodeSize
 *   Number of Unicode characters in the resulting string.
 */
    static int  ConvertUTF8ToUCS2( const char * iUTF8String, size_t iUTF8Size, 
				   CATUC2Bytes *oUnicodeString, int *oUnicodeSize );

		
/**
 * Determination of the validity of an UTF-8 buffer.
 * <br><b>Role</b>: Determines if the input buffer correspond to a valid UTF-8 buffer. About UTF-8, see
 * @href CATUnicodeString .
 *  @return
 *    Boolean specifying if the input buffer correspond to a valid UTF-8 buffer or not.
 *   <br><b>Legal values</b>: <tt>TRUE</tt> valid UTF-8 buffer, or <tt>FALSE</tt> not an UTF-8 buffer.
 */
		static CATBoolean IsUTF8(const char * iBuffer, int iLength);

/**
 * Determination of the possibility to convert a Unicode string into a string in the instance code page.
 * <br><b>Role</b>: Determines if, when converting the given Unicode String into a string in the instance code page,
 * some data is lost or not. In other words, this method determine in the given Unicode string characters all belong
 * to the instance code page character set.
 * <br><b>CAUTION</b>: This method supposes that, when it is called, the code page of the thread locale is 
 * the same as the code page of the current instance, see the comments of the @href CATCodePage#ConvertStrToUcs 
 * method, overloading version without the input string length. 
 *  @return
 *    Boolean specifying if the given unicode string can be converted into a string in the instance code page.
 *   <br><b>Legal values</b>: <tt>TRUE</tt> unicode string can be converted, or <tt>FALSE</tt> cannot be converted.
 */
		static CATBoolean CanConvertToMBCS(const CATUC2Bytes * iUnicodeString, int iUnicodeSize);

/**
 * Converts a binary buffer to a base-64 string.
 * <br><b>Role</b>: Converts a binary buffer to a base-64 string. About the base-64 conversion, see
 * @href CATCodePage#ConvertFromBase64 .
 * @param iBinaryBuffer
 *   The binary buffer to convert
 * @param iLength
 *   Length of iBinaryBuffer, in bytes
 * @param oBase64Buffer
 *   Base-64 string resulting from the conversion of iBinaryBuffer. oBase64Buffer is allocated by the callee with the
 *   new operator, and the must ne deallocated by the caller using delete[]
 */
		static HRESULT ConvertToBase64(
			const unsigned char* iBinaryBuffer,
			const unsigned int iLength,
			char*& oBase64Buffer);

/**
 * Converts a base-64 string to a binary buffer.
 * <br><b>Role</b>: Converts a base-64 string to a binary buffer. 
 * <br> The base-64 conversion enables, as the hexadecimal encoding, to encode a binary buffer in a clear-text string,
 * but the resulting string is shorter than using the hexadecimal encoding. The following character set is used:
 * <ul>
 * <li>A - Z</li>
 * <li>a - z</li>
 * <li>0 - 9</li>
 * <li>+</li>
 * <li>/</li>
 * <li>=</li>
 * </ul>
 * @param iBase64Buffer
 *   The base-64 string to convert
 * @param oBinaryBuffer
 *   The binary buffer resulting from the conversion of iBase64Buffer. oBinaryBuffer is allocated by the callee with the
 *   new operator, and the must ne deallocated by the caller using delete[]
 * @param oBufferLength
 *   Length of oBinaryBuffer, in bytes.
 */
		static HRESULT ConvertFromBase64(
			const char* iBase64Buffer,
			unsigned char*& oBinaryBuffer,
			unsigned int& oBufferLength);

/**
 * @deprecated
 * Environment locale type.
 * <br><b>Role</b>: Precises what is the type of the environment locale.
 * <br><b>CAUTION</b>: The application should not modify this variable, otherwise, results would be unpredictible.<br>
 * possible values are:
 * <pre>
 *   0: sbcs
 *   1: japanese
 *   2: korean
 *   3: traditional chinese
 *   4: simplified chinese
 * </pre>
 */
        static int sEnvironmentLocaleType;
		
#if defined(_WINDOWS_SOURCE)    // Signatures provided for Native wchar_t support
        // On Windows, sizeof(wchar_t) == sizeof(CATUC2Bytes), so the cast it safe
		void ConvertStrToUcs( const char* iCodePageString, int iStringLength, wchar_t * oUnicodeString, int *oUnicodeSize )
		{
			ConvertStrToUcs(iCodePageString, iStringLength, reinterpret_cast<CATUC2Bytes *>(oUnicodeString), oUnicodeSize);
		}
		void ConvertStrToUcs( const char* iCodePageString, wchar_t * oUnicodeString, int *oUnicodeSize )
		{
			ConvertStrToUcs( iCodePageString, reinterpret_cast<CATUC2Bytes *>(oUnicodeString), oUnicodeSize );
		}
		void ConvertUcsToStr( wchar_t * iUnicodeString, int iUnicodeSize, char *oCodePageString, int *oStringLength = NULL )
		{
			ConvertUcsToStr( reinterpret_cast<CATUC2Bytes *>(iUnicodeString), iUnicodeSize, oCodePageString, oStringLength );
		}
		static int ConvertUCS2ToUTF8( wchar_t * iUnicodeString, int iUnicodeSize, char *oUTF8String, size_t *oUTF8Size )
		{
			return ConvertUCS2ToUTF8( reinterpret_cast<CATUC2Bytes *>(iUnicodeString), iUnicodeSize, oUTF8String, oUTF8Size );
		}
		static int ConvertUTF8ToUCS2( const char * iUTF8String, size_t iUTF8Size, wchar_t *oUnicodeString, int *oUnicodeSize )
		{
			return ConvertUTF8ToUCS2( iUTF8String, iUTF8Size, reinterpret_cast<CATUC2Bytes *>(oUnicodeString), oUnicodeSize );
		}
		static CATBoolean CanConvertToMBCS(const wchar_t * iUnicodeString, int iUnicodeSize)
		{
			return CanConvertToMBCS(reinterpret_cast<const CATUC2Bytes *>(iUnicodeString), iUnicodeSize);
		}
#endif
        
private:

        DSYSysCodePage *m_converter;
        /**
         * @deprecated.
         * Locale type.
         * <br><b>Role</b>: Precises what is the type of an average locale corresponding to the code page.
         * <br><b>CAUTION</b>: The application should not modify this variable, otherwise, results would be unpredictible.<br>
         * possible values are:
         * <pre>
         *   0: sbcs
         *   1: japanese
         *   2: korean
         *   3: traditional chinese
         *   4: simplified chinese
         * </pre>
         */
        int _LocaleType;
        
        /**
         * _GetConverter should not be used in constructors
         */
        const DSYSysCodePage & _GetConverter();
};
#endif	// CATCodePage_H
