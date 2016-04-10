INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_SYNC_FFT sync_fft)

FIND_PATH(
    SYNC_FFT_INCLUDE_DIRS
    NAMES sync_fft/api.h
    HINTS $ENV{SYNC_FFT_DIR}/include
        ${PC_SYNC_FFT_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    SYNC_FFT_LIBRARIES
    NAMES gnuradio-sync_fft
    HINTS $ENV{SYNC_FFT_DIR}/lib
        ${PC_SYNC_FFT_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SYNC_FFT DEFAULT_MSG SYNC_FFT_LIBRARIES SYNC_FFT_INCLUDE_DIRS)
MARK_AS_ADVANCED(SYNC_FFT_LIBRARIES SYNC_FFT_INCLUDE_DIRS)

