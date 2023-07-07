//
// VulkanHpp Samples : 01_InitInstance
//                     Create and destroy a vk::Instance

import vulkan;
import std;

static std::string AppName = "01_InitInstance";
static std::string EngineName = "Vulkan.hpp";

int main(int /*argc*/, char ** /*argv*/) {
    /* VULKAN_HPP_KEY_START */

    try {
        // initialize the vk::ApplicationInfo structure
        vk::ApplicationInfo applicationInfo{
            .pApplicationName = AppName.c_str(),
            .applicationVersion = 1,
            .pEngineName = EngineName.c_str(),
            .engineVersion = 1,
            .apiVersion = vk::makeApiVersion(1, 0, 0, 0)
            // VK_API_VERSION_1_1 模块内部的宏默认不会导出
        };
        // initialize the vk::InstanceCreateInfo
        vk::InstanceCreateInfo instanceCreateInfo({}, &applicationInfo);

        // create an Instance
        vk::Instance instance = vk::createInstance(instanceCreateInfo);

        // destroy it again
        instance.destroy();
        std::println("successfully");
    } catch (vk::SystemError &err) {
        std::cout << "vk::SystemError: " << err.what() << std::endl;
        // exit(-1);
    } catch (std::exception &err) {
        std::cout << "std::exception: " << err.what() << std::endl;
        // exit(-1);
    } catch (...) {
        std::cout << "unknown error\n";
        // exit(-1);
    }

    /* VULKAN_HPP_KEY_END */

    return 0;
}
