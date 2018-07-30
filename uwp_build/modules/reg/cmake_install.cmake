# Install script for directory: C:/Users/Ilir/Projects/UWPOpenCV/opencv_contrib/modules/reg

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/Ilir/Projects/UWPOpenCV/opencv/uwp_build/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/x86/vc14/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Ilir/Projects/UWPOpenCV/opencv/uwp_build/lib/Debug/opencv_reg300d.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/x86/vc14/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Ilir/Projects/UWPOpenCV/opencv/uwp_build/lib/Release/opencv_reg300.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libs")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/x86/vc14/bin" TYPE SHARED_LIBRARY OPTIONAL FILES "C:/Users/Ilir/Projects/UWPOpenCV/opencv/uwp_build/bin/Debug/opencv_reg300d.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/x86/vc14/bin" TYPE SHARED_LIBRARY OPTIONAL FILES "C:/Users/Ilir/Projects/UWPOpenCV/opencv/uwp_build/bin/Release/opencv_reg300.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/reg" TYPE FILE OPTIONAL FILES "C:/Users/Ilir/Projects/UWPOpenCV/opencv_contrib/modules/reg/include/opencv2/reg/map.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/reg" TYPE FILE OPTIONAL FILES "C:/Users/Ilir/Projects/UWPOpenCV/opencv_contrib/modules/reg/include/opencv2/reg/mapaffine.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/reg" TYPE FILE OPTIONAL FILES "C:/Users/Ilir/Projects/UWPOpenCV/opencv_contrib/modules/reg/include/opencv2/reg/mapper.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/reg" TYPE FILE OPTIONAL FILES "C:/Users/Ilir/Projects/UWPOpenCV/opencv_contrib/modules/reg/include/opencv2/reg/mappergradaffine.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/reg" TYPE FILE OPTIONAL FILES "C:/Users/Ilir/Projects/UWPOpenCV/opencv_contrib/modules/reg/include/opencv2/reg/mappergradeuclid.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/reg" TYPE FILE OPTIONAL FILES "C:/Users/Ilir/Projects/UWPOpenCV/opencv_contrib/modules/reg/include/opencv2/reg/mappergradproj.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/reg" TYPE FILE OPTIONAL FILES "C:/Users/Ilir/Projects/UWPOpenCV/opencv_contrib/modules/reg/include/opencv2/reg/mappergradshift.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/reg" TYPE FILE OPTIONAL FILES "C:/Users/Ilir/Projects/UWPOpenCV/opencv_contrib/modules/reg/include/opencv2/reg/mappergradsimilar.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/reg" TYPE FILE OPTIONAL FILES "C:/Users/Ilir/Projects/UWPOpenCV/opencv_contrib/modules/reg/include/opencv2/reg/mapperpyramid.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/reg" TYPE FILE OPTIONAL FILES "C:/Users/Ilir/Projects/UWPOpenCV/opencv_contrib/modules/reg/include/opencv2/reg/mapprojec.hpp")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/opencv2/reg" TYPE FILE OPTIONAL FILES "C:/Users/Ilir/Projects/UWPOpenCV/opencv_contrib/modules/reg/include/opencv2/reg/mapshift.hpp")
endif()

