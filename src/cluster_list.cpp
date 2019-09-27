//
// Created by shivesh on 9/17/19.
//

#include "continental_radar/cluster_list.hpp"

namespace continental_radar
{
namespace cluster_list
{
Cluster_0_Status::Cluster_0_Status()
{
}

Cluster_0_Status::~Cluster_0_Status()
{
}

int Cluster_0_Status::get_no_of_clusters_near()
{
  return static_cast<int>(cluster_0_status_msg.data.Cluster_NofClustersNear);
}

int Cluster_0_Status::get_no_of_clusters_far()
{
  return static_cast<int>(cluster_0_status_msg.data.Cluster_NofClustersFar);
}

int Cluster_0_Status::get_measurement_cycle_counter()
{
  return static_cast<int>(cluster_0_status_msg.data.Cluster_MeasCounter1 << 8
      | cluster_0_status_msg.data.Cluster_MeasCounter2);
}

int Cluster_0_Status::get_interface_version()
{
  return static_cast<int>(cluster_0_status_msg.data.Cluster_InterfaceVersion);
}

cluster_0_status * Cluster_0_Status::get_cluster_0_status()
{
  return & cluster_0_status_msg;
}

Cluster_1_General::Cluster_1_General()
{
}

Cluster_1_General::~Cluster_1_General()
{
}

int Cluster_1_General::get_cluster_id()
{
  return static_cast<int>(cluster_1_general_msg.data.Cluster_ID);
}

double Cluster_1_General::get_cluster_long_dist()
{
  return (cluster_1_general_msg.data.Cluster_DistLong1 << 5 |
    cluster_1_general_msg.data.Cluster_DistLong2) * 0.2 - 500.0;
}

double Cluster_1_General::get_cluster_lat_dist()
{
  return (cluster_1_general_msg.data.Cluster_DistLat1 << 8 |
      cluster_1_general_msg.data.Cluster_DistLat2) * 0.2 - 102.3;
}

double Cluster_1_General::get_cluster_long_rel_vel()
{
  return (cluster_1_general_msg.data.Cluster_VrelLong1 << 2 |
      cluster_1_general_msg.data.Cluster_VrelLong2) * 0.25 - 128.0;
}

double Cluster_1_General::get_cluster_lat_rel_vel()
{
  return (cluster_1_general_msg.data.Cluster_VrelLat1 << 3 |
      cluster_1_general_msg.data.Cluster_VrelLat2) * 0.25 - 64.0;
}

int Cluster_1_General::get_cluster_dyn_prop()
{
  return cluster_1_general_msg.data.Cluster_DynProp;
}

double Cluster_1_General::get_cluster_rcs()
{
  return cluster_1_general_msg.data.Cluster_RCS * 0.5 - 64.0;
}

cluster_1_general * Cluster_1_General::get_cluster_1_general()
{
  return & cluster_1_general_msg;
}

Cluster_2_Quality::Cluster_2_Quality()
{
}

Cluster_2_Quality::~Cluster_2_Quality()
{
}
}
}