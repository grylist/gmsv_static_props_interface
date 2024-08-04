#pragma once

#ifndef STATIC_PROPS_INTERFACE_H
#define STATIC_PROPS_INTERFACE_H

class IStaticPropMgrServer;
class IVModelInfo;

extern IStaticPropMgrServer *staticpropmgr;
extern IVModelInfo          *modelinfo;

IStaticPropMgrServer    *StaticProp( );
IVModelInfo             *ModelInfo( );

#endif		//STATIC_PROPS_INTERFACE_H