rem 
rem    mktutilc.bat
rem 
rem    Creates tutils_c.lib for MS Visual C++ and moves it to the
rem    appropriate Toolkit directory.
rem 
rem
rem    Version 1.1.0  19-OCT-2003 (BVS)
rem
rem       added -DNON_ANSI_STDIO compile option.
rem
rem    Version 1.0.0  15-SEP-1999 (NJB) 
rem

set cl= /c /O2 -D_COMPLEX_DEFINED -DMSDOS -DOMIT_BLANK_CC -DNON_ANSI_STDIO


for %%f in (*.c) do cl %%f 


dir /b *.obj > temp.lst

link -lib /out:tutils_c.lib  @temp.lst

move tutils_c.lib  ..\..\lib

del *.obj

del temp.lst

