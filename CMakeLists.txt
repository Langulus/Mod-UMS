cmake_minimum_required(VERSION 3.28)
project(LangulusModUMS
    VERSION         1.0.0
    DESCRIPTION     "Module for managing users and permissions"
    HOMEPAGE_URL    https://langulus.com
)

file(GLOB_RECURSE
    LANGULUS_MOD_UMS_SOURCES 
    LIST_DIRECTORIES FALSE CONFIGURE_DEPENDS
    source/*.cpp
)

# Build the module                                                              
add_langulus_mod(LangulusModUMS ${LANGULUS_MOD_UMS_SOURCES})

if(LANGULUS_TESTING)
    enable_testing()
    add_subdirectory(test)
endif()