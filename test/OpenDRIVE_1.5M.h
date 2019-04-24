#include <Attribute.h>

struct t_grEqZero;
struct t_grZero;
struct t_zeroOne;
struct t_bool;
struct t_yesNo;
struct t_header_Version;
struct t_maxSpeed;
struct e_maxSpeedString;
struct t_junction_id;
struct e_trafficRule;
struct e_road_link_elementType;
struct e_road_link_neighbor_side;
struct e_paramPoly3_pRange;
struct e_road_lateralProfile_crossfall_side;
struct e_road_lanes_laneSection_lcr_lane_roadMark_laneChange;
struct e_road_lanes_laneSection_lr_lane_access_rule;
struct e_road_objects_object_parkingSpace_access;
struct e_road_signals_signal_reference_elementType;
struct e_road_surface_CRG_purpose;
struct e_road_surface_CRG_mode;
struct e_road_railroad_switch_position;
struct e_junction_type;
struct e_junctionGroup_type;
struct e_station_type;
struct e_station_platform_segment_side;
struct e_dataQuality_RawData_Source;
struct e_dataQuality_RawData_PostProcessing;
struct e_unitDistance;
struct e_unitSpeed;
struct e_unitMass;
struct e_unitSlope;
struct e_unit;
struct e_roadType;
struct e_roadMarkType;
struct e_roadMarkWeight;
struct e_roadMarkColor;
struct e_laneType;
struct e_objectType;
struct e_tunnelType;
struct e_bridgeType;
struct e_accessRestrictionType;
struct e_countryCode;
struct e_countryCode_deprecated;
struct e_countryCode_iso3166alpha3;
struct e_sideType;
struct e_outlineFillType;
struct e_borderType;
struct e_contactPoint;
struct e_elementDir;
struct e_direction;
struct e_roadMarkRule;
struct e_orientation;
struct t_grEqZero {
	Attribute<double> value;
};

struct t_grZero {
	Attribute<double> value;
};

struct t_zeroOne {
	Attribute<double> value;
};

struct t_bool {
	Attribute<std::string> value;
};

struct t_yesNo {
	Attribute<std::string> value;
};

struct t_header_Version {
	Attribute<float> value;
};

struct t_maxSpeed {
	Attribute<e_maxSpeedString> v1;
	Attribute<t_grEqZero> v2;
};

struct e_maxSpeedString {
	Attribute<std::string> value;
};

struct t_junction_id {
	Attribute<std::string> value;
};

struct e_trafficRule {
	Attribute<std::string> value;
};

struct e_road_link_elementType {
	Attribute<std::string> value;
};

struct e_road_link_neighbor_side {
	Attribute<std::string> value;
};

struct e_paramPoly3_pRange {
	Attribute<std::string> value;
};

struct e_road_lateralProfile_crossfall_side {
	Attribute<std::string> value;
};

struct e_road_lanes_laneSection_lcr_lane_roadMark_laneChange {
	Attribute<std::string> value;
};

struct e_road_lanes_laneSection_lr_lane_access_rule {
	Attribute<std::string> value;
};

struct e_road_objects_object_parkingSpace_access {
	Attribute<std::string> value;
};

struct e_road_signals_signal_reference_elementType {
	Attribute<std::string> value;
};

struct e_road_surface_CRG_purpose {
	Attribute<std::string> value;
};

struct e_road_surface_CRG_mode {
	Attribute<std::string> value;
};

struct e_road_railroad_switch_position {
	Attribute<std::string> value;
};

struct e_junction_type {
	Attribute<std::string> value;
};

struct e_junctionGroup_type {
	Attribute<std::string> value;
};

struct e_station_type {
	Attribute<std::string> value;
};

struct e_station_platform_segment_side {
	Attribute<std::string> value;
};

struct e_dataQuality_RawData_Source {
	Attribute<std::string> value;
};

struct e_dataQuality_RawData_PostProcessing {
	Attribute<std::string> value;
};

struct e_unitDistance {
	Attribute<std::string> value;
};

struct e_unitSpeed {
	Attribute<std::string> value;
};

struct e_unitMass {
	Attribute<std::string> value;
};

struct e_unitSlope {
	Attribute<std::string> value;
};

struct e_unit {
	Attribute<e_unitDistance> v1;
	Attribute<e_unitSpeed> v2;
	Attribute<e_unitMass> v3;
	Attribute<e_unitSlope> v4;
};

struct e_roadType {
	Attribute<std::string> value;
};

struct e_roadMarkType {
	Attribute<std::string> value;
};

struct e_roadMarkWeight {
	Attribute<std::string> value;
};

struct e_roadMarkColor {
	Attribute<std::string> value;
};

struct e_laneType {
	Attribute<std::string> value;
};

struct e_objectType {
	Attribute<std::string> value;
};

struct e_tunnelType {
	Attribute<std::string> value;
};

struct e_bridgeType {
	Attribute<std::string> value;
};

struct e_accessRestrictionType {
	Attribute<std::string> value;
};

struct e_countryCode {
	Attribute<e_countryCode_deprecated> v1;
	Attribute<e_countryCode_iso3166alpha3> v2;
};

struct e_countryCode_deprecated {
	Attribute<std::string> value;
};

struct e_countryCode_iso3166alpha3 {
	Attribute<std::string> value;
};

struct e_sideType {
	Attribute<std::string> value;
};

struct e_outlineFillType {
	Attribute<std::string> value;
};

struct e_borderType {
	Attribute<std::string> value;
};

struct e_contactPoint {
	Attribute<std::string> value;
};

struct e_elementDir {
	Attribute<std::string> value;
};

struct e_direction {
	Attribute<std::string> value;
};

struct e_roadMarkRule {
	Attribute<std::string> value;
};

struct e_orientation {
	Attribute<std::string> value;
};

struct t_header {
	Attribute<int> revMajor;
};

struct t_header_GeoReference {
};

struct t_header_Offset {
	Attribute<double> x;
};

struct t_road {
	Attribute<std::string> name;
};

struct t_road_link {
};

struct t_road_link_predecessorSuccessor {
	Attribute<e_road_link_elementType> elementType;
};

struct t_road_link_neighbor {
	Attribute<e_road_link_neighbor_side> side;
};

struct t_road_type {
	Attribute<t_grEqZero> s;
};

struct t_road_type_speed {
	Attribute<t_maxSpeed> max;
};

struct t_road_planView {
};

struct t_road_planView_geometry {
	Attribute<t_grEqZero> s;
};

struct t_road_planView_geometry_line {
};

struct t_road_planView_geometry_spiral {
	Attribute<double> curvStart;
};

struct t_road_planView_geometry_arc {
	Attribute<double> curvature;
};

struct t_road_planView_geometry_poly3 {
	Attribute<double> a;
};

struct t_road_planView_geometry_paramPoly3 {
	Attribute<double> aU;
};

struct t_road_elevationProfile {
};

struct t_road_elevationProfile_elevation {
	Attribute<t_grEqZero> s;
};

struct t_road_lateralProfile {
};

struct t_road_lateralProfile_superelevation {
	Attribute<t_grEqZero> s;
};

struct t_road_lateralProfile_crossfall {
	Attribute<e_road_lateralProfile_crossfall_side> side;
};

struct t_road_lateralProfile_shape {
	Attribute<t_grEqZero> s;
};

struct t_road_lanes {
};

struct t_road_lanes_laneOffset {
	Attribute<t_grEqZero> s;
};

struct t_road_lanes_laneSection {
	Attribute<t_grEqZero> s;
};

struct t_road_lanes_laneSection_left {
};

struct t_road_lanes_laneSection_center {
};

struct t_road_lanes_laneSection_right {
};

struct t_road_lanes_laneSection_center_lane {
	Attribute<int> id;
};

struct t_road_lanes_laneSection_lr_lane {
	Attribute<e_laneType> type;
};

struct t_road_lanes_laneSection_left_lane {
};

struct t_road_lanes_laneSection_right_lane {
};

struct t_road_lanes_laneSection_lcr_lane_link {
};

struct t_road_lanes_laneSection_lcr_lane_link_predecessorSuccessor {
	Attribute<int> id;
};

struct t_road_lanes_laneSection_lr_lane_width {
	Attribute<t_grEqZero> sOffset;
};

struct t_road_lanes_laneSection_lr_lane_border {
	Attribute<t_grEqZero> sOffset;
};

struct t_road_lanes_laneSection_lcr_lane_roadMark {
	Attribute<t_grEqZero> sOffset;
};

struct t_road_lanes_laneSection_lcr_lane_roadMark_sway {
	Attribute<t_grEqZero> ds;
};

struct t_road_lanes_laneSection_lcr_lane_roadMark_type {
	Attribute<std::string> name;
};

struct t_road_lanes_laneSection_lcr_lane_roadMark_type_line {
	Attribute<t_grEqZero> length;
};

struct t_road_lanes_laneSection_lcr_lane_roadMark_explicit {
};

struct t_road_lanes_laneSection_lcr_lane_roadMark_explicit_line {
	Attribute<t_grEqZero> length;
};

struct t_road_lanes_laneSection_lr_lane_material {
	Attribute<t_grEqZero> sOffset;
};

struct t_road_lanes_laneSection_lr_lane_visibility {
	Attribute<t_grEqZero> sOffset;
};

struct t_road_lanes_laneSection_lr_lane_speed {
	Attribute<t_grEqZero> sOffset;
};

struct t_road_lanes_laneSection_lr_lane_access {
	Attribute<t_grEqZero> sOffset;
};

struct t_road_lanes_laneSection_lr_lane_height {
	Attribute<t_grEqZero> sOffset;
};

struct t_road_lanes_laneSection_lr_lane_rule {
	Attribute<t_grEqZero> sOffset;
};

struct t_road_objects {
};

struct t_road_objects_object {
	Attribute<e_objectType> type;
};

struct t_road_objects_object_repeat {
	Attribute<t_grEqZero> s;
};

struct t_road_objects_object_outlines {
};

struct t_road_objects_object_outlines_outline {
	Attribute<unsigned int> id;
};

struct t_road_objects_object_outlines_outline_cornerRoad {
	Attribute<t_grEqZero> s;
};

struct t_road_objects_object_outlines_outline_cornerLocal {
	Attribute<double> u;
};

struct t_road_objects_object_material {
	Attribute<std::string> surface;
};

struct t_road_objects_object_laneValidity {
	Attribute<int> fromLane;
};

struct t_road_objects_object_parkingSpace {
	Attribute<e_road_objects_object_parkingSpace_access> access;
};

struct t_road_objects_object_markings {
};

struct t_road_objects_object_markings_marking {
	Attribute<e_sideType> side;
};

struct t_road_objects_object_markings_marking_cornerReference {
	Attribute<unsigned int> id;
};

struct t_road_objects_object_borders {
};

struct t_road_objects_object_borders_border {
	Attribute<t_grEqZero> width;
};

struct t_road_objects_objectReference {
	Attribute<t_grEqZero> s;
};

struct t_road_objects_tunnel {
	Attribute<t_grEqZero> s;
};

struct t_road_objects_bridge {
	Attribute<t_grEqZero> s;
};

struct t_road_signals {
};

struct t_road_signals_signal {
	Attribute<t_grEqZero> s;
};

struct t_road_signals_signal_dependency {
	Attribute<std::string> id;
};

struct t_road_signals_signal_reference {
	Attribute<e_road_signals_signal_reference_elementType> elementType;
};

struct t_road_signals_signal_positionRoad {
	Attribute<std::string> roadId;
};

struct t_road_signals_signal_positionInertial {
	Attribute<double> x;
};

struct t_road_signals_signalReference {
	Attribute<t_grEqZero> s;
};

struct t_road_surface {
};

struct t_road_surface_CRG {
	Attribute<std::string> file;
};

struct t_road_railroad {
};

struct t_road_railroad_switch {
	Attribute<std::string> name;
};

struct t_road_railroad_switch_mainTrack {
	Attribute<std::string> id;
};

struct t_road_railroad_switch_sideTrack {
	Attribute<std::string> id;
};

struct t_road_railroad_switch_partner {
	Attribute<std::string> name;
};

struct t_controller {
	Attribute<std::string> id;
};

struct t_controller_control {
	Attribute<std::string> signalId;
};

struct t_junction {
	Attribute<std::string> name;
};

struct t_junction_connection {
	Attribute<std::string> id;
};

struct t_junction_predecessorSuccessor {
	Attribute<std::string> elementType;
};

struct t_junction_connection_laneLink {
	Attribute<int> from;
};

struct t_junction_priority {
	Attribute<std::string> high;
};

struct t_junction_controller {
	Attribute<std::string> id;
};

struct t_junction_surface {
};

struct t_junction_surface_CRG {
	Attribute<std::string> file;
};

struct t_junctionGroup {
	Attribute<std::string> name;
};

struct t_junctionGroup_junctionReference {
	Attribute<std::string> junction;
};

struct t_station {
	Attribute<std::string> name;
};

struct t_station_platform {
	Attribute<std::string> name;
};

struct t_station_platform_segment {
	Attribute<std::string> roadId;
};

struct t_userData {
	Attribute<std::string> code;
};

struct t_include {
	Attribute<std::string> file;
};

struct t_dataQuality {
};

struct t_dataQuality_Error {
	Attribute<double> xyAbsolute;
};

struct t_dataQuality_RawData {
	Attribute<std::string> date;
};

