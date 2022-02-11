#include "vrmine\vr_plugins\treeitem\layeritem.h"


VRLayerItem::VRLayerItem()
	:mType(""),ref_mpBindingObject(NULL)
{

}

VRLayerItem::~VRLayerItem()
{

}

std::string& VRLayerItem::getType()
{
	return this->mType;
}

void VRLayerItem::setType(const std::string& type)
{
	this->mType = type;
}

void VRLayerItem::setBindingObject(VirtualMine::SpatialInterface::ILayer* ref_pBindingObject)
{
	this->ref_mpBindingObject = ref_pBindingObject;
}

VirtualMine::SpatialInterface::ILayer* VRLayerItem::getBindingObject()
{
	return this->ref_mpBindingObject;
}

VRFeatureItem::VRFeatureItem()
	:ref_mpBindingObject(NULL)
{

}

VRFeatureItem::~VRFeatureItem()
{

}

void VRFeatureItem::setBindingObject(VirtualMine::SpatialInterface::IGeoObject* ref_pBindingObject)
{
	this->ref_mpBindingObject = ref_pBindingObject;
}

VirtualMine::SpatialInterface::IGeoObject* VRFeatureItem::getBindingObject()
{
	return this->ref_mpBindingObject;
}