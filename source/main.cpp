#include "GarrysMod/Lua/Interface.h"
#include "engine/IStaticPropMgr.h"
#include "engine/ivmodelinfo.h"
#include "engine/ICollideable.h"
#include "main.hpp"
#include <cstdint>

using namespace GarrysMod::Lua;

IStaticPropMgrServer *staticpropmgr = nullptr;
IVModelInfo *modelinfo = nullptr;

LUA_FUNCTION_STATIC( GetStaticPropModelNameByIndex )
{
 	uint16_t index = LUA->CheckNumber( 1 );

	ICollideable *pCollide = staticpropmgr->GetStaticPropByIndex( index );
	if(pCollide == nullptr){
		LUA->ThrowError("[gmsv_static_props_interface] Failed to get static prop: invalid index");
	}

	const model_t *pModel = pCollide->GetCollisionModel();
	const char *pModelName = modelinfo->GetModelName( pModel );

	LUA->PushString( pModelName );

	return 1;
}

GMOD_MODULE_OPEN()
{
	staticpropmgr = StaticProp();
	if (staticpropmgr == nullptr) {
		Msg("[gmsv_static_props_interface] Failed to load required IStaticPropMgrServer interface\n");
		return 0;
    }

	modelinfo = ModelInfo();
	if (modelinfo == nullptr) {
		Msg("[gmsv_static_props_interface] Failed to load required IVModelInfo interface\n");
		return 0;
    }

	Msg("[gmsv_static_props_interface] Loaded succesfully.\n");

	LUA->PushSpecial( SPECIAL_GLOB );
	LUA->PushString( "GetStaticPropModelNameByIndex" );
	LUA->PushCFunction( GetStaticPropModelNameByIndex );
	LUA->SetTable( -3 );

	return 0;
}

GMOD_MODULE_CLOSE()
{
	Msg("[gmsv_static_props_interface] Unloaded succesfully.\n");

	return 0;
}