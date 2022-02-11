
#include "vrmine/vr_core/geodatatype.h"

namespace VirtualMine
{
	namespace Core
	{				
		std::string GeoDataType::GDT_IMAGE("GDT_IMAGE_TYPE");
		std::string GeoDataType::GDT_DEM("GDT_DEM_TYPE");
		std::string GeoDataType::GDT_MODEL("GDT_MODEL_TYPE");
		std::string GeoDataType::GDT_VECTOR("GDT_VECTOR_TYPE");
		std::string GeoDataType::GDT_LANWAY("GDT_LANWAY_TYPE");
		//kk
		std::string GeoDataType::GDT_LANWAYPRO("GDT_LANWAYPRO_TYPE");
		std::string GeoDataType::GDT_COALSEAM("GDT_COALSEAM_TYPE");
		std::string GeoDataType::GDT_FAULT("GDT_FAULT_TYPE");
		std::string GeoDataType::GDT_DRILL("GDT_DRILL_TYPE");
		std::string GeoDataType::GDT_MINE("GDT_MINE_TYPE");
		std::string GeoDataType::GDT_MININGAREA("GDT_MININGAREA_TYPE");
		std::string GeoDataType::GDT_POINT("GDT_POINT_TYPE");
		std::string GeoDataType::GDT_LINE("GDT_LINE_TYPE");
		std::string GeoDataType::GDT_POLYGON("GDT_POLYGON_TYPE");
		std::string GeoDataType::GDT_WORKINGPLANE("GDT_WORKINGPLANE_TYPE");
		std::string GeoDataType::GDT_TERRANE("GDT_TERRANE_TYPE");
		std::string GeoDataType::GDT_ESCAPEROUTE("GDT_ESCAPEROUTE_TYPE");
		std::string GeoDataType::GDT_SHOTHOLE("GDT_SHOTHOLE_TYPE");
		std::string GeoDataType::GDT_2DSHOTHOLE("GDT_2DSHOTHOLE_TYPE");
		std::string GeoDataType::GDT_2DROCKLAYER("GDT_GDT_2DROCKLAYER_TYPE");
	    std::string GeoDataType::GDT_LANEWAYSECTION("GDT_LANEWAYSECTION_TYPE");
		//kk施工组织
		std::string GeoDataType::GDT_CONORGANIZATION("GDT_CONORGANIZATION_TYPE");
		//kk施工进度
		std::string GeoDataType::GDT_CONPROGRESS("GDT_CONPROGRESS_TYPE");

		std::string GeoDatabaseType::GDBT_SQLITE("GDBT_SQLITE_TYPE");
		std::string GeoDatabaseType::GDBT_MYSQL("GDBT_ACCESS_TYPE");
		std::string GeoDatabaseType::GDBT_ORACLE("GDBT_MYSQL_TYPE");
		std::string GeoDatabaseType::GDBT_ACCESS("GDBT_ORACLE_TYPE");
		std::string GeoDatabaseType::GDBT_REMOTE("GDBT_REMOTE_TYPE");

		std::string GeoMaterialType::GMT_LANEWAY_NORMAL("testMaterial");

		std::string GeoMaterialType::GMT_LANEWAY_NOAIR("lanewayWindMaterialNo");

		std::string GeoMaterialType::GMT_LANEWAY_FRESHWIND_FORWARD("lanewayWindMaterial");
		std::string GeoMaterialType::GMT_LANEWAY_FRESHWIND_REVERSE("lanewayInverseWindMaterial");

		std::string GeoMaterialType::GMT_LANEWAY_WASTEWIND_FORWARD("lanewayWindMaterial2");
		std::string GeoMaterialType::GMT_LANEWAY_WASTEWIND_REVERSE("lanewayInverseWindMaterial2");
	}
}