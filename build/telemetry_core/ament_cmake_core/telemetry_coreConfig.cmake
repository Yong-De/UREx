# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_telemetry_core_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED telemetry_core_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(telemetry_core_FOUND FALSE)
  elseif(NOT telemetry_core_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(telemetry_core_FOUND FALSE)
  endif()
  return()
endif()
set(_telemetry_core_CONFIG_INCLUDED TRUE)

# output package information
if(NOT telemetry_core_FIND_QUIETLY)
  message(STATUS "Found telemetry_core: 0.0.0 (${telemetry_core_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'telemetry_core' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT telemetry_core_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(telemetry_core_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${telemetry_core_DIR}/${_extra}")
endforeach()
