#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <thread>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

bool stop_node = false;

class OpticalFlowNode : public rclcpp::Node
{
    public:
        OpticalFlowNode()
            : Node("optical_flow_node"), count_(0)
        {
            publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
            while(!stop_node){ /* Start optical flow algorithm here, maybe in its own thread. */
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                auto message = std_msgs::msg::String();
                message.data = "Hello, world! " + std::to_string(count_++);
                RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
                publisher_->publish(message);
                if(count_ > 10)
                    break;
            }
        }

    private:
        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        size_t count_;
};

void mySigintHandler(int sig)
{
    std::cout << "Interrupt signal (" << sig << ") received.\n";
    stop_node = true;
}

int main(int argc, char * argv[])
{
    signal(SIGINT, mySigintHandler);
    rclcpp::init(argc, argv);
    rclcpp::spin_some(std::make_shared<OpticalFlowNode>());
    rclcpp::shutdown();
    return 0;
}
