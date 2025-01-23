class CfgPatches
{
	class UnderbarrelCigarette
	{
		requiredAddons[] = 
		{
			"DZ_Data",
			"JM_CF_Scripts",
			"NH_Scripts"
		};
	};
};

class CfgMods
{
	class UnderbarrelCigarette
	{
		type = "mod";
		inputs="UnderbarrelCigarette\data\modded_inputs.xml";
		dependencies[]={"World", "Mission"}; 
		class defs
		{
            class worldScriptModule
            {
                files[] = {"UnderbarrelCigarette/scripts/4_World"};
            };
			class missionScriptModule
			{
				files[] = {"UnderbarrelCigarette/scripts/5_Mission"};
			};
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class BlobBolt: Inventory_Base
	{
		scope=1;
		displayName="Bolt";
		descriptionShort="A rusty old bolt.";
		model="UnderbarrelCigarette\data\blobbolt.p3d";
		hiddenSelectionsTextures[] = {"UnderbarrelCigarette\data\blobbolt\blobbolt_co.paa"};
		debug_ItemCategory=2;
		rotationFlags=17;
		weight=1000;
		absorbency=0.5;
		itemSize[]={1,1};
		canBeSplit=1;
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=1;
		varQuantityDestroyOnMin=1;
		soundImpactType="metal";
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