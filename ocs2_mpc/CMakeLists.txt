cmake_minimum_required(VERSION 3.14)
project(ocs2_mpc)

# 系统依赖
find_package(Eigen3 3.3 REQUIRED NO_MODULE)
find_package(Boost REQUIRED COMPONENTS system filesystem)
find_package(Threads REQUIRED)

# 编译选项
include(cmake/ocs2_cxx_flags.cmake OPTIONAL)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 自动添加所有源文件
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp)

# 添加库
add_library(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME}
  PUBLIC ocs2_core
  PUBLIC ocs2_oc
  PUBLIC Eigen3::Eigen
  PUBLIC Threads::Threads
  PUBLIC ${Boost_LIBRARIES}
)

target_compile_options(${PROJECT_NAME} PUBLIC ${OCS2_CXX_FLAGS})
target_include_directories(${PROJECT_NAME} PUBLIC include)

# lintTarget 可选构建工具
add_executable(${PROJECT_NAME}_lintTarget src/lintTarget.cpp)
target_link_libraries(${PROJECT_NAME}_lintTarget PRIVATE ${PROJECT_NAME})

# Clang tooling（可选）
find_package(cmake_clang_tools QUIET)
if(cmake_clang_tools_FOUND)
  add_clang_tooling(
    TARGETS ${PROJECT_NAME}_lintTarget
    SOURCE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/src ${CMAKE_CURRENT_SOURCE_DIR}/include
    CT_HEADER_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include
    CF_WERROR
  )
endif()

# 安装（可选）
# install(TARGETS ${PROJECT_NAME} DESTINATION lib)
# install(DIRECTORY include/ DESTINATION include)
