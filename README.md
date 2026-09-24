# 环境

- 开发板：ATK-DNESP32S3 v1.4
- IDF 版本：6.0.2

# 其他

## IDF 命令

```shell
# 创建项目
$ idf.py create-project atk_dnesp32s3

# 设置芯片
$ idf.py set-target esp32s3

# 全部编译
$ idf.py build

# 仅编译 APP
$ idf.py app

# 删除 build 目录的生成文件
$ idf.py clean

# 删除 build 目录的所有内容
$ idf.py fullclean

# 通过指定的串口烧录整个 FLASH
$ idf.py flash -p COM6

# 仅烧录 APP
$ idf.py app-flash -p COM6
```

## 脚本

- `env_init.bat`

  Windows 环境下，如果是使用 .exe 安装的 ESP-IDF，可以使用该脚本，双击即可启动。

  具体配置路径可以查看里面的注释。

- `env_init_eim.bat`

  Windows 环境下，如果是使用 EIM 安装的 ESP-IDF，可以使用该脚本，双击即可启动。
  
  具体配置路径可以查看里面的注释。

