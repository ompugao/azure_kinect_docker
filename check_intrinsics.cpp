#include <iostream>
#include <vector>
#include <string>
#include <k4a/k4a.hpp>

int main(int argc, char * argv[])
{
    // CREATE DEVICE OPBJECT
    k4a::device device = k4a::device::open(0);
    k4a_device_configuration_t config = K4A_DEVICE_CONFIG_INIT_DISABLE_ALL;

    // SET DESIRED DEPTH MODE IN DEVICE CONFIG
    config.depth_mode = (k4a_depth_mode_t)K4A_DEPTH_MODE_WFOV_2X2BINNED;
    // SET DESIRED COLOR RESOLUTION IN DEVICE CONFIG
    config.color_format = k4a_image_format_t(K4A_IMAGE_FORMAT_COLOR_BGRA32);
    config.color_resolution = (k4a_color_resolution_t)K4A_COLOR_RESOLUTION_720P;
    device.start_cameras(&config);
    k4a::calibration calibration = 
        device.get_calibration(config.depth_mode, config.color_resolution);
    // STRUCTURE DEREFERENCE FOR DEPTH CALIBRATION PARAMETERS
    // calibration.depth_camera_calibration
    // STRUCTURE DEREFERENCE FOR DEPTH CALIBRATION PARAMETERS
    std::cout << "w: " << calibration.color_camera_calibration.resolution_width << std::endl;
    std::cout << "h: " << calibration.color_camera_calibration.resolution_height << std::endl;
    std::cout << "fov: " << calibration.color_camera_calibration.metric_radius << std::endl;
    // THIS WILL GET THE INTRINSICS FOR THE COLOR CAMERA
    k4a_calibration_intrinsic_parameters_t& intrinsics = 
        calibration.color_camera_calibration.intrinsics.parameters;
    // std::cout << "param: " << std::endl;
    // for (int i = 0; i < calibration.color_camera_calibration.intrinsics.parameter_count; i++) {
    //     std::cout << intrinsics.v[i] << ", ";
    // }
    // std::cout << std::endl;
    std::cout << "cx: " << intrinsics.param.cx << std::endl;
    std::cout << "cy: " << intrinsics.param.cy << std::endl;
    std::cout << "fx: " << intrinsics.param.fx << std::endl;
    std::cout << "fy: " << intrinsics.param.fy << std::endl;
    std::cout << "k1: " << intrinsics.param.k1 << std::endl;
    std::cout << "k2: " << intrinsics.param.k2 << std::endl;
    std::cout << "k3: " << intrinsics.param.k3 << std::endl;
    std::cout << "k4: " << intrinsics.param.k4 << std::endl;
    std::cout << "k5: " << intrinsics.param.k5 << std::endl;
    std::cout << "k6: " << intrinsics.param.k6 << std::endl;
    return 0;
}
