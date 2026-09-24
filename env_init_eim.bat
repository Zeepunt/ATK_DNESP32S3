::
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:: SPDX-License-Identifier: Apache-2.0
:: SPDX-FileCopyrightText: 2026 Zeepunt
::
:: ESP-IDF 编译环境初始化 (适用于 EIM)
::
:: 修改说明:
:: 1. IDF_TOOLS_PATH 默认是 C:\Espressif\tools
:: 2. IDF_PATH 默认是 C:\esp
::
:: 注意: 如果安装 ESP-IDF 时选择的是 "自定义安装", 那么在 "选择安装路径" 时
:: 1. IDF_PATH       : ESP-IDF 安装目录
:: 2. IDF_TOOLS_PATH : 使用自定义的工具下载/安装文件夹位置
::
::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::

@echo off

setlocal

set IDF_TOOLS_PATH=C:\Espressif\tools

:: ESP-IDF v6.0.2
set IDF_VERSION=v6.0.2

::set IDF_PATH=D:\ESP-IDF\%IDF_VERSION%\esp-idf
set IDF_PYTHON_ENV_PATH=%IDF_TOOLS_PATH%\python\%IDF_VERSION%\venv

powershell -NoExit -ExecutionPolicy Bypass -NoProfile -Command "%IDF_TOOLS_PATH%\Microsoft.%IDF_VERSION%.PowerShell_profile.ps1"

endlocal