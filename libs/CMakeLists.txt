set(JSON_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/json/src PARENT_SCOPE)

set(BUILD_CPR_TESTS OFF CACHE BOOL "No need for cpr tests, just takes time.")
find_package(CURL)
if(CURL_FOUND)
    set(USE_SYSTEM_CURL ON CACHE BOOL "Use teh system curl")
endif()
add_subdirectory(cpr)