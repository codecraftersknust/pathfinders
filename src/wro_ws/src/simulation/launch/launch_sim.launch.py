import os

from ament_index_python.packages import get_package_share_directory


from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

from launch_ros.actions import Node



def generate_launch_description():

    package_name='simulation' 

    rsp = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    get_package_share_directory(package_name),'launch','rsp.launch.py'
                )]), launch_arguments={'use_sim_time': 'true'}.items()
    )

    # Include the Gazebo launch file, provided by the gazebo_ros package
    gazebo = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([os.path.join(
                    get_package_share_directory('gazebo_ros'), 'launch', 'gazebo.launch.py')]),
             )

    # Run the spawner node from the gazebo_ros package. The entity name doesn't really matter if you only have a single robot.
    spawn_entity = Node(package='gazebo_ros', executable='spawn_entity.py',
                        arguments=['-topic', 'robot_description',
                                   '-entity', 'my_bot'],
                        output='screen')
    
    ack_steer_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["ack_cont"],
    )
    
    joint_broadcaster_spawner = Node(
        package="controller_manager",
        executable="spawner",
        arguments=["joint_broad"],
    )
    
    # twist_mux_params = os.path.join(get_package_share_directory(package_name),
    #                                 'config', 'twist_mux.yaml')
    # twist_mux = Node(
    #     package="twist_mux",
    #     executable="twist_mux",
    #     parameters=[twist_mux_params, {"use_sim_time": True}],
    #     remappings=[("/cmd_vel_out", "/diff_cont/cmd_vel_unstamped")],
    # )
    
    # robot_localization_node = Node(
    #    package='robot_localization',
    #    executable='ekf_node',
    #    name='ekf_filter_node',
    #    output='screen',
    #    parameters=[os.path.join(get_package_share_directory(package_name), 'config', 'ekf.yaml'), 
    #                {'use_sim_time': True}
    #                 ]
    # )

    


    # Launch them all!
    return LaunchDescription([
        rsp,
        # twist_mux,
        gazebo,
        spawn_entity,
        ack_steer_spawner,
        joint_broadcaster_spawner,
        # robot_localization_node,
    ])