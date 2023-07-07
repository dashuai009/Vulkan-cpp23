## vulkan-cpp23

A.cpp contains an example of cpp23.

### build

env:
vs 17.7.0 preview 2.0
cmake 3.26
vulkan sdk 1.3.243

download & build:
```
git clone --recurse-submodules https://github.com/dashuai009/Vulkan-cpp23.git Vulkan-cpp23
cd Vulkan-cpp23
cmake -S . -B build -G "Visual Studio 17 2022"
cmake --build build --target vulkan-cpp23-A --config Debug -j 24
```

error:
```
MSBuild version 17.7.0-preview-23279-01+d4c4d1ec7 for .NET Framework

  正在扫描源以查找模块依赖项...
  VulkanCppModule.vcxproj -> C:\Users\15258\work\vulkan-cpp23\build\Debug\VulkanCppModule.lib
  A.cpp
C:\Users\15258\work\vulkan-cpp23\A.cpp(48,1): fatal  error C1001: 内部编译器错误。 [C:\Users\15258\work\vulkan-cpp23\build\vulk
an-cpp23-A.vcxproj]
  (编译器文件“msc1.cpp”，第 1628 行)
   要解决此问题，请尝试简化或更改上面所列位置附近的程序。
  如果可以，请在此处提供重现步骤: https://developercommunity.visualstudio.com
  请选择 Visual C++
  “帮助”菜单上的“技术支持”命令，或打开技术支持帮助文件来获得详细信息。
  “C:\Program Files\Microsoft Visual Studio\2022\Preview\VC\Tools\MSVC\14.37.32705\bin\HostX64\x64\CL.exe”中的内部编译器错误
    请选择 Visual C++
  “帮助”菜单上的“技术支持”命令，或打开技术支持帮助文件来获得详细信息
```
