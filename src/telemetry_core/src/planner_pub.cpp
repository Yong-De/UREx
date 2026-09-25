#include "telemetry_core_msgs/msg/camera_target.hpp"
#include <memory>
#include <rclcpp/executors.hpp>
#include <rclcpp/logging.hpp>
#include <rclcpp/publisher.hpp>
#include <rclcpp/timer.hpp>
#include <rclcpp/utilities.hpp>

using namespace std::chrono_literals;

class PlannerPub : public rclcpp::Node {
  public:
    PlannerPub() : Node("planner_node") {
        publisher_ =
            this->create_publisher<telemetry_core_msgs::msg::CameraTarget>(
                "camera_setpoint", 10);
        timer_ = this->create_wall_timer(
            500ms, std::bind(&PlannerPub::timer_callback, this));
    }

  private:
    void timer_callback() {
        auto message = telemetry_core_msgs::msg::CameraTarget();

        message.header.stamp = this->get_clock()->now();
        message.header.frame_id = "debris_lvlh";

        message.position.x = 1.5;
        message.position.y = 0.0;
        message.position.z = 0.3;

        message.use_look_at = true;
        message.look_at.x = 0.0;
        message.look_at.y = 0.0;
        message.look_at.z = 0.0;

        RCLCPP_INFO(this->get_logger(),
                    "Publishing Setpoint: '%.2f', '%.2f', '%.2f'",
                    message.position.x, message.position.y, message.position.z);

        publisher_->publish(message);
    }
    rclcpp::Publisher<telemetry_core_msgs::msg::CameraTarget>::SharedPtr
        publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PlannerPub>());
    rclcpp::shutdown();
    return 0;
}
