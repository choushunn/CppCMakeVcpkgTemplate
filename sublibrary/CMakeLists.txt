project(sublibrary)


# ############################################################
# # Create static library
# ############################################################
add_library(${PROJECT_NAME}  STATIC src/sublib1.cpp)
add_library(sub::lib1 ALIAS ${PROJECT_NAME})
target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

############################################################
# Create dynamic library
############################################################
# add_library(${PROJECT_NAME} SHARED src/sublib1.cpp)
# add_library(sub::lib1 ALIAS ${PROJECT_NAME})
# target_include_directories(${PROJECT_NAME}
#     PRIVATE ${PROJECT_SOURCE_DIR}/include
# )
# set_target_properties(${PROJECT_NAME}
#     PROPERTIES
#         PUBLIC_HEADER ${PROJECT_SOURCE_DIR}/include/sublib1.h
#         OUTPUT_NAME ${PROJECT_NAME} 
# )