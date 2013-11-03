import os

env = Environment(
    ENV=os.environ,
    EMHOME='/Users/chad/projects/emscripten',
    CC='$EMHOME/emcc',
    CXX='$EMHOME/em++',
    AR='/opt/local/bin/llvm-link-mp-3.2',
    ARCOM='$AR -o $TARGET $SOURCES',
    RANLIB='$EMHOME/emranlib',
    OBJSUFFIX='.bc',
    LIBSUFFIX='.bc',
    PROGSUFFIX='.html',
    CPPPATH=[
        '#/deps/libogg-1.3.1/include',
        '#/deps/libvorbis-1.3.3/include',
        '$EMHOME/tests/freetype/include',
        '$EMHOME/tests/freealut/include' ],
    CCFLAGS=[
        '-Wall',
        '-Wno-unused-variable',
        '-Wno-warn-absolute-paths',
        '-Wno-unused-function',
        '-Wno-overloaded-virtual',
        '-O0' ],
    LINKFLAGS=[
        '-O0',
        '-s', 'LEGACY_GL_EMULATION=1',
        '-s', 'SAFE_DYNCALLS=1',
        '-s', 'ERROR_ON_UNDEFINED_SYMBOLS=1' ])

Export('env')
SConscript(dirs=['.'], variant_dir='build', duplicate=0)
