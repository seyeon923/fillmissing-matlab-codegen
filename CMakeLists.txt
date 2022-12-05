cmake_minimum_required(VERSION 3.10)

project(fillmissing)

SET(codegen_dir "${CMAKE_CURRENT_SOURCE_DIR}/codegen/lib/FillMissingNearestDouble") # <- codegen으로 생성된 소스파일 위치

include_directories("${codegen_dir}" "${CMAKE_CURRENT_SOURCE_DIR}")

add_compile_options(/utf-8)

add_executable(fillmissing
    fillmissing_test.cpp
    "${codegen_dir}/FillMissingNearestDouble.cpp"
    "${codegen_dir}/FillMissingNearestDouble_terminate.cpp"
    "${codegen_dir}/FillMissingNearestDouble_initialize.cpp"
    "${codegen_dir}/FillMissingNearestDouble_data.cpp"
    "${codegen_dir}/interp1.cpp"
    "${codegen_dir}/permute.cpp"
)
