class CfgPatches
{
	class BlobBoltPicker2
	{
		requiredAddons[] = 
		{
			"DZ_Data",
			"JM_CF_Scripts"
		};
	};
};

class CfgMods
{
	class BlobBoltPicker2
	{
		type = "mod";
		inputs="BoltPicker2\data\modded_inputs.xml";
		dependencies[]={"World", "Mission"}; 
		class defs
		{
            class worldScriptModule
            {
                files[] = {".../scripts/4_World"}
            };
			class missionScriptModule
			{
				files[] = {".../scripts/5_Mission"};
			};
		};
	};
};

class CfgVehicles
{
	class ItemBase;
	class BlobBolt: ItemBase
	{
		scope=1;
		displayName="Bolt";
		descriptionShort="A rusty old bolt.";
		model="BoltPicker2\data\economy\bolt.p3d";
		
		debug_ItemCategory=2;
		rotationFlags=17;
		weight=10;
		absorbency=0.5;
		itemSize[]={1,1};
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=1;
		varQuantityDestroyOnMin=1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10;
				};
			};
		};
	};
};