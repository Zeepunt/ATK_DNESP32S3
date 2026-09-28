set(module_inc
    "modules/console"
    "modules/fs"
)

set(module_src
    "modules/console/mod_console.c"
    "modules/console/cmd_os.c"
    "modules/fs/mod_fs.c"
)

idf_component_register(
    SRCS
    "main.c"
    ${module_src}
    INCLUDE_DIRS
    "."
    ${module_inc}
)

partition_table_get_partition_info(partition_subtype "--partition-name fs" "subtype")
if(partition_subtype STREQUAL "130")     # 0x82 - ESP_PARTITION_SUBTYPE_DATA_SPIFFS
    message(STATUS "Partition 'fs' is SPIFFS type, creating SPIFFS image")
    spiffs_create_partition_image(fs ../fs FLASH_IN_PROJECT)
elseif(partition_subtype STREQUAL "131") # 0x83 - ESP_PARTITION_SUBTYPE_DATA_LITTLEFS
    message(STATUS "Partition 'fs' is LittleFS type, creating LittleFS image")
    littlefs_create_partition_image(fs ../fs FLASH_IN_PROJECT)
elseif(partition_subtype STREQUAL "129") # 0x81 - ESP_PARTITION_SUBTYPE_DATA_FAT
    message(STATUS "Partition 'fs' is FAT type")
else()
    message(FATAL_ERROR "Partition 'fs' has unknown subtype: '${partition_subtype}'")
endif()
