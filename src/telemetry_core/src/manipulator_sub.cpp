#include "geometry_msgs/msg/pose_stamped.hpp"
#include "telemetry_core_msgs/msg/camera_target.hpp"
#include <functional>
#include <memory>
#include <rclcpp/executors.hpp>
#include <rclcpp/logging.hpp>
#include <rclcpp/node.hpp>
#include <rclcpp/subscription.hpp>
#include <rclcpp/utilities.hpp>

class ManipulatorSub : public rclcpp::Node {
  public:
    ManipulatorSub() : Node("manipulator_node") {
        subscription_ =
            this->create_subscription<telemetry_core_msgs::msg::CameraTarget>(
                "camera_setpoint", 10,
                std::bind(&ManipulatorSub::topic_callback, this,
                          std::placeholders::_1));
    }

  private:
    void topic_callback(
        const telemetry_core_msgs::msg::CameraTarget &message) const {
        RCLCPP_INFO(this->get_logger(),
                    "Received Target: '%.2f, %.2f, %.2f' in frame '%s'",
                    message.position.x, message.position.y, message.position.z,
                    message.header.frame_id.c_str());
    }
    rclcpp::Subscription<telemetry_core_msgs::msg::CameraTarget>::SharedPtr
        subscription_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ManipulatorSub>());
    rclcpp::shutdown();
    return 0;
}
