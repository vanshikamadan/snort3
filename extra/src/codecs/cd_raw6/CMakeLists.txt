cmake_minimum_required ( VERSION 2.8.11 )
project ( cd_raw6 CXX )

if ( APPLE )
    set ( CMAKE_MACOSX_RPATH OFF )
endif ( APPLE )

include ( FindPkgConfig )
pkg_search_module ( SNORT3 REQUIRED snort>=3 )

add_library (
    cd_raw6 MODULE
    cd_raw6.cc
)

if ( APPLE )
    set_target_properties (
        cd_raw6
        PROPERTIES
            LINK_FLAGS "-undefined dynamic_lookup"
    )
endif ( APPLE )

set_target_properties (
    cd_raw6
    PROPERTIES
        PREFIX ""
)

set ( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )

target_include_directories (
    cd_raw6 PUBLIC
    ${SNORT3_INCLUDE_DIRS}
)

install (
    TARGETS cd_raw6
    LIBRARY
        DESTINATION "lib/${CMAKE_PROJECT_NAME}/codecs"
)
