cmake_minimum_required(VERSION 3.8)
project(robot_description)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra )
endif()

set(THIS_PACKAGE_INCLUDE_DEPENDS
  hardware_interface
  pluginlib
  rclcpp
  rclcpp_lifecycle
)

# find dependencies
find_package(ament_cmake REQUIRED)
foreach(Dependency IN ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS})
  find_package(${Dependency} REQUIRED)
endforeach()

# compile
add_library(
  robot_description
  SHARED
  hardware/carlikebot_system.cpp
)
target_compile_features(robot_description PUBLIC cxx_std_17)
target_include_directories(robot_description PUBLIC
$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/hardware/include>
$<INSTALL_INTERFACE:include/robot_description>
)
ament_target_dependencies(
  robot_description PUBLIC
  ${THIS_PACKAGE_INCLUDE_DEPENDS}
)

target_link_libraries(robot_description PUBLIC serial)

target_compile_definitions(${PROJECT_NAME} PRIVATE "ROBOT_DESCRIPTION_BUILDING_DLL")

# Export hardware plugins
pluginlib_export_plugin_description_file(hardware_interface bicdrive_arduino.xml)

# install
install(
  DIRECTORY hardware/include/
  DESTINATION include/robot_description 
)

install(
  DIRECTORY launch rviz worlds urdf models config hardware
  DESTINATION share/${PROJECT_NAME}
)

install(TARGETS robot_description
  EXPORT export_robot_description
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()


## EXPORTS
ament_export_targets(export_robot_description HAS_LIBRARY_TARGET)
ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_package()
