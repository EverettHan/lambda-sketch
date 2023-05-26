#ifndef CATDlgLinuxEmbedResource_H
#define CATDlgLinuxEmbedResource_H

#ifdef _LINUX_SOURCE

#if defined(__aarch64__)
// Linux ARM
// No way to embed binary data for now, not really useful for now
#define DECLARE_APPLICATION_ICON(name) \
char app_icon = '\0'; \
int app_icon_size = 0;

#else

// Thanks to https://stackoverflow.com/questions/7288279/how-to-embed-a-file-into-an-executable
// We can embed binary data inside executable on Linux too

//
// Usage
// To embed "sample.png" and access it as sample_buffer / sample_buffer_size
//    BINDATA(sample_buffer, sample.png)
// Then, data is available as &sample_buffer, and its size is sample_buffer_size
//

__asm__(
".altmacro\n" \
".macro binfile p q\n" \
"   .global \\p\n" \
"\\p:\n" \
"   .incbin \\q\n" \
"\\p&_end:\n" \
"   .byte 0\n" \
"   .global \\p&_size\n" \
"\\p&_size:\n" \
"   .int(\\p&_end - \\p)\n" \
".endm\n\t"
);

extern "C" {

#define BINDATA(n, s) \
__asm__("\n\n.data\n\tbinfile " #n " \"" #s "\"\n"); \
extern char n; \
extern int n##_size;

}

//
// Application Icon
//
// To declare the application icon, use
//    DECLARE_APPLICATION_ICON(resource.ico)
// Warning: you must not put double quotes around the icon name
//
// You must add following rule in your application Imakefile.mk
//    LOCAL_LDFLAGS=-rdynamic
//
// To force rebuild automatically when you change the icon resource on disk, you can use following lines in your cpp code
// #ifdef MakeMkmkAwareOfTheDependency
// #include "resource.ico"
// #endif
//
// mkmk will then detect that the include has been modified and rebuild the module even if the include directive is not used by the compiler
//

#define DECLARE_APPLICATION_ICON(name) \
BINDATA(app_icon, name)

#endif

#endif

#endif
