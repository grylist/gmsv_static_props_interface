#include "main.hpp"
#include <GarrysMod/FactoryLoader.hpp>

IStaticPropMgrServer *StaticProp( )
{
	static IStaticPropMgrServer *iface_pointer = nullptr;
	if( iface_pointer == nullptr )
	{
		SourceSDK::FactoryLoader engine_loader( "engine" );
		iface_pointer = engine_loader.GetInterface<IStaticPropMgrServer>( "StaticPropMgrServer002" );
	}

	return iface_pointer;
}

IVModelInfo *ModelInfo( )
{
	static IVModelInfo *iface_pointer = nullptr;
	if( iface_pointer == nullptr )
	{
		SourceSDK::FactoryLoader engine_loader( "engine" );
		iface_pointer = engine_loader.GetInterface<IVModelInfo>( "VModelInfoServer004" );
	}

	return iface_pointer;
}