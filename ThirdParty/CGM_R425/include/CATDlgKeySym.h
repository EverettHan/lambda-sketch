// COPYRIGHT DASSAULT SYSTEMES 1999

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

// Meta/Ctrl/Shift are not compliant with non permissive C/C++ code

/**
 * @nodoc 
 * Definitions of the keys.
 */
#ifndef NO_META_CTRL_SHIFT
// @deprecated R424 CATDlgMetaKey
#define Meta  ( 1 << 31 )
#endif
#define CATDlgMetaKey  ( 1 << 31 )
/**
 * @nodoc 
 */
#ifndef NO_META_CTRL_SHIFT
// @deprecated R424 CATDlgCtrlKey
#define Ctrl  ( 1 << 30 )
#endif
#define CATDlgCtrlKey  ( 1 << 30 )
/**
 * @nodoc 
 */
#ifndef NO_META_CTRL_SHIFT
// @deprecated R424 CATDlgShiftKey
#define DlgShift ( 1 << 29 )
#endif
#define CATDlgShiftKey ( 1 << 29 )

/**
 * @nodoc 
 */
#define UIK_BackSpace		0xFF08	/* back space, back char */
/**
 * @nodoc 
 */
#define UIK_Tab			0xFF09
/**
 * @nodoc 
 */
#define UIK_Linefeed		0xFF0A	/* Linefeed, LF */
/**
 * @nodoc 
 */
#define UIK_Clear		0xFF0B
/**
 * @nodoc 
 */
#define UIK_Return		0xFF0D	/* Return, enter */
/**
 * @nodoc 
 */
#define UIK_Pause		0xFF13	/* Pause, hold */
/**
 * @nodoc 
 */
#define UIK_Scroll_Lock		0xFF14
/**
 * @nodoc 
 */
#define UIK_Escape		0xFF1B
/**
 * @nodoc 
 */
#define UIK_Delete		0xFFFF	/* Delete, rubout */
/**
 * @nodoc 
 */
#define UIK_Multi_key		0xFF20  /* Multi-key character compose */
/**
 * @nodoc 
 */
#define UIK_Kanji		0xFF21	/* Kanji, Kanji convert */
/**
 * @nodoc 
 */
#define UIK_Muhenkan		0xFF22  /* Cancel Conversion */
/**
 * @nodoc 
 */
#define UIK_Henkan_Mode		0xFF23  /* Start/Stop Conversion */
/**
 * @nodoc 
 */
#define UIK_Henkan		0xFF23  /* Alias for Henkan_Mode */
/**
 * @nodoc 
 */
#define UIK_Romaji		0xFF24  /* to Romaji */
/**
 * @nodoc 
 */
#define UIK_Hiragana		0xFF25  /* to Hiragana */
/**
 * @nodoc 
 */
#define UIK_Katakana		0xFF26  /* to Katakana */
/**
 * @nodoc 
 */
#define UIK_Hiragana_Katakana	0xFF27  /* Hiragana/Katakana toggle */
/**
 * @nodoc 
 */
#define UIK_Zenkaku		0xFF28  /* to Zenkaku */
/**
 * @nodoc 
 */
#define UIK_Hankaku		0xFF29  /* to Hankaku */
/**
 * @nodoc 
 */
#define UIK_Zenkaku_Hankaku	0xFF2A  /* Zenkaku/Hankaku toggle */
/**
 * @nodoc 
 */
#define UIK_Touroku		0xFF2B  /* Add to Dictionary */
/**
 * @nodoc 
 */
#define UIK_Massyo		0xFF2C  /* Delete from Dictionary */
/**
 * @nodoc 
 */
#define UIK_Kana_Lock		0xFF2D  /* Kana Lock */
/**
 * @nodoc 
 */
#define UIK_Kana_Shift		0xFF2E  /* Kana Shift */
/**
 * @nodoc 
 */
#define UIK_Eisu_Shift		0xFF2F  /* Alphanumeric Shift */
/**
 * @nodoc 
 */
#define UIK_Eisu_toggle		0xFF30  /* Alphanumeric toggle */
/**
 * @nodoc 
 */
#define UIK_Home			0xFF50
/**
 * @nodoc 
 */
#define UIK_Left			0xFF51	/* Move left, left arrow */
/**
 * @nodoc 
 */
#define UIK_Up			0xFF52	/* Move up, up arrow */
/**
 * @nodoc 
 */
#define UIK_Right		0xFF53	/* Move right, right arrow */
/**
 * @nodoc 
 */
#define UIK_Down			0xFF54	/* Move down, down arrow */
/**
 * @nodoc 
 */
#define UIK_Prior		0xFF55	/* Prior, previous */
/**
 * @nodoc 
 */
#define UIK_Next			0xFF56	/* Next */
/**
 * @nodoc 
 */
#define UIK_End			0xFF57	/* EOL */
/**
 * @nodoc 
 */
#define UIK_Begin		0xFF58	/* BOL */
/**
 * @nodoc 
 */
#define UIK_Select		0xFF60	/* Select, mark */
/**
 * @nodoc 
 */
#define UIK_Print		0xFF61
/**
 * @nodoc 
 */
#define UIK_Execute		0xFF62	/* Execute, run, do */
/**
 * @nodoc 
 */
#define UIK_Insert		0xFF63	/* Insert, insert here */
/**
 * @nodoc 
 */
#define UIK_Undo			0xFF65	/* Undo, oops */
/**
 * @nodoc 
 */
#define UIK_Redo			0xFF66	/* redo, again */
/**
 * @nodoc 
 */
#define UIK_Menu			0xFF67
/**
 * @nodoc 
 */
#define UIK_Find			0xFF68	/* Find, search */
/**
 * @nodoc 
 */
#define UIK_Cancel		0xFF69	/* Cancel, stop, abort, exit */
/**
 * @nodoc 
 */
#define UIK_Help			0xFF6A	/* Help, ? */
/**
 * @nodoc 
 */
#define UIK_Break		0xFF6B
/**
 * @nodoc 
 */
#define UIK_Mode_switch		0xFF7E	/* Character set switch */
/**
 * @nodoc 
 */
#define UIK_script_switch        0xFF7E  /* Alias for mode_switch */
/**
 * @nodoc 
 */
#define UIK_Num_Lock		0xFF7F
/**
 * @nodoc 
 */
#define UIK_KP_Space		0xFF80	/* space */
/**
 * @nodoc 
 */
#define UIK_KP_Tab		0xFF89
/**
 * @nodoc 
 */
#define UIK_KP_Enter		0xFF8D	/* enter */
/**
 * @nodoc 
 */
#define UIK_KP_F1		0xFF91	/* PF1, KP_A, ... */
/**
 * @nodoc 
 */
#define UIK_KP_F2		0xFF92
/**
 * @nodoc 
 */
#define UIK_KP_F3		0xFF93
/**
 * @nodoc 
 */
#define UIK_KP_F4		0xFF94
/**
 * @nodoc 
 */
#define UIK_KP_Equal		0xFFBD	/* equals */
/**
 * @nodoc 
 */
#define UIK_KP_Multiply		0xFFAA
/**
 * @nodoc 
 */
#define UIK_KP_Add		0xFFAB
/**
 * @nodoc 
 */
#define UIK_KP_Separator		0xFFAC	/* separator, often comma */
/**
 * @nodoc 
 */
#define UIK_KP_Subtract		0xFFAD
/**
 * @nodoc 
 */
#define UIK_KP_Decimal		0xFFAE
/**
 * @nodoc 
 */
#define UIK_KP_Divide		0xFFAF
/**
 * @nodoc 
 */
#define UIK_KP_0			0xFFB0
/**
 * @nodoc 
 */
#define UIK_KP_1			0xFFB1
/**
 * @nodoc 
 */
#define UIK_KP_2			0xFFB2
/**
 * @nodoc 
 */
#define UIK_KP_3			0xFFB3
/**
 * @nodoc 
 */
#define UIK_KP_4			0xFFB4
/**
 * @nodoc 
 */
#define UIK_KP_5			0xFFB5
/**
 * @nodoc 
 */
#define UIK_KP_6			0xFFB6
/**
 * @nodoc 
 */
#define UIK_KP_7			0xFFB7
/**
 * @nodoc 
 */
#define UIK_KP_8			0xFFB8
/**
 * @nodoc 
 */
#define UIK_KP_9			0xFFB9



/**
 * @nodoc 
 * Auxilliary Functions; note the duplicate definitions for left and right
 * function keys;  Sun keyboards and a few other manufacturers have such
 * function key groups on the left and/or right sides of the keyboard.
 * We've not found a keyboard with more than 35 function keys total.
 */
#define UIK_F1			0xFFBE
/**
 * @nodoc 
 */
#define UIK_F2			0xFFBF
/**
 * @nodoc 
 */
#define UIK_F3			0xFFC0
/**
 * @nodoc 
 */
#define UIK_F4			0xFFC1
/**
 * @nodoc 
 */
#define UIK_F5			0xFFC2
/**
 * @nodoc 
 */
#define UIK_F6			0xFFC3
/**
 * @nodoc 
 */
#define UIK_F7			0xFFC4
/**
 * @nodoc 
 */
#define UIK_F8			0xFFC5
/**
 * @nodoc 
 */
#define UIK_F9			0xFFC6
/**
 * @nodoc 
 */
#define UIK_F10			0xFFC7
/**
 * @nodoc 
 */
#define UIK_F11			0xFFC8
/**
 * @nodoc 
 */
#define UIK_L1			0xFFC8
/**
 * @nodoc 
 */
#define UIK_F12			0xFFC9
/**
 * @nodoc 
 */
#define UIK_L2			0xFFC9
/**
 * @nodoc 
 */
#define UIK_F13			0xFFCA
/**
 * @nodoc 
 */
#define UIK_L3			0xFFCA
/**
 * @nodoc 
 */
#define UIK_F14			0xFFCB
/**
 * @nodoc 
 */
#define UIK_L4			0xFFCB
/**
 * @nodoc 
 */
#define UIK_F15			0xFFCC
/**
 * @nodoc 
 */
#define UIK_L5			0xFFCC
/**
 * @nodoc 
 */
#define UIK_F16			0xFFCD
/**
 * @nodoc 
 */
#define UIK_L6			0xFFCD
/**
 * @nodoc 
 */
#define UIK_F17			0xFFCE
/**
 * @nodoc 
 */
#define UIK_L7			0xFFCE
/**
 * @nodoc 
 */
#define UIK_F18			0xFFCF
/**
 * @nodoc 
 */
#define UIK_L8			0xFFCF
/**
 * @nodoc 
 */
#define UIK_F19			0xFFD0
/**
 * @nodoc 
 */
#define UIK_L9			0xFFD0
/**
 * @nodoc 
 */
#define UIK_F20			0xFFD1
/**
 * @nodoc 
 */
#define UIK_L10			0xFFD1
/**
 * @nodoc 
 */
#define UIK_F21			0xFFD2
/**
 * @nodoc 
 */
#define UIK_R1			0xFFD2
/**
 * @nodoc 
 */
#define UIK_F22			0xFFD3
/**
 * @nodoc 
 */
#define UIK_R2			0xFFD3
/**
 * @nodoc 
 */
#define UIK_F23			0xFFD4
/**
 * @nodoc 
 */
#define UIK_R3			0xFFD4
/**
 * @nodoc 
 */
#define UIK_F24			0xFFD5
/**
 * @nodoc 
 */
#define UIK_R4			0xFFD5
/**
 * @nodoc 
 */
#define UIK_F25			0xFFD6
/**
 * @nodoc 
 */
#define UIK_R5			0xFFD6
/**
 * @nodoc 
 */
#define UIK_F26			0xFFD7
/**
 * @nodoc 
 */
#define UIK_R6			0xFFD7
/**
 * @nodoc 
 */
#define UIK_F27			0xFFD8
/**
 * @nodoc 
 */
#define UIK_R7			0xFFD8
/**
 * @nodoc 
 */
#define UIK_F28			0xFFD9
/**
 * @nodoc 
 */
#define UIK_R8			0xFFD9
/**
 * @nodoc 
 */
#define UIK_F29			0xFFDA
/**
 * @nodoc 
 */
#define UIK_R9			0xFFDA
/**
 * @nodoc 
 */
#define UIK_F30			0xFFDB
/**
 * @nodoc 
 */
#define UIK_R10			0xFFDB
/**
 * @nodoc 
 */
#define UIK_F31			0xFFDC
/**
 * @nodoc 
 */
#define UIK_R11			0xFFDC
/**
 * @nodoc 
 */
#define UIK_F32			0xFFDD
/**
 * @nodoc 
 */
#define UIK_R12			0xFFDD
/**
 * @nodoc 
 */
#define UIK_R13			0xFFDE
/**
 * @nodoc 
 */
#define UIK_F33			0xFFDE
/**
 * @nodoc 
 */
#define UIK_F34			0xFFDF
/**
 * @nodoc 
 */
#define UIK_R14			0xFFDF
/**
 * @nodoc 
 */
#define UIK_F35			0xFFE0
/**
 * @nodoc 
 */
#define UIK_R15			0xFFE0

/**
 * @nodoc 
 */
#define UIK_Shift_L		0xFFE1	/* Left shift */
/**
 * @nodoc 
 */
#define UIK_Shift_R		0xFFE2	/* Right shift */
/**
 * @nodoc 
 */
#define UIK_Control_L		0xFFE3	/* Left control */
/**
 * @nodoc 
 */
#define UIK_Control_R		0xFFE4	/* Right control */
/**
 * @nodoc 
 */
#define UIK_Caps_Lock		0xFFE5	/* Caps lock */
/**
 * @nodoc 
 */
#define UIK_Shift_Lock		0xFFE6	/* Shift lock */

/**
 * @nodoc 
 */
#define UIK_Meta_L		0xFFE7	/* Left meta */
/**
 * @nodoc 
 */
#define UIK_Meta_R		0xFFE8	/* Right meta */
/**
 * @nodoc 
 */
#define UIK_Alt_L		0xFFE9	/* Left alt */
/**
 * @nodoc 
 */
#define UIK_Alt_R		0xFFEA	/* Right alt */
/**
 * @nodoc 
 */
#define UIK_Super_L		0xFFEB	/* Left super */
/**
 * @nodoc 
 */
#define UIK_Super_R		0xFFEC	/* Right super */
/**
 * @nodoc 
 */
#define UIK_Hyper_L		0xFFED	/* Left hyper */
/**
 * @nodoc 
 */
#define UIK_Hyper_R		0xFFEE	/* Right hyper */
/**
 * @nodoc 
 */
#define UIK_space               0x020
/**
 * @nodoc 
 */
#define UIK_exclam              0x021
/**
 * @nodoc 
 */
#define UIK_quotedbl            0x022
/**
 * @nodoc 
 */
#define UIK_numbersign          0x023
/**
 * @nodoc 
 */
#define UIK_dollar              0x024
/**
 * @nodoc 
 */
#define UIK_percent             0x025
/**
 * @nodoc 
 */
#define UIK_ampersand           0x026
/**
 * @nodoc 
 */
#define UIK_apostrophe          0x027
/**
 * @nodoc 
 */
#define UIK_quoteright          0x027	/* deprecated */
/**
 * @nodoc 
 */
#define UIK_parenleft           0x028
/**
 * @nodoc 
 */
#define UIK_parenright          0x029
/**
 * @nodoc 
 */
#define UIK_asterisk            0x02a
/**
 * @nodoc 
 */
#define UIK_plus                0x02b
/**
 * @nodoc 
 */
#define UIK_comma               0x02c
/**
 * @nodoc 
 */
#define UIK_minus               0x02d
/**
 * @nodoc 
 */
#define UIK_period              0x02e
/**
 * @nodoc 
 */
#define UIK_slash               0x02f
/**
 * @nodoc 
 */
#define UIK_0                   0x030
/**
 * @nodoc 
 */
#define UIK_1                   0x031
/**
 * @nodoc 
 */
#define UIK_2                   0x032
/**
 * @nodoc 
 */
#define UIK_3                   0x033
/**
 * @nodoc 
 */
#define UIK_4                   0x034
/**
 * @nodoc 
 */
#define UIK_5                   0x035
/**
 * @nodoc 
 */
#define UIK_6                   0x036
/**
 * @nodoc 
 */
#define UIK_7                   0x037
/**
 * @nodoc 
 */
#define UIK_8                   0x038
/**
 * @nodoc 
 */
#define UIK_9                   0x039
/**
 * @nodoc 
 */
#define UIK_colon               0x03a
/**
 * @nodoc 
 */
#define UIK_semicolon           0x03b
/**
 * @nodoc 
 */
#define UIK_less                0x03c
/**
 * @nodoc 
 */
#define UIK_equal               0x03d
/**
 * @nodoc 
 */
#define UIK_greater             0x03e
/**
 * @nodoc 
 */
#define UIK_question            0x03f
/**
 * @nodoc 
 */
#define UIK_at                  0x040
/**
 * @nodoc 
 */
#define UIK_A                   0x041
/**
 * @nodoc 
 */
#define UIK_B                   0x042
/**
 * @nodoc 
 */
#define UIK_C                   0x043
/**
 * @nodoc 
 */
#define UIK_D                   0x044
/**
 * @nodoc 
 */
#define UIK_E                   0x045
/**
 * @nodoc 
 */
#define UIK_F                   0x046
/**
 * @nodoc 
 */
#define UIK_G                   0x047
/**
 * @nodoc 
 */
#define UIK_H                   0x048
/**
 * @nodoc 
 */
#define UIK_I                   0x049
/**
 * @nodoc 
 */
#define UIK_J                   0x04a
/**
 * @nodoc 
 */
#define UIK_K                   0x04b
/**
 * @nodoc 
 */
#define UIK_L                   0x04c
/**
 * @nodoc 
 */
#define UIK_M                   0x04d
/**
 * @nodoc 
 */
#define UIK_N                   0x04e
/**
 * @nodoc 
 */
#define UIK_O                   0x04f
/**
 * @nodoc 
 */
#define UIK_P                   0x050
/**
 * @nodoc 
 */
#define UIK_Q                   0x051
/**
 * @nodoc 
 */
#define UIK_R                   0x052
/**
 * @nodoc 
 */
#define UIK_S                   0x053
/**
 * @nodoc 
 */
#define UIK_T                   0x054
/**
 * @nodoc 
 */
#define UIK_U                   0x055
/**
 * @nodoc 
 */
#define UIK_V                   0x056
/**
 * @nodoc 
 */
#define UIK_W                   0x057
/**
 * @nodoc 
 */
#define UIK_X                   0x058
/**
 * @nodoc 
 */
#define UIK_Y                   0x059
/**
 * @nodoc 
 */
#define UIK_Z                   0x05a
/**
 * @nodoc 
 */
#define UIK_bracketleft         0x05b
/**
 * @nodoc 
 */
#define UIK_backslash           0x05c
/**
 * @nodoc 
 */
#define UIK_bracketright        0x05d
/**
 * @nodoc 
 */
#define UIK_asciicircum         0x05e
/**
 * @nodoc 
 */
#define UIK_underscore          0x05f
/**
 * @nodoc 
 */
#define UIK_grave               0x060
/**
 * @nodoc 
 */
#define UIK_quoteleft           0x060	/* deprecated */
/**
 * @nodoc 
 */
#define UIK_a                   0x061
/**
 * @nodoc 
 */
#define UIK_b                   0x062
/**
 * @nodoc 
 */
#define UIK_c                   0x063
/**
 * @nodoc 
 */
#define UIK_d                   0x064
/**
 * @nodoc 
 */
#define UIK_e                   0x065
/**
 * @nodoc 
 */
#define UIK_f                   0x066
/**
 * @nodoc 
 */
#define UIK_g                   0x067
/**
 * @nodoc 
 */
#define UIK_h                   0x068
/**
 * @nodoc 
 */
#define UIK_i                   0x069
/**
 * @nodoc 
 */
#define UIK_j                   0x06a
/**
 * @nodoc 
 */
#define UIK_k                   0x06b
/**
 * @nodoc 
 */
#define UIK_l                   0x06c
/**
 * @nodoc 
 */
#define UIK_m                   0x06d
/**
 * @nodoc 
 */
#define UIK_n                   0x06e
/**
 * @nodoc 
 */
#define UIK_o                   0x06f
/**
 * @nodoc 
 */
#define UIK_p                   0x070
/**
 * @nodoc 
 */
#define UIK_q                   0x071
/**
 * @nodoc 
 */
#define UIK_r                   0x072
/**
 * @nodoc 
 */
#define UIK_s                   0x073
/**
 * @nodoc 
 */
#define UIK_t                   0x074
/**
 * @nodoc 
 */
#define UIK_u                   0x075
/**
 * @nodoc 
 */
#define UIK_v                   0x076
/**
 * @nodoc 
 */
#define UIK_w                   0x077
/**
 * @nodoc 
 */
#define UIK_x                   0x078
/**
 * @nodoc 
 */
#define UIK_y                   0x079
/**
 * @nodoc 
 */
#define UIK_z                   0x07a
/**
 * @nodoc 
 */
#define UIK_braceleft           0x07b
/**
 * @nodoc 
 */
#define UIK_bar                 0x07c
/**
 * @nodoc 
 */
#define UIK_braceright          0x07d
/**
 * @nodoc 
 */
#define UIK_asciitilde          0x07e

/**
 * @nodoc 
 */
#define UIK_nobreakspace        0x0a0
/**
 * @nodoc 
 */
#define UIK_exclamdown          0x0a1
/**
 * @nodoc 
 */
#define UIK_cent        	       0x0a2
/**
 * @nodoc 
 */
#define UIK_sterling            0x0a3
/**
 * @nodoc 
 */
#define UIK_currency            0x0a4
/**
 * @nodoc 
 */
#define UIK_yen                 0x0a5
/**
 * @nodoc 
 */
#define UIK_brokenbar           0x0a6
/**
 * @nodoc 
 */
#define UIK_section             0x0a7
/**
 * @nodoc 
 */
#define UIK_diaeresis           0x0a8
/**
 * @nodoc 
 */
#define UIK_copyright           0x0a9
/**
 * @nodoc 
 */
#define UIK_ordfeminine         0x0aa
/**
 * @nodoc 
 */
#define UIK_guillemotleft       0x0ab	/* left angle quotation mark */
/**
 * @nodoc 
 */
#define UIK_notsign             0x0ac
/**
 * @nodoc 
 */
#define UIK_hyphen              0x0ad
/**
 * @nodoc 
 */
#define UIK_registered          0x0ae
/**
 * @nodoc 
 */
#define UIK_macron              0x0af
/**
 * @nodoc 
 */
#define UIK_degree              0x0b0
/**
 * @nodoc 
 */
#define UIK_plusminus           0x0b1
/**
 * @nodoc 
 */
#define UIK_twosuperior         0x0b2
/**
 * @nodoc 
 */
#define UIK_threesuperior       0x0b3
/**
 * @nodoc 
 */
#define UIK_acute               0x0b4
/**
 * @nodoc 
 */
#define UIK_mu                  0x0b5
/**
 * @nodoc 
 */
#define UIK_paragraph           0x0b6
/**
 * @nodoc 
 */
#define UIK_periodcentered      0x0b7
/**
 * @nodoc 
 */
#define UIK_cedilla             0x0b8
/**
 * @nodoc 
 */
#define UIK_onesuperior         0x0b9
/**
 * @nodoc 
 */
#define UIK_masculine           0x0ba
/**
 * @nodoc 
 */
#define UIK_guillemotright      0x0bb	/* right angle quotation mark */
/**
 * @nodoc 
 */
#define UIK_onequarter          0x0bc
/**
 * @nodoc 
 */
#define UIK_onehalf             0x0bd
/**
 * @nodoc 
 */
#define UIK_threequarters       0x0be
/**
 * @nodoc 
 */
#define UIK_questiondown        0x0bf
/**
 * @nodoc 
 */
#define UIK_Agrave              0x0c0
/**
 * @nodoc 
 */
#define UIK_Aacute              0x0c1
/**
 * @nodoc 
 */
#define UIK_Acircumflex         0x0c2
/**
 * @nodoc 
 */
#define UIK_Atilde              0x0c3
/**
 * @nodoc 
 */
#define UIK_Adiaeresis          0x0c4
/**
 * @nodoc 
 */
#define UIK_Aring               0x0c5
/**
 * @nodoc 
 */
#define UIK_AE                  0x0c6
/**
 * @nodoc 
 */
#define UIK_Ccedilla            0x0c7
/**
 * @nodoc 
 */
#define UIK_Egrave              0x0c8
/**
 * @nodoc 
 */
#define UIK_Eacute              0x0c9
/**
 * @nodoc 
 */
#define UIK_Ecircumflex         0x0ca
/**
 * @nodoc 
 */
#define UIK_Ediaeresis          0x0cb
/**
 * @nodoc 
 */
#define UIK_Igrave              0x0cc
/**
 * @nodoc 
 */
#define UIK_Iacute              0x0cd
/**
 * @nodoc 
 */
#define UIK_Icircumflex         0x0ce
/**
 * @nodoc 
 */
#define UIK_Idiaeresis          0x0cf
/**
 * @nodoc 
 */
#define UIK_ETH                 0x0d0
/**
 * @nodoc 
 */
#define UIK_Eth                 0x0d0	/* deprecated */
/**
 * @nodoc 
 */
#define UIK_Ntilde              0x0d1
/**
 * @nodoc 
 */
#define UIK_Ograve              0x0d2
/**
 * @nodoc 
 */
#define UIK_Oacute              0x0d3
/**
 * @nodoc 
 */
#define UIK_Ocircumflex         0x0d4
/**
 * @nodoc 
 */
#define UIK_Otilde              0x0d5
/**
 * @nodoc 
 */
#define UIK_Odiaeresis          0x0d6
/**
 * @nodoc 
 */
#define UIK_multiply            0x0d7
/**
 * @nodoc 
 */
#define UIK_Ooblique            0x0d8
/**
 * @nodoc 
 */
#define UIK_Ugrave              0x0d9
/**
 * @nodoc 
 */
#define UIK_Uacute              0x0da
/**
 * @nodoc 
 */
#define UIK_Ucircumflex         0x0db
/**
 * @nodoc 
 */
#define UIK_Udiaeresis          0x0dc
/**
 * @nodoc 
 */
#define UIK_Yacute              0x0dd
/**
 * @nodoc 
 */
#define UIK_THORN               0x0de
/**
 * @nodoc 
 */
#define UIK_Thorn               0x0de	/* deprecated */
/**
 * @nodoc 
 */
#define UIK_ssharp              0x0df
/**
 * @nodoc 
 */
#define UIK_agrave              0x0e0
/**
 * @nodoc 
 */
#define UIK_aacute              0x0e1
/**
 * @nodoc 
 */
#define UIK_acircumflex         0x0e2
/**
 * @nodoc 
 */
#define UIK_atilde              0x0e3
/**
 * @nodoc 
 */
#define UIK_adiaeresis          0x0e4
/**
 * @nodoc 
 */
#define UIK_aring               0x0e5
/**
 * @nodoc 
 */
#define UIK_ae                  0x0e6
/**
 * @nodoc 
 */
#define UIK_ccedilla            0x0e7
/**
 * @nodoc 
 */
#define UIK_egrave              0x0e8
/**
 * @nodoc 
 */
#define UIK_eacute              0x0e9
/**
 * @nodoc 
 */
#define UIK_ecircumflex         0x0ea
/**
 * @nodoc 
 */
#define UIK_ediaeresis          0x0eb
/**
 * @nodoc 
 */
#define UIK_igrave              0x0ec
/**
 * @nodoc 
 */
#define UIK_iacute              0x0ed
/**
 * @nodoc 
 */
#define UIK_icircumflex         0x0ee
/**
 * @nodoc 
 */
#define UIK_idiaeresis          0x0ef
/**
 * @nodoc 
 */
#define UIK_eth                 0x0f0
/**
 * @nodoc 
 */
#define UIK_ntilde              0x0f1
/**
 * @nodoc 
 */
#define UIK_ograve              0x0f2
/**
 * @nodoc 
 */
#define UIK_oacute              0x0f3
/**
 * @nodoc 
 */
#define UIK_ocircumflex         0x0f4
/**
 * @nodoc 
 */
#define UIK_otilde              0x0f5
/**
 * @nodoc 
 */
#define UIK_odiaeresis          0x0f6
/**
 * @nodoc 
 */
#define UIK_division            0x0f7
/**
 * @nodoc 
 */
#define UIK_oslash              0x0f8
/**
 * @nodoc 
 */
#define UIK_ugrave              0x0f9
/**
 * @nodoc 
 */
#define UIK_uacute              0x0fa
/**
 * @nodoc 
 */
#define UIK_ucircumflex         0x0fb
/**
 * @nodoc 
 */
#define UIK_udiaeresis          0x0fc
/**
 * @nodoc 
 */
#define UIK_yacute              0x0fd
/**
 * @nodoc 
 */
#define UIK_thorn               0x0fe
/**
 * @nodoc 
 */
#define UIK_ydiaeresis          0x0ff
/**
 * @nodoc 
 */
#define UIK_Aogonek             0x1a1
/**
 * @nodoc 
 */
#define UIK_breve               0x1a2
/**
 * @nodoc 
 */
#define UIK_Lstroke             0x1a3
/**
 * @nodoc 
 */
#define UIK_Lcaron              0x1a5
/**
 * @nodoc 
 */
#define UIK_Sacute              0x1a6
/**
 * @nodoc 
 */
#define UIK_Scaron              0x1a9
/**
 * @nodoc 
 */
#define UIK_Scedilla            0x1aa
/**
 * @nodoc 
 */
#define UIK_Tcaron              0x1ab
/**
 * @nodoc 
 */
#define UIK_Zacute              0x1ac
/**
 * @nodoc 
 */
#define UIK_Zcaron              0x1ae
/**
 * @nodoc 
 */
#define UIK_Zabovedot           0x1af
/**
 * @nodoc 
 */
#define UIK_aogonek             0x1b1
/**
 * @nodoc 
 */
#define UIK_ogonek              0x1b2
/**
 * @nodoc 
 */
#define UIK_lstroke             0x1b3
/**
 * @nodoc 
 */
#define UIK_lcaron              0x1b5
/**
 * @nodoc 
 */
#define UIK_sacute              0x1b6
/**
 * @nodoc 
 */
#define UIK_caron               0x1b7
/**
 * @nodoc 
 */
#define UIK_scaron              0x1b9
/**
 * @nodoc 
 */
#define UIK_scedilla            0x1ba
/**
 * @nodoc 
 */
#define UIK_tcaron              0x1bb
/**
 * @nodoc 
 */
#define UIK_zacute              0x1bc
/**
 * @nodoc 
 */
#define UIK_doubleacute         0x1bd
/**
 * @nodoc 
 */
#define UIK_zcaron              0x1be
/**
 * @nodoc 
 */
#define UIK_zabovedot           0x1bf
/**
 * @nodoc 
 */
#define UIK_Racute              0x1c0
/**
 * @nodoc 
 */
#define UIK_Abreve              0x1c3
/**
 * @nodoc 
 */
#define UIK_Lacute              0x1c5
/**
 * @nodoc 
 */
#define UIK_Cacute              0x1c6
/**
 * @nodoc 
 */
#define UIK_Ccaron              0x1c8
/**
 * @nodoc 
 */
#define UIK_Eogonek             0x1ca
/**
 * @nodoc 
 */
#define UIK_Ecaron              0x1cc
/**
 * @nodoc 
 */
#define UIK_Dcaron              0x1cf
/**
 * @nodoc 
 */
#define UIK_Dstroke             0x1d0
/**
 * @nodoc 
 */
#define UIK_Nacute              0x1d1
/**
 * @nodoc 
 */
#define UIK_Ncaron              0x1d2
/**
 * @nodoc 
 */
#define UIK_Odoubleacute        0x1d5
/**
 * @nodoc 
 */
#define UIK_Rcaron              0x1d8
/**
 * @nodoc 
 */
#define UIK_Uring               0x1d9
/**
 * @nodoc 
 */
#define UIK_Udoubleacute        0x1db
/**
 * @nodoc 
 */
#define UIK_Tcedilla            0x1de
/**
 * @nodoc 
 */
#define UIK_racute              0x1e0
/**
 * @nodoc 
 */
#define UIK_abreve              0x1e3
/**
 * @nodoc 
 */
#define UIK_lacute              0x1e5
/**
 * @nodoc 
 */
#define UIK_cacute              0x1e6
/**
 * @nodoc 
 */
#define UIK_ccaron              0x1e8
/**
 * @nodoc 
 */
#define UIK_eogonek             0x1ea
/**
 * @nodoc 
 */
#define UIK_ecaron              0x1ec
/**
 * @nodoc 
 */
#define UIK_dcaron              0x1ef
/**
 * @nodoc 
 */
#define UIK_dstroke             0x1f0
/**
 * @nodoc 
 */
#define UIK_nacute              0x1f1
/**
 * @nodoc 
 */
#define UIK_ncaron              0x1f2
/**
 * @nodoc 
 */
#define UIK_odoubleacute        0x1f5
/**
 * @nodoc 
 */
#define UIK_udoubleacute        0x1fb
/**
 * @nodoc 
 */
#define UIK_rcaron              0x1f8
/**
 * @nodoc 
 */
#define UIK_uring               0x1f9
/**
 * @nodoc 
 */
#define UIK_tcedilla            0x1fe
/**
 * @nodoc 
 */
#define UIK_abovedot            0x1ff
/**
 * @nodoc 
 */
#define UIK_Hstroke             0x2a1
/**
 * @nodoc 
 */
#define UIK_Hcircumflex         0x2a6
/**
 * @nodoc 
 */
#define UIK_Iabovedot           0x2a9
/**
 * @nodoc 
 */
#define UIK_Gbreve              0x2ab
/**
 * @nodoc 
 */
#define UIK_Jcircumflex         0x2ac
/**
 * @nodoc 
 */
#define UIK_hstroke             0x2b1
/**
 * @nodoc 
 */
#define UIK_hcircumflex         0x2b6
/**
 * @nodoc 
 */
#define UIK_idotless            0x2b9
/**
 * @nodoc 
 */
#define UIK_gbreve              0x2bb
/**
 * @nodoc 
 */
#define UIK_jcircumflex         0x2bc
/**
 * @nodoc 
 */
#define UIK_Cabovedot           0x2c5
/**
 * @nodoc 
 */
#define UIK_Ccircumflex         0x2c6
/**
 * @nodoc 
 */
#define UIK_Gabovedot           0x2d5
/**
 * @nodoc 
 */
#define UIK_Gcircumflex         0x2d8
/**
 * @nodoc 
 */
#define UIK_Ubreve              0x2dd
/**
 * @nodoc 
 */
#define UIK_Scircumflex         0x2de
/**
 * @nodoc 
 */
#define UIK_cabovedot           0x2e5
/**
 * @nodoc 
 */
#define UIK_ccircumflex         0x2e6
/**
 * @nodoc 
 */
#define UIK_gabovedot           0x2f5
/**
 * @nodoc 
 */
#define UIK_gcircumflex         0x2f8
/**
 * @nodoc 
 */
#define UIK_ubreve              0x2fd
/**
 * @nodoc 
 */
#define UIK_scircumflex         0x2fe
/**
 * @nodoc 
 */
#define UIK_kra                 0x3a2
/**
 * @nodoc 
 */
#define UIK_kappa               0x3a2	/* deprecated */
/**
 * @nodoc 
 */
#define UIK_Rcedilla            0x3a3
/**
 * @nodoc 
 */
#define UIK_Itilde              0x3a5
/**
 * @nodoc 
 */
#define UIK_Lcedilla            0x3a6
/**
 * @nodoc 
 */
#define UIK_Emacron             0x3aa
/**
 * @nodoc 
 */
#define UIK_Gcedilla            0x3ab
/**
 * @nodoc 
 */
#define UIK_Tslash              0x3ac
/**
 * @nodoc 
 */
#define UIK_rcedilla            0x3b3
/**
 * @nodoc 
 */
#define UIK_itilde              0x3b5
/**
 * @nodoc 
 */
#define UIK_lcedilla            0x3b6
/**
 * @nodoc 
 */
#define UIK_emacron             0x3ba
/**
 * @nodoc 
 */
#define UIK_gcedilla            0x3bb
/**
 * @nodoc 
 */
#define UIK_tslash              0x3bc
/**
 * @nodoc 
 */
#define UIK_ENG                 0x3bd
/**
 * @nodoc 
 */
#define UIK_eng                 0x3bf
/**
 * @nodoc 
 */
#define UIK_Amacron             0x3c0
/**
 * @nodoc 
 */
#define UIK_Iogonek             0x3c7
/**
 * @nodoc 
 */
#define UIK_Eabovedot           0x3cc
/**
 * @nodoc 
 */
#define UIK_Imacron             0x3cf
/**
 * @nodoc 
 */
#define UIK_Ncedilla            0x3d1
/**
 * @nodoc 
 */
#define UIK_Omacron             0x3d2
/**
 * @nodoc 
 */
#define UIK_Kcedilla            0x3d3
/**
 * @nodoc 
 */
#define UIK_Uogonek             0x3d9
/**
 * @nodoc 
 */
#define UIK_Utilde              0x3dd
/**
 * @nodoc 
 */
#define UIK_Umacron             0x3de
/**
 * @nodoc 
 */
#define UIK_amacron             0x3e0
/**
 * @nodoc 
 */
#define UIK_iogonek             0x3e7
/**
 * @nodoc 
 */
#define UIK_eabovedot           0x3ec
/**
 * @nodoc 
 */
#define UIK_imacron             0x3ef
/**
 * @nodoc 
 */
#define UIK_ncedilla            0x3f1
/**
 * @nodoc 
 */
#define UIK_omacron             0x3f2
/**
 * @nodoc 
 */
#define UIK_kcedilla            0x3f3
/**
 * @nodoc 
 */
#define UIK_uogonek             0x3f9
/**
 * @nodoc 
 */
#define UIK_utilde              0x3fd
/**
 * @nodoc 
 */
#define UIK_umacron             0x3fe
/**
 * @nodoc 
 */
#define UIK_overline				       0x47e
/**
 * @nodoc 
 */
#define UIK_kana_fullstop                               0x4a1
/**
 * @nodoc 
 */
#define UIK_kana_openingbracket                         0x4a2
/**
 * @nodoc 
 */
#define UIK_kana_closingbracket                         0x4a3
/**
 * @nodoc 
 */
#define UIK_kana_comma                                  0x4a4
/**
 * @nodoc 
 */
#define UIK_kana_conjunctive                            0x4a5
/**
 * @nodoc 
 */
#define UIK_kana_middledot                              0x4a5  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_kana_WO                                     0x4a6
/**
 * @nodoc 
 */
#define UIK_kana_a                                      0x4a7
/**
 * @nodoc 
 */
#define UIK_kana_i                                      0x4a8
/**
 * @nodoc 
 */
#define UIK_kana_u                                      0x4a9
/**
 * @nodoc 
 */
#define UIK_kana_e                                      0x4aa
/**
 * @nodoc 
 */
#define UIK_kana_o                                      0x4ab
/**
 * @nodoc 
 */
#define UIK_kana_ya                                     0x4ac
/**
 * @nodoc 
 */
#define UIK_kana_yu                                     0x4ad
/**
 * @nodoc 
 */
#define UIK_kana_yo                                     0x4ae
/**
 * @nodoc 
 */
#define UIK_kana_tsu                                    0x4af
/**
 * @nodoc 
 */
#define UIK_kana_tu                                     0x4af  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_prolongedsound                              0x4b0
/**
 * @nodoc 
 */
#define UIK_kana_A                                      0x4b1
/**
 * @nodoc 
 */
#define UIK_kana_I                                      0x4b2
/**
 * @nodoc 
 */
#define UIK_kana_U                                      0x4b3
/**
 * @nodoc 
 */
#define UIK_kana_E                                      0x4b4
/**
 * @nodoc 
 */
#define UIK_kana_O                                      0x4b5
/**
 * @nodoc 
 */
#define UIK_kana_KA                                     0x4b6
/**
 * @nodoc 
 */
#define UIK_kana_KI                                     0x4b7
/**
 * @nodoc 
 */
#define UIK_kana_KU                                     0x4b8
/**
 * @nodoc 
 */
#define UIK_kana_KE                                     0x4b9
/**
 * @nodoc 
 */
#define UIK_kana_KO                                     0x4ba
/**
 * @nodoc 
 */
#define UIK_kana_SA                                     0x4bb
/**
 * @nodoc 
 */
#define UIK_kana_SHI                                    0x4bc
/**
 * @nodoc 
 */
#define UIK_kana_SU                                     0x4bd
/**
 * @nodoc 
 */
#define UIK_kana_SE                                     0x4be
/**
 * @nodoc 
 */
#define UIK_kana_SO                                     0x4bf
/**
 * @nodoc 
 */
#define UIK_kana_TA                                     0x4c0
/**
 * @nodoc 
 */
#define UIK_kana_CHI                                    0x4c1
/**
 * @nodoc 
 */
#define UIK_kana_TI                                     0x4c1  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_kana_TSU                                    0x4c2
/**
 * @nodoc 
 */
#define UIK_kana_TU                                     0x4c2  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_kana_TE                                     0x4c3
/**
 * @nodoc 
 */
#define UIK_kana_TO                                     0x4c4
/**
 * @nodoc 
 */
#define UIK_kana_NA                                     0x4c5
/**
 * @nodoc 
 */
#define UIK_kana_NI                                     0x4c6
/**
 * @nodoc 
 */
#define UIK_kana_NU                                     0x4c7
/**
 * @nodoc 
 */
#define UIK_kana_NE                                     0x4c8
/**
 * @nodoc 
 */
#define UIK_kana_NO                                     0x4c9
/**
 * @nodoc 
 */
#define UIK_kana_HA                                     0x4ca
/**
 * @nodoc 
 */
#define UIK_kana_HI                                     0x4cb
/**
 * @nodoc 
 */
#define UIK_kana_FU                                     0x4cc
/**
 * @nodoc 
 */
#define UIK_kana_HU                                     0x4cc  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_kana_HE                                     0x4cd
/**
 * @nodoc 
 */
#define UIK_kana_HO                                     0x4ce
/**
 * @nodoc 
 */
#define UIK_kana_MA                                     0x4cf
/**
 * @nodoc 
 */
#define UIK_kana_MI                                     0x4d0
/**
 * @nodoc 
 */
#define UIK_kana_MU                                     0x4d1
/**
 * @nodoc 
 */
#define UIK_kana_ME                                     0x4d2
/**
 * @nodoc 
 */
#define UIK_kana_MO                                     0x4d3
/**
 * @nodoc 
 */
#define UIK_kana_YA                                     0x4d4
/**
 * @nodoc 
 */
#define UIK_kana_YU                                     0x4d5
/**
 * @nodoc 
 */
#define UIK_kana_YO                                     0x4d6
/**
 * @nodoc 
 */
#define UIK_kana_RA                                     0x4d7
/**
 * @nodoc 
 */
#define UIK_kana_RI                                     0x4d8
/**
 * @nodoc 
 */
#define UIK_kana_RU                                     0x4d9
/**
 * @nodoc 
 */
#define UIK_kana_RE                                     0x4da
/**
 * @nodoc 
 */
#define UIK_kana_RO                                     0x4db
/**
 * @nodoc 
 */
#define UIK_kana_WA                                     0x4dc
/**
 * @nodoc 
 */
#define UIK_kana_N                                      0x4dd
/**
 * @nodoc 
 */
#define UIK_voicedsound                                 0x4de
/**
 * @nodoc 
 */
#define UIK_semivoicedsound                             0x4df
/**
 * @nodoc 
 */
#define UIK_kana_switch          0xFF7E  /* Alias for mode_switch */
/**
 * @nodoc 
 */
#define UIK_Arabic_comma                                0x5ac
/**
 * @nodoc 
 */
#define UIK_Arabic_semicolon                            0x5bb
/**
 * @nodoc 
 */
#define UIK_Arabic_question_mark                        0x5bf
/**
 * @nodoc 
 */
#define UIK_Arabic_hamza                                0x5c1
/**
 * @nodoc 
 */
#define UIK_Arabic_maddaonalef                          0x5c2
/**
 * @nodoc 
 */
#define UIK_Arabic_hamzaonalef                          0x5c3
/**
 * @nodoc 
 */
#define UIK_Arabic_hamzaonwaw                           0x5c4
/**
 * @nodoc 
 */
#define UIK_Arabic_hamzaunderalef                       0x5c5
/**
 * @nodoc 
 */
#define UIK_Arabic_hamzaonyeh                           0x5c6
/**
 * @nodoc 
 */
#define UIK_Arabic_alef                                 0x5c7
/**
 * @nodoc 
 */
#define UIK_Arabic_beh                                  0x5c8
/**
 * @nodoc 
 */
#define UIK_Arabic_tehmarbuta                           0x5c9
/**
 * @nodoc 
 */
#define UIK_Arabic_teh                                  0x5ca
/**
 * @nodoc 
 */
#define UIK_Arabic_theh                                 0x5cb
/**
 * @nodoc 
 */
#define UIK_Arabic_jeem                                 0x5cc
/**
 * @nodoc 
 */
#define UIK_Arabic_hah                                  0x5cd
/**
 * @nodoc 
 */
#define UIK_Arabic_khah                                 0x5ce
/**
 * @nodoc 
 */
#define UIK_Arabic_dal                                  0x5cf
/**
 * @nodoc 
 */
#define UIK_Arabic_thal                                 0x5d0
/**
 * @nodoc 
 */
#define UIK_Arabic_ra                                   0x5d1
/**
 * @nodoc 
 */
#define UIK_Arabic_zain                                 0x5d2
/**
 * @nodoc 
 */
#define UIK_Arabic_seen                                 0x5d3
/**
 * @nodoc 
 */
#define UIK_Arabic_sheen                                0x5d4
/**
 * @nodoc 
 */
#define UIK_Arabic_sad                                  0x5d5
/**
 * @nodoc 
 */
#define UIK_Arabic_dad                                  0x5d6
/**
 * @nodoc 
 */
#define UIK_Arabic_tah                                  0x5d7
/**
 * @nodoc 
 */
#define UIK_Arabic_zah                                  0x5d8
/**
 * @nodoc 
 */
#define UIK_Arabic_ain                                  0x5d9
/**
 * @nodoc 
 */
#define UIK_Arabic_ghain                                0x5da
/**
 * @nodoc 
 */
#define UIK_Arabic_tatweel                              0x5e0
/**
 * @nodoc 
 */
#define UIK_Arabic_feh                                  0x5e1
/**
 * @nodoc 
 */
#define UIK_Arabic_qaf                                  0x5e2
/**
 * @nodoc 
 */
#define UIK_Arabic_kaf                                  0x5e3
/**
 * @nodoc 
 */
#define UIK_Arabic_lam                                  0x5e4
/**
 * @nodoc 
 */
#define UIK_Arabic_meem                                 0x5e5
/**
 * @nodoc 
 */
#define UIK_Arabic_noon                                 0x5e6
/**
 * @nodoc 
 */
#define UIK_Arabic_ha                                   0x5e7
/**
 * @nodoc 
 */
#define UIK_Arabic_heh                                  0x5e7  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_Arabic_waw                                  0x5e8
/**
 * @nodoc 
 */
#define UIK_Arabic_alefmaksura                          0x5e9
/**
 * @nodoc 
 */
#define UIK_Arabic_yeh                                  0x5ea
/**
 * @nodoc 
 */
#define UIK_Arabic_fathatan                             0x5eb
/**
 * @nodoc 
 */
#define UIK_Arabic_dammatan                             0x5ec
/**
 * @nodoc 
 */
#define UIK_Arabic_kasratan                             0x5ed
/**
 * @nodoc 
 */
#define UIK_Arabic_fatha                                0x5ee
/**
 * @nodoc 
 */
#define UIK_Arabic_damma                                0x5ef
/**
 * @nodoc 
 */
#define UIK_Arabic_kasra                                0x5f0
/**
 * @nodoc 
 */
#define UIK_Arabic_shadda                               0x5f1
/**
 * @nodoc 
 */
#define UIK_Arabic_sukun                                0x5f2
/**
 * @nodoc 
 */
#define UIK_Arabic_switch        0xFF7E  /* Alias for mode_switch */
/**
 * @nodoc 
 */
#define UIK_Serbian_dje                                 0x6a1
/**
 * @nodoc 
 */
#define UIK_Macedonia_gje                               0x6a2
/**
 * @nodoc 
 */
#define UIK_Cyrillic_io                                 0x6a3
/**
 * @nodoc 
 */
#define UIK_Ukrainian_ie                                0x6a4
/**
 * @nodoc 
 */
#define UIK_Ukranian_je                                 0x6a4  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_Macedonia_dse                               0x6a5
/**
 * @nodoc 
 */
#define UIK_Ukrainian_i                                 0x6a6
/**
 * @nodoc 
 */
#define UIK_Ukranian_i                                  0x6a6  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_Ukrainian_yi                                0x6a7
/**
 * @nodoc 
 */
#define UIK_Ukranian_yi                                 0x6a7  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_Cyrillic_je                                 0x6a8
/**
 * @nodoc 
 */
#define UIK_Serbian_je                                  0x6a8  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_Cyrillic_lje                                0x6a9
/**
 * @nodoc 
 */
#define UIK_Serbian_lje                                 0x6a9  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_Cyrillic_nje                                0x6aa
/**
 * @nodoc 
 */
#define UIK_Serbian_nje                                 0x6aa  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_Serbian_tshe                                0x6ab
/**
 * @nodoc 
 */
#define UIK_Macedonia_kje                               0x6ac
/**
 * @nodoc 
 */
#define UIK_Byelorussian_shortu                         0x6ae
/**
 * @nodoc 
 */
#define UIK_Cyrillic_dzhe                               0x6af
/**
 * @nodoc 
 */
#define UIK_Serbian_dze                                 0x6af  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_numerosign                                  0x6b0
/**
 * @nodoc 
 */
#define UIK_Serbian_DJE                                 0x6b1
/**
 * @nodoc 
 */
#define UIK_Macedonia_GJE                               0x6b2
/**
 * @nodoc 
 */
#define UIK_Cyrillic_IO                                 0x6b3
/**
 * @nodoc 
 */
#define UIK_Ukrainian_IE                                0x6b4
/**
 * @nodoc 
 */
#define UIK_Ukranian_JE                                 0x6b4  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_Macedonia_DSE                               0x6b5
/**
 * @nodoc 
 */
#define UIK_Ukrainian_I                                 0x6b6
/**
 * @nodoc 
 */
#define UIK_Ukranian_I                                  0x6b6  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_Ukrainian_YI                                0x6b7
/**
 * @nodoc 
 */
#define UIK_Ukranian_YI                                 0x6b7  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_Cyrillic_JE                                 0x6b8
/**
 * @nodoc 
 */
#define UIK_Serbian_JE                                  0x6b8  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_Cyrillic_LJE                                0x6b9
/**
 * @nodoc 
 */
#define UIK_Serbian_LJE                                 0x6b9  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_Cyrillic_NJE                                0x6ba
/**
 * @nodoc 
 */
#define UIK_Serbian_NJE                                 0x6ba  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_Serbian_TSHE                                0x6bb
/**
 * @nodoc 
 */
#define UIK_Macedonia_KJE                               0x6bc
/**
 * @nodoc 
 */
#define UIK_Byelorussian_SHORTU                         0x6be
/**
 * @nodoc 
 */
#define UIK_Cyrillic_DZHE                               0x6bf
/**
 * @nodoc 
 */
#define UIK_Serbian_DZE                                 0x6bf  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_Cyrillic_yu                                 0x6c0
/**
 * @nodoc 
 */
#define UIK_Cyrillic_a                                  0x6c1
/**
 * @nodoc 
 */
#define UIK_Cyrillic_be                                 0x6c2
/**
 * @nodoc 
 */
#define UIK_Cyrillic_tse                                0x6c3
/**
 * @nodoc 
 */
#define UIK_Cyrillic_de                                 0x6c4
/**
 * @nodoc 
 */
#define UIK_Cyrillic_ie                                 0x6c5
/**
 * @nodoc 
 */
#define UIK_Cyrillic_ef                                 0x6c6
/**
 * @nodoc 
 */
#define UIK_Cyrillic_ghe                                0x6c7
/**
 * @nodoc 
 */
#define UIK_Cyrillic_ha                                 0x6c8
/**
 * @nodoc 
 */
#define UIK_Cyrillic_i                                  0x6c9
/**
 * @nodoc 
 */
#define UIK_Cyrillic_shorti                             0x6ca
/**
 * @nodoc 
 */
#define UIK_Cyrillic_ka                                 0x6cb
/**
 * @nodoc 
 */
#define UIK_Cyrillic_el                                 0x6cc
/**
 * @nodoc 
 */
#define UIK_Cyrillic_em                                 0x6cd
/**
 * @nodoc 
 */
#define UIK_Cyrillic_en                                 0x6ce
/**
 * @nodoc 
 */
#define UIK_Cyrillic_o                                  0x6cf
/**
 * @nodoc 
 */
#define UIK_Cyrillic_pe                                 0x6d0
/**
 * @nodoc 
 */
#define UIK_Cyrillic_ya                                 0x6d1
/**
 * @nodoc 
 */
#define UIK_Cyrillic_er                                 0x6d2
/**
 * @nodoc 
 */
#define UIK_Cyrillic_es                                 0x6d3
/**
 * @nodoc 
 */
#define UIK_Cyrillic_te                                 0x6d4
/**
 * @nodoc 
 */
#define UIK_Cyrillic_u                                  0x6d5
/**
 * @nodoc 
 */
#define UIK_Cyrillic_zhe                                0x6d6
/**
 * @nodoc 
 */
#define UIK_Cyrillic_ve                                 0x6d7
/**
 * @nodoc 
 */
#define UIK_Cyrillic_softsign                           0x6d8
/**
 * @nodoc 
 */
#define UIK_Cyrillic_yeru                               0x6d9
/**
 * @nodoc 
 */
#define UIK_Cyrillic_ze                                 0x6da
/**
 * @nodoc 
 */
#define UIK_Cyrillic_sha                                0x6db
/**
 * @nodoc 
 */
#define UIK_Cyrillic_e                                  0x6dc
/**
 * @nodoc 
 */
#define UIK_Cyrillic_shcha                              0x6dd
/**
 * @nodoc 
 */
#define UIK_Cyrillic_che                                0x6de
/**
 * @nodoc 
 */
#define UIK_Cyrillic_hardsign                           0x6df
/**
 * @nodoc 
 */
#define UIK_Cyrillic_YU                                 0x6e0
/**
 * @nodoc 
 */
#define UIK_Cyrillic_A                                  0x6e1
/**
 * @nodoc 
 */
#define UIK_Cyrillic_BE                                 0x6e2
/**
 * @nodoc 
 */
#define UIK_Cyrillic_TSE                                0x6e3
/**
 * @nodoc 
 */
#define UIK_Cyrillic_DE                                 0x6e4
/**
 * @nodoc 
 */
#define UIK_Cyrillic_IE                                 0x6e5
/**
 * @nodoc 
 */
#define UIK_Cyrillic_EF                                 0x6e6
/**
 * @nodoc 
 */
#define UIK_Cyrillic_GHE                                0x6e7
/**
 * @nodoc 
 */
#define UIK_Cyrillic_HA                                 0x6e8
/**
 * @nodoc 
 */
#define UIK_Cyrillic_I                                  0x6e9
/**
 * @nodoc 
 */
#define UIK_Cyrillic_SHORTI                             0x6ea
/**
 * @nodoc 
 */
#define UIK_Cyrillic_KA                                 0x6eb
/**
 * @nodoc 
 */
#define UIK_Cyrillic_EL                                 0x6ec
/**
 * @nodoc 
 */
#define UIK_Cyrillic_EM                                 0x6ed
/**
 * @nodoc 
 */
#define UIK_Cyrillic_EN                                 0x6ee
/**
 * @nodoc 
 */
#define UIK_Cyrillic_O                                  0x6ef
/**
 * @nodoc 
 */
#define UIK_Cyrillic_PE                                 0x6f0
/**
 * @nodoc 
 */
#define UIK_Cyrillic_YA                                 0x6f1
/**
 * @nodoc 
 */
#define UIK_Cyrillic_ER                                 0x6f2
/**
 * @nodoc 
 */
#define UIK_Cyrillic_ES                                 0x6f3
/**
 * @nodoc 
 */
#define UIK_Cyrillic_TE                                 0x6f4
/**
 * @nodoc 
 */
#define UIK_Cyrillic_U                                  0x6f5
/**
 * @nodoc 
 */
#define UIK_Cyrillic_ZHE                                0x6f6
/**
 * @nodoc 
 */
#define UIK_Cyrillic_VE                                 0x6f7
/**
 * @nodoc 
 */
#define UIK_Cyrillic_SOFTSIGN                           0x6f8
/**
 * @nodoc 
 */
#define UIK_Cyrillic_YERU                               0x6f9
/**
 * @nodoc 
 */
#define UIK_Cyrillic_ZE                                 0x6fa
/**
 * @nodoc 
 */
#define UIK_Cyrillic_SHA                                0x6fb
/**
 * @nodoc 
 */
#define UIK_Cyrillic_E                                  0x6fc
/**
 * @nodoc 
 */
#define UIK_Cyrillic_SHCHA                              0x6fd
/**
 * @nodoc 
 */
#define UIK_Cyrillic_CHE                                0x6fe
/**
 * @nodoc 
 */
#define UIK_Cyrillic_HARDSIGN                           0x6ff
/**
 * @nodoc 
 */
#define UIK_Greek_ALPHAaccent                           0x7a1
/**
 * @nodoc 
 */
#define UIK_Greek_EPSILONaccent                         0x7a2
/**
 * @nodoc 
 */
#define UIK_Greek_ETAaccent                             0x7a3
/**
 * @nodoc 
 */
#define UIK_Greek_IOTAaccent                            0x7a4
/**
 * @nodoc 
 */
#define UIK_Greek_IOTAdiaeresis                         0x7a5
/**
 * @nodoc 
 */
#define UIK_Greek_OMICRONaccent                         0x7a7
/**
 * @nodoc 
 */
#define UIK_Greek_UPSILONaccent                         0x7a8
/**
 * @nodoc 
 */
#define UIK_Greek_UPSILONdieresis                       0x7a9
/**
 * @nodoc 
 */
#define UIK_Greek_OMEGAaccent                           0x7ab
/**
 * @nodoc 
 */
#define UIK_Greek_accentdieresis                        0x7ae
/**
 * @nodoc 
 */
#define UIK_Greek_horizbar                              0x7af
/**
 * @nodoc 
 */
#define UIK_Greek_alphaaccent                           0x7b1
/**
 * @nodoc 
 */
#define UIK_Greek_epsilonaccent                         0x7b2
/**
 * @nodoc 
 */
#define UIK_Greek_etaaccent                             0x7b3
/**
 * @nodoc 
 */
#define UIK_Greek_iotaaccent                            0x7b4
/**
 * @nodoc 
 */
#define UIK_Greek_iotadieresis                          0x7b5
/**
 * @nodoc 
 */
#define UIK_Greek_iotaaccentdieresis                    0x7b6
/**
 * @nodoc 
 */
#define UIK_Greek_omicronaccent                         0x7b7
/**
 * @nodoc 
 */
#define UIK_Greek_upsilonaccent                         0x7b8
/**
 * @nodoc 
 */
#define UIK_Greek_upsilondieresis                       0x7b9
/**
 * @nodoc 
 */
#define UIK_Greek_upsilonaccentdieresis                 0x7ba
/**
 * @nodoc 
 */
#define UIK_Greek_omegaaccent                           0x7bb
/**
 * @nodoc 
 */
#define UIK_Greek_ALPHA                                 0x7c1
/**
 * @nodoc 
 */
#define UIK_Greek_BETA                                  0x7c2
/**
 * @nodoc 
 */
#define UIK_Greek_GAMMA                                 0x7c3
/**
 * @nodoc 
 */
#define UIK_Greek_DELTA                                 0x7c4
/**
 * @nodoc 
 */
#define UIK_Greek_EPSILON                               0x7c5
/**
 * @nodoc 
 */
#define UIK_Greek_ZETA                                  0x7c6
/**
 * @nodoc 
 */
#define UIK_Greek_ETA                                   0x7c7
/**
 * @nodoc 
 */
#define UIK_Greek_THETA                                 0x7c8
/**
 * @nodoc 
 */
#define UIK_Greek_IOTA                                  0x7c9
/**
 * @nodoc 
 */
#define UIK_Greek_KAPPA                                 0x7ca
/**
 * @nodoc 
 */
#define UIK_Greek_LAMDA                                 0x7cb
/**
 * @nodoc 
 */
#define UIK_Greek_LAMBDA                                0x7cb
/**
 * @nodoc 
 */
#define UIK_Greek_MU                                    0x7cc
/**
 * @nodoc 
 */
#define UIK_Greek_NU                                    0x7cd
/**
 * @nodoc 
 */
#define UIK_Greek_XI                                    0x7ce
/**
 * @nodoc 
 */
#define UIK_Greek_OMICRON                               0x7cf
/**
 * @nodoc 
 */
#define UIK_Greek_PI                                    0x7d0
/**
 * @nodoc 
 */
#define UIK_Greek_RHO                                   0x7d1
/**
 * @nodoc 
 */
#define UIK_Greek_SIGMA                                 0x7d2
/**
 * @nodoc 
 */
#define UIK_Greek_TAU                                   0x7d4
/**
 * @nodoc 
 */
#define UIK_Greek_UPSILON                               0x7d5
/**
 * @nodoc 
 */
#define UIK_Greek_PHI                                   0x7d6
/**
 * @nodoc 
 */
#define UIK_Greek_CHI                                   0x7d7
/**
 * @nodoc 
 */
#define UIK_Greek_PSI                                   0x7d8
/**
 * @nodoc 
 */
#define UIK_Greek_OMEGA                                 0x7d9
/**
 * @nodoc 
 */
#define UIK_Greek_alpha                                 0x7e1
/**
 * @nodoc 
 */
#define UIK_Greek_beta                                  0x7e2
/**
 * @nodoc 
 */
#define UIK_Greek_gamma                                 0x7e3
/**
 * @nodoc 
 */
#define UIK_Greek_delta                                 0x7e4
/**
 * @nodoc 
 */
#define UIK_Greek_epsilon                               0x7e5
/**
 * @nodoc 
 */
#define UIK_Greek_zeta                                  0x7e6
/**
 * @nodoc 
 */
#define UIK_Greek_eta                                   0x7e7
/**
 * @nodoc 
 */
#define UIK_Greek_theta                                 0x7e8
/**
 * @nodoc 
 */
#define UIK_Greek_iota                                  0x7e9
/**
 * @nodoc 
 */
#define UIK_Greek_kappa                                 0x7ea
/**
 * @nodoc 
 */
#define UIK_Greek_lamda                                 0x7eb
/**
 * @nodoc 
 */
#define UIK_Greek_lambda                                0x7eb
/**
 * @nodoc 
 */
#define UIK_Greek_mu                                    0x7ec
/**
 * @nodoc 
 */
#define UIK_Greek_nu                                    0x7ed
/**
 * @nodoc 
 */
#define UIK_Greek_xi                                    0x7ee
/**
 * @nodoc 
 */
#define UIK_Greek_omicron                               0x7ef
/**
 * @nodoc 
 */
#define UIK_Greek_pi                                    0x7f0
/**
 * @nodoc 
 */
#define UIK_Greek_rho                                   0x7f1
/**
 * @nodoc 
 */
#define UIK_Greek_sigma                                 0x7f2
/**
 * @nodoc 
 */
#define UIK_Greek_finalsmallsigma                       0x7f3
/**
 * @nodoc 
 */
#define UIK_Greek_tau                                   0x7f4
/**
 * @nodoc 
 */
#define UIK_Greek_upsilon                               0x7f5
/**
 * @nodoc 
 */
#define UIK_Greek_phi                                   0x7f6
/**
 * @nodoc 
 */
#define UIK_Greek_chi                                   0x7f7
/**
 * @nodoc 
 */
#define UIK_Greek_psi                                   0x7f8
/**
 * @nodoc 
 */
#define UIK_Greek_omega                                 0x7f9
/**
 * @nodoc 
 */
#define UIK_Greek_switch         0xFF7E  /* Alias for mode_switch */
/**
 * @nodoc 
 */
#define UIK_leftradical                                 0x8a1
/**
 * @nodoc 
 */
#define UIK_topleftradical                              0x8a2
/**
 * @nodoc 
 */
#define UIK_horizconnector                              0x8a3
/**
 * @nodoc 
 */
#define UIK_topintegral                                 0x8a4
/**
 * @nodoc 
 */
#define UIK_botintegral                                 0x8a5
/**
 * @nodoc 
 */
#define UIK_vertconnector                               0x8a6
/**
 * @nodoc 
 */
#define UIK_topleftsqbracket                            0x8a7
/**
 * @nodoc 
 */
#define UIK_botleftsqbracket                            0x8a8
/**
 * @nodoc 
 */
#define UIK_toprightsqbracket                           0x8a9
/**
 * @nodoc 
 */
#define UIK_botrightsqbracket                           0x8aa
/**
 * @nodoc 
 */
#define UIK_topleftparens                               0x8ab
/**
 * @nodoc 
 */
#define UIK_botleftparens                               0x8ac
/**
 * @nodoc 
 */
#define UIK_toprightparens                              0x8ad
/**
 * @nodoc 
 */
#define UIK_botrightparens                              0x8ae
/**
 * @nodoc 
 */
#define UIK_leftmiddlecurlybrace                        0x8af
/**
 * @nodoc 
 */
#define UIK_rightmiddlecurlybrace                       0x8b0
/**
 * @nodoc 
 */
#define UIK_topleftsummation                            0x8b1
/**
 * @nodoc 
 */
#define UIK_botleftsummation                            0x8b2
/**
 * @nodoc 
 */
#define UIK_topvertsummationconnector                   0x8b3
/**
 * @nodoc 
 */
#define UIK_botvertsummationconnector                   0x8b4
/**
 * @nodoc 
 */
#define UIK_toprightsummation                           0x8b5
/**
 * @nodoc 
 */
#define UIK_botrightsummation                           0x8b6
/**
 * @nodoc 
 */
#define UIK_rightmiddlesummation                        0x8b7
/**
 * @nodoc 
 */
#define UIK_lessthanequal                               0x8bc
/**
 * @nodoc 
 */
#define UIK_notequal                                    0x8bd
/**
 * @nodoc 
 */
#define UIK_greaterthanequal                            0x8be
/**
 * @nodoc 
 */
#define UIK_integral                                    0x8bf
/**
 * @nodoc 
 */
#define UIK_therefore                                   0x8c0
/**
 * @nodoc 
 */
#define UIK_variation                                   0x8c1
/**
 * @nodoc 
 */
#define UIK_infinity                                    0x8c2
/**
 * @nodoc 
 */
#define UIK_nabla                                       0x8c5
/**
 * @nodoc 
 */
#define UIK_approximate                                 0x8c8
/**
 * @nodoc 
 */
#define UIK_similarequal                                0x8c9
/**
 * @nodoc 
 */
#define UIK_ifonlyif                                    0x8cd
/**
 * @nodoc 
 */
#define UIK_implies                                     0x8ce
/**
 * @nodoc 
 */
#define UIK_identical                                   0x8cf
/**
 * @nodoc 
 */
#define UIK_radical                                     0x8d6
/**
 * @nodoc 
 */
#define UIK_includedin                                  0x8da
/**
 * @nodoc 
 */
#define UIK_includes                                    0x8db
/**
 * @nodoc 
 */
#define UIK_intersection                                0x8dc
/**
 * @nodoc 
 */
#define UIK_union                                       0x8dd
/**
 * @nodoc 
 */
#define UIK_logicaland                                  0x8de
/**
 * @nodoc 
 */
#define UIK_logicalor                                   0x8df
/**
 * @nodoc 
 */
#define UIK_partialderivative                           0x8ef
/**
 * @nodoc 
 */
#define UIK_function                                    0x8f6
/**
 * @nodoc 
 */
#define UIK_leftarrow                                   0x8fb
/**
 * @nodoc 
 */
#define UIK_uparrow                                     0x8fc
/**
 * @nodoc 
 */
#define UIK_rightarrow                                  0x8fd
/**
 * @nodoc 
 */
#define UIK_downarrow                                   0x8fe
/**
 * @nodoc 
 */
#define UIK_blank                                       0x9df
/**
 * @nodoc 
 */
#define UIK_soliddiamond                                0x9e0
/**
 * @nodoc 
 */
#define UIK_checkerboard                                0x9e1
/**
 * @nodoc 
 */
#define UIK_ht                                          0x9e2
/**
 * @nodoc 
 */
#define UIK_ff                                          0x9e3
/**
 * @nodoc 
 */
#define UIK_cr                                          0x9e4
/**
 * @nodoc 
 */
#define UIK_lf                                          0x9e5
/**
 * @nodoc 
 */
#define UIK_nl                                          0x9e8
/**
 * @nodoc 
 */
#define UIK_vt                                          0x9e9
/**
 * @nodoc 
 */
#define UIK_lowrightcorner                              0x9ea
/**
 * @nodoc 
 */
#define UIK_uprightcorner                               0x9eb
/**
 * @nodoc 
 */
#define UIK_upleftcorner                                0x9ec
/**
 * @nodoc 
 */
#define UIK_lowleftcorner                               0x9ed
/**
 * @nodoc 
 */
#define UIK_crossinglines                               0x9ee
/**
 * @nodoc 
 */
#define UIK_horizlinescan1                              0x9ef
/**
 * @nodoc 
 */
#define UIK_horizlinescan3                              0x9f0
/**
 * @nodoc 
 */
#define UIK_horizlinescan5                              0x9f1
/**
 * @nodoc 
 */
#define UIK_horizlinescan7                              0x9f2
/**
 * @nodoc 
 */
#define UIK_horizlinescan9                              0x9f3
/**
 * @nodoc 
 */
#define UIK_leftt                                       0x9f4
/**
 * @nodoc 
 */
#define UIK_rightt                                      0x9f5
/**
 * @nodoc 
 */
#define UIK_bott                                        0x9f6
/**
 * @nodoc 
 */
#define UIK_topt                                        0x9f7
/**
 * @nodoc 
 */
#define UIK_vertbar                                     0x9f8
/**
 * @nodoc 
 */
#define UIK_emspace                                     0xaa1
/**
 * @nodoc 
 */
#define UIK_enspace                                     0xaa2
/**
 * @nodoc 
 */
#define UIK_em3space                                    0xaa3
/**
 * @nodoc 
 */
#define UIK_em4space                                    0xaa4
/**
 * @nodoc 
 */
#define UIK_digitspace                                  0xaa5
/**
 * @nodoc 
 */
#define UIK_punctspace                                  0xaa6
/**
 * @nodoc 
 */
#define UIK_thinspace                                   0xaa7
/**
 * @nodoc 
 */
#define UIK_hairspace                                   0xaa8
/**
 * @nodoc 
 */
#define UIK_emdash                                      0xaa9
/**
 * @nodoc 
 */
#define UIK_endash                                      0xaaa
/**
 * @nodoc 
 */
#define UIK_signifblank                                 0xaac
/**
 * @nodoc 
 */
#define UIK_ellipsis                                    0xaae
/**
 * @nodoc 
 */
#define UIK_doubbaselinedot                             0xaaf
/**
 * @nodoc 
 */
#define UIK_onethird                                    0xab0
/**
 * @nodoc 
 */
#define UIK_twothirds                                   0xab1
/**
 * @nodoc 
 */
#define UIK_onefifth                                    0xab2
/**
 * @nodoc 
 */
#define UIK_twofifths                                   0xab3
/**
 * @nodoc 
 */
#define UIK_threefifths                                 0xab4
/**
 * @nodoc 
 */
#define UIK_fourfifths                                  0xab5
/**
 * @nodoc 
 */
#define UIK_onesixth                                    0xab6
/**
 * @nodoc 
 */
#define UIK_fivesixths                                  0xab7
/**
 * @nodoc 
 */
#define UIK_careof                                      0xab8
/**
 * @nodoc 
 */
#define UIK_figdash                                     0xabb
/**
 * @nodoc 
 */
#define UIK_leftanglebracket                            0xabc
/**
 * @nodoc 
 */
#define UIK_decimalpoint                                0xabd
/**
 * @nodoc 
 */
#define UIK_rightanglebracket                           0xabe
/**
 * @nodoc 
 */
#define UIK_marker                                      0xabf
/**
 * @nodoc 
 */
#define UIK_oneeighth                                   0xac3
/**
 * @nodoc 
 */
#define UIK_threeeighths                                0xac4
/**
 * @nodoc 
 */
#define UIK_fiveeighths                                 0xac5
/**
 * @nodoc 
 */
#define UIK_seveneighths                                0xac6
/**
 * @nodoc 
 */
#define UIK_trademark                                   0xac9
/**
 * @nodoc 
 */
#define UIK_signaturemark                               0xaca
/**
 * @nodoc 
 */
#define UIK_trademarkincircle                           0xacb
/**
 * @nodoc 
 */
#define UIK_leftopentriangle                            0xacc
/**
 * @nodoc 
 */
#define UIK_rightopentriangle                           0xacd
/**
 * @nodoc 
 */
#define UIK_emopencircle                                0xace
/**
 * @nodoc 
 */
#define UIK_emopenrectangle                             0xacf
/**
 * @nodoc 
 */
#define UIK_leftsinglequotemark                         0xad0
/**
 * @nodoc 
 */
#define UIK_rightsinglequotemark                        0xad1
/**
 * @nodoc 
 */
#define UIK_leftdoublequotemark                         0xad2
/**
 * @nodoc 
 */
#define UIK_rightdoublequotemark                        0xad3
/**
 * @nodoc 
 */
#define UIK_prescription                                0xad4
/**
 * @nodoc 
 */
#define UIK_minutes                                     0xad6
/**
 * @nodoc 
 */
#define UIK_seconds                                     0xad7
/**
 * @nodoc 
 */
#define UIK_latincross                                  0xad9
/**
 * @nodoc 
 */
#define UIK_hexagram                                    0xada
/**
 * @nodoc 
 */
#define UIK_filledrectbullet                            0xadb
/**
 * @nodoc 
 */
#define UIK_filledlefttribullet                         0xadc
/**
 * @nodoc 
 */
#define UIK_filledrighttribullet                        0xadd
/**
 * @nodoc 
 */
#define UIK_emfilledcircle                              0xade
/**
 * @nodoc 
 */
#define UIK_emfilledrect                                0xadf
/**
 * @nodoc 
 */
#define UIK_enopencircbullet                            0xae0
/**
 * @nodoc 
 */
#define UIK_enopensquarebullet                          0xae1
/**
 * @nodoc 
 */
#define UIK_openrectbullet                              0xae2
/**
 * @nodoc 
 */
#define UIK_opentribulletup                             0xae3
/**
 * @nodoc 
 */
#define UIK_opentribulletdown                           0xae4
/**
 * @nodoc 
 */
#define UIK_openstar                                    0xae5
/**
 * @nodoc 
 */
#define UIK_enfilledcircbullet                          0xae6
/**
 * @nodoc 
 */
#define UIK_enfilledsqbullet                            0xae7
/**
 * @nodoc 
 */
#define UIK_filledtribulletup                           0xae8
/**
 * @nodoc 
 */
#define UIK_filledtribulletdown                         0xae9
/**
 * @nodoc 
 */
#define UIK_leftpointer                                 0xaea
/**
 * @nodoc 
 */
#define UIK_rightpointer                                0xaeb
/**
 * @nodoc 
 */
#define UIK_club                                        0xaec
/**
 * @nodoc 
 */
#define UIK_diamond                                     0xaed
/**
 * @nodoc 
 */
#define UIK_heart                                       0xaee
/**
 * @nodoc 
 */
#define UIK_maltesecross                                0xaf0
/**
 * @nodoc 
 */
#define UIK_dagger                                      0xaf1
/**
 * @nodoc 
 */
#define UIK_doubledagger                                0xaf2
/**
 * @nodoc 
 */
#define UIK_checkmark                                   0xaf3
/**
 * @nodoc 
 */
#define UIK_ballotcross                                 0xaf4
/**
 * @nodoc 
 */
#define UIK_musicalsharp                                0xaf5
/**
 * @nodoc 
 */
#define UIK_musicalflat                                 0xaf6
/**
 * @nodoc 
 */
#define UIK_malesymbol                                  0xaf7
/**
 * @nodoc 
 */
#define UIK_femalesymbol                                0xaf8
/**
 * @nodoc 
 */
#define UIK_telephone                                   0xaf9
/**
 * @nodoc 
 */
#define UIK_telephonerecorder                           0xafa
/**
 * @nodoc 
 */
#define UIK_phonographcopyright                         0xafb
/**
 * @nodoc 
 */
#define UIK_caret                                       0xafc
/**
 * @nodoc 
 */
#define UIK_singlelowquotemark                          0xafd
/**
 * @nodoc 
 */
#define UIK_doublelowquotemark                          0xafe
/**
 * @nodoc 
 */
#define UIK_cursor                                      0xaff
/**
 * @nodoc 
 */
#define UIK_leftcaret                                   0xba3
/**
 * @nodoc 
 */
#define UIK_rightcaret                                  0xba6
/**
 * @nodoc 
 */
#define UIK_downcaret                                   0xba8
/**
 * @nodoc 
 */
#define UIK_upcaret                                     0xba9
/**
 * @nodoc 
 */
#define UIK_overbar                                     0xbc0
/**
 * @nodoc 
 */
#define UIK_downtack                                    0xbc2
/**
 * @nodoc 
 */
#define UIK_upshoe                                      0xbc3
/**
 * @nodoc 
 */
#define UIK_downstile                                   0xbc4
/**
 * @nodoc 
 */
#define UIK_underbar                                    0xbc6
/**
 * @nodoc 
 */
#define UIK_jot                                         0xbca
/**
 * @nodoc 
 */
#define UIK_quad                                        0xbcc
/**
 * @nodoc 
 */
#define UIK_uptack                                      0xbce
/**
 * @nodoc 
 */
#define UIK_circle                                      0xbcf
/**
 * @nodoc 
 */
#define UIK_upstile                                     0xbd3
/**
 * @nodoc 
 */
#define UIK_downshoe                                    0xbd6
/**
 * @nodoc 
 */
#define UIK_rightshoe                                   0xbd8
/**
 * @nodoc 
 */
#define UIK_leftshoe                                    0xbda
/**
 * @nodoc 
 */
#define UIK_lefttack                                    0xbdc
/**
 * @nodoc 
 */
#define UIK_righttack                                   0xbfc
/**
 * @nodoc 
 */
#define UIK_hebrew_doublelowline                        0xcdf
/**
 * @nodoc 
 */
#define UIK_hebrew_aleph                                0xce0
/**
 * @nodoc 
 */
#define UIK_hebrew_bet                                  0xce1
/**
 * @nodoc 
 */
#define UIK_hebrew_beth                                 0xce1  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_hebrew_gimel                                0xce2
/**
 * @nodoc 
 */
#define UIK_hebrew_gimmel                               0xce2  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_hebrew_dalet                                0xce3
/**
 * @nodoc 
 */
#define UIK_hebrew_daleth                               0xce3  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_hebrew_he                                   0xce4
/**
 * @nodoc 
 */
#define UIK_hebrew_waw                                  0xce5
/**
 * @nodoc 
 */
#define UIK_hebrew_zain                                 0xce6
/**
 * @nodoc 
 */
#define UIK_hebrew_zayin                                0xce6  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_hebrew_chet                                 0xce7
/**
 * @nodoc 
 */
#define UIK_hebrew_het                                  0xce7  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_hebrew_tet                                  0xce8
/**
 * @nodoc 
 */
#define UIK_hebrew_teth                                 0xce8  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_hebrew_yod                                  0xce9
/**
 * @nodoc 
 */
#define UIK_hebrew_finalkaph                            0xcea
/**
 * @nodoc 
 */
#define UIK_hebrew_kaph                                 0xceb
/**
 * @nodoc 
 */
#define UIK_hebrew_lamed                                0xcec
/**
 * @nodoc 
 */
#define UIK_hebrew_finalmem                             0xced
/**
 * @nodoc 
 */
#define UIK_hebrew_mem                                  0xcee
/**
 * @nodoc 
 */
#define UIK_hebrew_finalnun                             0xcef
/**
 * @nodoc 
 */
#define UIK_hebrew_nun                                  0xcf0
/**
 * @nodoc 
 */
#define UIK_hebrew_samech                               0xcf1
/**
 * @nodoc 
 */
#define UIK_hebrew_samekh                               0xcf1  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_hebrew_ayin                                 0xcf2
/**
 * @nodoc 
 */
#define UIK_hebrew_finalpe                              0xcf3
/**
 * @nodoc 
 */
#define UIK_hebrew_pe                                   0xcf4
/**
 * @nodoc 
 */
#define UIK_hebrew_finalzade                            0xcf5
/**
 * @nodoc 
 */
#define UIK_hebrew_finalzadi                            0xcf5  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_hebrew_zade                                 0xcf6
/**
 * @nodoc 
 */
#define UIK_hebrew_zadi                                 0xcf6  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_hebrew_qoph                                 0xcf7
/**
 * @nodoc 
 */
#define UIK_hebrew_kuf                                  0xcf7  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_hebrew_resh                                 0xcf8
/**
 * @nodoc 
 */
#define UIK_hebrew_shin                                 0xcf9
/**
 * @nodoc 
 */
#define UIK_hebrew_taw                                  0xcfa
/**
 * @nodoc 
 */
#define UIK_hebrew_taf                                  0xcfa  /* deprecated */
/**
 * @nodoc 
 */
#define UIK_Hebrew_switch        0xFF7E  /* Alias for mode_switch */
