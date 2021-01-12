交叉编译 arm架构 以demo为例gcc 7.5为列子
1.在arm平台确认gcc的版本 gcc--version 并下载GCC-Linaro-7.5.0-2019.12 
2.打开test文件夹[交叉编译工具链] 打开toolchain/toolchain-aarch64.cmake设置 
SET (CMAKE_C_COMPILER /home/jun/Desktop/GCC-Linaro-7.5.0-2019.12/bin/aarch64-linux-gnu-gcc)
SET (CMAKE_CXX_COMPILER /home/jun/Desktop/GCC-Linaro-7.5.0-2019.12/bin/aarch64-linux-gnu-g++)
建立build文件 cmake -DCMAKE_TOOLCHAIN_FILE=../toolchain/toolchain-aarch64.cmake ../&&make -j4

3.进入带有cyberRT的demo测试文件
编译方法同第二点

4.将build文件夹中的libcyber_core.so+/external_linux/lib_arm+/third_party/cyber/conf+/third_party/cyber/setup.bash拷贝就可以用了

5.运行文件时将setup.bash中的CYBER_IP进行修改  GLOG_minloglevel=2【可选】
  export导入第4点库所在路径的动态环境变量+source setup.bash

6.运行./talker talker    ./listener talker talker1 1[Hz]


注意test只是一个小demo  cyberRT是topic收发demo
