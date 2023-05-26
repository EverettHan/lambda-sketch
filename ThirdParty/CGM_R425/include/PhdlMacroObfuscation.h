#pragma once

//Obfuscation macros definitions - the definitions below should not be edited during the integration

#define PHDL_OBFUSCATION_KEY1 29 //value between 0 and 256
#define PHDL_OBFUSCATION_KEY2 53 //value between 0 and 256

#define SCS_ObfuscateEven(ch) ch ^ PHDL_OBFUSCATION_KEY1
#define SCS_ObfuscateOdd(ch) (ch + PHDL_OBFUSCATION_KEY2) & 0xff
#define SCS_STRINGIFY(x) #x

#define SCS_ObfuscateStringInitializer(text) SCS_ObfuscateEven(text[0]), SCS_ObfuscateOdd(text[1]), SCS_ObfuscateEven(text[2]), SCS_ObfuscateOdd(text[3]), SCS_ObfuscateEven(text[4]), SCS_ObfuscateOdd(text[5]), SCS_ObfuscateEven(text[6]), SCS_ObfuscateOdd(text[7]), SCS_ObfuscateEven(text[8]), SCS_ObfuscateOdd(text[9]), \
				SCS_ObfuscateEven(text[10]), SCS_ObfuscateOdd(text[11]), SCS_ObfuscateEven(text[12]), SCS_ObfuscateOdd(text[13]), SCS_ObfuscateEven(text[14]), SCS_ObfuscateOdd(text[15]), SCS_ObfuscateEven(text[16]), SCS_ObfuscateOdd(text[17]), SCS_ObfuscateEven(text[18]), SCS_ObfuscateOdd(text[19]), \
				SCS_ObfuscateEven(text[20]), SCS_ObfuscateOdd(text[21]), SCS_ObfuscateEven(text[22]), SCS_ObfuscateOdd(text[23]), SCS_ObfuscateEven(text[24]), SCS_ObfuscateOdd(text[25]), SCS_ObfuscateEven(text[26]), SCS_ObfuscateOdd(text[27]), SCS_ObfuscateEven(text[28]), SCS_ObfuscateOdd(text[29]), \
				SCS_ObfuscateEven(text[30]), SCS_ObfuscateOdd(text[31]), SCS_ObfuscateEven(text[32]), SCS_ObfuscateOdd(text[33]), SCS_ObfuscateEven(text[34]), SCS_ObfuscateOdd(text[35]), SCS_ObfuscateEven(text[36]), SCS_ObfuscateOdd(text[37]), SCS_ObfuscateEven(text[38]), SCS_ObfuscateOdd(text[39]), \
				SCS_ObfuscateEven(text[40]), SCS_ObfuscateOdd(text[41]), SCS_ObfuscateEven(text[42]), SCS_ObfuscateOdd(text[43]), SCS_ObfuscateEven(text[44]), SCS_ObfuscateOdd(text[45]), SCS_ObfuscateEven(text[46]), SCS_ObfuscateOdd(text[47]), SCS_ObfuscateEven(text[48]), SCS_ObfuscateOdd(text[49]), \
				SCS_ObfuscateEven(text[50]), SCS_ObfuscateOdd(text[51]), SCS_ObfuscateEven(text[52]), SCS_ObfuscateOdd(text[53]), SCS_ObfuscateEven(text[54]), SCS_ObfuscateOdd(text[55]), SCS_ObfuscateEven(text[56]), SCS_ObfuscateOdd(text[57]), SCS_ObfuscateEven(text[58]), SCS_ObfuscateOdd(text[59]), \
				SCS_ObfuscateEven(text[60]), SCS_ObfuscateOdd(text[61]), SCS_ObfuscateEven(text[62]), SCS_ObfuscateOdd(text[63]), SCS_ObfuscateEven(text[64]), SCS_ObfuscateOdd(text[65]), SCS_ObfuscateEven(text[66]), SCS_ObfuscateOdd(text[67]), SCS_ObfuscateEven(text[68]), SCS_ObfuscateOdd(text[69]), \
				SCS_ObfuscateEven(text[70]), SCS_ObfuscateOdd(text[71]), SCS_ObfuscateEven(text[72]), SCS_ObfuscateOdd(text[73]), SCS_ObfuscateEven(text[74]), SCS_ObfuscateOdd(text[75]), SCS_ObfuscateEven(text[76]), SCS_ObfuscateOdd(text[77]), SCS_ObfuscateEven(text[78]), SCS_ObfuscateOdd(text[79]), \
				SCS_ObfuscateEven(text[80]), SCS_ObfuscateOdd(text[81]), SCS_ObfuscateEven(text[82]), SCS_ObfuscateOdd(text[83]), SCS_ObfuscateEven(text[84]), SCS_ObfuscateOdd(text[85]), SCS_ObfuscateEven(text[86]), SCS_ObfuscateOdd(text[87]), SCS_ObfuscateEven(text[88]), SCS_ObfuscateOdd(text[89]), \
				SCS_ObfuscateEven(text[90]), SCS_ObfuscateOdd(text[91]), SCS_ObfuscateEven(text[92]), SCS_ObfuscateOdd(text[93]), SCS_ObfuscateEven(text[94]), SCS_ObfuscateOdd(text[95]), SCS_ObfuscateEven(text[96]), SCS_ObfuscateOdd(text[97]), SCS_ObfuscateEven(text[98]), SCS_ObfuscateOdd(text[99]), \
				SCS_ObfuscateEven(text[100]), SCS_ObfuscateOdd(text[101]), SCS_ObfuscateEven(text[102]), SCS_ObfuscateOdd(text[103]), SCS_ObfuscateEven(text[104]), SCS_ObfuscateOdd(text[105]), SCS_ObfuscateEven(text[106]), SCS_ObfuscateOdd(text[107]), SCS_ObfuscateEven(text[108]), SCS_ObfuscateOdd(text[109]), \
				SCS_ObfuscateEven(text[110]), SCS_ObfuscateOdd(text[111]), SCS_ObfuscateEven(text[112]), SCS_ObfuscateOdd(text[113]), SCS_ObfuscateEven(text[114]), SCS_ObfuscateOdd(text[115]), SCS_ObfuscateEven(text[116]), SCS_ObfuscateOdd(text[117]), SCS_ObfuscateEven(text[118]), SCS_ObfuscateOdd(text[119]), \
				SCS_ObfuscateEven(text[120]), SCS_ObfuscateOdd(text[121]), SCS_ObfuscateEven(text[122]), SCS_ObfuscateOdd(text[123]), SCS_ObfuscateEven(text[124]), SCS_ObfuscateOdd(text[125]), SCS_ObfuscateEven(text[126]), SCS_ObfuscateOdd(text[127]), '\0'

#define SCS_ObfuscateKey(key0, key1, key2, key3, key4, key5, key6, key7, key8, key9, key10, key11, key12, key13, key14, key15, key16, key17, key18, key19, key20, key21, key22, key23, key24, key25, key26, key27, key28, key29, key30, key31) { SCS_ObfuscateEven(key0), SCS_ObfuscateOdd(key1), \
				SCS_ObfuscateEven(key2), SCS_ObfuscateOdd(key3), SCS_ObfuscateEven(key4), SCS_ObfuscateOdd(key5), SCS_ObfuscateEven(key6), SCS_ObfuscateOdd(key7), SCS_ObfuscateEven(key8), SCS_ObfuscateOdd(key9), SCS_ObfuscateEven(key10), SCS_ObfuscateOdd(key11), \
				SCS_ObfuscateEven(key12), SCS_ObfuscateOdd(key13), SCS_ObfuscateEven(key14), SCS_ObfuscateOdd(key15), SCS_ObfuscateEven(key16), SCS_ObfuscateOdd(key17), SCS_ObfuscateEven(key18), SCS_ObfuscateOdd(key19), SCS_ObfuscateEven(key20), SCS_ObfuscateOdd(key21), \
				SCS_ObfuscateEven(key22), SCS_ObfuscateOdd(key23), SCS_ObfuscateEven(key24), SCS_ObfuscateOdd(key25), SCS_ObfuscateEven(key26), SCS_ObfuscateOdd(key27), SCS_ObfuscateEven(key28), SCS_ObfuscateOdd(key29), SCS_ObfuscateEven(key30), SCS_ObfuscateOdd(key31) }

#define SCS_ObfuscateString(text) { SCS_ObfuscateStringInitializer(text SCS_STRINGIFY(\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0)) }
