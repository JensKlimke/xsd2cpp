#include <string>
#include <Attribute.h>
#include <tinyxml2.h>

struct t_maxSpeed;
struct e_unit;
struct e_countryCode;
struct t_header;
struct t_header_GeoReference;
struct t_header_Offset;
struct t_road;
struct t_road_link;
struct t_road_link_predecessorSuccessor;
struct t_road_link_neighbor;
struct t_road_type;
struct t_road_type_speed;
struct t_road_planView;
struct t_road_planView_geometry;
struct t_road_planView_geometry_line;
struct t_road_planView_geometry_spiral;
struct t_road_planView_geometry_arc;
struct t_road_planView_geometry_poly3;
struct t_road_planView_geometry_paramPoly3;
struct t_road_elevationProfile;
struct t_road_elevationProfile_elevation;
struct t_road_lateralProfile;
struct t_road_lateralProfile_superelevation;
struct t_road_lateralProfile_crossfall;
struct t_road_lateralProfile_shape;
struct t_road_lanes;
struct t_road_lanes_laneOffset;
struct t_road_lanes_laneSection;
struct t_road_lanes_laneSection_left;
struct t_road_lanes_laneSection_center;
struct t_road_lanes_laneSection_right;
struct t_road_lanes_laneSection_center_lane;
struct t_road_lanes_laneSection_lr_lane;
struct t_road_lanes_laneSection_left_lane;
struct t_road_lanes_laneSection_right_lane;
struct t_road_lanes_laneSection_lcr_lane_link;
struct t_road_lanes_laneSection_lcr_lane_link_predecessorSuccessor;
struct t_road_lanes_laneSection_lr_lane_width;
struct t_road_lanes_laneSection_lr_lane_border;
struct t_road_lanes_laneSection_lcr_lane_roadMark;
struct t_road_lanes_laneSection_lcr_lane_roadMark_sway;
struct t_road_lanes_laneSection_lcr_lane_roadMark_type;
struct t_road_lanes_laneSection_lcr_lane_roadMark_type_line;
struct t_road_lanes_laneSection_lcr_lane_roadMark_explicit;
struct t_road_lanes_laneSection_lcr_lane_roadMark_explicit_line;
struct t_road_lanes_laneSection_lr_lane_material;
struct t_road_lanes_laneSection_lr_lane_visibility;
struct t_road_lanes_laneSection_lr_lane_speed;
struct t_road_lanes_laneSection_lr_lane_access;
struct t_road_lanes_laneSection_lr_lane_height;
struct t_road_lanes_laneSection_lr_lane_rule;
struct t_road_objects;
struct t_road_objects_object;
struct t_road_objects_object_repeat;
struct t_road_objects_object_outlines;
struct t_road_objects_object_outlines_outline;
struct t_road_objects_object_outlines_outline_cornerRoad;
struct t_road_objects_object_outlines_outline_cornerLocal;
struct t_road_objects_object_material;
struct t_road_objects_object_laneValidity;
struct t_road_objects_object_parkingSpace;
struct t_road_objects_object_markings;
struct t_road_objects_object_markings_marking;
struct t_road_objects_object_markings_marking_cornerReference;
struct t_road_objects_object_borders;
struct t_road_objects_object_borders_border;
struct t_road_objects_objectReference;
struct t_road_objects_tunnel;
struct t_road_objects_bridge;
struct t_road_signals;
struct t_road_signals_signal;
struct t_road_signals_signal_dependency;
struct t_road_signals_signal_reference;
struct t_road_signals_signal_positionRoad;
struct t_road_signals_signal_positionInertial;
struct t_road_signals_signalReference;
struct t_road_surface;
struct t_road_surface_CRG;
struct t_road_railroad;
struct t_road_railroad_switch;
struct t_road_railroad_switch_mainTrack;
struct t_road_railroad_switch_sideTrack;
struct t_road_railroad_switch_partner;
struct t_controller;
struct t_controller_control;
struct t_junction;
struct t_junction_connection;
struct t_junction_predecessorSuccessor;
struct t_junction_connection_laneLink;
struct t_junction_priority;
struct t_junction_controller;
struct t_junction_surface;
struct t_junction_surface_CRG;
struct t_junctionGroup;
struct t_junctionGroup_junctionReference;
struct t_station;
struct t_station_platform;
struct t_station_platform_segment;
struct t_userData;
struct t_include;
struct t_dataQuality;
struct t_dataQuality_Error;
struct t_dataQuality_RawData;


typedef _Attribute<double> t_grEqZero;
typedef _Attribute<double> t_grZero;
typedef _Attribute<double> t_zeroOne;
typedef _Attribute<std::string> t_bool;
typedef _Attribute<std::string> t_yesNo;
typedef _Attribute<float> t_header_Version;
typedef _Attribute<std::string> e_maxSpeedString;
typedef _Attribute<std::string> t_junction_id;
typedef _Attribute<std::string> e_trafficRule;
typedef _Attribute<std::string> e_road_link_elementType;
typedef _Attribute<std::string> e_road_link_neighbor_side;
typedef _Attribute<std::string> e_paramPoly3_pRange;
typedef _Attribute<std::string> e_road_lateralProfile_crossfall_side;
typedef _Attribute<std::string> e_road_lanes_laneSection_lcr_lane_roadMark_laneChange;
typedef _Attribute<std::string> e_road_lanes_laneSection_lr_lane_access_rule;
typedef _Attribute<std::string> e_road_objects_object_parkingSpace_access;
typedef _Attribute<std::string> e_road_signals_signal_reference_elementType;
typedef _Attribute<std::string> e_road_surface_CRG_purpose;
typedef _Attribute<std::string> e_road_surface_CRG_mode;
typedef _Attribute<std::string> e_road_railroad_switch_position;
typedef _Attribute<std::string> e_junction_type;
typedef _Attribute<std::string> e_junctionGroup_type;
typedef _Attribute<std::string> e_station_type;
typedef _Attribute<std::string> e_station_platform_segment_side;
typedef _Attribute<std::string> e_dataQuality_RawData_Source;
typedef _Attribute<std::string> e_dataQuality_RawData_PostProcessing;
typedef _Attribute<std::string> e_unitDistance;
typedef _Attribute<std::string> e_unitSpeed;
typedef _Attribute<std::string> e_unitMass;
typedef _Attribute<std::string> e_unitSlope;
typedef _Attribute<std::string> e_roadType;
typedef _Attribute<std::string> e_roadMarkType;
typedef _Attribute<std::string> e_roadMarkWeight;
typedef _Attribute<std::string> e_roadMarkColor;
typedef _Attribute<std::string> e_laneType;
typedef _Attribute<std::string> e_objectType;
typedef _Attribute<std::string> e_tunnelType;
typedef _Attribute<std::string> e_bridgeType;
typedef _Attribute<std::string> e_accessRestrictionType;
typedef _Attribute<std::string> e_countryCode_deprecated;
typedef _Attribute<std::string> e_countryCode_iso3166alpha3;
typedef _Attribute<std::string> e_sideType;
typedef _Attribute<std::string> e_outlineFillType;
typedef _Attribute<std::string> e_borderType;
typedef _Attribute<std::string> e_contactPoint;
typedef _Attribute<std::string> e_elementDir;
typedef _Attribute<std::string> e_direction;
typedef _Attribute<std::string> e_roadMarkRule;
typedef _Attribute<std::string> e_orientation;



struct t_maxSpeed : public _Union<2> {

	_Attribute<e_maxSpeedString> _v0;
	_Attribute<t_grEqZero> _v1;

};


struct e_unit : public _Union<4> {

	_Attribute<e_unitDistance> _v0;
	_Attribute<e_unitSpeed> _v1;
	_Attribute<e_unitMass> _v2;
	_Attribute<e_unitSlope> _v3;

};


struct e_countryCode : public _Union<2> {

	_Attribute<e_countryCode_deprecated> _v0;
	_Attribute<e_countryCode_iso3166alpha3> _v1;

};


struct t_header {

	_Vector<t_header_GeoReference> __vec_geoReference;
	_Vector<t_header_Offset> __vec_offset;
	_Attribute<int> _revMajor;
	_Attribute<int> _revMinor;
	_Attribute<std::string> _name;
	t_header_Version _version;
	_Attribute<std::string> _date;
	_Attribute<double> _north;
	_Attribute<double> _south;
	_Attribute<double> _east;
	_Attribute<double> _west;
	_Attribute<std::string> _vendor;

};


struct t_header_GeoReference {


};


struct t_header_Offset {

	_Attribute<double> _x;
	_Attribute<double> _y;
	_Attribute<double> _z;
	_Attribute<float> _hdg;

};


struct t_road {

	_Vector<t_road_link> __vec_link;
	_Vector<t_road_type> __vec_type;
	_Vector<t_road_planView> __vec_planView;
	_Vector<t_road_elevationProfile> __vec_elevationProfile;
	_Vector<t_road_lateralProfile> __vec_lateralProfile;
	_Vector<t_road_lanes> __vec_lanes;
	_Vector<t_road_objects> __vec_objects;
	_Vector<t_road_signals> __vec_signals;
	_Vector<t_road_surface> __vec_surface;
	_Vector<t_road_railroad> __vec_railroad;
	_Attribute<std::string> _name;
	t_grEqZero _length;
	_Attribute<std::string> _id;
	_Attribute<std::string> _junction;
	e_trafficRule _rule;

};


struct t_road_link {

	_Vector<t_road_link_predecessorSuccessor> __vec_predecessor;
	_Vector<t_road_link_predecessorSuccessor> __vec_successor;
	_Vector<t_road_link_neighbor> __vec_neighbor;

};


struct t_road_link_predecessorSuccessor {

	e_road_link_elementType _elementType;
	_Attribute<std::string> _elementId;
	e_contactPoint _contactPoint;
	t_grEqZero _elementS;
	e_elementDir _elementDir;

};


struct t_road_link_neighbor {

	e_road_link_neighbor_side _side;
	_Attribute<std::string> _elementId;
	e_direction _direction;

};


struct t_road_type {

	_Vector<t_road_type_speed> __vec_speed;
	t_grEqZero _s;
	e_roadType _type;
	e_countryCode _country;

};


struct t_road_type_speed {

	t_maxSpeed _max;
	e_unitSpeed _unit;

};


struct t_road_planView {

	_Vector<t_road_planView_geometry> __vec_geometry;

};


struct t_road_planView_geometry {

	t_grEqZero _s;
	_Attribute<double> _x;
	_Attribute<double> _y;
	_Attribute<double> _hdg;
	t_grEqZero _length;

};


struct t_road_planView_geometry_line {


};


struct t_road_planView_geometry_spiral {

	_Attribute<double> _curvStart;
	_Attribute<double> _curvEnd;

};


struct t_road_planView_geometry_arc {

	_Attribute<double> _curvature;

};


struct t_road_planView_geometry_poly3 {

	_Attribute<double> _a;
	_Attribute<double> _b;
	_Attribute<double> _c;
	_Attribute<double> _d;

};


struct t_road_planView_geometry_paramPoly3 {

	_Attribute<double> _aU;
	_Attribute<double> _bU;
	_Attribute<double> _cU;
	_Attribute<double> _dU;
	_Attribute<double> _aV;
	_Attribute<double> _bV;
	_Attribute<double> _cV;
	_Attribute<double> _dV;
	e_paramPoly3_pRange _pRange;

};


struct t_road_elevationProfile {

	_Vector<t_road_elevationProfile_elevation> __vec_elevation;

};


struct t_road_elevationProfile_elevation {

	t_grEqZero _s;
	_Attribute<double> _a;
	_Attribute<double> _b;
	_Attribute<double> _c;
	_Attribute<double> _d;

};


struct t_road_lateralProfile {

	_Vector<t_road_lateralProfile_superelevation> __vec_superelevation;
	_Vector<t_road_lateralProfile_crossfall> __vec_crossfall;
	_Vector<t_road_lateralProfile_shape> __vec_shape;

};


struct t_road_lateralProfile_superelevation {

	t_grEqZero _s;
	_Attribute<double> _a;
	_Attribute<double> _b;
	_Attribute<double> _c;
	_Attribute<double> _d;

};


struct t_road_lateralProfile_crossfall {

	e_road_lateralProfile_crossfall_side _side;
	t_grEqZero _s;
	_Attribute<double> _a;
	_Attribute<double> _b;
	_Attribute<double> _c;
	_Attribute<double> _d;

};


struct t_road_lateralProfile_shape {

	t_grEqZero _s;
	_Attribute<double> _t;
	_Attribute<double> _a;
	_Attribute<double> _b;
	_Attribute<double> _c;
	_Attribute<double> _d;

};


struct t_road_lanes {

	_Vector<t_road_lanes_laneOffset> __vec_laneOffset;
	_Vector<t_road_lanes_laneSection> __vec_laneSection;

};


struct t_road_lanes_laneOffset {

	t_grEqZero _s;
	_Attribute<double> _a;
	_Attribute<double> _b;
	_Attribute<double> _c;
	_Attribute<double> _d;

};


struct t_road_lanes_laneSection {

	_Vector<t_road_lanes_laneSection_left> __vec_left;
	_Vector<t_road_lanes_laneSection_center> __vec_center;
	_Vector<t_road_lanes_laneSection_right> __vec_right;
	t_grEqZero _s;
	t_bool _singleSide;

};


struct t_road_lanes_laneSection_left {

	_Vector<t_road_lanes_laneSection_left_lane> __vec_lane;

};


struct t_road_lanes_laneSection_center {

	_Vector<t_road_lanes_laneSection_center_lane> __vec_lane;

};


struct t_road_lanes_laneSection_right {

	_Vector<t_road_lanes_laneSection_right_lane> __vec_lane;

};


struct t_road_lanes_laneSection_center_lane {

	_Vector<t_road_lanes_laneSection_lcr_lane_link> __vec_link;
	_Vector<t_road_lanes_laneSection_lcr_lane_roadMark> __vec_roadMark;
	_Attribute<int> _id;
	e_laneType _type;
	t_bool _level;

};


struct t_road_lanes_laneSection_lr_lane {

	_Vector<t_road_lanes_laneSection_lcr_lane_link> __vec_link;
	_Vector<t_road_lanes_laneSection_lcr_lane_roadMark> __vec_roadMark;
	_Vector<t_road_lanes_laneSection_lr_lane_material> __vec_material;
	_Vector<t_road_lanes_laneSection_lr_lane_visibility> __vec_visibility;
	_Vector<t_road_lanes_laneSection_lr_lane_speed> __vec_speed;
	_Vector<t_road_lanes_laneSection_lr_lane_access> __vec_access;
	_Vector<t_road_lanes_laneSection_lr_lane_height> __vec_height;
	_Vector<t_road_lanes_laneSection_lr_lane_rule> __vec_rule;
	e_laneType _type;
	t_bool _level;

};


struct t_road_lanes_laneSection_left_lane {


};


struct t_road_lanes_laneSection_right_lane {


};


struct t_road_lanes_laneSection_lcr_lane_link {

	_Vector<t_road_lanes_laneSection_lcr_lane_link_predecessorSuccessor> __vec_predecessor;
	_Vector<t_road_lanes_laneSection_lcr_lane_link_predecessorSuccessor> __vec_successor;

};


struct t_road_lanes_laneSection_lcr_lane_link_predecessorSuccessor {

	_Attribute<int> _id;

};


struct t_road_lanes_laneSection_lr_lane_width {

	t_grEqZero _sOffset;
	_Attribute<double> _a;
	_Attribute<double> _b;
	_Attribute<double> _c;
	_Attribute<double> _d;

};


struct t_road_lanes_laneSection_lr_lane_border {

	t_grEqZero _sOffset;
	_Attribute<double> _a;
	_Attribute<double> _b;
	_Attribute<double> _c;
	_Attribute<double> _d;

};


struct t_road_lanes_laneSection_lcr_lane_roadMark {

	_Vector<t_road_lanes_laneSection_lcr_lane_roadMark_sway> __vec_sway;
	_Vector<t_road_lanes_laneSection_lcr_lane_roadMark_type> __vec_type;
	_Vector<t_road_lanes_laneSection_lcr_lane_roadMark_explicit> __vec_explicit;
	t_grEqZero _sOffset;
	e_roadMarkType _type;
	e_roadMarkWeight _weight;
	e_roadMarkColor _color;
	_Attribute<std::string> _material;
	t_grEqZero _width;
	e_road_lanes_laneSection_lcr_lane_roadMark_laneChange _laneChange;
	_Attribute<double> _height;

};


struct t_road_lanes_laneSection_lcr_lane_roadMark_sway {

	t_grEqZero _ds;
	_Attribute<double> _a;
	_Attribute<double> _b;
	_Attribute<double> _c;
	_Attribute<double> _d;

};


struct t_road_lanes_laneSection_lcr_lane_roadMark_type {

	_Vector<t_road_lanes_laneSection_lcr_lane_roadMark_type_line> __vec_line;
	_Attribute<std::string> _name;
	t_grEqZero _width;

};


struct t_road_lanes_laneSection_lcr_lane_roadMark_type_line {

	t_grEqZero _length;
	t_grEqZero _space;
	_Attribute<double> _tOffset;
	t_grEqZero _sOffset;
	e_roadMarkRule _rule;
	t_grEqZero _width;
	e_roadMarkColor _color;

};


struct t_road_lanes_laneSection_lcr_lane_roadMark_explicit {

	_Vector<t_road_lanes_laneSection_lcr_lane_roadMark_explicit_line> __vec_line;

};


struct t_road_lanes_laneSection_lcr_lane_roadMark_explicit_line {

	t_grEqZero _length;
	_Attribute<double> _tOffset;
	t_grEqZero _sOffset;
	e_roadMarkRule _rule;
	t_grEqZero _width;

};


struct t_road_lanes_laneSection_lr_lane_material {

	t_grEqZero _sOffset;
	_Attribute<std::string> _surface;
	t_grEqZero _friction;
	t_grEqZero _roughness;

};


struct t_road_lanes_laneSection_lr_lane_visibility {

	t_grEqZero _sOffset;
	t_grEqZero _forward;
	t_grEqZero _back;
	t_grEqZero _left;
	t_grEqZero _right;

};


struct t_road_lanes_laneSection_lr_lane_speed {

	t_grEqZero _sOffset;
	t_grEqZero _max;
	e_unitSpeed _unit;

};


struct t_road_lanes_laneSection_lr_lane_access {

	t_grEqZero _sOffset;
	e_road_lanes_laneSection_lr_lane_access_rule _rule;
	e_accessRestrictionType _restriction;

};


struct t_road_lanes_laneSection_lr_lane_height {

	t_grEqZero _sOffset;
	_Attribute<double> _inner;
	_Attribute<double> _outer;

};


struct t_road_lanes_laneSection_lr_lane_rule {

	t_grEqZero _sOffset;
	_Attribute<std::string> _value;

};


struct t_road_objects {

	_Vector<t_road_objects_object> __vec_object;
	_Vector<t_road_objects_objectReference> __vec_objectReference;
	_Vector<t_road_objects_tunnel> __vec_tunnel;
	_Vector<t_road_objects_bridge> __vec_bridge;

};


struct t_road_objects_object {

	_Vector<t_road_objects_object_repeat> __vec_repeat;
	_Vector<t_road_objects_object_outlines_outline> __vec_outline;
	_Vector<t_road_objects_object_outlines> __vec_outlines;
	_Vector<t_road_objects_object_material> __vec_material;
	_Vector<t_road_objects_object_laneValidity> __vec_validity;
	_Vector<t_road_objects_object_parkingSpace> __vec_parkingSpace;
	_Vector<t_road_objects_object_markings> __vec_markings;
	_Vector<t_road_objects_object_borders> __vec_borders;
	e_objectType _type;
	_Attribute<std::string> _subtype;
	t_yesNo _dynamic;
	_Attribute<std::string> _name;
	_Attribute<std::string> _id;
	t_grEqZero _s;
	_Attribute<double> _t;
	_Attribute<double> _zOffset;
	t_grEqZero _validLength;
	e_orientation _orientation;
	_Attribute<double> _hdg;
	_Attribute<double> _pitch;
	_Attribute<double> _roll;
	_Attribute<double> _height;
	_Attribute<double> _length;
	_Attribute<double> _width;
	_Attribute<double> _radius;

};


struct t_road_objects_object_repeat {

	t_grEqZero _s;
	t_grEqZero _length;
	t_grEqZero _distance;
	_Attribute<double> _tStart;
	_Attribute<double> _tEnd;
	_Attribute<double> _heightStart;
	_Attribute<double> _heightEnd;
	_Attribute<double> _zOffsetStart;
	_Attribute<double> _zOffsetEnd;
	t_grEqZero _widthStart;
	t_grEqZero _widthEnd;
	t_grEqZero _lengthStart;
	t_grEqZero _lengthEnd;
	t_grEqZero _radiusStart;
	t_grEqZero _radiusEnd;

};


struct t_road_objects_object_outlines {

	_Vector<t_road_objects_object_outlines_outline> __vec_outline;

};


struct t_road_objects_object_outlines_outline {

	_Vector<t_road_objects_object_outlines_outline_cornerRoad> __vec_cornerRoad;
	_Vector<t_road_objects_object_outlines_outline_cornerLocal> __vec_cornerLocal;
	_Attribute<unsigned int> _id;
	e_outlineFillType _fillType;
	t_bool _outer;
	t_bool _closed;
	e_laneType _laneType;

};


struct t_road_objects_object_outlines_outline_cornerRoad {

	t_grEqZero _s;
	_Attribute<double> _t;
	_Attribute<double> _dz;
	_Attribute<double> _height;
	_Attribute<unsigned int> _id;

};


struct t_road_objects_object_outlines_outline_cornerLocal {

	_Attribute<double> _u;
	_Attribute<double> _v;
	_Attribute<double> _z;
	_Attribute<double> _height;
	_Attribute<unsigned int> _id;

};


struct t_road_objects_object_material {

	_Attribute<std::string> _surface;
	t_grEqZero _friction;
	t_grEqZero _roughness;

};


struct t_road_objects_object_laneValidity {

	_Attribute<int> _fromLane;
	_Attribute<int> _toLane;

};


struct t_road_objects_object_parkingSpace {

	e_road_objects_object_parkingSpace_access _access;
	_Attribute<std::string> _restrictions;

};


struct t_road_objects_object_markings {

	_Vector<t_road_objects_object_markings_marking> __vec_marking;

};


struct t_road_objects_object_markings_marking {

	_Vector<t_road_objects_object_markings_marking_cornerReference> __vec_cornerReference;
	e_sideType _side;
	e_roadMarkWeight _weight;
	t_grEqZero _width;
	e_roadMarkColor _color;
	t_grEqZero _zOffset;
	t_grEqZero _spaceLength;
	t_grEqZero _lineLength;
	_Attribute<double> _startOffset;
	_Attribute<double> _stopOffset;

};


struct t_road_objects_object_markings_marking_cornerReference {

	_Attribute<unsigned int> _id;

};


struct t_road_objects_object_borders {

	_Vector<t_road_objects_object_borders_border> __vec_border;

};


struct t_road_objects_object_borders_border {

	_Vector<t_road_objects_object_markings_marking_cornerReference> __vec_cornerReference;
	t_grEqZero _width;
	e_borderType _type;
	_Attribute<unsigned int> _outlineId;
	t_bool _useCompleteOutline;

};


struct t_road_objects_objectReference {

	_Vector<t_road_objects_object_laneValidity> __vec_validity;
	t_grEqZero _s;
	_Attribute<double> _t;
	_Attribute<std::string> _id;
	_Attribute<double> _zOffset;
	t_grEqZero _validLength;
	e_orientation _orientation;

};


struct t_road_objects_tunnel {

	_Vector<t_road_objects_object_laneValidity> __vec_validity;
	t_grEqZero _s;
	t_grEqZero _length;
	_Attribute<std::string> _name;
	_Attribute<std::string> _id;
	e_tunnelType _type;
	t_zeroOne _lighting;
	t_zeroOne _daylight;

};


struct t_road_objects_bridge {

	_Vector<t_road_objects_object_laneValidity> __vec_validity;
	t_grEqZero _s;
	t_grEqZero _length;
	_Attribute<std::string> _name;
	_Attribute<std::string> _id;
	e_bridgeType _type;

};


struct t_road_signals {

	_Vector<t_road_signals_signal> __vec_signal;
	_Vector<t_road_signals_signalReference> __vec_signalReference;

};


struct t_road_signals_signal {

	_Vector<t_road_objects_object_laneValidity> __vec_validity;
	_Vector<t_road_signals_signal_dependency> __vec_dependency;
	_Vector<t_road_signals_signal_reference> __vec_reference;
	t_grEqZero _s;
	_Attribute<double> _t;
	_Attribute<std::string> _id;
	_Attribute<std::string> _name;
	t_yesNo _dynamic;
	e_orientation _orientation;
	_Attribute<double> _zOffset;
	e_countryCode _country;
	_Attribute<std::string> _countryRevision;
	_Attribute<std::string> _type;
	_Attribute<std::string> _subtype;
	_Attribute<double> _value;
	e_unit _unit;
	t_grEqZero _height;
	t_grEqZero _width;
	_Attribute<std::string> _text;
	_Attribute<double> _hOffset;
	_Attribute<double> _pitch;
	_Attribute<double> _roll;

};


struct t_road_signals_signal_dependency {

	_Attribute<std::string> _id;
	_Attribute<std::string> _type;

};


struct t_road_signals_signal_reference {

	e_road_signals_signal_reference_elementType _elementType;
	_Attribute<std::string> _elementId;
	_Attribute<std::string> _type;

};


struct t_road_signals_signal_positionRoad {

	_Attribute<std::string> _roadId;
	t_grEqZero _s;
	_Attribute<double> _t;
	_Attribute<double> _zOffset;
	_Attribute<double> _hOffset;
	_Attribute<double> _pitch;
	_Attribute<double> _roll;

};


struct t_road_signals_signal_positionInertial {

	_Attribute<double> _x;
	_Attribute<double> _y;
	_Attribute<double> _z;
	_Attribute<double> _hdg;
	_Attribute<double> _pitch;
	_Attribute<double> _roll;

};


struct t_road_signals_signalReference {

	_Vector<t_road_objects_object_laneValidity> __vec_validity;
	t_grEqZero _s;
	_Attribute<double> _t;
	_Attribute<std::string> _id;
	e_orientation _orientation;

};


struct t_road_surface {

	_Vector<t_road_surface_CRG> __vec_CRG;

};


struct t_road_surface_CRG {

	_Attribute<std::string> _file;
	t_grEqZero _sStart;
	t_grEqZero _sEnd;
	e_direction _orientation;
	e_road_surface_CRG_mode _mode;
	e_road_surface_CRG_purpose _purpose;
	_Attribute<double> _sOffset;
	_Attribute<double> _tOffset;
	_Attribute<double> _zOffset;
	_Attribute<double> _zScale;
	_Attribute<double> _hOffset;

};


struct t_road_railroad {

	_Vector<t_road_railroad_switch> __vec_switch;

};


struct t_road_railroad_switch {

	_Vector<t_road_railroad_switch_mainTrack> __vec_mainTrack;
	_Vector<t_road_railroad_switch_sideTrack> __vec_sideTrack;
	_Vector<t_road_railroad_switch_partner> __vec_partner;
	_Attribute<std::string> _name;
	_Attribute<std::string> _id;
	e_road_railroad_switch_position _position;

};


struct t_road_railroad_switch_mainTrack {

	_Attribute<std::string> _id;
	t_grEqZero _s;
	e_elementDir _dir;

};


struct t_road_railroad_switch_sideTrack {

	_Attribute<std::string> _id;
	t_grEqZero _s;
	e_elementDir _dir;

};


struct t_road_railroad_switch_partner {

	_Attribute<std::string> _name;
	_Attribute<std::string> _id;

};


struct t_controller {

	_Vector<t_controller_control> __vec_control;
	_Attribute<std::string> _id;
	_Attribute<std::string> _name;
	_Attribute<unsigned int> _sequence;

};


struct t_controller_control {

	_Attribute<std::string> _signalId;
	_Attribute<std::string> _type;

};


struct t_junction {

	_Vector<t_junction_connection> __vec_connection;
	_Vector<t_junction_priority> __vec_priority;
	_Vector<t_junction_controller> __vec_controller;
	_Vector<t_junction_surface> __vec_surface;
	_Attribute<std::string> _name;
	t_junction_id _id;
	e_junction_type _type;

};


struct t_junction_connection {

	_Vector<t_junction_predecessorSuccessor> __vec_predecessor;
	_Vector<t_junction_predecessorSuccessor> __vec_successor;
	_Vector<t_junction_connection_laneLink> __vec_laneLink;
	_Attribute<std::string> _id;
	_Attribute<std::string> _incomingRoad;
	_Attribute<std::string> _connectingRoad;
	e_contactPoint _contactPoint;
	_Attribute<std::string> _connectionMaster;
	e_junction_type _type;

};


struct t_junction_predecessorSuccessor {

	_Attribute<std::string> _elementType;
	_Attribute<std::string> _elementId;
	t_grZero _elementS;
	e_elementDir _elementDir;

};


struct t_junction_connection_laneLink {

	_Attribute<int> _from;
	_Attribute<int> _to;

};


struct t_junction_priority {

	_Attribute<std::string> _high;
	_Attribute<std::string> _low;

};


struct t_junction_controller {

	_Attribute<std::string> _id;
	_Attribute<std::string> _type;
	_Attribute<unsigned int> _sequence;

};


struct t_junction_surface {

	_Vector<t_junction_surface_CRG> __vec_CRG;

};


struct t_junction_surface_CRG {

	_Attribute<std::string> _file;
	e_road_surface_CRG_mode _mode;
	e_road_surface_CRG_purpose _purpose;
	_Attribute<double> _zOffset;
	_Attribute<double> _zScale;

};


struct t_junctionGroup {

	_Vector<t_junctionGroup_junctionReference> __vec_junctionReference;
	_Attribute<std::string> _name;
	_Attribute<std::string> _id;
	e_junctionGroup_type _type;

};


struct t_junctionGroup_junctionReference {

	_Attribute<std::string> _junction;

};


struct t_station {

	_Vector<t_station_platform> __vec_platform;
	_Attribute<std::string> _name;
	_Attribute<std::string> _id;
	e_station_type _type;

};


struct t_station_platform {

	_Vector<t_station_platform_segment> __vec_segment;
	_Attribute<std::string> _name;
	_Attribute<std::string> _id;

};


struct t_station_platform_segment {

	_Attribute<std::string> _roadId;
	t_grEqZero _sStart;
	t_grEqZero _sEnd;
	e_station_platform_segment_side _side;

};


struct t_userData {

	_Attribute<std::string> _code;
	_Attribute<std::string> _value;

};


struct t_include {

	_Attribute<std::string> _file;

};


struct t_dataQuality {

	_Vector<t_dataQuality_Error> __vec_error;
	_Vector<t_dataQuality_RawData> __vec_rawData;

};


struct t_dataQuality_Error {

	_Attribute<double> _xyAbsolute;
	_Attribute<double> _zAbsolute;
	_Attribute<double> _xyRelative;
	_Attribute<double> _zRelative;

};


struct t_dataQuality_RawData {

	_Attribute<std::string> _date;
	e_dataQuality_RawData_Source _source;
	_Attribute<std::string> _sourceComment;
	e_dataQuality_RawData_PostProcessing _postProcessing;
	_Attribute<std::string> _postProcessingComment;

};



void parse_t_grEqZero(tinyxml2::XMLElement *elem, t_grEqZero& t);
void parse_t_grZero(tinyxml2::XMLElement *elem, t_grZero& t);
void parse_t_zeroOne(tinyxml2::XMLElement *elem, t_zeroOne& t);
void parse_t_bool(tinyxml2::XMLElement *elem, t_bool& t);
void parse_t_yesNo(tinyxml2::XMLElement *elem, t_yesNo& t);
void parse_t_header_Version(tinyxml2::XMLElement *elem, t_header_Version& t);
void parse_t_maxSpeed(tinyxml2::XMLElement *elem, t_maxSpeed& t);
void parse_e_maxSpeedString(tinyxml2::XMLElement *elem, e_maxSpeedString& t);
void parse_t_junction_id(tinyxml2::XMLElement *elem, t_junction_id& t);
void parse_e_trafficRule(tinyxml2::XMLElement *elem, e_trafficRule& t);
void parse_e_road_link_elementType(tinyxml2::XMLElement *elem, e_road_link_elementType& t);
void parse_e_road_link_neighbor_side(tinyxml2::XMLElement *elem, e_road_link_neighbor_side& t);
void parse_e_paramPoly3_pRange(tinyxml2::XMLElement *elem, e_paramPoly3_pRange& t);
void parse_e_road_lateralProfile_crossfall_side(tinyxml2::XMLElement *elem, e_road_lateralProfile_crossfall_side& t);
void parse_e_road_lanes_laneSection_lcr_lane_roadMark_laneChange(tinyxml2::XMLElement *elem, e_road_lanes_laneSection_lcr_lane_roadMark_laneChange& t);
void parse_e_road_lanes_laneSection_lr_lane_access_rule(tinyxml2::XMLElement *elem, e_road_lanes_laneSection_lr_lane_access_rule& t);
void parse_e_road_objects_object_parkingSpace_access(tinyxml2::XMLElement *elem, e_road_objects_object_parkingSpace_access& t);
void parse_e_road_signals_signal_reference_elementType(tinyxml2::XMLElement *elem, e_road_signals_signal_reference_elementType& t);
void parse_e_road_surface_CRG_purpose(tinyxml2::XMLElement *elem, e_road_surface_CRG_purpose& t);
void parse_e_road_surface_CRG_mode(tinyxml2::XMLElement *elem, e_road_surface_CRG_mode& t);
void parse_e_road_railroad_switch_position(tinyxml2::XMLElement *elem, e_road_railroad_switch_position& t);
void parse_e_junction_type(tinyxml2::XMLElement *elem, e_junction_type& t);
void parse_e_junctionGroup_type(tinyxml2::XMLElement *elem, e_junctionGroup_type& t);
void parse_e_station_type(tinyxml2::XMLElement *elem, e_station_type& t);
void parse_e_station_platform_segment_side(tinyxml2::XMLElement *elem, e_station_platform_segment_side& t);
void parse_e_dataQuality_RawData_Source(tinyxml2::XMLElement *elem, e_dataQuality_RawData_Source& t);
void parse_e_dataQuality_RawData_PostProcessing(tinyxml2::XMLElement *elem, e_dataQuality_RawData_PostProcessing& t);
void parse_e_unitDistance(tinyxml2::XMLElement *elem, e_unitDistance& t);
void parse_e_unitSpeed(tinyxml2::XMLElement *elem, e_unitSpeed& t);
void parse_e_unitMass(tinyxml2::XMLElement *elem, e_unitMass& t);
void parse_e_unitSlope(tinyxml2::XMLElement *elem, e_unitSlope& t);
void parse_e_unit(tinyxml2::XMLElement *elem, e_unit& t);
void parse_e_roadType(tinyxml2::XMLElement *elem, e_roadType& t);
void parse_e_roadMarkType(tinyxml2::XMLElement *elem, e_roadMarkType& t);
void parse_e_roadMarkWeight(tinyxml2::XMLElement *elem, e_roadMarkWeight& t);
void parse_e_roadMarkColor(tinyxml2::XMLElement *elem, e_roadMarkColor& t);
void parse_e_laneType(tinyxml2::XMLElement *elem, e_laneType& t);
void parse_e_objectType(tinyxml2::XMLElement *elem, e_objectType& t);
void parse_e_tunnelType(tinyxml2::XMLElement *elem, e_tunnelType& t);
void parse_e_bridgeType(tinyxml2::XMLElement *elem, e_bridgeType& t);
void parse_e_accessRestrictionType(tinyxml2::XMLElement *elem, e_accessRestrictionType& t);
void parse_e_countryCode(tinyxml2::XMLElement *elem, e_countryCode& t);
void parse_e_countryCode_deprecated(tinyxml2::XMLElement *elem, e_countryCode_deprecated& t);
void parse_e_countryCode_iso3166alpha3(tinyxml2::XMLElement *elem, e_countryCode_iso3166alpha3& t);
void parse_e_sideType(tinyxml2::XMLElement *elem, e_sideType& t);
void parse_e_outlineFillType(tinyxml2::XMLElement *elem, e_outlineFillType& t);
void parse_e_borderType(tinyxml2::XMLElement *elem, e_borderType& t);
void parse_e_contactPoint(tinyxml2::XMLElement *elem, e_contactPoint& t);
void parse_e_elementDir(tinyxml2::XMLElement *elem, e_elementDir& t);
void parse_e_direction(tinyxml2::XMLElement *elem, e_direction& t);
void parse_e_roadMarkRule(tinyxml2::XMLElement *elem, e_roadMarkRule& t);
void parse_e_orientation(tinyxml2::XMLElement *elem, e_orientation& t);
void parse_t_header(tinyxml2::XMLElement *elem, t_header& t);
void parse_t_header_GeoReference(tinyxml2::XMLElement *elem, t_header_GeoReference& t);
void parse_t_header_Offset(tinyxml2::XMLElement *elem, t_header_Offset& t);
void parse_t_road(tinyxml2::XMLElement *elem, t_road& t);
void parse_t_road_link(tinyxml2::XMLElement *elem, t_road_link& t);
void parse_t_road_link_predecessorSuccessor(tinyxml2::XMLElement *elem, t_road_link_predecessorSuccessor& t);
void parse_t_road_link_neighbor(tinyxml2::XMLElement *elem, t_road_link_neighbor& t);
void parse_t_road_type(tinyxml2::XMLElement *elem, t_road_type& t);
void parse_t_road_type_speed(tinyxml2::XMLElement *elem, t_road_type_speed& t);
void parse_t_road_planView(tinyxml2::XMLElement *elem, t_road_planView& t);
void parse_t_road_planView_geometry(tinyxml2::XMLElement *elem, t_road_planView_geometry& t);
void parse_t_road_planView_geometry_line(tinyxml2::XMLElement *elem, t_road_planView_geometry_line& t);
void parse_t_road_planView_geometry_spiral(tinyxml2::XMLElement *elem, t_road_planView_geometry_spiral& t);
void parse_t_road_planView_geometry_arc(tinyxml2::XMLElement *elem, t_road_planView_geometry_arc& t);
void parse_t_road_planView_geometry_poly3(tinyxml2::XMLElement *elem, t_road_planView_geometry_poly3& t);
void parse_t_road_planView_geometry_paramPoly3(tinyxml2::XMLElement *elem, t_road_planView_geometry_paramPoly3& t);
void parse_t_road_elevationProfile(tinyxml2::XMLElement *elem, t_road_elevationProfile& t);
void parse_t_road_elevationProfile_elevation(tinyxml2::XMLElement *elem, t_road_elevationProfile_elevation& t);
void parse_t_road_lateralProfile(tinyxml2::XMLElement *elem, t_road_lateralProfile& t);
void parse_t_road_lateralProfile_superelevation(tinyxml2::XMLElement *elem, t_road_lateralProfile_superelevation& t);
void parse_t_road_lateralProfile_crossfall(tinyxml2::XMLElement *elem, t_road_lateralProfile_crossfall& t);
void parse_t_road_lateralProfile_shape(tinyxml2::XMLElement *elem, t_road_lateralProfile_shape& t);
void parse_t_road_lanes(tinyxml2::XMLElement *elem, t_road_lanes& t);
void parse_t_road_lanes_laneOffset(tinyxml2::XMLElement *elem, t_road_lanes_laneOffset& t);
void parse_t_road_lanes_laneSection(tinyxml2::XMLElement *elem, t_road_lanes_laneSection& t);
void parse_t_road_lanes_laneSection_left(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_left& t);
void parse_t_road_lanes_laneSection_center(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_center& t);
void parse_t_road_lanes_laneSection_right(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_right& t);
void parse_t_road_lanes_laneSection_center_lane(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_center_lane& t);
void parse_t_road_lanes_laneSection_lr_lane(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_lr_lane& t);
void parse_t_road_lanes_laneSection_left_lane(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_left_lane& t);
void parse_t_road_lanes_laneSection_right_lane(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_right_lane& t);
void parse_t_road_lanes_laneSection_lcr_lane_link(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_lcr_lane_link& t);
void parse_t_road_lanes_laneSection_lcr_lane_link_predecessorSuccessor(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_lcr_lane_link_predecessorSuccessor& t);
void parse_t_road_lanes_laneSection_lr_lane_width(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_lr_lane_width& t);
void parse_t_road_lanes_laneSection_lr_lane_border(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_lr_lane_border& t);
void parse_t_road_lanes_laneSection_lcr_lane_roadMark(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_lcr_lane_roadMark& t);
void parse_t_road_lanes_laneSection_lcr_lane_roadMark_sway(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_lcr_lane_roadMark_sway& t);
void parse_t_road_lanes_laneSection_lcr_lane_roadMark_type(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_lcr_lane_roadMark_type& t);
void parse_t_road_lanes_laneSection_lcr_lane_roadMark_type_line(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_lcr_lane_roadMark_type_line& t);
void parse_t_road_lanes_laneSection_lcr_lane_roadMark_explicit(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_lcr_lane_roadMark_explicit& t);
void parse_t_road_lanes_laneSection_lcr_lane_roadMark_explicit_line(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_lcr_lane_roadMark_explicit_line& t);
void parse_t_road_lanes_laneSection_lr_lane_material(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_lr_lane_material& t);
void parse_t_road_lanes_laneSection_lr_lane_visibility(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_lr_lane_visibility& t);
void parse_t_road_lanes_laneSection_lr_lane_speed(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_lr_lane_speed& t);
void parse_t_road_lanes_laneSection_lr_lane_access(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_lr_lane_access& t);
void parse_t_road_lanes_laneSection_lr_lane_height(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_lr_lane_height& t);
void parse_t_road_lanes_laneSection_lr_lane_rule(tinyxml2::XMLElement *elem, t_road_lanes_laneSection_lr_lane_rule& t);
void parse_t_road_objects(tinyxml2::XMLElement *elem, t_road_objects& t);
void parse_t_road_objects_object(tinyxml2::XMLElement *elem, t_road_objects_object& t);
void parse_t_road_objects_object_repeat(tinyxml2::XMLElement *elem, t_road_objects_object_repeat& t);
void parse_t_road_objects_object_outlines(tinyxml2::XMLElement *elem, t_road_objects_object_outlines& t);
void parse_t_road_objects_object_outlines_outline(tinyxml2::XMLElement *elem, t_road_objects_object_outlines_outline& t);
void parse_t_road_objects_object_outlines_outline_cornerRoad(tinyxml2::XMLElement *elem, t_road_objects_object_outlines_outline_cornerRoad& t);
void parse_t_road_objects_object_outlines_outline_cornerLocal(tinyxml2::XMLElement *elem, t_road_objects_object_outlines_outline_cornerLocal& t);
void parse_t_road_objects_object_material(tinyxml2::XMLElement *elem, t_road_objects_object_material& t);
void parse_t_road_objects_object_laneValidity(tinyxml2::XMLElement *elem, t_road_objects_object_laneValidity& t);
void parse_t_road_objects_object_parkingSpace(tinyxml2::XMLElement *elem, t_road_objects_object_parkingSpace& t);
void parse_t_road_objects_object_markings(tinyxml2::XMLElement *elem, t_road_objects_object_markings& t);
void parse_t_road_objects_object_markings_marking(tinyxml2::XMLElement *elem, t_road_objects_object_markings_marking& t);
void parse_t_road_objects_object_markings_marking_cornerReference(tinyxml2::XMLElement *elem, t_road_objects_object_markings_marking_cornerReference& t);
void parse_t_road_objects_object_borders(tinyxml2::XMLElement *elem, t_road_objects_object_borders& t);
void parse_t_road_objects_object_borders_border(tinyxml2::XMLElement *elem, t_road_objects_object_borders_border& t);
void parse_t_road_objects_objectReference(tinyxml2::XMLElement *elem, t_road_objects_objectReference& t);
void parse_t_road_objects_tunnel(tinyxml2::XMLElement *elem, t_road_objects_tunnel& t);
void parse_t_road_objects_bridge(tinyxml2::XMLElement *elem, t_road_objects_bridge& t);
void parse_t_road_signals(tinyxml2::XMLElement *elem, t_road_signals& t);
void parse_t_road_signals_signal(tinyxml2::XMLElement *elem, t_road_signals_signal& t);
void parse_t_road_signals_signal_dependency(tinyxml2::XMLElement *elem, t_road_signals_signal_dependency& t);
void parse_t_road_signals_signal_reference(tinyxml2::XMLElement *elem, t_road_signals_signal_reference& t);
void parse_t_road_signals_signal_positionRoad(tinyxml2::XMLElement *elem, t_road_signals_signal_positionRoad& t);
void parse_t_road_signals_signal_positionInertial(tinyxml2::XMLElement *elem, t_road_signals_signal_positionInertial& t);
void parse_t_road_signals_signalReference(tinyxml2::XMLElement *elem, t_road_signals_signalReference& t);
void parse_t_road_surface(tinyxml2::XMLElement *elem, t_road_surface& t);
void parse_t_road_surface_CRG(tinyxml2::XMLElement *elem, t_road_surface_CRG& t);
void parse_t_road_railroad(tinyxml2::XMLElement *elem, t_road_railroad& t);
void parse_t_road_railroad_switch(tinyxml2::XMLElement *elem, t_road_railroad_switch& t);
void parse_t_road_railroad_switch_mainTrack(tinyxml2::XMLElement *elem, t_road_railroad_switch_mainTrack& t);
void parse_t_road_railroad_switch_sideTrack(tinyxml2::XMLElement *elem, t_road_railroad_switch_sideTrack& t);
void parse_t_road_railroad_switch_partner(tinyxml2::XMLElement *elem, t_road_railroad_switch_partner& t);
void parse_t_controller(tinyxml2::XMLElement *elem, t_controller& t);
void parse_t_controller_control(tinyxml2::XMLElement *elem, t_controller_control& t);
void parse_t_junction(tinyxml2::XMLElement *elem, t_junction& t);
void parse_t_junction_connection(tinyxml2::XMLElement *elem, t_junction_connection& t);
void parse_t_junction_predecessorSuccessor(tinyxml2::XMLElement *elem, t_junction_predecessorSuccessor& t);
void parse_t_junction_connection_laneLink(tinyxml2::XMLElement *elem, t_junction_connection_laneLink& t);
void parse_t_junction_priority(tinyxml2::XMLElement *elem, t_junction_priority& t);
void parse_t_junction_controller(tinyxml2::XMLElement *elem, t_junction_controller& t);
void parse_t_junction_surface(tinyxml2::XMLElement *elem, t_junction_surface& t);
void parse_t_junction_surface_CRG(tinyxml2::XMLElement *elem, t_junction_surface_CRG& t);
void parse_t_junctionGroup(tinyxml2::XMLElement *elem, t_junctionGroup& t);
void parse_t_junctionGroup_junctionReference(tinyxml2::XMLElement *elem, t_junctionGroup_junctionReference& t);
void parse_t_station(tinyxml2::XMLElement *elem, t_station& t);
void parse_t_station_platform(tinyxml2::XMLElement *elem, t_station_platform& t);
void parse_t_station_platform_segment(tinyxml2::XMLElement *elem, t_station_platform_segment& t);
void parse_t_userData(tinyxml2::XMLElement *elem, t_userData& t);
void parse_t_include(tinyxml2::XMLElement *elem, t_include& t);
void parse_t_dataQuality(tinyxml2::XMLElement *elem, t_dataQuality& t);
void parse_t_dataQuality_Error(tinyxml2::XMLElement *elem, t_dataQuality_Error& t);
void parse_t_dataQuality_RawData(tinyxml2::XMLElement *elem, t_dataQuality_RawData& t);
