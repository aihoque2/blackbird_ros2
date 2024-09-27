
#include <chrono>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#include <gz/sim/components/Pose.hh>

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/Pose.hpp

class BlackbirdPosePublisher: gz::sim::ISystemConfigure, 
                                gz::sim::ISystemPostUpdate
{
    public:
        BlackBirdPosePublisher();
        ~BlackBirdPosePublisher();

        void Configure(const gz::sim::Entity& entity,
                       const std::shared_ptr<const sdf::Element>&,
                       gz::sim::EntityComponentManager& ecm,
                       gz::sim::EventManager& event_mgr);
        
        void PostUpdate(const gz::sim::UpdateInfo &_info,
                                const gz::sim::EntityComponentManager &ecm);

        rclcpp::Node node_;
        rclcpp::Publisher<geometry_msgs::msg::Pose> pub_;
        
        // position
        double x;
        double y;
        double z;

        // orientation
        double q1;
        double q2;
        double q3;
        double w;

}